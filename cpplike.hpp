#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <iterator>

namespace cpplike {

int driver_main(int argc, char const * argv[]);

static
auto constexpr prn_max(60);

inline
static
void randomize_vett(std::vector<int> & vett) {
    std::transform(vett.begin(), vett.end(), vett.begin(), [](auto x_) {
        int srn = rand() % prn_max;  //  get pseudo-random number
        return srn;  //  put pseudo-random number into array
    });
}

inline
static
void print(std::vector<int> const & vett) {
    std::for_each(vett.begin(), vett.end(), [](auto x_) {
        std::cout << std::setw(3) << x_;
    });
    std::cout << '\n';
}

template <typename RAI>
void bubble_sort(RAI begin, RAI end) {
  bool swapped = true;
  while (begin != end-- && swapped) {
    swapped = false;
    for (auto i_(begin); i_ != end; ++i_) {
      if (*(i_ + 1) < *i_) {
        std::iter_swap(i_, i_ + 1);
        swapped = true;
      }
    }
  }
}


} /* namespace cpplike */
