#pragma once

namespace Tests{
class TestUtils{
  static void SetDefaultMatrix();

 public:
  static void SetDefaultTournamentConfiguration(bool add_random = false);

  static void SetDefaultFastConfiguration();

  static void SetDefaultDetailedConfiguration();
};
}