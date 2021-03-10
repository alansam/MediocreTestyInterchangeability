// cpp

#define DEBUG_
#undef DEBUG_

#include "clike.hpp"

namespace clike {

//using namespace std;

int driver_main(int argc, char const * argv[]) {
	size_t num(0UL);
  int vett[SIZE] { 0, };
  int vett2[SIZE] { 0, };
//	int min, max, p;

	srand(time(NULL));

	do {
//  std::cout << "Inserisci quanti numeri deve avere il vettore: ";
	  std::cout << "Enter how many numbers the vector should have: ";
	  std::cin >> num;
	} while (num <= 0 || num > SIZE);   //`make sure input will fit in array

  // insert random numbers into vett
  randomize_vett(num, vett);

  //ciclo di copia
	vcopy(num, vett2, vett);

  //  do the bubbles
  std::cout << std::endl;
  bubbles(num, vett2);

  print(num, vett);   //  before
  print(num, vett2);  //  after

  //ciclo di copia
	vcopy(num, vett2, vett);

  //  do the bubble2
  std::cout << std::endl;
  bubble2(num, vett2);

  print(num, vett);   //  before
  print(num, vett2);  //  after

  return 0;
}

//  simple bubble sort
void bubbles(size_t sz, int * vett) {
#ifdef DEBUG_
//std::cout << "\n\n inzia il bubble Sort\n\n";
	std::cout << "\n\n bubble Sort begins\n\n";
#endif
  size_t j = sz;
  bool swap = true;

  while (swap) {
    swap = false;
    for (size_t i = 1; i < j; i++) {
      if (vett[i] < vett[i - 1]) {
#ifdef DEBUG_
        std::cout << "swap elements " << std::setw(2) << i - 1 << " [" << std::setw(2) << vett[i - 1]
                  << "] and "         << std::setw(2) << i     << " [" << std::setw(2) << vett[i] 
                  << "]\n";
#endif
        //  swap elements
        int temp = vett[i];
        vett[i] = vett[i - 1];
        vett[i - 1] = temp;
        swap = true;
      }
    }
    j--;
  }
}

//  your sort code moved into a separate function
void bubble2(size_t sz, int * vett2) {
#ifdef DEBUG_
//	cout << "\n\n inzia il bubble Sort\n\n";
	std::cout << "\n\n bubble Sort begins\n\n";
#endif

	for (size_t i = 0; i < sz - 1; i++) {
#ifdef DEBUG_
//	std::cout << "Il vettore e' cosi' adesso:" << endl;
	  std::cout << "The vector looks like this now:" << std::endl;

    for (size_t k = 0; k < sz - i; k++) { //ciclo di visualizzazione
//	  std::cout << "il "< <k + 1 << "^ elemento vale: " << vett2[k] << endl;
		  std::cout <<"the " << k + 1 << "^ element holds: " << vett2[k] << std::endl;
    }
#endif

	  for (size_t j = 0; j < sz - 1 - i; j++) { //ciclo interno
#ifdef DEBUG_
//	   std::cout << "Confronto " << vett2[j] << " con " << vett2[j + 1] << std::endl; 
	    std::cout <<"Comparison " << vett2[j] << " with " << vett2[j + 1] << std::endl; 
#endif
	    if (vett2[j] > vett2[j + 1]) {  //confronta ogni elemento con il successivo
#ifdef DEBUG_
//	    std::cout << "effettuo lo scambio" << std::endl;
	      std::cout << "I make the exchange" << std::endl;
#endif
	      int tmp = vett2[j + 1];
	      vett2[j + 1] = vett2[j];
	      vett2[j] = tmp;
		  }
#ifdef DEBUG_
			else {
//			std::cout << "non effettuo lo scambio" << std::endl;
			  std::cout << "I am not making the exchange" << std::endl;
			}

		  for (size_t k = 0; k < sz - i; k++) { //ciclo di visualizzazione
        std::cout << vett2[k] << " "; 
		  }
#endif
		}

#ifdef DEBUG_
//	 std::cout << "\nIl vettore e' cosi' adesso:" << std::endl;
	  std::cout << "\nThe vector is like this now:" << std::endl;
    for (size_t k = 0; k < sz; k++) { //ciclo di visualizzazione
//    std::cout << "il " << k + 1 << "^ elemento vale: " << vett2[k] << std::endl;
	    std::cout << "the " << k + 1 << "^ element holds: " << vett2[k] << std::endl;
    }
#endif
  }
}

} /* namespace clike */
