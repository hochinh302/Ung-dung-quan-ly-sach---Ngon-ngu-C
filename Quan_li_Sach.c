#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<time.h>
// Khai báo thong tin sach. 
struct Thong_Tin_Sach{ 
	char Ma_So[6];    
	char Ten_Sach[50];
	char Tac_Gia[50];
	char The_Loai[50];
	float Gia;
};

// Dinh Dang MENU 
void Menu(){
		system("color e");
		printf("\t\t\t\t=========================o0o=============================\n");
		printf("\t\t\t\t*\t============= _PROGRAM_ =============\t\t* \n");
		printf("\t\t\t\t*\t|    _CHUONG TRINH QUAN LI SACH_    |\t\t* \n");
		printf("\t\t\t\t*\t=====================================\t\t* \n");
		printf("\t\t\t\t*\t[1]. CAP NHAT THONG TIN SACH.\t\t\t*\n");
		printf("\t\t\t\t*\t[2]. HIEN THI THONG TIN SACH.\t\t\t*\n");
		printf("\t\t\t\t*\t[3]. SAP XEP SACH THEO GIA YEU CAU.\t\t*\n");
		printf("\t\t\t\t*\t[4]. TIM KIEM SACH THEO THONG TIN.\t\t*\n");
		printf("\t\t\t\t*\t[5]. THOAT CHUONG TRINH.\t\t\t*\n");
		printf("\t\t\t\t=========================o0o=============================\n");
		printf("\n\t\t+ Moi Ban Chon Chuong Trinh : ");
}

// Hien thi thong tin sach tren 1 hang 
void Hien_Thi_Cot(){
		printf("\t+---------+-----------------------------------+-------------------------+---------------+--------------+\n");
		printf("\t|  %-7s|    %-20s    |   %-12s     |  %-10s   |  %-10s  |\n","Ma So","\t\tTen Sach","\tTac gia","  The loai","    Gia ");
		printf("\t+---------+-----------------------------------+-------------------------+---------------+--------------+\n");
}

// Cap nhat thong tin sach [Them] 
void INPUT(struct Thong_Tin_Sach arr[],int n) {
	int i;
	arr[n];
	for(i=0; i<n; i++){
		printf("\t\t\t** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **\n");
		printf("\t\t\t**\t\t============= _PROGRAM_ ============== \t\t\t**\n");
		printf("\t\t\t**\t\t|    Thong Tin Quyen Sach Thu [%d]:   |\t\t\t**\n",i+1);
		printf("\t\t\t**\t\t====================================== \t\t\t**\n"); 
		do {
			printf("\t\t\t\tMa_So : ");
			fflush(stdin);
			gets(arr[i].Ma_So);
			printf("\n");
			} while(strlen(arr[i].Ma_So) != 5 && printf("\t\t\t\t======================= _Canh Bao_ ========================\n\t\t\t\t| x. XIN LOI, MA SO PHAI BANG 5 KI TU. VUI LONG NHAP LAI. |\n\t\t\t\t===========================================================\n"));
		
		do {
			printf("\t\t\t\tTen_Sach : ");
			fflush(stdin);
			gets(arr[i].Ten_Sach);
			printf("\n");
		} while((strlen(arr[i].Ten_Sach) < 10 || No_Ky_Tu(arr[i].Ten_Sach) == 1 || No_Chu_Thuong(arr[i].Ten_Sach) == 0 ) && printf("\t\t\t\t\t=============== _Canh Bao_ =================\n\t\t\t\t\t| x. XIN LOI, TEN SACH PHAI TREN 1O KI TU  |\n\t\t\t\t\t|\t   KHONG CO KI TU DAC BIET         |\n\t\t\t\t\t|\t  VIET HOA CHU CAI DAU MOI TU      |\n\t\t\t\t\t|\t    VUI LONG NHAP LAI.             |\n\t\t\t\t\t============================================\n"));

		
		do{	
			printf("\t\t\t\tTac_Gia : ");
			fflush(stdin);
			gets(arr[i].Tac_Gia);
			Doi_Chu(arr[i].Tac_Gia);
			printf("\n");
		}while((strlen(arr[i].Tac_Gia) < 1) && (printf("\t\t\t\t============================ _Canh Bao_ ==========================\n\t\t\t\t| x. XIN LOI, BAN CHUA NHAP THONG TIN TAC GIA, VUI LONG NHAP LAI.|\n\t\t\t\t==================================================================\n"))); 

		do {
			printf("\t\t\t\tGia_Sach : ");
			float Money = 0;
			scanf("%f",&Money);
			arr[i].Gia=Money;
			printf("\n");
			} while(arr[i].Gia<1000 && printf("\t\t\t\t\t=============== _Canh Bao_ ===============\n\t\t\t\t\t| x.Gia sach >= 1000. Vui long nhap lai. |\n\t\t\t\t\t==========================================\n"));

		do{
			printf("\t\t\t\tThe_Loai : ");
			fflush(stdin);
			gets(arr[i].The_Loai);
			Doi_Chu(arr[i].The_Loai);
			printf("\n");
		}while((strlen(arr[i].The_Loai) < 1) && (printf("\n\t\t\t\t============================= _Canh Bao_ ==========================\n\t\t\t\t| x. XIN LOI, BAN CHUA NHAP THONG TIN THE LOAI, VUI LONG NHAP LAI.|\n\t\t\t\t===================================================================\n"))); 
 
		printf("\t\t\t**\t\t\t\t\t\t\t\t\t**\n");
		printf("\t\t\t**\t\t\tSach La Tri Thuc Nhan Loai.\t\t\t**\n");
		printf("\t\t\t**\t\t\t\t\t\t\t\t\t**\n");
		printf("\t\t\t** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** \n");
		printf("\n");
		
		
	}
}

