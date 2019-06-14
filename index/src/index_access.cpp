// File: index_access.cpp
//
// Example showing index access in Xtensor.
// Example is from web page https://xtensor.readthedocs.io/en/latest/getting_started.html
#include <iostream>
#include "xtensor/xarray.hpp"
#include "xtensor/xio.hpp"

int main(int argc, char* argv[]){
   xt::xarray<double> arr1
      {{1.0,2.0,3.0},
       {2.0,5.0,7.0},
       {2.0,5.0,7.0}};

   std::cout << arr1(0,0) << std::endl;

   xt::xarray<int> arr2
      {1, 2, 3, 4, 5, 6, 7, 8, 9,};

   std::cout << arr2(0);
   std::cout << std::endl;
   return 0;
}
