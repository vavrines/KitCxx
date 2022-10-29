/*
Workaround using extern "C"
Note that template or oveload is not supported
*/

#ifndef LIBRARY_LIBKIT_H
#define LIBRARY_LIBKIT_H

extern "C"
{
void hello();
void conserve_prim_1d(double *prim, double *w, double gamma);
void maxwell_1f1v(double *H, double *prim, double *uspace, int nu);
}

#endif // LIBRARY_LIBKIT_H