// Cap nhat thong tin sach [Sua]
void Repair(struct Thong_Tin_Sach arr[], int n){
	int i;
	arr[n];
	int Flag = 0; 
	char Code[6];
 	do{	
 	fflush(stdin);
	printf("\n\t+ Moi Ban Chon Ma So :  ");
	gets(Code);
	int Ckeck; 
	for(i = 0; i <n ; i++) {

		if(strcmp(Code, arr[i].Ma_So) == 0){
			Nhap_Lai:
			system("cls");
			printf("\t\t\t\t\t_THONG TIN SACH DANG CO_\n");
			Hien_Thi_Cot();
			HienThiRieng(arr[i],n);
			printf("\nChuc Nang [3]. SUA THONG TIN SACH.\n");
			printf("\n");
			printf("\t[1]. Ma So \t\t[2]. Ten Sach \t\t[3]. Tac Gia\n\n\t[4]. The Loai \t\t[5]. Gia Sach \t\t[6]. Sua Tat Ca"); 
			printf("\n________________________________________________________________________________________________________________________\n");
			printf("\n\t+ Moi Ban Chon Chuong Trinh : ");
			scanf("%d", &Ckeck); 
			
			printf("\t\t\t** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **\n");
			printf("\t\t\t**\t\t============= _PROGRAM_ ============== \t\t\t**\n");
			printf("\t\t\t**\t\t|         Nhap Lai Thong Tin         |\t\t\t**\n");
			printf("\t\t\t**\t\t====================================== \t\t\t**\n");
			if(Ckeck == 1){
				do{
				printf("\t\t\t\tMa_So : ");
				fflush(stdin);
				gets(arr[i].Ma_So);
				printf("\n");
				} while(strlen(arr[i].Ma_So) != 5 && printf("\t\t\t\t======================= _Canh Bao_ ========================\n\t\t\t\t| x. Xin loi, Ma so phai bang 5 ky tu. Vui long nhap lai. |\n\t\t\t\t===========================================================\n\n"));
		}else if(Ckeck == 2){
			do {
				printf("\t\t\t\tTen_Sach : ");
				fflush(stdin);
				gets(arr[i].Ten_Sach);
				printf("\n");
				}while((strlen(arr[i].Ten_Sach)<10 || No_Ky_Tu(arr[i].Ten_Sach) == 1 || No_Chu_Thuong(arr[i].Ten_Sach) == 0 )&& printf("\t\t\t\t\t=============== _Canh Bao_ =================\n\t\t\t\t\t| x. XIN LOI, TEN SACH PHAI TREN 1O KI TU  |\n\t\t\t\t\t|\t   KHONG CO KI TU DAC BIET         |\n\t\t\t\t\t|\t  VIET HOA CHU CAI DAU MOI TU      |\n\t\t\t\t\t|\t    VUI LONG NHAP LAI.             |\n\t\t\t\t\t============================================\n"));
				
		}else if(Ckeck == 3){
			do{	
				printf("\t\t\t\tTac_Gia : ");
				fflush(stdin);
				gets(arr[i].Tac_Gia);
				Doi_Chu(arr[i].Tac_Gia);
				printf("\n");
			}while((strlen(arr[i].Tac_Gia) < 1) && (printf("\n\t\t\t\t============================ _Canh Bao_ ==========================\n\t\t\t\t| x. XIN LOI, BAN CHUA NHAP THONG TIN TAC GIA, VUI LONG NHAP LAI.|\n\t\t\t\t==================================================================\n"))); 
			
		}else if(Ckeck == 5){
			do {
				printf("\t\t\t\tGia_Sach : ");
				float Money = 0;
				scanf("%f",&Money);
				arr[i].Gia=Money;
				printf("\n");
			} while(arr[i].Gia<1000 && printf("\t\t\t\t\t=============== _Canh Bao_ ===============\n\t\t\t\t\t| x.Gia sach >= 1000. Vui long nhap lai. |\n\t\t\t\t\t==========================================\n\n"));
		}else if(Ckeck == 4 ){
			do{
			printf("\t\t\t\tThe_Loai : ");
			fflush(stdin);
			gets(arr[i].The_Loai);
			Doi_Chu(arr[i].The_Loai);
			printf("\n");
			}while((strlen(arr[i].The_Loai) < 1) && (printf("\n\t\t\t\t============================= _Canh Bao_ ==========================\n\t\t\t\t| x. XIN LOI, BAN CHUA NHAP THONG TIN THE LOAI, VUI LONG NHAP LAI.|\n\t\t\t\t===================================================================\n"))); 
 
		}else if(Ckeck == 6){
			do {
			printf("\t\t\t\tMa_So : ");
			fflush(stdin);
			gets(arr[i].Ma_So);
			printf("\n");
			} while(strlen(arr[i].Ma_So) != 5 && printf("\t\t\t\t======================= _Canh Bao_ ========================\n\t\t\t\t| x. Xin loi, Ma so phai bang 5 ky tu. Vui long nhap lai. |\n\t\t\t\t===========================================================\n\n"));
		
		do {
			printf("\t\t\t\tTen_Sach : ");
			fflush(stdin);
			gets(arr[i].Ten_Sach);
			printf("\n");
			} while((strlen(arr[i].Ten_Sach) < 10 || No_Ky_Tu(arr[i].Ten_Sach) == 1 || No_Chu_Thuong(arr[i].Ten_Sach) == 0 )&& printf("\t\t\t\t\t=============== _Canh Bao_ =================\n\t\t\t\t\t| x. XIN LOI, TEN SACH PHAI TREN 1O KI TU  |\n\t\t\t\t\t|\t   KHONG CO KI TU DAC BIET         |\n\t\t\t\t\t|\t  VIET HOA CHU CAI DAU MOI TU      |\n\t\t\t\t\t|\t    VUI LONG NHAP LAI.             |\n\t\t\t\t\t============================================\n"));

		do{	
			printf("\t\t\t\tTac_Gia : ");
			fflush(stdin);
			gets(arr[i].Tac_Gia);
			Doi_Chu(arr[i].Tac_Gia);
			printf("\n");
		}while((strlen(arr[i].Tac_Gia) < 1) && (printf("\n\t\t\t\t============================ _Canh Bao_ ==========================\n\t\t\t\t| x. XIN LOI, BAN CHUA NHAP THONG TIN TAC GIA, VUI LONG NHAP LAI.|\n\t\t\t\t==================================================================\n"))); 

		do {
			printf("\t\t\t\tGia_Sach : ");
			float Money = 0;
			scanf("%f",&Money);
			arr[i].Gia=Money;
			printf("\n");
			} while(arr[i].Gia<1000 || No_Ky_Tu(arr[i].Ten_Sach) == 1 &&
		        printf("\t\t\t\t\t=============== _Canh Bao_ ===============\n\t\t\t\t\t| x.Gia sach >= 1000. Vui long nhap lai. |\n\t\t\t\t\t==========================================\n\n"));

		do{
			printf("\t\t\t\tThe_Loai : ");
			fflush(stdin);
			gets(arr[i].The_Loai);
			Doi_Chu(arr[i].The_Loai);
			printf("\n");
		}while((strlen(arr[i].The_Loai) < 1) && (printf("\n\t\t\t\t============================= _Canh Bao_ ==========================\n\t\t\t\t| x. XIN LOI, BAN CHUA NHAP THONG TIN THE LOAI, VUI LONG NHAP LAI.|\n\t\t\t\t===================================================================\n"))); 
 
				}else{
					goto Nhap_Lai;
					}	 
			Flag++;
		}
	}
		if(Flag == 0){
			printf("\n\t\t\t\t====================== _Canh Bao_ =======================\n");
			printf("\t\t\t\t|\t x. KHONG TON TAI MA SO TRONG DANH SACH ! \t|\n\t\t\t\t|\t\t   VUI LONG NHAP LAI !\t\t\t|\n");
			printf("\t\t\t\t=========================================================\n"); 
		}else{
			printf("\n\t\t\t\t\t============== _Chuc Mung_ ==============\n");
			printf("\t\t\t\t\t|\t     Sua Thanh Cong            \t|\n\t\t\t\t\t|     Moi Ban Chon Tiep Chuong Trinh    |\n");
			printf("\t\t\t\t\t=========================================\n");
			}
	}while(Flag == 0);
			printf("\t\t\t**\t\t\t\t\t\t\t\t\t**\n");
			printf("\t\t\t**\t\t\tSach La Tri Thuc Nhan Loai.\t\t\t**\n");
			printf("\t\t\t**\t\t\t\t\t\t\t\t\t**\n");
			printf("\t\t\t** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** \n");
			printf("\n");
}

