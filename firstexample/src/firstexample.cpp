// File: firstexample.cpp
//
// Using xtensor according to the documentation
// https://xtensor.readthedocs.io/en/latest/getting_started.html
#include <iostream>
#include "xtensor/xarray.hpp"
#include "xtensor/xio.hpp"
#include "xtensor/xview.hpp"

int main(int argc, char* arv[]) {
   xt::xarray<double> arr1
      {{1.0, 2.0, 3.0},
       {2.0, 5.0, 7.0},
       {2.0, 5.0, 7.0}};

   xt::xarray<double> arr2
      {5.0, 6.0, 7.0};

   xt::xarray<double> res = xt::view(arr1,1) + arr2;
   std::cout << res;
   std::cout << '\n';

   return 0;
}
