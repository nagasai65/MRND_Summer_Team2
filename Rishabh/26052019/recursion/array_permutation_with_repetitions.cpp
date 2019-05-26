#include "array_permutation_with_repetitions.h"
#include "array_permutations.h"
#include <map>

void _generateAllPossiblePermutationsWithoutRepetitions(int **resultPtr, std::map<int, int> chosenElements, 
                        int numberOfElementsChosen, int *arr, int size) {
    if(numberOfElementsChosen == size) return;
    int elementToChoose, chosenValues[10] = { 0 };

    for(elementToChoose = 0; elementToChoose < size; ++elementToChoose) {
        if(chosenElements.find(elementToChoose) == chosenElements.end() && !chosenElements[arr[elementToChoose]]) {
            **resultPtr = arr[elementToChoose];
            chosenElements.insert({elementToChoose, 1});
            (*resultPtr)++;
            _generateAllPossiblePermutationsWithoutRepetitions(resultPtr, chosenElements, numberOfElementsChosen + 1, arr, size);
            chosenElements.erase(elementToChoose);
            chosenElements[arr[elementToChoose]] = 1;
        }
    }
}

int **generateAllPossiblePermutationsWithRepetitions(int *arr, int size) {
    std::map<int, int> chosen;
    int **result = (int **)malloc(sizeof(int) * factorial(size)), start;
    
    for(start = 0; start < size; ++start) {
        result[start] = new int[size];
        _generateAllPossiblePermutationsWithoutRepetitions(result + start, chosen, 0, arr, size);
    }

    return result;
}