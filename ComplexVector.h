#pragma once
#include "vector.h"


typedef struct Complex{
    void *Re;
    void *Im;
}Complex;

void *Sum_Complex(Complex *vector1, Complex *vector2);
void *Subtract_Complex(Complex *vector1, Complex *vector2);
void *Multiply_Complex(Complex *vector1, Complex *vector2);
void print_complex(Complex *vector);
void *input_complex();

Vector *Make_Complex_Vector();
