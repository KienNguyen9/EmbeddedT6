/*
* File: main.c
* Author: Kien Nguyen
* Date: 19/06/2023
* Description: Compare strings in C use array 
*/
#include <stdio.h> // Standard Input/Output Library
#include <stdbool.h> // Standard Boolean Library

//this typedef for an enumeration called Compare and this enumeration has three values: SMALLER, BIGGER, and EQUAL
typedef enum {
    SMALLER,
    BIGGER,
    EQUAL
}Compare;

//
/*
* Function: isEqual
* Description: This function takes two arrays of characters as input and returns a value of type Compare
* Input:
*   arr1[] - an array
*   arr2[] - an array
* Output:
*   returns a value of type Compare: SMALLER, BIGGER, and EQUAL
*/
Compare isEqual(const char arr1[], const char arr2[]) {
    int i = 0, result;
    while (arr1[i] == arr2[i])
    {
        if(arr1[i] == '\0' || arr2[i] == '\0') {
            break;
        }
        i++;
    }
    result = arr1[i] - arr2[i];
    if (result < 0)
        return 0;
    else if(result > 0) 
        return 1;
    else 
        return 2;
}

int main(int argc, char const *argv[])
{
    char arr1[] = "aaaaa";
    char arr2[] = "aaaa";
    int result;
    result = isEqual(arr1, arr2);
    if(result == 0){
        printf("Smaller");
    } else if(result == 1){
        printf("Bigger");
    } else {
        printf("Equal");
    }
    return 0;
}