// Cap nhat thong tin sach [Xoa] 
int Delete(struct Thong_Tin_Sach arr[], int n, int key) {
	int i;
	int Flag = 0; 
	arr[n];
	char Code[6];
	do{
		fflush(stdin);
		printf("\n\t+ Moi Ban Chon Ma So :  ");
		gets(Code);
		for(i = 0 ; i < n ; i++) {
			if(strcmp(Code, arr[i].Ma_So) == 0){
				Flag ++; 
				arr[i] =  arr[i + 1];
			}
		}
		if(Flag == 0){
			printf("\n\t\t\t\t====================== _Canh Bao_ =======================\n");
			printf("\t\t\t\t|\t x. KHONG TON TAI MA SO TRONG DANH SACH ! \t|\n\t\t\t\t|\t\t   VUI LONG NHAP LAI !\t\t\t|\n");
			printf("\t\t\t\t=========================================================\n");
		}else{
			n = n - Flag;
			printf("\n\t\t\t\t\t============== _Chuc Mung_ ==============\n");
			printf("\t\t\t\t\t|\t     Xoa Thanh Cong            \t|\n\t\t\t\t\t|     Moi Ban Chon Tiep Chuong Trinh    |\n");
			printf("\t\t\t\t\t=========================================\n");
		}
	}while(Flag == 0);
		
	return n;
} 	

