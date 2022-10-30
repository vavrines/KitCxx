#include "jlcxx/jlcxx.hpp"
#include <cmath>
#include <iostream>

#define PI acos(-1.0)

std::string greet() { return "hello, world"; }

class Solution {
public:
  double w;
  double prim;
  // methods
  double get(void);
  void set(double _w, double _prim);
  Solution(); // constructor
  ~Solution() { std::cout << "Solution destroyed" << std::endl; }
};
Solution::Solution(void) { std::cout << "Solution created" << std::endl; }
double Solution::get(void) { return w * prim; }
void Solution::set(double _w, double _prim) {
  prim = _prim;
  w = _w;
}

struct World {
  World(const std::string &message = "default hello") : msg(message) {}
  void set(const std::string &msg) { this->msg = msg; }
  std::string greet() { return msg; }
  std::string msg;
  ~World() { std::cout << "World destroyed" << std::endl; }
};

void conserve_prim_1d(double *prim, double *w, double gamma) {
  prim[0] = w[0];
  prim[1] = w[1] / w[0];
  prim[2] = 0.5 * w[0] / (gamma - 1.0) / (w[2] - 0.5 * w[1] * w[1] / w[0]);
}

void maxwell_1f1v(double *H, double *prim, double *uspace, int nu) {
  for (int i = 0; i < nu; i++) {
    H[i] = prim[0] * pow(prim[2] / PI, 0.5) *
           exp(-prim[2] * pow(uspace[i] - prim[2], 2));
  }
}

JLCXX_MODULE define_julia_module(jlcxx::Module &mod) {
  mod.method("greet", &greet);
  mod.add_type<World>("World")
      .constructor<const std::string &>()
      .method("set", &World::set)
      .method("greet", &World::greet);
  mod.method("conserve_prim_1d", &conserve_prim_1d);
  mod.add_type<Solution>("Solution")
      .constructor<>()
      .method("set", &Solution::set)
      .method("get", &Solution::get);
}