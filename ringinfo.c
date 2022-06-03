#include <stdlib.h>
#include "ringinfo.h"

RingInfo *create(
        size_t size,
        void *zero,
        void *one,
        void* (*subtract)(void*,void*),
        void* (*sum)(void *,void*),
        void* (*multiply)(void *, void*),
        void *(*input)(),
        void (*print)(void *v))
        {
            RingInfo *ringInfo = calloc(1, sizeof(RingInfo));
            ringInfo->zero = zero;
            ringInfo->one = one;
            ringInfo->size = size;
            ringInfo->sum = sum;
            ringInfo->multiply = multiply;
            ringInfo->subtract = subtract;
            ringInfo->input = input;
            ringInfo->print = print;
            return ringInfo;
        }

bool Equals_of_Ring(RingInfo* ring1, RingInfo* ring2)
{
    return ring1->sum != ring2->sum;
}
