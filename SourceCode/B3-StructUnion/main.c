#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef union {
    uint8_t var1; // 1 byte
    uint32_t var2; // 4 byte
    uint64_t var3; // 8 byte
}typeDataUnion;

typedef struct {
    uint8_t var1; // 1 byte 
    uint32_t var2; // 4 byte
    uint64_t var3; // 8 byte
}typeDataStruct;


typedef union {
    struct {
        uint8_t Id[2];
        uint8_t Data[3];
        uint8_t Cs[1];
    }data;
    uint8_t array[6];
}DataFrame;
int main() {
    DataFrame dataFrame;
    dataFrame.data.Id[0] = 0x01;
    dataFrame.data.Id[1] = 0x02;
    
    dataFrame.data.Data[0] = 0xC1;
    dataFrame.data.Data[1] = 0xC2;
    dataFrame.data.Data[2] = 0xC3;

    dataFrame.data.Cs[0] = 0xC8;
    printf("Compare size of Struct and Union\n");
    printf("Size of Union: %lu\n", sizeof(typeDataUnion)); // result: 8
    printf("Size of Struct: %lu\n", sizeof(typeDataStruct)); // result: 24
    return 0;
}
