#include <iostream>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
int main() {
    // Sum
    xt::xarray<int> a_sum = {{1,2,3},{4,5,6}};
    xt::xarray<int> r0 = xt::sum(a_sum,{1});
    std::cout << "r0 = " << r0 << std::endl;

    // Prod
    xt::xarray<int> a_prod = {{1,2},{3, 4}};
    xt::xarray<int> p0 = xt::prod(a_prod, {1});
    xt::xarray<int> p1 = xt::prod(a_prod);
    int p2 = xt::prod(a_prod)();
    auto p3 = xt::prod(a_prod, {0});
    std::cout << "p1 = " << p1 << std::endl;
    std::cout << "p2 = " << p2 << std::endl;
    std::cout << "p3 = " << p3 << std::endl;
    return 0;
}