#include "array_sum.h"

long long arraySumRecursion(int *arr, int size) {
    return !size || !arr ? 0 : arr[size - 1] + arraySumRecursion(arr, size - 1);
}