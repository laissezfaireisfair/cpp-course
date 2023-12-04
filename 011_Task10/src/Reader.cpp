#include <fstream>
#include <regex>

#include "Reader.h"

namespace ini {
using std::getline;
using std::make_unique;
using std::regex;
using std::regex_match;

class Reader::Impl {
 public:
  Impl() :
      comment_regex_{R"(^\s*[;#].*(\r|\n|\r\n)?$)"},
      whitespace_regex_{R"(^\s*(\r|\n|\r\n)?$)"},
      section_header_regex_{R"(^\s*\[[^\s\[\]]+\]\s*[;#]?.*(\r|\n|\r\n)?$)"},
      entry_regex_{R"(^\S+\s*=\s*\S+\s*[;#]?.*(\r|\n|\r\n)?$)"} {
  }

  Document ReadDocument(istream& stream) {
    auto document = Document();
    Section* current_section = nullptr;

    for (string line; getline(stream, line);) {
      bool is_comment_or_whitespace = regex_match(line, comment_regex_)
          || regex_match(line, whitespace_regex_);
      if (is_comment_or_whitespace)
        continue;

      bool is_section_header = regex_match(line, section_header_regex_);
      if (is_section_header) {
        current_section = ReadSectionHeader(line, document);
        continue;
      }

      bool is_entry = regex_match(line, entry_regex_);
      if (is_entry)
        ReadEntry(line, current_section);
      else
        continue;
    }

    return document;
  }

  ~Impl() = default;

 private:
  regex comment_regex_;

  regex whitespace_regex_;

  regex section_header_regex_;

  regex entry_regex_;

  static Section* ReadSectionHeader(string& line, Document& document) {
    enum ReadStatus { Prefix = 0, Name = 1, Postfix = 2 };

    string name;
    ReadStatus read_status = Prefix;
    for (char symbol : line) {
      switch (read_status) {
        case Prefix:
          if (symbol == '[')
            read_status = Name;
          break;

        case Name:
          if (symbol != ']') {
            name.push_back(symbol);
            break;
          }
          read_status = Postfix;
          [[fallthrough]];

        case Postfix: break;
      }

      if (read_status == Postfix)
        break;
    }

    return &document.AddSection(name);
  }

  static void ReadEntry(string& line, Section* current_section) {
    enum ReadStatus { Prefix = 0, Key = 1, Value = 2, Postfix = 3 };

    ReadStatus read_status = Prefix;
    string key;
    string value;
    for (char symbol : line) {
      switch (read_status) {
        case Prefix:
          if (isspace(symbol))
            break;
          read_status = Key;
          [[fallthrough]];

        case Key:
          if (symbol != '=') {
            if (!isspace(symbol))
              key.push_back(symbol);
          } else {
            read_status = Value;
          }
          break;

        case Value:
          if (isspace(symbol)) {
            if (value.empty())
              break;

            read_status = Postfix;
            [[fallthrough]];
          } else {
            value.push_back(symbol);
            break;
          }

        case Postfix: break;
      }

      if (read_status == Postfix)
        break;
    }

    current_section->SetValueByKey(key, value);
  }
};

Reader::Reader() :
    pimpl_{make_unique<Impl>()} {
}

Document Reader::ReadDocument(istream& stream) {
  return pimpl_->ReadDocument(stream);
}

Reader::~Reader() = default;
}