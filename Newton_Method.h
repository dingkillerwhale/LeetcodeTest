#include <stdio.h>
#include <math.h>

void Newton(double (*f)(double), double (*df)(double), double x0);
double f(double x);
double df(double x);