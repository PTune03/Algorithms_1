#include "vector.h"
#include <stdio.h>

Vector *zero = NULL;
Vector *x1 = NULL;
Vector *y1 = NULL;
Vector *z1 = NULL;

Vector *Make_zero(RingInfo *ringInfo)
{
    if (!zero)
    {
        zero = (Vector *) calloc (1, sizeof(Vector));
        zero->ringInfo = ringInfo;
        Set_x(zero, ringInfo->zero);
        Set_y(zero, ringInfo->zero);
        Set_z(zero, ringInfo->zero);
    }

    return zero;
}

Vector *X1(RingInfo *ringInfo)
{
    if (!x1)
    {
        x1=(Vector *) calloc(1,sizeof(Vector));
        x1->ringInfo=ringInfo;
        Set_x(x1,ringInfo->one);
        Set_y(x1,ringInfo->zero);
        Set_z(x1,ringInfo->zero);
    }
    return x1;
}
Vector *Y1(RingInfo *ringInfo)
{
    if (!y1)
    {
        y1=(Vector *) calloc(1,sizeof(Vector));
        y1->ringInfo=ringInfo;
        Set_x(y1,ringInfo->zero);
        Set_y(y1,ringInfo->one);
        Set_z(y1,ringInfo->zero);
    }
    return y1;
}

Vector *Z1(RingInfo *ringInfo)
{
    if (!z1)
    {
        z1=(Vector *) calloc(1,sizeof(Vector));
        z1->ringInfo=ringInfo;
        Set_x(z1,ringInfo->zero);
        Set_y(z1,ringInfo->zero);
        Set_z(z1,ringInfo->one);
    }
    return z1;
}

Vector *Make_Vector(RingInfo *ringInfo)
{
    Vector *vector = (Vector *) calloc(1, sizeof(Vector));
    vector->ringInfo = ringInfo;
    void *x = ringInfo->input();
    void *y = ringInfo->input();
    void *z = ringInfo->input();
    Set_x(vector, x);
    Set_y(vector, y);
    Set_z(vector, z);
    return vector;
}

void *Get_x(Vector *vector)
{
    if (vector)
        return vector->x;
    return NULL;
}

void *Get_y(Vector *vector)
{
    if (vector)
        return vector->y;
    return NULL;
}

void *Get_z(Vector *vector)
{
    if (vector)
        return vector->z;
    return NULL;
}

void Set_x(Vector *vector, void *x)
{
    if (vector)
    {
        vector->x = malloc(sizeof(int));
        vector->x = x;
    }
}

void Set_y(Vector *vector, void *y)
{
    if (vector)
    {
        vector->y = malloc(sizeof(int));
        vector->y = y;
    }
}

void Set_z(Vector *vector, void *z)
{
    if (vector)
    {
        vector->z = malloc(sizeof(int));
        vector->z = z;
    }
}

Vector *Subtract(Vector *v1, Vector *v2)
{
    if(Equals_of_Ring(v1->ringInfo, v2->ringInfo))
    {
//        printf("Error");
        return NULL;
    }
    Vector *result = (Vector *) calloc(1, sizeof(Vector));
    result->ringInfo = v1->ringInfo;
    Set_x(result, v1->ringInfo->subtract(Get_x(v1), Get_x(v2)));
    Set_y(result, v1->ringInfo->subtract(Get_y(v1), Get_y(v2)));
    Set_z(result, v1->ringInfo->subtract(Get_z(v1), Get_z(v2)));
    return result;
}

void print_vector(Vector *v)
{
    printf("x = ");
    v->ringInfo->print(Get_x(v));
    printf("y = ");
    v->ringInfo->print(Get_y(v));
    printf("z = ");
    v->ringInfo->print(Get_z(v));
    printf("\n");
}

void print_vector_product(Vector *v, void *i, void *j, void *k)
{
    printf("The vector product is:");
    v->ringInfo->print(i);
    printf("*i+");
    v->ringInfo->print(j);
    printf("*j+");
    v->ringInfo->print(k);
    printf("*k");
}

Vector *Sum(Vector *v1, Vector *v2)
{
    if (Equals_of_Ring(v1->ringInfo, v2->ringInfo))
    {
        return NULL;
    }
    Vector *result = (Vector *) calloc(1, sizeof(Vector));
    result->ringInfo = v1->ringInfo;
    Set_x(result, v1->ringInfo->sum(Get_x(v1), Get_x(v2)));
    Set_y(result, v1->ringInfo->sum(Get_y(v1), Get_y(v2)));
    Set_z(result, v1->ringInfo->sum(Get_z(v1), Get_z(v2)));

    return result;
}

void *Multiply_vectors(Vector *v1, Vector *v2)
{
    if (Equals_of_Ring(v1->ringInfo, v2->ringInfo))
    {
        return NULL;
    }
    void *result = malloc(sizeof(int));
    result = v1->ringInfo->zero;
    result = v1->ringInfo->sum(v1->ringInfo->multiply(Get_y(v1), Get_y(v2)), v1->ringInfo->multiply(Get_x(v1), Get_x(v2)));
    result = v1->ringInfo->sum(result, v1->ringInfo->multiply(Get_z(v1), Get_z(v2)));
    return result;
}

Vector *Multiply_on_scalar(Vector *v1, void *scalar)
{
    Vector *result = (Vector *) calloc(1, sizeof(Vector));
    result->ringInfo = v1->ringInfo;
//    void *scalar = malloc(v1->ringInfo->size);
//    printf("Input scalar: ");
    //scalar = v1->ringInfo->input();
    Set_x(result, v1->ringInfo->multiply(Get_x(v1), scalar));
    Set_y(result, v1->ringInfo->multiply(Get_y(v1), scalar));
    Set_z(result, v1->ringInfo->multiply(Get_z(v1), scalar));
    return result;
}

void Vector_Product(Vector *v1, Vector *v2)
{
    if (Equals_of_Ring(v1->ringInfo, v2->ringInfo))
    {
        printf("Error");
    }
    void *i = malloc(v1->ringInfo->size);
    void *j = malloc(v1->ringInfo->size);
    void *k = malloc(v1->ringInfo->size);
    i = v1->ringInfo->subtract(v1->ringInfo->multiply(Get_y(v1), Get_z(v2)), v1->ringInfo->multiply(Get_z(v1), Get_y(v2)));
    j=v1->ringInfo->subtract(v1->ringInfo->multiply(Get_x(v1), Get_z(v2)),v1->ringInfo->multiply(Get_z(v1), Get_x(v2)));
    k=v1->ringInfo->subtract(v1->ringInfo->multiply(Get_x(v1), Get_y(v2)),v1->ringInfo->multiply(Get_x(v2), Get_y(v1)));
    print_vector_product(v1,i,j,k);
}


















