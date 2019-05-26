#include <stdio.h>
#include <stdlib.h>
#include "linked_list/doubly_linked_list_merge_sort.h"
#include "recursion/array_sum.h"
#include "recursion/power.h"
#include "recursion/fibonacci.h"
#include "recursion/steps_backtracking.h"
#include "recursion/number_series.h"
#include "recursion/array_permutations.h"

void printTestCaseStatus(const char *funcName, int condition) {
    printf("%s: %s\n", funcName, condition ? "Passed" : "Failed");
}

DNode *newDLLNode(int data) {
    DNode *node = (DNode *)calloc(sizeof(DNode), 1);

    node->data = data;

    return node;
}

DNode *strToDLL(const char *str1) {
    char *str = (char *)str1;
    DNode *head = newDLLNode(*str - '0'), *prev = head;
    str++;

    while(*str) {
        head->next = newDLLNode(*str - '0');
        head = head->next;
        head->prev = prev;
        prev = head;
    }

    return head;
}

int areTwoDoublyLinkedListEqual(DNode *ll1, DNode *ll2) {
    while(ll1 && ll2) {
        if(ll1->data != ll2->data)
            return 0;
    }
    return ll1 == ll2;
}

void doublyLinkedListMergeSortTestCase1() {
    DNode *ll = strToDLL("14352");
    DNode *expectedOutput = strToDLL("12345"), *actualOutput = doublyLinkedListMergeSort(ll);

    printTestCaseStatus(__func__, areTwoDoublyLinkedListEqual(expectedOutput, actualOutput));
}

void arraySumRecursionTestCase1() {
    int arr[] = {1, 2, 3, 4, 5}, size = 5;
    long long expectedOutput = 15, actualOutput = arraySumRecursion(arr, size);

    printTestCaseStatus(__func__, actualOutput == expectedOutput);
}

void powerApproach1TestCase1() {

}

void fibonacciTestCase1() {
    unsigned int n = 5;
    unsigned long long expectedOutput = 3, actualOutput = fibonacci(n);

    printTestCaseStatus(__func__, expectedOutput == actualOutput);
}

void numberOfWaysOfClimbingStairsTestCase1() {
    unsigned int n = 4, k = 2;
    unsigned long expectedOutput = 5, actualOutput = numberOfWaysOfClimbingStairs(n, k);

    printTestCaseStatus(__func__, expectedOutput == actualOutput);
}

int areArraysEqual(int *arr1, int *arr2, int size) {
    while(size-- && (*arr1++ == *arr2++));

    return arr1 == arr2;
}

void generateNumberSeriesTestCase1() {
    int n = 3, itr;
    int expectedOutput[100], *actualOutput = generateNumberSeries(n);
    for(itr = 0; itr < 100; ++itr)
        expectedOutput[itr] = itr;

    printTestCaseStatus(__func__, areArraysEqual(expectedOutput, actualOutput, 100));
}

int areMatricesEqual(int **arr1, int **arr2, int m, int n) {
    int rowItr, columnItr;

    for(rowItr = 0; rowItr < m; ++rowItr) {
        for(columnItr = 0; columnItr < n; ++columnItr) {
            if(arr1[rowItr][columnItr] != arr2[rowItr][columnItr])
                return 0;
        }
    }

    return 1;
}

void arrayPermutationsWithoutRepetitionsTestCase1() {
    int arr[] = {1, 2, 3}, size = 3;
    int expectedOutput[6][3] = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}},
            **actualOutput = generateAllPossiblePermutationsWithoutRepetitions(arr, size);
    int **pass = (int **)malloc(sizeof(int *) * 6), i;

    for(i = 0; i < 6; ++i) {
        pass[i] = expectedOutput[i];
    }

    printTestCaseStatus(__func__, areMatricesEqual(pass, actualOutput, 6, 3));
}