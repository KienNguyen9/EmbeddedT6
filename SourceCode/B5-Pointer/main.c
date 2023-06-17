#include <stdio.h>
void tong(int a, int b) {
    printf("Tong %d va %d = %d\n", a, b, a + b);
}
void hieu(int a, int b) {
    printf("Hieu %d va %d = %d\n", a, b, a - b);
}
void tich(int a, int b) {
    printf("Tich %d va %d = %d\n", a, b, a*b);
}
void thuong(int a, int b) {
    printf("Thuong %d va %d = %f\n", a, b, (float)a/b);
}
void ToanHoc(void (*ptr)(int, int), int a, int b) {
    printf("Chuong trinh tinh toan\n");
    ptr(a, b);
}
int main(int argc, char const *argv[])
{
    double d = 10.3;
    char string[] = "Hello";
    char *ptr = string;
    void *array[] = {&ToanHoc, &d, string};
    printf("Gia tri: %f\n", *(double*)(array[1]));
    // vì mảng kí tự trong C đã được ánh xạ trực tiếp vào địa chỉ của bộ nhớ của phần tử đầu tiên nên không cần * ở printf
    printf("Chuoi: %s\n", (char*)(array[2])); 
    ((void (*)(void (int, int),int, int))array[0])(&tong, 3, 2);
    ((void (*)(void (int, int),int, int))array[0])(&hieu, 3, 2);
    ((void (*)(void (int, int),int, int))array[0])(&tich, 3, 2);
    ((void (*)(void (int, int),int, int))array[0])(&thuong, 3, 2);
    return 0;
}

//con trỏ void gán được địa chỉ của tất cả kiểu dữ liệu nhưng phải ép kiểu trước khi đọc giá trị *(int *)ptr

// nếu khai báo con trỏ mà chưa sử dụng thì khai báo no = NULL, có giá trị và địa chỉ = 0

// con trỏ hàm void (*ptr)(int, int)

// pointer to pointer

//bt: ép toán học và string
