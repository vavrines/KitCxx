#ifndef TYPEDEFS_JL
#define TYPEDEFS_JL
typedef xt::jltensor<double, 1> JVector;
typedef xt::jltensor<double, 2> JMatrix;
#endif // typedef

std::string greet() { return "hello, world"; }
std::string greet(std::string &msg) { return msg; }

void conserve_prim_1d(double *prim, double *w, double gamma) {
  prim[0] = w[0];
  prim[1] = w[1] / w[0];
  prim[2] = 0.5 * w[0] / (gamma - 1.0) / (w[2] - 0.5 * w[1] * w[1] / w[0]);
}
void maxwell_1f1v(double *H, double *prim, double *uspace, int nu) {
  for (int i = 0; i < nu; i++) {
    H[i] = prim[0] * pow(prim[2] / PI, 0.5) *
           exp(-prim[2] * pow(uspace[i] - prim[1], 2));
  }
}

class Solution {
public:
  std::string msg;
  double w;
  double prim;
  // methods
  double get(void);
  void set(std::string _msg, double _w, double _prim);
  Solution();                                                     // constructor
  ~Solution() { std::cout << "Solution destroyed" << std::endl; } // destructor
};
Solution::Solution(void) { std::cout << "Solution created" << std::endl; }
double Solution::get(void) { return w * prim; }
void Solution::set(std::string _msg, double _w, double _prim) {
  msg = _msg;
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

template <typename T> T inc(T x) { return x + static_cast<T>(1); }

JLCXX_MODULE define_julia_module(jlcxx::Module &mod) {
  // for a single dispatch: `mod.method("greet", &greet)`
  mod.method("greet", static_cast<std::string (*)()>(&greet));
  mod.method("greet", static_cast<std::string (*)(std::string &)>(&greet));
  mod.add_type<World>("World")
      .constructor<const std::string &>()
      .method("set", &World::set)
      .method("greet", &World::greet);
  mod.add_type<Solution>("Solution")
      .constructor<>()
      .method("set", &Solution::set)
      .method("get", &Solution::get);
  mod.method("inc", static_cast<double (*)(double)>(&inc));
  mod.method("inc", static_cast<float (*)(float)>(&inc));

}