#include "fibonacci_using_matrix_exponentation.h"
#include <string.h>

void multiplyMatrices(unsigned long matrix1[2][2], unsigned long matrix2[2][2], unsigned long result[2][2]) {
   result[0][0] = matrix1[0][0] * matrix2[0][0] + matrix1[0][1] * matrix2[1][0];
   result[0][1] = matrix1[0][0] * matrix2[0][1] + matrix1[0][1] * matrix2[1][1];
   result[1][0] = matrix1[1][0] * matrix2[0][0] + matrix1[1][1] * matrix2[1][0];
   result[1][1] = matrix1[1][0] * matrix2[0][1] + matrix1[1][1] * matrix2[1][1];
}

void matrixPower(unsigned long A[2][2], unsigned long finalResult[2][2], unsigned int n) {
    if(n == 0) {
        finalResult[0][0] = finalResult[1][1] = 1;
        return;
    }   else    {
        memcpy(finalResult, A, sizeof(int) * 4);
        return;
    }
    
    unsigned long halfResult[2][2], tmp[2][2];
    matrixPower(A, halfResult, n / 2);
    multiplyMatrices(halfResult, halfResult, finalResult);
    if(n & 1) {
        memcpy(tmp, finalResult, sizeof(int) * 4);
        multiplyMatrices(tmp, A, finalResult);
    }
}

unsigned long fibonacciUsingMatrixExponentation(unsigned int n) {
    unsigned long defaultMatrix[2][2] = {{0, 1}, {1, 1}}, result[2][2] = {{1, 0}, {0, 1}};
    matrixPower(defaultMatrix, result, n);
    return result[1][1];
}