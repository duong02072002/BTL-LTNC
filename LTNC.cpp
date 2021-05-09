#include<stdio.h>
typedef struct Sanpham{
    char tensp[30];
    char msp[30];
    int gia;
    int sl;
}SP;
typedef struct Giohang_st{
    char tenKhach[30];
    char diaChi[30];
    int soluong_sp;
    SP ds_hang[100];
}GH;
void nhapKhachHang(GH &input);
void nhapSP(SP &input);
int main(){
    GH danhsach;
    int input;
    nhapKhachHang(input);
    nhapSP(input);
    return 0;
}
void nhapKhachHang(GH &input){
    fflush(stdin);
    printf("\nnhap ten khach hang: ");
    gets(input.tenKhach);
    printf("\nnhap dia chi: ");
    gets(input.diaChi);
    do{
    printf("\nnhap so luong loai san pham: ");  
    scanf("%d", &input.soluong_sp);
    } while (input.soluong_sp < 0);
    for(int i = 0; i<input.soluong_sp;i++){
    	printf("\n-----------------------------");
        printf("\nnhap thong tin sp %d", i+1);
        nhapSP(input.ds_hang[i]);
    }
}
void nhapSP(SP &input){
    fflush(stdin);
    printf("\nnhap ten san pham: ");
    gets(input.tensp);
    printf("\nnhap ma san pham: ");
    gets(input.msp);
    printf("\nnhap so luong: ");
    scanf("%d",&input.sl);
    printf("\nnhap gia: ");
    scanf("%d",&input.gia);
}