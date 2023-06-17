// trình biên dịch compiler (.c >>> hex)

// main.c > main.i do qua quá trình tiền xử lý (pre-prosessed)
//gcc -E main.c -o main.i

// main.i thành main.s gọi là assembly code (compiler)
// gcc main.i -S -o main.s

// tiếp, thành object files(main.o) + thư viện (assembler)
//gcc -C main.s -o main.o

// tiếp là quá tình linker để tạo thành main.exe (executable)

#include <stdio.h>
#include "test.c"

#define MAX 10

void display() {
    printf("hello\n");
}

int main(int argc, char const *argv[])
{
    
    display();
    printf("Max: %d\n", MAX);
    test();
    return 0;
}
