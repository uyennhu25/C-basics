#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize);

int main () {
    int arr[] = {2,3,5,1,3};
    int* candies = arr;
    int* returnSize;
    kidsWithCandies(candies, 5, 3, returnSize);
    for (int i = 0; i < 5; i++) {
        printf("%d", returnSize[i]);
    }
    
}
int* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    int max = 0;
    for (int i = 0; i < candiesSize; i++) {
        if (candies[i]>max) {
            max = candies[i];
        }
    }
    returnSize = (int*)malloc(candiesSize*sizeof(int));
    for (int i = 0; i < candiesSize; i++) {
        if ((candies[i] + extraCandies) >= max) {
            returnSize[i] = 1;
        } else {
            returnSize[i] = 0;
        }
    }
    return returnSize;
}

