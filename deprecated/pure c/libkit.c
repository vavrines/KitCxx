#include "libkit.h"
#include <math.h>
#include <stdio.h>

#define PI acos(-1.0)

void hello() { printf("Hello, World! \n"); }

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

void test(double a[][2]) { a[0][1] = 79.0; }