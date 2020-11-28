#include <stdio.h>
#include "libkit.h"

void hello() {
    printf("Hello, World! \n");
}

void conserve_prim_1d(double *prim, double *w, double gamma) {
    prim[0] = w[0];
    prim[1] = w[1] / w[0];
    prim[2] = 0.5 * w[0] / (gamma - 1.0) / (w[2] - 0.5 * w[1] * w[1] / w[0]);
}