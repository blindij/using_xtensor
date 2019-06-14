// File: reshape.cpp
// 
// Example initializes a 1-dimensonal array and reshapes it in-place
// Original example page:https://xtensor.readthedocs.io/en/latest/getting_started.html
#include <iostream>
#include "xtensor/xarray.hpp"
#include "xtensor/xio.hpp"

int main(int argc, char* argv[]) {
   xt::xarray<int> arr {1, 2, 3, 4, 5, 6, 7, 8, 9};
   arr.reshape({3,3});
   std::cout << arr;
   std::cout << '\n';
   return 0;
}
