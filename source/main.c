#include<stdio.h>
#include<string.h>
// creat type  struct .
typedef struct
{
    int msv ;
    char Ho[10];
    char dem[10];
    char ten[10];
    char gioitinh[10];
    int tuoi ;
    float diemtoan ;
    float diemvan;
    float diemanh;
    float diemtb ;
} sv_info_t;

//sv_info_t sv_arr[100] ; // quan ly tat ca sinh vien
int i = 0 ;

sv_info_t NhapSv(void)
{
    sv_info_t sv ; // number 1 student .
    printf("Nhap Msvv[%d]:" , i+1);
    scanf("%d" , &sv.msv);
    fflush(stdin);
    printf("Nhap ho va ten :");
    scanf("%s %s %s" , sv.Ho , sv.dem , sv.ten);
    fflush(stdin);
    printf("Nhap tuoi :");
    scanf("%d" , &sv.tuoi);
    printf("Nhap gioi tinh :");
    fflush(stdin);
    gets(sv.gioitinh);
    printf("Nhap diem :");
    scanf("%f %f %f", &sv.diemtoan , &sv.diemvan , &sv.diemanh);
    sv.diemtb = (sv.diemtoan + sv.diemvan + sv.diemanh)/3;
    //numbersv++;
    i++;
    return sv ;
}
// printf number student . <-> number student.
void InSV(sv_info_t sv)
{
    printf("%-10d%-10s%-10s%-10s%-10d%-15s%-10.2f%-10.2f%-10.2f%-10.2f\n" , sv.msv , sv.Ho , sv.dem , sv.ten , sv.tuoi , sv.gioitinh , sv.diemtoan , sv.diemvan , sv.diemanh , sv.diemtb);

}
// printf all student
void inallSv( sv_info_t *sv , int num )
{
    printf("------------------------------------\n");
    printf("%-10s%-10s%-10s%-10s%-10s%-15s%-10s%-10s%-10s%-10s\n" , "MASV" , "HO" , "DEM" , "TEN" , "TUOI" , "GIOI TINH" , "TOAN" ,"VAN" , "ANH" ,"DIEMB" );
    for ( int i = 0 ; i < num ; i++)
    {
        InSV(sv[i]);
        //printf("%-10d%-10s%-10s%-10s%-10d%-15s%-10.2f%-10.2f%-10.2f%-10.2f\n" , sv[i].msv , sv[i].Ho , sv[i].dem , sv[i].ten , sv[i].tuoi , sv[i].gioitinh , sv[i].diemtoan , sv[i].diemvan , sv[i].diemanh , sv[i].diemtb);
    }
    printf("------------------------------------\n");
}
void sapxepSV(sv_info_t *sv , int num , char *option)
{
    sv_info_t sv_clone[100];
    memcpy(sv_clone , sv , num*sizeof(sv_info_t)); // copy cac phan tu sang mang sv clone .
    if(strstr(option,"ten"))  // find char in option
    {
        // selection sort .
        for ( int i = 0 ; i < num ; i++)
        {
            for(int j = i+1 ; j < num ; j++)
            {
                if(strcmp(sv_clone[i].ten,sv_clone[j].ten) > 0)
                {
                    sv_info_t temp ;
                    temp = sv_clone[i] ;
                    sv_clone[i] = sv_clone[j] ;
                    sv_clone[j] = temp;
                }
            }
        }
        inallSv(sv_clone,num);
    }
    else if(strstr(option,"diemtb"))
    {
        // selection sort .
        for ( int i = 0 ; i < num ; i++)
        {
            for(int j = i+1 ; j < num ; j++)
            {
                if((sv_clone[i].diemtb) > (sv_clone[j].diemtb))
                {
                    sv_info_t temp ;
                    temp = sv_clone[i] ;
                    sv_clone[i] = sv_clone[j] ;
                    sv_clone[j] = temp;
                }
            }
        }
        inallSv(sv_clone,num);
    }
}

void XuatFile(sv_info_t *sv , int num , char dir[])
{
    FILE *fptr ;
    fptr = fopen(dir,"a");
    fprintf(fptr, "%-10s%-10s%-10s%-10s%-10s%-15s%-10s%-10s%-10s%-10s\n" , "MASV" , "HO" , "DEM" , "TEN" , "TUOI" , "GIOI TINH" , "TOAN" ,"VAN" , "ANH" ,"DIEMB" );
    for(int i = 0 ; i < num ; i++)
    {
        fprintf(fptr , "%-10d%-10s%-10s%-10s%-10d%-15s%-10.2f%-10.2f%-10.2f%-10.2f\n" , sv[i].msv , sv[i].Ho , sv[i].dem , sv[i].ten , sv[i].tuoi , sv[i].gioitinh , sv[i].diemtoan , sv[i].diemvan , sv[i].diemanh , sv[i].diemtb);

    }
    fclose(fptr);
    printf("OK -> du lieu da duoc ghi vao trong file .\n");
}
void DocFile(sv_info_t *sv_1 , int *numbersv , char dir[])
{
    FILE *fptr ;
    fptr = fopen(dir,"r");
    int dem = 0 ;
    if(fptr){
        while(1)
        {
            sv_info_t sv ;
            fscanf(fptr , "%10d %10s %10s %10s %10d %15s %10f %10f %10f %10f\n" , &sv.msv , sv.Ho , sv.dem , sv.ten , &sv.tuoi , sv.gioitinh , &sv.diemtoan , &sv.diemvan , &sv.diemanh , &sv.diemtb);
            sv_1[dem++] = sv ;
            if(feof(fptr))
            {
                break ;
            }
        }
    }
    fclose(fptr);
    *numbersv = dem ;
}

