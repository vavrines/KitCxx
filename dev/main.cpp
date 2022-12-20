#include <iostream>
#include <string>
#include "xtensor/xarray.hpp"
#include "xtensor/xio.hpp"
#include "xtensor/xview.hpp"

using namespace std;

template <typename T> T Max(const T &a, const T &b) { return a < b ? b : a; }

std::string greet() { return "hello, world"; }
std::string greet(std::string &message) { return message; }

void test(xt::xarray<double> &a) {
  a(1, 1) = 79.0;
}

void test1(xt::xarray<double> &f, xt::xarray<double> &u) {f = u;}

int main() {
  std::string i = "miao";
  std::cout << greet() << std::endl;
  std::cout << greet(i) << std::endl;

  auto t = Max(2, 1);
  std::cout << t << std::endl;

  xt::xarray<double> a = {{1., 2., 3.}, {4., 5., 6.}};
  test(a);
  std::cout << a << std::endl;

  xt::xarray<double> b({2, 3});
  b.fill(0.0);
  test1(b, a);
  std::cout << b << std::endl;

  return 0;
}