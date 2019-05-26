#include "string_search_in_matrix.h"
#include <string.h>

int searchDown(char *str, char **matrix, int rowItr, int columnItr, int maxRow, int maxColumn) {
    if(!*str) return 1;
    return  rowItr < maxRow 
            && columnItr < maxColumn 
            && *str == matrix[rowItr][columnItr] 
            && searchDown(str + 1, matrix, rowItr + 1, columnItr, maxRow, maxColumn);
}

int searchRight(char *str, char **matrix, int rowItr, int columnItr, int maxRow, int maxColumn) {
    if(!*str) return 1;
    return rowItr < maxRow 
            && columnItr < maxColumn 
            && *str == matrix[rowItr][columnItr] 
            && searchRight(str + 1, matrix, rowItr, columnItr + 1, maxRow, maxColumn);
}

int searchLeft(char *str, char **matrix, int rowItr, int columnItr, int maxRow, int maxColumn) {
    if(!*str) return 1;
    return  rowItr < maxRow  
            && columnItr >= 0
            && *str == matrix[rowItr][columnItr] 
            && searchLeft(str + 1, matrix, rowItr, columnItr - 1, maxRow, maxColumn);
}

int searchUp(char *str, char **matrix, int rowItr, int columnItr, int maxRow, int maxColumn) {
    if(!*str) return 1;
    return  rowItr >= 0
            && columnItr < maxColumn 
            && *str == matrix[rowItr][columnItr] 
            && searchUp(str + 1, matrix, rowItr - 1, columnItr, maxRow, maxColumn);
}


int searchDownRight(char *str, char **matrix, int rowItr, int columnItr, int maxRow, int maxColumn) {
    if(!*str) return 1;
    return  rowItr < maxRow 
            && columnItr < maxColumn 
            && *str == matrix[rowItr][columnItr]
            && searchDownRight(str + 1, matrix, rowItr + 1, columnItr + 1, maxRow, maxColumn);
}

int searchDownLeft(char *str, char **matrix, int rowItr, int columnItr, int maxRow, int maxColumn) {
    if(!*str) return 1;
    return  rowItr < maxRow 
            && columnItr >= 0
            && *str == matrix[rowItr][columnItr] 
            && searchDownLeft(str + 1, matrix, rowItr + 1, columnItr - 1, maxRow, maxColumn);
}

int searchUpLeft(char *str, char **matrix, int rowItr, int columnItr, int maxRow, int maxColumn) {
    if(!*str) return 1;
    return  rowItr >= 0
            && columnItr >= 0
            && *str == matrix[rowItr][columnItr] 
            && searchUpLeft(str + 1, matrix, rowItr - 1, columnItr - 1, maxRow, maxColumn);
}

int searchUpRight(char *str, char **matrix, int rowItr, int columnItr, int maxRow, int maxColumn) {
    if(!*str) return 1;
    return  rowItr >= 0
            && columnItr < maxColumn 
            && *str == matrix[rowItr][columnItr] 
            && searchUpRight(str + 1, matrix, rowItr - 1, columnItr + 1, maxRow, maxColumn);
}

int min(int a, int b) {
    return (a > b) ? b : a;
}

unsigned int numberOfSubStrings(char *str, char **table, int maxRow, int maxColumn) {
    int occurences = 0, length = strlen(str);
    int rowItr, columnItr;

    for(rowItr = 0; rowItr < maxRow; ++rowItr) {
        for(columnItr = 0; columnItr < maxColumn; ++columnItr) {
            if(table[rowItr][columnItr] == *str){
                if(length == 1) {
                    occurences += 1;
                }   else    {
                    if(maxRow - rowItr >= length - 1)
                        occurences += searchDown(str, table, rowItr, columnItr, maxRow, maxColumn);
                    if(maxColumn - columnItr >= length - 1)
                        occurences += searchRight(str, table, rowItr, columnItr, maxRow, maxColumn);
                    if(rowItr >= length - 1)
                        occurences += searchUp(str, table, rowItr, columnItr, maxRow, maxColumn);
                    if(columnItr >= length - 1)
                        occurences += searchLeft(str, table, rowItr, columnItr, maxRow, maxColumn);
                    if(min(maxColumn - columnItr, maxRow - rowItr) >= length - 1)
                        occurences += searchDownRight(str, table, rowItr, columnItr, maxRow, maxColumn);
                    if(min(maxColumn - columnItr, rowItr) >= length - 1)
                        occurences += searchUpRight(str, table, rowItr, columnItr, maxRow, maxColumn);
                    if(min(columnItr, rowItr) >= length - 1)
                        occurences += searchUpLeft(str, table, rowItr, columnItr, maxRow, maxColumn);
                    if(min(columnItr, maxRow - rowItr) >= length - 1)
                        occurences += searchDownLeft(str, table, rowItr, columnItr, maxRow, maxColumn);
                }
            }
        }
    }

    return occurences;
}