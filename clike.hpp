
#pragma once

#include <iostream>
#include <iomanip>

namespace clike {

static
size_t constexpr SIZE(40);  //  maximum array size

static
auto constexpr prn_max(60);

int driver_main(int argc, char const * argv[]);

void bubbles(size_t sz, int * vett);
void bubble2(size_t sz, int * vett2);

//  general purpose array print function
inline
static
void print (size_t sz, int const * ary) {
  for (size_t e_ = 0; e_ < sz; ++e_) {
    std::cout << std::setw(3) << std::setw(3) << ary[e_];
  }
  std::cout << '\n';
}

inline
static
void vcopy(size_t sz, int * tgt, int const * src) {
  for (size_t c_(0); c_ < sz; ++c_) {
    tgt[c_] = src[c_];
  }
}

inline
static
void randomize_vett(size_t num, int * vett) {
	for (size_t i = 0; i < num; i++) {
    int srn = rand() % prn_max;  //  get pseudo-random number
#ifdef DEBUG_
    //  report
//	cout << "Ho generato i numeri: " << srn << endl;
    std::cout << "I generated the numbers: " << srn << std::endl;
#endif
    vett[i] = srn;  //  put pseudo-random number into aray
	}
}

} /* namespace clike */
