#include "DoubleVector.h"
#include <stdio.h>
#include <stdlib.h>


Vector *Make_Double_Vector()
{
    double zero = 0.0f;
    double one = 1.0f;
    RingInfo *ringInfo = create (sizeof(double), &zero, &one, Subtract_Double, Sum_Double, Multiply_Double, input_double, print_double);
    Vector *vector = Make_Vector(ringInfo);
    return vector;
}
void *input_double()
{
    double *result = malloc (sizeof(double));
    int k;
    double a;
    k = scanf("%lf", &a);
    if (k<1)
        return (void *) -1;
    else {

        *result = a;

        return (void *) result;
    }
}

void print_double(void *d)
{
    printf("%lf", *(double *) d);
}

void *Sum_Double(void *a, void  *b)
{
    double double_a = *(double *)a;
    double double_b = *(double *)b;
    double *result = calloc (1, sizeof(double));
    *result = double_a + double_b;

    return (void *) result;
}

void *Subtract_Double(void *a, void *b)
{
    double double_a = *(double *)a;
    double double_b = *(double *)b;
    double *result = calloc (1, sizeof(double));
    *result = double_a - double_b;

    return (void *) result;
}

void *Multiply_Double(void *a, void *b)
{
    double double_a = *(double *)a;
    double double_b = *(double *)b;
    double *result = calloc (1, sizeof(double));
    *result = double_a * double_b;

    return (void *) result;
}