// Hien thi thong tin sach 
void Hien_Thi(struct Thong_Tin_Sach arr[], int n) {
	int i;
	arr[n];
		printf("\t+---------+-----------------------------------+-------------------------+---------------+--------------+\n");
		printf("\t|  %-7s|    %-20s    |   %-12s     |  %-10s   |  %-10s  |\n","Ma So","\t\tTen Sach","\tTac gia","  The loai","    Gia ");
		printf("\t+---------+-----------------------------------+-------------------------+---------------+--------------+\n");
		for(i=0;i<n;i++){
			printf("\t|  %-7s|   %-30s  |  %-12s           |  %-10s   |  %-10.2f  |\n",arr[i].Ma_So,arr[i].Ten_Sach,arr[i].Tac_Gia,arr[i].The_Loai,arr[i].Gia);
			printf("\t+---------+-----------------------------------+-------------------------+---------------+--------------+\n");
		}
	}

// Hien thi chuc nang tim kiem	
int HienThiRieng(struct Thong_Tin_Sach Sach,int n){
			printf("\t|  %-7s|   %-30s  |  %-20s   |  %-10s   |  %-10.2f  |\n",Sach.Ma_So,Sach.Ten_Sach,Sach.Tac_Gia,Sach.The_Loai,Sach.Gia);
			printf("\t+---------+-----------------------------------+-------------------------+---------------+--------------+\n");
		return 0;
	}	
// Sap Xep [Tang]
void sapXep_Tang(struct Thong_Tin_Sach arr[],int n){
	int i,j;
	arr[n];
	struct Thong_Tin_Sach tmp;
		for(i = 0 ; i < n ; i++){
			for(j = 0 ; j < n - i - 1 ; j++){
				if(arr[j].Gia > arr[j + 1].Gia){
					tmp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tmp;
				}
			}
		}
}

