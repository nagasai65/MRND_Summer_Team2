#include "array_permutations.h"
#include <stdlib.h>
#include <map>

int factorial(int n) {
    int result = n;

    while(n--) result *= n;

    return result;
}

void _generateAllPossiblePermutations(int **resultPtr, std::map<int, int> chosenElements, 
                        int numberOfElementsChosen, int *arr, int size) {
    if(numberOfElementsChosen == size) return;
    int elementToChoose;

    for(elementToChoose = 0; elementToChoose < size; ++elementToChoose) {
        if(chosenElements.find(elementToChoose) == chosenElements.end()) {
            **resultPtr = arr[elementToChoose];
            chosenElements.insert({elementToChoose, 1});
            (*resultPtr)++;
            _generateAllPossiblePermutations(resultPtr, chosenElements, numberOfElementsChosen + 1, arr, size);
            chosenElements.erase(elementToChoose);
        }
    }
}

int **generateAllPossiblePermutationsWithoutRepetitions(int *arr, int size) {
    int **result = (int **)malloc(sizeof(int) * factorial(size)), start;
    std::map<int, int> chosen;

    for(start = 0; start < size; ++start) {
        result[start] = new int[size];
        _generateAllPossiblePermutations(result + start, chosen, 0, arr, size);
    }

    return result;
}