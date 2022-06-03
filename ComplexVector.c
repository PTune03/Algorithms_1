#include <stdlib.h>
#include <stdio.h>
#include "ComplexVector.h"


Vector *Make_Complex_Vector()
{
    double zero = 0.0000;
    double one = 1.0000;
    RingInfo *ringInfo = create(sizeof(Complex), &zero, &one, (void *(*)(void *, void *)) Subtract_Complex,
                                (void *(*)(void *, void *)) Sum_Complex, (void *(*)(void *, void *)) Multiply_Complex, input_complex,
                                (void (*)(void *)) print_complex);
    Vector *vector = Make_Vector(ringInfo);

    return vector;
}

void *input_complex()
{
    Complex *complex = calloc (2, sizeof(Complex));
    complex->Im = calloc(1,sizeof(double ));
    complex->Re = calloc(1, sizeof(double));
    int k;
    double *a = malloc(sizeof (double));
    double *b = malloc(sizeof (double));
    double a1, b1;
    printf("Input real part: ");
    k = scanf("%lf", &a1);
    if (k < 1)
        return (void *) -1;
    printf("Input imaginary part: ");
    k = scanf("%lf", &b1);
    if (k < 1)
        return (void *) -1;

    *a = a1;
    *b = b1;
    complex->Re = a;
    complex->Im = b;

    return (void *) complex;
}

void *Sum_Complex(Complex *vector1, Complex *vector2)
{
    Complex *result = calloc (1, sizeof(Complex));
    result->Im = calloc(1,sizeof(double));
    result->Re = calloc (1, sizeof(double));
    *(double *) result->Re = *(double *) vector1->Re + *(double *) vector2->Re;
    *(double *) result->Im = *(double *) vector1->Im + *(double *) vector2->Im;

    return (void *) result;
}

void *Subtract_Complex(Complex *vector1, Complex *vector2)
{
    Complex *result = calloc (1, sizeof(Complex));
    result->Im = calloc(1,sizeof(double));
    result->Re = calloc (1, sizeof(double));
    *(double *) result->Re = *(double *) vector1->Re - *(double *) vector2->Re;
    *(double *) result->Im = *(double *) vector1->Im - *(double *) vector2->Im;

    return (void *) result;
}

void *Multiply_Complex(Complex *vector1, Complex *vector2)
{
    Complex *result = calloc (1, sizeof(Complex));
    result->Im = calloc(1,sizeof(double));
    result->Re = calloc (1, sizeof(double));
    *(double *) result->Re = ((*(double *) vector1->Re) * (*(double *) vector2->Re)) - ((*(double *) vector1->Im) * (*(double *) vector2->Im));
    *(double *) result->Im=(((*(double *) vector1->Re) * (*(double *) vector2->Im)) + (((*(double *) vector1->Im) * (*(double *) vector2->Re))));

    return (void *) result;
}

void print_complex(Complex *vector)
{
    printf("%lf + %lf * i  ", *(double *) vector->Re, *(double *) vector->Im);
}


