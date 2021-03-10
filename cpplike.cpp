
#include "cpplike.hpp"

namespace cpplike {

int driver_main(int argc, char const * argv[]) {
  auto num(0UL);

	do {
//	std::cout << "Inserisci quanti numeri deve avere il vettore: ";
		std::cout << "Enter how many numbers the vector should have: ";
		std::cin >> num;
	} while (num <= 0);   //`make sure input will fit in array

  std::vector<int> vett(num);
  std::vector<int> vett2(num);

  // insert random numbers into vett
  randomize_vett(vett);
  std::copy(vett.cbegin(), vett.cend(), vett2.begin());

  std::cout << "std::sort\n";
  std::sort(vett2.begin(), vett2.end());
  print(vett);
  print(vett2);
  std::cout << std::endl;

  std::cout << "bubble sort\n";
  bubble_sort(vett2.begin(), vett2.end());
  print(vett);
  print(vett2);
  std::cout << std::endl;
    
  return 0;
}

} /* namespace cpplike */
