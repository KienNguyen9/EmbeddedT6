// This file is "defined in another file" use for extern example

#include<stdio.h>
// void display(){
//     printf("this is a test\n");
// }
static int count = 10;

void display() {
    count;
    printf("count = %d\n", count);
}