// Sap xep [Giam] 
void sapXep_Giam(struct Thong_Tin_Sach arr[100],int n){
	int i,j; 
	arr[n];
	struct Thong_Tin_Sach tmp;
		for(i = 0 ; i < n ; i++){
			for(j = 0 ; j < n - i -1 ; j++){
				if(arr[j].Gia < arr[j + 1].Gia){
					tmp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tmp;
				}
			}
		}
}

// Tim kiem sach [Tac_Gia] 
void Search_TacGia(struct Thong_Tin_Sach arr[],int n){
	arr[n]; 
	int i, Search = 0;
	char Tac_Gia[30];
		do{
	printf("\n");
	printf("\t + Nhap Ten Tac Gia : ");
	fflush(stdin);
	gets(Tac_Gia);
	printf("\n");
		printf("\t\t\t\t\t\t_THONG TIN SACH DANG CO_\n");
	Hien_Thi_Cot(); 
	for(i = 0; i < n ; i++){
		if(strcmp(Tac_Gia, arr[i].Tac_Gia) == 0){ 
			HienThiRieng(arr[i],n);
			Search = 1;
		} 
	} 
		if(Search == 0){
			printf("\n\t\t\t\t====================== _Canh Bao_ ========================\n");
			printf("\t\t\t\t**\t\t\t\t\t\t\t**\n"); 
			printf("\t\t\t\t\t\t   Tac Gia : %s       \n",Tac_Gia); 
			printf("\t\t\t\t\t    x. Khong Ton Tai Trong Danh Sach         \t\n");
			printf("\t\t\t\t**\t\t  Vui Long Nhap Lai !   \t\t**\n");            
			printf("\t\t\t\t==========================================================\n");
			}
		}while(Search == 0);	 
} 

