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
    std::cout << "s0 = " << s0 << std::endl;
    std::cout << "s1 = " << s1 << std::endl;
    std::cout << "s2 = " << s2 << std::endl;
    std::cout << "s3 = " << s3 << std::endl;
    std::cout << std::endl;

    // Variance
    std::cout << "------ V a r i a n c e -------" << std::endl;    
    xt::xarray<int> a = {{1, 2, 3},{4, 5, 6}};
    xt::xarray<int> t0 = xt::variance(a,{1});
    xt::xarray<int> t1 = xt::variance(a);
    int t2 = xt::variance(a)();
    auto t3 = xt::variance(a, {0});
    std::cout << "t0 = " << t0 << std::endl;
    std::cout << "t1 = " << t1 << std::endl;
    std::cout << "t2 = " << t2 << std::endl;
    std::cout << "t3 = " << t3 << std::endl;
    std::cout << std::endl;

    // Standard deviation
    std::cout << "------ S t a n d a r d   d e v i a t i o n -------" << std::endl;
    xt::xarray<int> a_sd = {{1, 2, 3}, {4, 5, 6}};
    xt::xarray<int> u0 = xt::stddev(a, {1});
    xt::xarray<int> u1 = xt::stddev(a);
    int u2 = xt::stddev(a)();
    auto u3 = xt::stddev(a, {0});
    std::cout << "u0 = " << u0 << std::endl;
    std::cout << "u1 = " << u1 << std::endl;
    std::cout << "u2 = " << u2 << std::endl;
    std::cout << "u3 = " << u3 << std::endl;
    std::cout << std::endl;

    // Diff
    std::cout << "------ D i f f -------" << std::endl;
    xt::xarray<int> a_diff = {{1, 2, 3}, {4, 5, 6}};
    xt::xarray<int> v0 = xt::diff(a_diff, 1, {0});
    xt::xarray<int> v1 = xt::diff(a_diff, 1, {1});
    std::cout << " v0 = " << v0 << std::endl;
    std::cout << " v1 = " << v1 << std::endl;
    std::cout << std::endl;
    
    return 0;
}
