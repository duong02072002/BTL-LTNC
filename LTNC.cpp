#include<stdio.h>
#include<string.h>
#include<conio.h>
typedef struct Sanpham{
    char tensp[30];
    char msp[30];
    int gia;
    int sl;
    int tongtien;
}SP;
typedef struct Giohang_st{
    char tenKhach[30];
    char diaChi[30];
    int soluong_sp;
    int tongTien_tt;
    SP ds_hang[100];
}GH;
void nhapKhachHang(GH &input);
void nhapSP(SP &input);
void inThongTinGioHang(GH output);
void tinhTien(SP &input);
void tongTienCanThanhToan(GH source);
void xepHang(GH &source);
void inTheoDS(GH &output);
void xoaHang(GH &source);
void inRafile(FILE *file, char *path, GH source);
void menu(FILE *file,char *path,GH source);
int main(){
    GH danhsach;
    FILE *file;
    char *path ="./baitaplon/gioHang.txt";
    menu(file, path, danhsach);
    return 0;
}
void menu(FILE *file,char *path,GH source){
    char chon;
    do{
    	printf("\n-----------------MENU------------------");
        printf("\n1. Tao gio hang.");
        printf("\n2. Tinh tien.");
        printf("\n3. Xem chi tiet mat hang theo thu tu a->z.");
        printf("\n4. Loai bo mot mat hang.");
        printf("\n5. In ra file nhi phan.");
        printf("\n6. Thoat chuong trinh (ESC).");
        printf("\n---------------------------------------");
        printf("\n=>Lua chon cua ban la: ");
        chon = getch(); // chuyển qua bản mã asc
        switch (chon)
        {
        case 49:
            nhapKhachHang(source);
            inThongTinGioHang(source);
            break;
        case 50:
        	tongTienCanThanhToan(source);
    		break;
    	case 51:
    		xepHang(source);
    		inTheoDS(source);
    		break;
        case 52:
            xoaHang(source);        
            inTheoDS(source);
            break;
        case 53: 
        	inRafile(file,path,source);
        	break;
        case 27:
            printf("\nGOOD BYE.");
            break;
        default:
            printf("\nLua chon cua ban khong hop le.");
            break;
        }
    }while(chon != 27);
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
void xepHang(GH &source){
	SP temp;
	for(int i = 0; i<source.soluong_sp-1;i++){
		for(int j = i+1; j<source.soluong_sp;j++){
			if(strcmp(source.ds_hang[i].tensp,source.ds_hang[j].tensp) > 0){
				temp = source.ds_hang[i];
				source.ds_hang[i] = source.ds_hang[j];
				source.ds_hang[j]= temp;
			}
		}
	}
}
void inTheoDS(GH &output){
	printf("\nSTT||ID\t\t||Ten\t\t||Gia\t\t||SL\t\t||Tong");
	for(int i = 0; i<output.soluong_sp;i++){
		printf("\n00%d||%s\t\t||%s\t\t||%d\t\t||%d\t\t||%d",i+1,output.ds_hang[i].msp,output.ds_hang[i].tensp,output.ds_hang[i].gia,output.ds_hang[i].sl,output.ds_hang[i].tongtien);
	}
}
void xoaHang(GH &source){
    bool kt_xoa = false;
    char maxoa[10];
    fflush(stdin);
    printf("\nNhap ma san pham ban muon xoa: ");
    gets(maxoa);
    for(int i = 0; i<source.soluong_sp;i++){
        if(strcmp((source.ds_hang[i].msp),maxoa) == 0){
            source.ds_hang[i] = source.ds_hang[i+1];
            kt_xoa = true;
        }
    }
    source.soluong_sp--;
    if(kt_xoa == true){
        printf("\nXoa thanh cong.");
    } else {
        printf("\nXoa khong thanh cong");
    }
}
void inRafile(FILE *file, char *path, GH source){
	char *mode = "a+b";
	file = fopen(path,mode);
	fprintf(file,"\nTen khach hang: %s", source.tenKhach);
	fprintf(file,"\nDia chi khach hang: %s", source.diaChi);
	fprintf(file,"\nSo luong san pham mua: %d", source.soluong_sp);
	fprintf(file,"\nSTT||ID\t\t||Ten\t\t||Gia\t\t||SL\t\t||Tong");
	for(int i = 0; i < source.soluong_sp; i++){
		fprintf(file,"\n00%d||%s\t\t||%s\t\t||%d\t\t||%d\t\t||%d",i+1,source.ds_hang[i].msp,source.ds_hang[i].tensp,source.ds_hang[i].gia,source.ds_hang[i].sl,source.ds_hang[i].tongtien);
	}
	fclose(file);
}
