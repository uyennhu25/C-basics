#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize);

int main () {
    int arr[] = {2,3,5,1,3};
    int* candies = arr;
    int* returnSize;
    /*kidsWithCandies(candies, 5, 3, returnSize);
    for (int i = 0; i < 5; i++) {
        printf("%d", returnSize[i]);
    }*/
    int* nums = {1,2,3,4}
    int* answer = (int*)malloc(numsSize*sizeof(int));
    int* left = (int*)malloc(numsSize*sizeof(int));
    int* right = (int*)malloc(numsSize*sizeof(int));
    left[0] = 1;
    right[numsSize-1] = 1;
    for(int i = 1; i < numsSize; i++) {
        left[i] = left[i-1] * nums[i-1];
    }
    for(int i = 2; i < numsSize; i++) {
        right[numsSize-i] = right[numsSize-i+1] *  nums[numsSize-i+1];
    }
    for (int i = 0; i < numsSize; i++) {
        answer[0] = left[0] * right[0];
    }
    *returnSize = numsSize;
    return right;
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


int maximumGain(char* s, int x, int y) {
    int res = 0;
    char top[3], bot[3];
    int top_score, bot_score;

    if (y > x) {
        strcpy(top, "ba");
        top_score = y;
        strcpy(bot, "ab");
        bot_score = x;
    } else {
        strcpy(top, "ab");
        top_score = x;
        strcpy(bot, "ba");
        bot_score = y;
    }

    char stack[strlen(s) + 1];
    int stack_len = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];  // Changed 'char' to 'ch'
        if (ch == top[1] && stack_len > 0 && stack[stack_len - 1] == top[0]) {
            res += top_score;
            stack_len--;
        } else {
            stack[stack_len++] = ch;
        }
    }

    char new_stack[strlen(s) + 1];
    int new_stack_len = 0;
    for (int i = 0; i < stack_len; i++) {
        char ch = stack[i];  // Changed 'char' to 'ch'
        if (ch == bot[1] && new_stack_len > 0 && new_stack[new_stack_len - 1] == bot[0]) {
            res += bot_score;
            new_stack_len--;
        } else {
            new_stack[new_stack_len++] = ch;
        }
    }
    
    return res;
}



