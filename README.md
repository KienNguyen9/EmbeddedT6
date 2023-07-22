    # EmbeddedT6
Learn Embedded 6/2023
<details>
<summary>BUỔI 1: GIỚI THIỆU </summary>
Một chương trình gồm có:
    
- Thư viện
- Các câu lệnh 
- Hàm & macro 
    
</details>
    
<details>
<summary>BUỔI 2: MACRO & FUNCTION </summary>
Được thực hiện ở quá trình tiền xử lí
    
Ta có thể hiểu đơn giản: 

- MACRO là định nghĩa để dễ dàng gọi và sử dụng.
- FUNTION là Hàm dùng để làm một chức năng nào đó cụ thể.

Macro  | Function
------------- | -------------
Macro là một thủ tục tiền xử lý  | Function là một thủ tục thực thi tại runtime
Được định nghĩa bằng cách sử dụng tiền xử lý (#define)  | Được định nghĩa bằng cách sử dụng cú pháp function
Được sử dụng để thay thế một đoạn mã nào đó trong mã nguồn bằng một giá trị cụ thể  | Được sử dụng để thực thi một tác vụ cụ thể và trả về một giá trị
Được thực hiện trong quá trình biên dịch, trước khi chương trình được thực thi  | Được thực thi trong quá trình chạy chương trình
Không có tham số kiểu dữ liệu  | Có thể có các tham số kiểu dữ liệu khác nhau
Vì biên dịch trước trong mã nguồn nên *Macro* tối ưu về tốc độ nhưng "có thể" làm tăng kích thước chương trình | Vì được lưu cố định trong 1 vùng nhớ nên *Function* tối ưu về kích thước chương trình nếu được gọi nhiều lần nhưng "có thể" không tối ưu tốc độ xử lý

Ví dụ: Tính tổng 2 số
Macro: 
```
#define SUM(x, y) ((x) + (y))
```
Function:
```
int sum(int x, int y) {
    return x + y;
}
```
Cả hai cách trên đều có thể được sử dụng để tính tổng của hai số, tuy nhiên, sử dụng function sẽ cho phép bạn định nghĩa các loại tham số và kiểu dữ liệu khác nhau và trả về một giá trị kiểu dữ liệu cụ thể.
</details>
<details>
<summary>BUỔI 3: STRUCT UNION  </summary> 

- Struct và Union là 2 cấu trúc dữ liệu do lập trình viên định nghĩa bao gồm các biến với kiểu dữ liệu khác nhau. <br/>
- Việc định nghĩa, khai báo biến, truy cập đến các thành phần của struct và union là giống nhau. Tuy nhiên, giữa struct và union có một vài điểm khác nhau sau:

Struct  | Union
------------- | -------------
Size của struct ít nhất bằng tổng size của các thành phần của struct. Sử dụng từ “ít nhất” là vì size struct còn phụ thuộc vào alignment struct. sizeof(A) = 16 (vì sizeof của uint64_t, uint32_t, uint8_t lần lượt là 8, 4, 1 byte nên 1 + 4 là 5 byte nên phải chèn thêm 3 byte bộ nhớ đệm và cho ra lần quét tiếp là 8 byte) ``` struct { uint8_t var1; uint32_t var2; uint64_t var3; } ``` | Size của union bằng size của thành phần có size lớn nhất trong union. sizeof(A) = 8 (kích thước của thành phần lớn nhất trong union là uint64_t là 8 byte) ``` union { uint8_t var1; uint32_t var2; uint64_t var3; } ```
Tại cùng 1 thời điểm run-time, có thể truy cập vào tất cả các thành phần của struct | Tại cùng 1 thời điểm run-time, chỉ có thể truy cập 1 thành phần của union
</details>

<details>
<summary>BUỔI 4: COMPILER - TRÌNH BIÊN DỊCH</summary>      
  
Compiler hay còn gọi là trình biên dịch có thể được hiểu là công việc dịch chuỗi câu lệnh được viết từ một ngôn ngữ lập trình thành chương trình tương đương dưới dạng ngôn ngữ máy tính, thường là ngôn ngữ ở cấp thấp hơn, ngôn ngữ máy. Đơn giản dễ hiểu thì có thể tạm nói là nhờ Complier này mà file .c chúng ta viết mới được dịch thành file .hex .bin để nạp được xuống một MCU bất kỳ.
Quá trình biên dịch.

# 1. Pre-processing (Tiền xử lí)
Bộ tiền xử lý C không phải là một phần của trình biên dịch, mà là một bước riêng biệt trong quá trình biên dịch. Nói một cách đơn giản, Bộ tiền xử lý C chỉ là một công cụ thay thế văn bản và nó hướng dẫn trình biên dịch thực hiện tiền xử lý cần thiết trước khi biên dịch thực tế. Các lệnh tiền xử lí bắt đầu bằng kí tự "#" 
Ví dụ: 
- " #define" :Thay thế các macro
- "#include" :Chèn thêm file khác như các thư viên
Dùng GCC bằng lệnh sau để có file tiền xử lí: gcc -E main.o -o main.i (chuyển từ file .c sang file .i)
# 2. Compiling (Giai đoạn dịch NNBC sang ngôn ngữ Assembly)
Chuyển chúng sang dạng mã Assembly là một ngôn ngữ bậc thấp (hợp ngữ) gần với tập lệnh của bộ vi xử lý.
Quá trình này sẽ biên dịch từ code `.i` sang ngôn ngữ assembly `.s`.
Dùng lệnh `gcc -S -o filename.s filename.c` để có thể xem code sau quá tình compiler.
# 3. Assembling (Hợp ngữ)
Dich chương trình => Sang mã máy 0 và 1
Một tệp mã máy (.obj) sinh ra trong hệ thống sau đó
# 4. Linking (Liên kết)
Trong giai đoạn này mã máy của một chương trình dịch từ nhiều nguồn (file .c hoặc file thư viện .lib) được liên kết lại với nhau để tạo thành chương trình đích duy nhất Mã máy của các hàm thư viện gọi trong chương trình cũng được đưa vào chương trình cuối trong giai đoạn này. Chính vì vậy mà các lỗi liên quan đến việc gọi hàm hay sử dụng biến tổng thể mà không tồn tại sẽ bị phát hiện. Kể cả lỗi viết chương trình chính không có hàm main() cũng được phát hiện trong liên kết.
</details>


<details>
<summary>BUỔI 5: POINTER - CON TRỎ</summary>      
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
```
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
```
# Null Pointer
Con trỏ null là con trỏ có giá trị và địa chỉ bằng 0.
Khi khai báo 1 con trỏ:
Phải khai báo địa chỉ cho nó.
Nếu mà chưa sử dụng thì gán cho nó con trỏ null.
Hoặc khi khai báo con trỏ và đã sử dụng nó rồi, khi không muốn sử dụng nó nữa thì phải gán nó lại là con trỏ null.
```
    int *ptr = NULL;
```
</details>

<details>
<summary>BUỔI 6: PHÂN VÙNG NHỚ</summary>

![Phân vùng nhớ](https://raw.githubusercontent.com/nvtquyen/EmbeddedT6/main/Picture/phan%20vung%20nho.png)
 
• Text : <br/>
– Quyền truy cập chỉ Read và nó chưa lệnh để thực thi nên tránh sửa đổi instruction. <br/>
– Chứa khai báo hằng số trong chương trình (.rodata) <br/>
• Data: <br/>
– Quyền truy cập là read-write. <br/>
– Chứa biến toàn cục or biến static với giá trị khởi tạo khác không. <br/>
– Được giải phóng khi kết thúc chương trình. <br/>
• Bss: <br/>
– Quyền truy cập là read-write. <br/>
– Chứa biến toàn cục or biến static với giá trị khởi tạo bằng không or không khởi tạo. <br/>
– Được giải phóng khi kết thúc chương trình. <br/>
• Stack: <br/>
– Quyền truy cập là read-write. <br/>
– Được sử dụng cấp phát cho biến local, input parameter của hàm,… <br/>
– Sẽ được giải phóng khi ra khỏi block code/hàm <br/>
• Heap: <br/>
– Quyền truy cập là read-write. <br/>
– Được sử dụng để cấp phát bộ nhớ động như: Malloc, Calloc, … <br/>
– Sẽ được giải phóng khi gọi hàm free,… <br/>

***So sánh Stack và Heap**: 
- Giống nhau: Bộ nhớ Heap và bộ nhớ Stack bản chất đều cùng là vùng nhớ được tạo ra và lưu trữ trong RAM khi chương trình được thực thi.
- Khác nhau:

Stack  | Heap
------------- | -------------
Được dùng để lưu trữ các biến cục bộ trong hàm, tham số truyền vào...Truy cập vào bộ nhớ này rất nhanh và được thực thi khi chương trình được biên dịch. |  Được dùng để lưu trữ vùng nhớ cho những biến con trỏ được cấp phát động bởi các hàm malloc - calloc - realloc (trong C).
Kích thước của bộ nhớ Stack là cố định, tùy thuộc vào từng hệ điều hành, ví dụ hệ điều hành Windows là 1 MB, hệ điều hành Linux là 8 MB (lưu ý là con số có thể khác tùy thuộc vào kiến trúc hệ điều hành của bạn).  | Kích thước của bộ nhớ Heap là không cố định, có thể tăng giảm do đó đáp ứng được nhu cầu lưu trữ dữ liệu của chương trình.
Vùng nhớ Stack được quản lý bởi hệ điều hành, dữ liệu được lưu trong Stack sẽ tự động hủy khi hàm thực hiện xong công việc của mình.  | Vùng nhớ Heap được quản lý bởi lập trình viên (trong C hoặc C++), dữ liệu trong Heap sẽ không bị hủy khi hàm thực hiện xong, điều đó có nghĩa bạn phải tự tay hủy vùng nhớ bằng câu lệnh free (trong C), và delete hoặc delete [] (trong C++), nếu không sẽ xảy ra hiện tượng rò rỉ bộ nhớ.

***Một số lưu ý**:
- Việc tự động dọn vùng nhớ còn tùy thuộc vào trình biên dịch trung gian.
- Vấn đề lỗi xảy ra đối với vùng nhớ: 
    - Stack: bởi vì bộ nhớ Stack cố định nên nếu chương trình bạn sử dụng quá nhiều bộ nhớ vượt quá khả năng lưu trữ của Stack chắc chắn sẽ xảy ra tình trạng tràn bộ nhớ Stack (Stack overflow), các trường hợp xảy ra như bạn khởi tạo quá nhiều biến cục bộ, hàm đệ quy vô hạn,... Ví dụ về tràn bộ nhớ Stack với hàm đệ quy vô hạn:
        ```
        int foo(int x){
            printf("De quy khong gioi han\n");
            return foo(x);
        }
        ```
    - Heap: Nếu bạn liên tục cấp phát vùng nhớ mà không giải phóng thì sẽ bị lỗi tràn vùng nhớ Heap (Heap overflow). Nếu bạn khởi tạo một vùng nhớ quá lớn mà vùng nhớ Heap không thể lưu trữ một lần được sẽ bị lỗi khởi tạo vùng nhớ Heap thất bại. Ví dụ trường hợp khởi tạo vùng nhớ Heap quá lớn:
        ```
        int *A = (int *)malloc(18446744073709551615);
        ```

</details>

<details>
<summary>BUỔI 7: VARIABLE - BIẾN </summary>

# Static Variable - Extern Variable
Là biến CHỈ ĐƯỢC KHỞI TẠO 1 LẦN DUY NHẤT khi gọi hàm lần đầu tiên (Nếu được khởi tại lại nó sẽ bỏ qua dòng lệnh đó) và nó sẽ tiếp tục tồn tại trong suốt vòng đời của chương trình.
Ví dụ: Biến static cục bộ
  
        
        void Count()
        {
        static int temp = 0;
        printf("Temp = %d",temp);
        temp++
        }
        
Ví dụ: biến toàn cục
File test.c có hàm sau: 
        ```
        void display(){
          printf('TEST')
        }
        ```
File main.c như sau:

        
        extern display();
        
        int main(){
          display();
          return 0;
        }
        
# Từ khóa volatile
Trong lập trình nhúng rất thường hay gặp khai báo biến với từ khóa volatile. Việc khai báo biến volatile là rất cần thiết để tránh những lỗi sai khó phát hiện do tính năng optimization của compiler.
- Volatile có nhiệm vụ báo cho Compiler không được tối ưu biến đó.
- Biến này dùng cho các biến mà giá trị của nó có thể thay đổi hoặc có nhiều task RTOS dùng chung 1 biến.
Ví dụ:

        volatile int x = readADC();

</details>
### C++ Program languge