// Sap Xep A-Z 
void sapXep_AZ(struct Thong_Tin_Sach arr[],int n){
	int i, j;
	struct Thong_Tin_Sach tmp;
	for(i = 0 ; i < n ; i++){
		for(j = 0 ; j < n ; j++){
			if(strcmp(arr[i].Ten_Sach, arr[j].Ten_Sach) < 0){
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
} 
// Tim Kiem Sach [Khoang Gia] 
void Search_KhoangGia(struct Thong_Tin_Sach arr[],int n){
	int i,Search = 0;
	float Money_1, Money_2;
	do{
	printf("\n\t + Moi Ban Nhap Money_1 : ");
	scanf("%f",&Money_1);
	printf("\n\t + Moi Ban Nhap Money_2 : ");
	scanf("%f",&Money_2);
	printf("\n");
	printf("\t\t\t\t\t_THONG TIN SACH DANG CO_\n");
	Hien_Thi_Cot(); 
	for(i = 0 ; i < n ; i++){
		if(arr[i].Gia > Money_1 && arr[i].Gia < Money_2){
			HienThiRieng(arr[i],n);
			Search++; 
		} 
	}
	if(Search == 0){
		printf("\n\t\t\t\t====================== _Canh Bao_ ========================\n");
		printf("\t\t\t\t**\t\t\t\t\t\t\t**\n"); 
		printf("\t\t\t\t\t    x. Khong Ton Tai Gia Tri Trong        \t\n");
		printf("\t\t\t\t\t\t( %0.2f , %0.2f )        \n",Money_1,Money_2); 
		printf("\t\t\t\t**\t\t  Vui Long Nhap Lai !   \t\t**\n");
		printf("\t\t\t\t==========================================================\n"); 
		}
	}while(Search == 0); 
}

// Tim Kiem Sach [The Loai] 
void Search_TheLoai(struct Thong_Tin_Sach arr[], int n){
	int i, Search = 0;
	char The_Loai[30];
	do{
		fflush(stdin);
		printf("\n\t\t+ Ban Muon Tim The Loai : ");
		gets(The_Loai);
		printf("\n");
		printf("\t\t\t\t\t_THONG TIN SACH DANG CO_\n");
		Hien_Thi_Cot();
		for(i = 0 ; i < n ; i++){
			if(strcmp(The_Loai, arr[i].The_Loai) == 0){
				HienThiRieng(arr[i], n);
				Search++;
			}
		}
		if(Search == 0){
			printf("\n\t\t\t\t====================== _Canh Bao_ ========================\n");
			printf("\t\t\t\t**\t\t\t\t\t\t\t**\n"); 
			printf("\t\t\t\t\t\t   The Loai : %s       \n",The_Loai); 
			printf("\t\t\t\t\t    x. Khong Ton Tai Trong Danh Sach         \t\n");
			printf("\t\t\t\t**\t\t  Vui Long Nhap Lai !   \t\t**\n");            
			printf("\t\t\t\t==========================================================\n");
		}	
	}while(Search == 0);
	
} 

// Ma hoa ten sach [In Hoa] 
int Doi_Chu(char Sach[]){
	int i;
	int n = strlen(Sach);
	for(i = 0 ; i < n ; i++){
		if((Sach[i] >= 'a' && Sach[i] <= 'z') && ( i == 0 || Sach[i - 1] == ' ')){
		   Sach[i] -= 32; 
		}
	}
	return n;
}
// Ma hoa ten Sach [Viet Hoa Chu Cai Dau Moi Tu]
int No_Chu_Thuong(char Sach[]){
	     int i;
	     int n = strlen(Sach);
	for(i = 0 ; i < n ; i++){
		if((Sach[i] >= 'a' && Sach[i] <= 'z') && ( i == 0 || Sach[i - 1] == ' ')) 
		{
			return 0; 
		} 
		return -1;
	}
}
// Ma hoa ten sach [Ky Tu Dac Biet] 
int No_Ky_Tu(char Sach[]){
	int i, n ;
	n = strlen(Sach);
	for(i = 0 ; i < n ; i++){
		if((Sach[i] >= 'a' && Sach[i] <= 'z') || (Sach[i] >= 'A' && Sach[i] <= 'Z') || (Sach[i] >= '0' && Sach[i] <= '9') || Sach[i] == ' '){

		}
		else{
			return 1; 
		}
	}
	return -1;
}

// Doc Ghi FILE [Luu File New] 
 void Save_Data(struct Thong_Tin_Sach arr[],int n){
	FILE *fp;
	fp = fopen("book.txt","ab");  //che do ab la viet noi vao hoac tao moi (neu chua co) dang nhi phan
	fwrite(arr, sizeof(struct Thong_Tin_Sach), n, fp);
	fclose(fp);
}

// Doc Ghi FILE [Luu File Sau Sua]
void Save_Reload_Data(struct Thong_Tin_Sach arr[],int n){
	FILE *fp;
	fp = fopen("book.txt","wb");   //wb la tao mot file nhi phan de ghi
	fwrite(arr, sizeof(struct Thong_Tin_Sach), n, fp);
	fclose(fp);
}

// Doc Ghi FILE [Doc File]
void Read_Data(struct Thong_Tin_Sach arr[],int *n){
	FILE *fp;
	fp = fopen("book.txt","rb");	//rd la mo file nhi phan de doc
	fseek(fp,0,SEEK_END);
	*n = (ftell(fp)+1)/sizeof(struct Thong_Tin_Sach);
	fseek(fp,0,SEEK_SET);
	fread(arr, sizeof(struct Thong_Tin_Sach), *n, fp);
	fclose(fp);
}

int main(){
	struct Thong_Tin_Sach arr[100];
	int n,i,key;
	int MENU;
	 	system("color e"); 
	 	time_t t = time(NULL);
		struct tm tm = *localtime(&t);
	
		printf("\t\t\t\t\tHA NOI, NGAY %d THANG %d NAM %d  %02d : %-02d : %-02d  \n\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
		printf("\t\t\t\t\t  ====================o0o================== \n\n");
		printf("\t\t\t\t#############################################################\n");
		printf("\t\t\t\t##                                                         ##\n");
		printf("\t\t\t\t## \t\t      BACH KHOA-APTECH                     ##\n");
		printf("\t\t\t\t##              HE THONG DAO TAO CNTT QUOC TE              ##\n");
		printf("\t\t\t\t##                                                         ##\n");
		printf("\t\t\t\t## HO VA TEN: HO THAN CHINH                 SINH NAM:2002  ##\n");
		printf("\t\t\t\t## LOP: C2010G2_CLC                         MSV: B9043     ##\n");
		printf("\t\t\t\t## QUE QUAN: NGHE AN       NGHANH: LAP TRINH VIEN QUOC TE  ##\n");
		printf("\t\t\t\t## MON THI: NGON NGU LAP TRINH C                           ##\n");
		printf("\t\t\t\t## SAN PHAM : UNG DUNG QUAN LI SACH                        ##\n");
		printf("\t\t\t\t#############################################################\n\n");
		printf("\t\t\t\t\t AN NUT BAT  KI DE TIEP TUC CHUONG TRINH !!!\n\n");
		getch();
		system("cls"); 
	do{
		int Chose; 
		Menu();
		scanf("%d",&MENU);
		switch(MENU) {
			case 1:
				system("cls");
				printf("\nChuong Trinh [1]. CAP NHAT THONG TIN SACH.\n");
				printf("\n\t[1]. THEM SACH \t\t\t [2]. SUA SACH \t\t\t [3].XOA SACH\n");
				printf("________________________________________________________________________________________________________________________\n"); 
				printf("\n\t+ Moi Ban Chon Chuc Nang : ");
				scanf("%d",&Chose);
				switch(Chose){
					case 1: 
					Read_Data(arr, &n);
					system("cls");
					printf("\nChuc Nang [1]. THEM THONG TIN SACH.\n");
					printf("________________________________________________________________________________________________________________________\n");
					printf("\n\t\t\t+ So Luong Nhap Vao : ");
					scanf("%d",&n);
					printf("\n");
					INPUT(arr,n);
					printf("%d",n);
					Save_Data(arr,n);
					printf("\n");
					printf("\t\t\t\t\t_THONG TIN SACH MOI NHAP_\n");
					Hien_Thi(arr,n);
					printf("\n");
					break;
					case 2:
					Read_Data(arr, &n);
					system("cls");
					printf("\nChuc Nang [2]. SUA THONG TIN SACH.\n");
					printf("________________________________________________________________________________________________________________________\n");
					printf("\n");
					printf("\t\t\t\t\t_THONG TIN SACH DANG CO_\n");
					Hien_Thi(arr,n);
					Repair(arr,n);
					Save_Reload_Data(arr,n);
					printf("\n");
					break;
					case 3:
					Read_Data(arr, &n);
					system("cls");
					printf("\nChuc Nang [3]. XOA THONG TIN SACH.\n");
					printf("________________________________________________________________________________________________________________________\n");
					printf("\n");
					printf("\t\t\t\t\t_THONG TIN SACH DANG CO_\n");
					Hien_Thi(arr,n);	
					n = Delete(arr,n,key);
					Save_Reload_Data(arr,n); 
					printf("\n");
					break;
					
					default:
					system("cls");
					printf("\n");
					printf("\t\t\t\t\t** ** ** ** ** ** **  ** ** ** ** ** ** **\n");
	                printf("\t\t\t\t\t**\t      KHONG HOP LE !\t\t**\n\t\t\t\t\t**    VUI LONG CHON LAI CHUONG TRINH.\t**\n\t\t\t\t\t**\t   (^.^) _CAM ON_ (^.^)    \t**\n");
	                printf("\t\t\t\t\t** ** ** ** ** ** **  ** ** ** ** ** ** **\n"); 
	                printf("\n");
					break;
				}
			break;
			
			case 2:
				system("cls");
				Read_Data(arr,&n);
				printf("\nChuong Trinh [2]. HIEN THI THONG TIN SACH.\n");
				printf("________________________________________________________________________________________________________________________\n");
				printf("\n");
				printf("\t\t\t\t\t_THONG TIN SACH DANG CO_\n");
				Hien_Thi(arr,n);
				printf("\n");
			break;
			
			case 3:
				system("cls");
				printf("\nChuong Trinh [3]. SAP XEP SACH THEO YEU CAU.\n");
				printf("\n\t\t[1].GIA TANG  \t\t [2].GIA GIAM \t\t\t [3].THEO ALPHABET (A - Z)\n");
				printf("________________________________________________________________________________________________________________________\n"); 	
				printf("\n\t+ Moi Ban Chon Chuc Nang : ");
				scanf("%d",&Chose);
				switch(Chose){
					case 1:
					Read_Data(arr, &n);
					system("cls");
					printf("\nChuc Nang [1]. SAP XEP SACH THEO GIA (TANG).\n");
					printf("________________________________________________________________________________________________________________________\n");
					sapXep_Tang(arr,n);
					printf("\n");
					printf("\t\t\t\t\t\t_THONG TIN SACH SAU SAP XEP_\n");
					Hien_Thi(arr,n);						
					printf("\n");
					break;
				
					case 2:
					Read_Data(arr, &n);
					system("cls");
					printf("\nChuc Nang [2]. SAP XEP SACH THEO GIA (GIAM).\n");
					printf("________________________________________________________________________________________________________________________\n");
					sapXep_Giam(arr,n);
					printf("\n");
					printf("\t\t\t\t\t\t_THONG TIN SACH SAU SAP XEP_\n");
					Hien_Thi(arr,n);
					printf("\n");
					break;
					
					case 3:
					Read_Data(arr, &n);
					system("cls");
					printf("\nChuc Nang [3]. SAP XEP SACH THEO ALPHABET (A - Z).\n");
					printf("________________________________________________________________________________________________________________________\n");
					sapXep_AZ(arr, n);
					printf("\n");
					printf("\t\t\t\t\t\t_THONG TIN SACH SAU SAP XEP_\n");
					Hien_Thi(arr, n);
					printf("\n");
					break;
					
					default:
					system("cls");
					printf("\n");
					printf("\t\t\t\t\t** ** ** ** ** ** **  ** ** ** ** ** ** **\n");
	                printf("\t\t\t\t\t**\t      KHONG HOP LE !\t\t**\n\t\t\t\t\t**    VUI LONG CHON LAI CHUONG TRINH.\t**\n\t\t\t\t\t**\t   (^.^) _CAM ON_ (^.^)    \t**\n");
	                printf("\t\t\t\t\t** ** ** ** ** ** **  ** ** ** ** ** ** **\n"); 
	                printf("\n");
					break;	 	
				}
			break;
			case 4:
				
				system("cls");
				printf("\nChuong Trinh [4]. TIM KIEM SACH.\n");
				printf("\n\t\t[1]. THEO TAC GIA.  \t\t [2]. THEO KHOANG GIA. \t\t [3]. THEO THE LOAI. \n");
				printf("________________________________________________________________________________________________________________________\n"); 
				printf("\n\t+ Moi Ban Chon Chuc Nang : ");
				scanf("%d",&Chose);
				switch(Chose){
					case 1:
					Read_Data(arr, &n);	
					system("cls");
					printf("\nChuc Nang [1]. TIM KIEM SACH THEO TEN TAC GIA.\n");
					printf("________________________________________________________________________________________________________________________\n");
					Search_TacGia(arr,n);
					printf("\n");
					break;
					
					case 2:
					Read_Data(arr, &n);	
					system("cls");
					printf("\nChuc Nang [2]. TIM KIEM SACH THEO KHOANG GIA.\n");
					printf("________________________________________________________________________________________________________________________\n"); 
					Search_KhoangGia(arr,n);
					printf("\n");
					break;
				
					case 3:
					Read_Data(arr, &n);	
					system("cls");
					printf("\nChuc Nang [3]. TIM KIEM SACH THEO THE LOAI.\n");
					printf("________________________________________________________________________________________________________________________\n"); 
					Search_TheLoai(arr,n);
					printf("\n");
					break;
					
					default:
					system("cls");
					printf("\n");
					printf("\t\t\t\t\t** ** ** ** ** ** **  ** ** ** ** ** ** **\n");
	                printf("\t\t\t\t\t**\t      KHONG HOP LE !\t\t**\n\t\t\t\t\t**    VUI LONG CHON LAI CHUONG TRINH.\t**\n\t\t\t\t\t**\t   (^.^) _CAM ON_ (^.^)    \t**\n");
	                printf("\t\t\t\t\t** ** ** ** ** ** **  ** ** ** ** ** ** **\n"); 
	                printf("\n");
					break;
				}
			break; 
			
			case 5:
				system("cls");
				printf("\n");
				printf("\t\t\t\t\t\t   XIN CHAO !\n\t\t\t\t\t      HEN GAP LAI LAN SAU.");
				printf("\n________________________________________________________________________________________________________________________\n");
				printf("\n\t\t\t\t\t\t\t\t\t\t#############################\n");
				printf("\t\t\t\t\t\t\t\t\t\t# Developer : Ho Than Chinh #\n\t\t\t\t\t\t\t\t\t\t# Lop : C2010G2_CLC	    #\n");
				printf("\t\t\t\t\t\t\t\t\t\t#############################\n");
				exit(0);
			break;
			
			default:
				system("cls");
				printf("\n");
				printf("\t\t\t\t\t** ** ** ** ** ** **  ** ** ** ** ** ** **\n");
                printf("\t\t\t\t\t**\t      KHONG HOP LE !\t\t**\n\t\t\t\t\t**    VUI LONG CHON LAI CHUONG TRINH.\t**\n\t\t\t\t\t**\t   (^.^) _CAM ON_ (^.^)    \t**\n");
                printf("\t\t\t\t\t** ** ** ** ** ** **  ** ** ** ** ** ** **\n");
                printf("\n");
			break;	
		} 
	}while(1 == 1); 
	return 0;
}

