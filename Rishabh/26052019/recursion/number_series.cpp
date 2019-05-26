#include "number_series.h"
#include <math.h>

void _generateNumberSeries(int **arr, int n, int val) {
    if(n == -1 && val != 0) {
        **arr = val;
        (*arr)++;
        return;
    }

    int i;
    for(i = (n == 0) ? 0 : 1; i < 10; ++i) {
        _generateNumberSeries(arr, n - 1, val + (i * pow(10, n)));
    }
}

int *generateNumberSeries(int n) {
    int *result = (int *)malloc(sizeof(int) * pow(10, n)), *ptr = result + 1, i;
    *result = 0;
    for(i = 0; i < n; ++i)
        _generateNumberSeries(&ptr, i, 0);

    return result;
}