// xep loai 1 sv .
void XepLoaiSV( sv_info_t sv )
{
    if(sv.diemtb >= 8){

        printf("gioi\n");

    }else if(sv.diemtb >= 6.5)
    {
        printf("Kha\n");

    }else if(sv.diemtb >= 4)
    {
        printf("trung binh\n");

    }else  printf("yeu\n");
}

void XepLoaiSV_N( sv_info_t *sv ,int num )
{
    printf("-------------------\n");
    for( int i = 0 ; i < num ; i++)
    {
        printf("xep loai cua sv thu %d la : " , i+1);
        XepLoaiSV(sv[i]);
    }
    printf("-------------------\n");
}

void ThemSV(sv_info_t *sv , int num , int pos)
{
    for ( int i = num - 1 ; i > pos ; i--){
        sv[i] = sv[i-1];
    }
    sv[pos] = NhapSv();
    num++;
}

void XoaSV(sv_info_t *sv , int num , int *pos)
{
    printf("Nhap vi tri SV can xoa : ");
    scanf("%d" , pos);
    for ( int i = num - 1 ; i >= *pos ; i--){
        sv[i] = sv[i+1];
    }
    num--;
}

void SuaSV(sv_info_t *sv , int num , int pos)
{
    for ( int i = 0 ; i < num ; i++){
        if( i == pos){
            sv[pos] = NhapSv();
        }
    }
}

char menu()
{
    char function = 0 ;
    printf("----------------MENU----------------\n");
    printf("1.Nhap sinh vien :\n");
    printf("2.In toan bo sinh vien :\n");
    printf("3.Sap xep theo ten sinh vien :\n");
    printf("4.Sap xep theo diem TB sinh vien :\n");
    printf("5.Ghi thong tin sinh vien vao file :\n");
    printf("6.Doc thong tin sinh vien tu file :\n");
    printf("7.Xep loai sinh vien theo diemtb :\n");
    printf("8.Them sinh vien vao danh sach quan ly:\n");
    printf("9.Xoa sinh vien khoi danh sach quan ly:\n");
    printf("a.Sua sinh vien trong danh sach quan ly:\n");
    printf("------------------------------------\n");
    while( function < '1' || function > 'a')
    {
        printf("Ban Hay Nhap lua chon so : ");
        fflush(stdin);
        scanf("%c" , &function);
    }
    return function ;
}
int main()
{
    sv_info_t sv_arr[100] ;
    int numbersv = 0 , pos;
    char dir[] = "G:\\xu_ly_File\\A.txt";
    char function1 ;
    DocFile(sv_arr,&numbersv,dir);
    printf("DANH SACH SINH VIEN :\n");
    inallSv(sv_arr,numbersv);
    while(1)
    {
        function1 = menu();

        switch(function1)
        {
            case '1':
            printf("Nhap so sinh vien : ");
            scanf("%d" , &numbersv);
            for(int i = 0 ; i < numbersv ; i++)
            {
                printf("Nhap thong tin sinh vien thu : %d\n" , i+1);
                sv_arr[i] = NhapSv();
            }
            getch();
            break ;
            case '2':
            inallSv(sv_arr , numbersv);
            getch();
            break ;
            case '3':
            sapxepSV(sv_arr , numbersv , "ten");
            getch();
            break ;
            case '4':
            sapxepSV(sv_arr , numbersv , "diemtb");
            getch();
            break ;
            case '5':
            XuatFile(sv_arr,numbersv,dir);
            getch();
            break;
            case '7':
            XepLoaiSV_N(sv_arr,numbersv);
            getch();
            break ;
            case '8':
            printf("Nhap vi tri can them SV : ");
            scanf("%d" , &pos);
            i = pos ;
            ThemSV(sv_arr,numbersv,pos);
            numbersv++; // increase numbersv in array .
            getch();
            break ;
            case '9':
            XoaSV(sv_arr,numbersv,&pos);
            numbersv--; // decrease numbersv in array .
            getch();
            break ;
            case 'a':
            printf("Nhap vi tri SV can sua : ");
            scanf("%d" , &pos);
            i = pos ;  // reset number i = pos .
            SuaSV(sv_arr,numbersv,pos);
            getch();
            break ;
        }
    }
    return 0 ;
}


