#pragma once
#include "ringinfo.h"

typedef struct Vector{
    void *x;
    void *y;
    void *z;
    RingInfo *ringInfo;
}Vector;

void Set_x(Vector *vector, void *x);
void Set_y(Vector *vector, void *y);
void Set_z(Vector *vector, void *z);

Vector *Make_Vector(RingInfo *ringInfo);

void *Get_x(Vector *vector);
void *Get_y(Vector *vector);
void *Get_z(Vector *vector);

Vector *Subtract(Vector *v1, Vector *v2);
Vector *Sum(Vector *v1, Vector *v2);
void *Multiply_vectors(Vector *v1, Vector *v2);
Vector *Multiply_on_scalar(Vector *v1, void *scalar);
void Vector_Product(Vector *v1, Vector *v2);

void print_vector(Vector *v);
void print_vector_product(Vector *v, void *i, void *j, void *k);

Vector *Make_zero(RingInfo *ringInfo);
Vector *X1(RingInfo *ringInfo);
Vector *Y1(RingInfo *ringInfo);
Vector *Z1(RingInfo *ringInfo);