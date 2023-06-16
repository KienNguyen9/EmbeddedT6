# EmbeddedT6
Learn Embedded 6/2023
# BUỔI 4: COMPILER - TRÌNH BIÊN DỊCH
Compiler hay còn gọi là trình biên dịch có thể được hiểu là công việc dịch chuỗi câu lệnh được viết từ một ngôn ngữ lập trình thành chương trình tương đương dưới dạng ngôn ngữ máy tính, thường là ngôn ngữ ở cấp thấp hơn, ngôn ngữ máy. Đơn giản dễ hiểu thì có thể tạm nói là nhờ Complier này mà file .c chúng ta viết mới được dịch thành file .hex .bin để nạp được xuống một MCU bất kỳ.
Quá trình biên dịch 
![image](https://github.com/KienNguyen9/EmbeddedT6/assets/136218538/0268c4fb-9806-424c-a8ac-3ae0afdc69db)
![image](https://github.com/KienNguyen9/EmbeddedT6/assets/136218538/562d9e22-66ef-4010-8893-c074d149f7e2)
![image](https://github.com/KienNguyen9/EmbeddedT6/assets/136218538/010b0838-7917-4e5b-8f1a-b11012bfc3d7)
# 1. Pre-processing (Tiền xử lí)
Bộ tiền xử lý C không phải là một phần của trình biên dịch, mà là một bước riêng biệt trong quá trình biên dịch. Nói một cách đơn giản, Bộ tiền xử lý C chỉ là một công cụ thay thế văn bản và nó hướng dẫn trình biên dịch thực hiện tiền xử lý cần thiết trước khi biên dịch thực tế. Các lệnh tiền xử lí bắt đầu bằng kí tự "#" 
Ví dụ: 
- " #define" :Thay thế các macro
- "#include" :Chèn thêm file khác như các thư viên

Dùng GCC bằng lệnh sau để có file tiền xử lí: gcc -E main.o -o main.i (chuyển từ file .c sang file .i)

# 2. Compiling (Biên dịch)
Chuyển chúng sang dạng mã Assembly là một ngôn ngữ bậc thấp (hợp ngữ) gần với tập lệnh của bộ vi xử lý.
Dùng GCC bằng lệnh sau để chuyển từ file .i sang file .s: gcc main.i -S -o main.s
# 3. Assembling (Hợp ngữ)
Dich chương trình => Sang mã máy 0 và 1
Một tệp mã máy (.obj) sinh ra trong hệ thống sau đó
# 4. Linking (Liên kết)
Trong giai đoạn này mã máy của một chương trình dịch từ nhiều nguồn (file .c hoặc file thư viện .lib) được liên kết lại với nhau để tạo thành chương trình đích duy nhất Mã máy của các hàm thư viện gọi trong chương trình cũng được đưa vào chương trình cuối trong giai đoạn này. Chính vì vậy mà các lỗi liên quan đến việc gọi hàm hay sử dụng biến tổng thể mà không tồn tại sẽ bị phát hiện. Kể cả lỗi viết chương trình chính không có hàm main() cũng được phát hiện trong liên kết.

# BUỔI 5: POINTER - CON TRỎ
POINTER: Là một biến đặc biệt, dùng để lưu địa chỉ của biến chứ không phải giá trị, được lưu trên ram. Kích thước của biến pointer phụ thuộc vào vi xử lý.

# Normal pointer 
Là con trỏ dùng để lưu địa chỉ của biến đó, kiểu dữ liệu của con biến như thế nào thì kiểu con trỏ cũng vậy.

Ví dụ:

int a = 10 // giả sử có địa chỉ là 0x01
int *ptr = &a = 0x01 // * ptr ở đây là biến con trỏ ptr, do quy tắc đặt tên biến pointer phải có dấu * ở trước.
printf("Dia chi: %p,ptr); // Dia chi 0x01.
printf("Gia tri: %d, *ptr);// * ptr là giá trị của con trỏ ptr trỏ đến.

# Void Pointer
Con trỏ void có thể trỏ đến các vùng nhớ có các kiểu dữ liệu khác nhau.
Con trỏ void không xác định được kiểu dữ liệu của vùng nhớ mà nó trỏ tới, vì vậy không thể truy cập xuất trực tiếp nội dung thông qua toán tử derefernce () được. Mà con trỏ kiểu void cần phải được ép kiểu một cách rõ ràng sang con trỏ có kiểu dữ liệu khác trước khi sử dụng toán tử derefernce ().
#include <stdio.h>

void tong(int a,int b){
   printf("tong %d va %d = %d\n", a, b, a + b);
}

int main()
{

   int i = 3;
   double d =12.4;
   char c ='B';

   // con trỏ void có thể trỏ đến bất kỳ địa chỉ nào 
   void *ptr = &i;

   // để lấy giá trị từ con trỏ void ta cần ép kiểu nó
   printf("i = %d\n",*(int *)ptr);

   ptr = &d;
   printf("d = %f\n",*(double *)ptr);

   ptr = &c;
   printf("c = %c\n",*(char *)ptr);

   ptr = &tong;
   ((void (*)(int, int))ptr)(9,1);
   return 0;
}
