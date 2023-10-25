import <iostream>;
import module1;
import module2;

int main() {
  std::cout <<  "Hello world!" << "\n";

  std::cout << Module1::getMyName() << "\n";
  std::cout << Module2::getMyName() << "\n";

  return 0;
}
