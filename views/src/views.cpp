// File: views.cpp
//
// Different examples of using Xtensor views
#include <vector>
#include "xtensor/xarray.hpp"
#include "xtensor/xview.hpp"
#include "xtensor/xio.hpp"

int main(int argc, char *argv[]){
   std::vector<size_t> shape = {3, 2, 4};
   xt::xarray<int> a(shape);

   // View with same number of dimensions
   auto v1 = xt::view(a, xt::range(1, 3), xt::all(), xt::range(1, 3));
   
   std::cout << a << std::endl;
   std::cout << v1 << std::endl;

//   v1.shape()  = {2,2,2};
   std::cout << v1(0,0,0) << std::endl; // a(1,0,1)
   // => v(1,1,1) = a(2,1,2)

   // Generate a range and assign it to array of shape {3,2,4}
   auto b = xt::arange<double>(0,25).reshape({3,2,4});
   // Create view with the same number of dimensions
   auto v1b = xt::view(b, xt::range(1,3), xt::all(), xt::range(1, 3));
   // Write array and view to console
   std::cout << b << std::endl;
   std::cout << v1b << std::endl;
   std::cout << std::endl;
   // Output v2(0,0,0) and v2(1,1,1)
   std::cout << v1b(0,0,0) << std::endl;
   std::cout << v1b(1,1,1) << std::endl;
   std::cout << std::endl;

   // A view which reduce the number of dimensions
   auto v2 = xt::view(b, 1, xt::all(), xt::range(0, 4, 2));
   // v2.shape() = {2, 2}
   // v2(0,0)
   std::cout << v2(0,0) << std::endl;
   std::cout << v2(1,1) << std::endl;
   std::cout << std::endl;
   
   std::cout << "The complete v2 view: " << std::endl;
   std::cout << v2 << std::endl;
   std::cout << std::endl;

   return 0;
}
