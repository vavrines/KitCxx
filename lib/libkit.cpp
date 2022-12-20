#include "jlcxx/jlcxx.hpp"
#include "xtensor-blas/xlinalg.hpp"
#include "xtensor-julia/jltensor.hpp" // Import the jltensor container definition
#include "xtensor/xmath.hpp"
#include <cmath>
#include <iostream>
#include <xtensor/xio.hpp>

#define PI acos(-1.0)

template <typename T> void maxwellian_1f1v(T H, T u, T prim) {
  // H = xt::eval(xt::sin(u));//prim[0] * prim[0] * pow(prim[2] / PI, 0.5) *
  // exp(-prim[2] * pow(u - prim[2], 2));
  int nu = H.shape(0);
  for (int i = 0; i < nu; i++) {
    H[i] = prim[0] * pow(prim[2] / PI, 0.5) *
           exp(-prim[2] * pow(u[i] - prim[1], 2));
  }
}

template <typename T> T test(T u) {
  //auto &&f = xt::eval(xt::exp(u));
  xt::jltensor<double, 1> f = u;
  return f;
}

template <typename T> void test1(T f, T u) { 
  //f = u; 
  int nu = u.shape(0);
  for (int i = 0; i < nu; i++) {
    f[i] = u[i];
  }
}

void test2(xt::jltensor<double, 1> &f, xt::jltensor<double, 1> &u) {f = u;}


JLCXX_MODULE define_julia_module(jlcxx::Module &mod) {
  mod.method(
      "maxwellian_1f1v",
      static_cast<void (*)(xt::jltensor<double, 1>, xt::jltensor<double, 1>,
                           xt::jltensor<double, 1>)>(&maxwellian_1f1v));
  mod.method(
      "test",
      static_cast<xt::jltensor<double, 1> (*)(xt::jltensor<double, 1>)>(&test));
  mod.method(
      "test1",
      static_cast<void (*)(xt::jltensor<double, 1>, xt::jltensor<double, 1>)>(&test1));
  mod.method("test2", &test2);
}