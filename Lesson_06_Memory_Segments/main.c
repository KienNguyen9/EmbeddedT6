/*
* File: main.c
* Author: Kien Nguyen
* Date: 19/06/2023
* Description: This is a sample file for Memory segments
*/
#include<stdio.h> // Standard Input/Output Library

// Text Segment example
const int i = 10;    
// Data Segment example
int x = 10; // bien toan cuc duoc luu vao ds
static int y =5; // bien static toan cuc duoc luu vao ds
void tong(){
   static int z = 19; // bien static cuc bo duoc luu vao ds 
} 

// BSS Segment example

// HEAP Segment example

// HEAP Segment example

int main(){
    // Text Segment example
    printf("i=%d",i); //Read-only

    // Data Segment example
    printf("i=%d",y);

    // BSS Segment example

    // HEAP Segment example

    // HEAP Segment example

}