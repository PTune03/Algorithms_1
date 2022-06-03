#include "IntVector.h"
#include <stdio.h>
#include <stdlib.h>

Vector *Make_Int_Vector()
{
    int zero = 0;
    int one = 1;
    RingInfo *ringInfo = create(sizeof(int), &zero, &one, subtract_int, sum_int, multiply_int, input_int, print_int);
    Vector *vector = Make_Vector(ringInfo);
    return vector;
}

void *input_int()
{
    int *res=malloc(sizeof (int));
    int k;
    int a;
    k=scanf("%d",&a);
//    while (k<1){
//        printf("Wrong input: ");
//        char c=getchar();
//        k=scanf("%d",&a);
//    }
    if (k<1)
        return (void *) -1;
    else {
        *res = a;
        return (void *) res;
    }
}

void print_int(void *value)
{
    printf("%d ", *(int *) value);
}

void *multiply_int(void *a, void *b)
{
    int multiplier_a = *(int *) a;
    int multiplier_b = *(int *) b;
    int *result = calloc(1, sizeof(int));
    *result = multiplier_a * multiplier_b;

    return (void *) result;
}

void *sum_int(void *a, void *b)
{
    int item_a = *(int *) a;
    int item_b = *(int *) b;
    int *result = calloc(1, sizeof(int));
    *result = item_a + item_b;

    return (void *) result;
}

void *subtract_int(void *a, void *b)
{
    int int_a = *(int *) a;
    int int_b = *(int *) b;
    int *result = calloc(1, sizeof(int));
    *result = int_a - int_b;

    return (void *) result;
}