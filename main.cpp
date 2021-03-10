
#include "clike.hpp"
#include "cpplike.hpp"

int main(int argc, char const * argv[]) {

  auto dlm = std::string(80, '.');

  std::cout << dlm << '\n';
  clike::driver_main(argc, argv);
  std::cout << std::endl;

  std::cout << dlm << '\n';
  cpplike::driver_main(argc, argv);
  std::cout << std::endl;

  return 0;
}
