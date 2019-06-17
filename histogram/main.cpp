#include <iostream>
#include <xtensor/xtensor.hpp>
#include <xtensor/xhistogram.hpp>
#include <xtensor/xio.hpp>

int main() {
    xt::xtensor<double,1> data = {1., 1., 2., 2., 3.};
    xt::xtensor<double,1> bin_edges = xt::histogram_bin_edges(data, std::size_t(2), xt::histogram_algorithm::uniform);
    xt::xtensor<double,1> prob = xt::histogram(data, bin_edges, true);
    std::cout << bin_edges << std::endl;
    std::cout << prob << std::endl;
    return 0;
}