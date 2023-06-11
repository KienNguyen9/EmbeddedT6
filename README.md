# EmbeddedT6
Learn Embedded 6/2023
# BUỔI 4: COMPILER - TRÌNH BIÊN DỊCH
Compiler hay còn gọi là trình biên dịch có thể được hiểu là công việc dịch chuỗi câu lệnh được viết từ một ngôn ngữ lập trình thành chương trình tương đương dưới dạng ngôn ngữ máy tính, thường là ngôn ngữ ở cấp thấp hơn, ngôn ngữ máy. Đơn giản dễ hiểu thì có thể tạm nói là nhờ Complier này mà file .c chúng ta viết mới được dịch thành file .hex .bin để nạp được xuống một MCU bất kỳ.
Quá trình biên dịch 
![image](https://github.com/KienNguyen9/EmbeddedT6/assets/136218538/0268c4fb-9806-424c-a8ac-3ae0afdc69db)
![image](https://github.com/KienNguyen9/EmbeddedT6/assets/136218538/562d9e22-66ef-4010-8893-c074d149f7e2)
![image](https://github.com/KienNguyen9/EmbeddedT6/assets/136218538/010b0838-7917-4e5b-8f1a-b11012bfc3d7)

1. Pre-processing (Tiền xử lí)
Bộ tiền xử lý C không phải là một phần của trình biên dịch, mà là một bước riêng biệt trong quá trình biên dịch. Nói một cách đơn giản, Bộ tiền xử lý C chỉ là một công cụ thay thế văn bản và nó hướng dẫn trình biên dịch thực hiện tiền xử lý cần thiết trước khi biên dịch thực tế. Các lệnh tiền xử lí bắt đầu bằng kí tự "#" 
Ví dụ: 
- " #define" :Thay thế các macro
- "#include" :Chèn thêm file khác như các thư viên
Dùng GCC bằng lệnh sau để có file tiền xử lí: gcc -E main.o -o main.i (chuyển từ file .c sang file .i)


2. Compiling (Biên dịch
3. Assembling (Hợp ngữ)
4. Linking (Liên kết)

