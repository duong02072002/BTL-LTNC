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
void inThongTinGioHang(GH output);
void tinhTien(SP &input);
void tongTienCanThanhToan(GH source);
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
    tinhTien(input);
}
void inThongTinGioHang(GH output){
	printf("\n--------------------Thong Tin Gio Hang-------------------");
	printf("\nTen khach hang: %s", output.tenKhach);
	printf("\nDia chi: %s", output.diaChi);
	printf("\nSTT||ID\t\t||Ten\t\t||Gia\t\t||SL\t\t||Tong");
	for(int i = 0; i<output.soluong_sp;i++){
		printf("\n00%d||%s\t\t||%s\t\t||%d\t\t||%d\t\t||%d",i+1,output.ds_hang[i].msp,output.ds_hang[i].tensp,output.ds_hang[i].gia,output.ds_hang[i].sl,output.ds_hang[i].tongtien);
	}
	printf("\n---------------------------------------------------------\n");
}
void tinhTien(SP &input){
	input.tongtien = input.gia * input.sl;
}
void tongTienCanThanhToan(GH source){
	source.tongTien_tt = 0;
	for(int i = 0; i<source.soluong_sp;i++){
		source.tongTien_tt += source.ds_hang[i].tongtien;
	}
	printf("\nTong tien khach can thanh toan la: %d", source.tongTien_tt);
}