#include <iostream>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
int main() {
    // Sum
    std::cout << " ------- S u m ----------" << std::endl;
    xt::xarray<int> a_sum = {{1,2,3},{4,5,6}};
    xt::xarray<int> r0 = xt::sum(a_sum,{1});
    xt::xarray<int> r1 = xt::sum(a_sum);
    int r2 = xt::sum(a_sum)();
    auto r3 = xt::sum(a_sum, {1});   // r3 is an unevaluated expression
    std::cout << "r0 = " << r0 << std::endl;
    std::cout << "r1 = " << r1 << std::endl; // Outputs {21}, a 0D-tensor???
    std::cout << "r2 = " << r2 << std::endl; // Outputs 21
    std::cout << "r3 = " << r3 << std::endl; // Outputs {6,15}. Values are computed upon each access
    std::cout << std::endl;

    // Prod
    std::cout << " ------ P r o d u c t -------" << std::endl;
    xt::xarray<int> a_prod = {{1,2},{3, 4}};
    xt::xarray<int> p0 = xt::prod(a_prod, {1});
    xt::xarray<int> p1 = xt::prod(a_prod);
    int p2 = xt::prod(a_prod)();
    auto p3 = xt::prod(a_prod, {0});
    std::cout << "p1 = " << p1 << std::endl;
    std::cout << "p2 = " << p2 << std::endl;
    std::cout << "p3 = " << p3 << std::endl;
    std::cout << std::endl;

    // Mean
    std::cout << "------ M e a n -------" << std::endl;
    xt::xarray<int> a_mean = {{1, 2, 3}, {4, 5, 6}};
    xt::xarray<int> s0 = xt::mean(a_mean,{1});
    xt::xarray<int> s1 = xt::mean(a_mean);
    int s2 = xt::mean(a_mean)();
    auto s3 = xt::mean(a_mean, {0});
    std::cout << "s1 = " << s1 << std::endl;
    std::cout << "s2 = " << s2 << std::endl;
    std::cout << "s3 = " << s3 << std::endl;
    std::cout << std::endl;

    return 0;
}