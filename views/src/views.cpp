// File: views.cpp
//
// Different examples of using Xtensor views
#include <vector>
#include "xtensor/xarray.hpp"
#include "xtensor/xview.hpp"
#include "xtensor/xio.hpp"

#define PRINTER(name) printer(#name, (name))
// description of this construct found here:
// https://stackoverflow.com/questions/3386861/converting-a-variable-name-to-a-string-in-c

template <typename T>
void printer(std::string const &name, T V){
    std::cout << "The view " << name << ": " << std::endl;
    std::cout << V << std::endl;
    std::cout << std::endl;
}

int main(int argc, char *argv[]){
   std::vector<size_t> shape = {3, 2, 4};
   xt::xarray<int> a(shape);

   // View with same number of dimensions
   auto v1 = xt::view(a, xt::range(1, 3), xt::all(), xt::range(1, 3));

   PRINTER(a);  // a is not view, but an array - wrong in output here.˚
   PRINTER(v1);
   //   v1.shape()  = {2,2,2};
   PRINTER(v1(1,1,1));
   // => v(1,1,1) = a(2,1,2)

   // Generate a range and assign it to array of shape {3,2,4}
   auto b = xt::arange<double>(0,25).reshape({3,2,4});
   // Create view with the same number of dimensions
   auto v1b = xt::view(b, xt::range(1,3), xt::all(), xt::range(1, 3));
   // Write array and view to console
   PRINTER(b);
   PRINTER(v1b);
   // Output v2(0,0,0) and v2(1,1,1)
   PRINTER(v1b(0,0,0));
   PRINTER(v1b(1,1,1));

   // A view which reduce the number of dimensions
   auto v2 = xt::view(b, 1, xt::all(), xt::range(0, 4, 2));
   // v2.shape() = {2, 2}
   // v2(0,0)
   PRINTER(v2);
   PRINTER(v2(0,0));

   // A view increasing the number of dimensions
   auto v3 = xt::view(b,xt::all(), xt::all(), xt::newaxis(), xt::all());
   // v3.shape = { 3, 2, 1, 4 }
   // v3(0,0,0,0) = a(0,0,0)

   PRINTER(v3(0,0,0,0));
   PRINTER(v3(2,1,0,3));
   PRINTER(v3);

    // A view with non-contiguous slices
    auto v4 = xt::view(b,xt::drop(0), xt::all(), xt::keep(0,3));
    // v3.shape = { 2, 2, 2 }
    // => v4(0,0,0) = a(1,0,0)
    // => v4(1,1,1) = a(2,1,3)

    PRINTER(v4(0,0,0));
    PRINTER(v4(1,1,1));
    PRINTER(v4);



    return 0;
}
