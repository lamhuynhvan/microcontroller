
- Nội dung training:
1. Giới thiệu tổng quan về kiến trúc một chương trình embedded
2. Giới thiệu về những bước + thành phần tham gia build một application

- HW: SoC, Memories, Peripherals
- SW: Low layer, Middleware, High layer

#define abc     10

void main(void)
{
    int x;
    x = abc;
    printf("Gia tri abc: $d", c);
}

=> Qua bước Preprocessing sẽ không tồn tại bước define nữa mà sẽ thay thế abc bằng 10

void main(void)
{
    int x;
    x = 10;
    printf("Gia tri abc: $d", c);
}
