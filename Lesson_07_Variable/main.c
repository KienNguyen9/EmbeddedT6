/*
* File: main.c
* Author: Kien Nguyen
* Date: 19/06/2023
* Description: This is a sample file for variables
*/
#include <stdio.h> // Standard Input/Output Library
//1. Static variable
/*
int main(){
void count() {
     static int temp = 0;
     printf("temp = %d\n", temp);
     temp++;
 }
 int main(int argc, char const *argv[])
 {
    count();
    count();
    count();
    return 0;
}
*/



// 2. The Extern keyword 
/*
extern void display();
int main() {
    display();
    return 0;
}
*/


// 3. The volatile keyword

/*
int main(int argc, char const *argv[])
{
    while(1) {
        volatile int a = 30; // báo Compiler không được tối ưu biến này
        A();
        B();
        C();
    }
    return 0;
}
*/

