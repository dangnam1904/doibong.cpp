#include<iostream>
#include <string>
#include<fstream>
#include <iomanip>
using namespace std;
class cauthu{
    // khai báo thuộc tính của lớp
    public:
        string hoten, cmnd, ngaysinh, quoctich, vtri_dau;
        double chieucao, cannang;
    public: 
        // hàm khởi tạo ko tham số
        cauthu(){
            this->hoten="";
            this->cmnd="";
            this->ngaysinh="";
            this->quoctich="";
            this-> vtri_dau="";
            this-> chieucao=0;
            this-> cannang=0;
        }
           cauthu(string hoten, string cmnd, string ngaysinh,string quoctich,string vtri_dau, double chieucao, double cannang){
            this->hoten=hoten;
            this->cmnd=cmnd;
            this->ngaysinh=ngaysinh;
            this->quoctich=quoctich;
            this-> vtri_dau=vtri_dau;
            this-> chieucao=chieucao;
            this-> cannang=cannang;
        }
        
        /// hàm nhạp dữ liệu
       
        void input(){
            cout<<" Ho ten: ";
            fflush(stdin);
            getline(cin, this->hoten);
            cout<<" CMND: ";
            fflush(stdin);
            getline(cin,this->cmnd);
            cout<<" Ngay sinh: ";
            fflush(stdin);
            getline(cin,this->ngaysinh);
            cout<<" Quoc tich: ";
            fflush(stdin);
            getline(cin,this->quoctich);
            cout<<" vi tri thi dau: ";
            fflush(stdin);
            getline(cin,this->vtri_dau);
            cout<<" chieu cao:";
            cin>>chieucao;
            cout<<" Can nang: ";
            cin>>cannang;
        }

        // hàm in dữ liệu
        void output(){
           
            
            cout<<setw(30)<<left<< hoten<<setw(30)<<left<<ngaysinh<<setw(30)<<left<<cmnd<<setw(30)<<left<<quoctich<<setw(15)<<left<<vtri_dau<<setw(15)<<left<<chieucao<<setw(10)<<left<<cannang<<"\n";

        }
      // hàm bạn  
        friend void tim_kiem_ten(cauthu *ct[], int  n);
        friend void tim_kiem_cmnd(cauthu *ct[], int  n);
        friend void tim_kiem_ten_vs_qtich(cauthu *ct[], int  n);
        friend void sua_thongtin_cthu(cauthu *ct[], int  n);
        friend void xoa_cthu(cauthu *ct[], int  &n);
        friend void sort_cthu(cauthu *ct[], int  n);
        friend void sort_cthu_chieucao(cauthu *ct[], int  n);
        friend void sort_cthu_can_nang(cauthu *ct[], int  n);
        friend void read_data_cauthu(ifstream &filein,cauthu *ct[],int &n);
        friend void write_data_cauthu(ofstream &fileout,cauthu *ct[],int &n);
        friend void write_data_cauthu_cuoifile(ofstream &fileout,cauthu *ct[],int &n);
};
void read_data_cauthu(ifstream &filein,cauthu *ct[], int &n){
  
//    int a;
//    filein>>n;
//   filein.ignore(); //bỏ qua \n
//    //n=a;
   
//     for(int i=0; i<n;i++){
//         ct[i]= new cauthu();
//        getline(filein,ct[i]->hoten,',');
//        getline(filein,ct[i]->cmnd,',');
//        getline(filein,ct[i]->ngaysinh,',');
//        getline(filein,ct[i]->quoctich,',');
//        getline(filein,ct[i]->vtri_dau,',');
//        filein>>ct[i]->cannang;
//        filein.ignore(); // bỏ dau ,
//        filein>>ct[i]->chieucao;
//        filein.ignore(); //xuong dòng
//     }
     int i=0;
    while (filein.eof()==false){
        ct[i]= new cauthu();
       getline(filein,ct[i]->hoten,',');
       getline(filein,ct[i]->cmnd,',');
       getline(filein,ct[i]->ngaysinh,',');
       getline(filein,ct[i]->quoctich,',');
       getline(filein,ct[i]->vtri_dau,',');
       filein>>ct[i]->cannang;
       filein.ignore(); // bỏ dau ,
       filein>>ct[i]->chieucao;
       filein.ignore(); //xuong dòng
       i++;
       n++;
    }
   
}

void write_data_cauthu(ofstream &fileout,cauthu *ct[],int &n){
 for( int i=0; i<n;i++){
        if(n-i==1){
        fileout<< ct[i]->hoten<<","<<ct[i]->cmnd<<","<<ct[i]->ngaysinh<<","<<ct[i]->quoctich<<","<<ct[i]->chieucao<<","<<ct[i]->cannang;
        }
        else{
            fileout<< ct[i]->hoten<<","<<ct[i]->cmnd<<","<<ct[i]->ngaysinh<<","<<ct[i]->quoctich<<","<<ct[i]->chieucao<<","<<ct[i]->cannang<<endl;
        }
 }
}
void write_data_cauthu_cuoifile(ofstream &fileout,cauthu *ct[],int &n){
    fileout<<"\n";
    for( int i=0; i<n;i++){
        if(n-i==1){
        fileout<< ct[i]->hoten<<","<<ct[i]->cmnd<<","<<ct[i]->ngaysinh<<","<<ct[i]->quoctich<<","<<ct[i]->chieucao<<","<<ct[i]->cannang;
        }
        else{
            fileout<< ct[i]->hoten<<","<<ct[i]->cmnd<<","<<ct[i]->ngaysinh<<","<<ct[i]->quoctich<<","<<ct[i]->chieucao<<","<<ct[i]->cannang<<endl;
        }
 }
}

void tim_kiem_ten(cauthu *ct[], int n){
    string ht;
    int i;
    int find = 0;
    cout << "\nNhap ten can tim: "; fflush(stdin); getline(cin,ht);
    cout<<setw(30)<<left<<"Ho ten"<<setw(30)<<left<<"Ngay sinh"<<setw(30)<<
    left<<"CMND"<<setw(30)<<left<<"Quoc tich" <<setw(15)<<left<<"Vi tri dau"<<setw(15)<<left<<"Chieu cao "<<setw(10)<<left<<"Can nang"<<endl;
    for (i = 0; i < n; i++)
    {   
        // kiểm tra không phân biêt hoa thường
        // if (stricmp(ct[i]->hoten.c_str(), ht.c_str()) == 0)
		// {
        //     ct[i]->output();
        //     find = 1;
        // }

        if (ct[i]->hoten == ht)
        {
            
            ct[i]->output();
            find = 1;
        }
    }
    if (find == 0)
    {
        cout << "\nKhong tim thay !";
    }
}

void tim_kiem_ten_vs_qtich(cauthu *ct[], int  n){
     string ht, q_tich;
   
    int find = 0;
    cout << "\nNhap ten can tim: "; fflush(stdin); getline(cin,ht);
    cout << "\nNhap quoc tich can tim: "; fflush(stdin); getline(cin,q_tich);
    cout<<setw(30)<<left<<"Ho ten"<<setw(30)<<left<<"Ngay sinh"<<setw(30)<<
    left<<"CMND"<<setw(30)<<left<<"Quoc tich" <<setw(15)<<left<<"Vi tri dau"<<setw(15)<<left<<"Chieu cao "<<setw(10)<<left<<"Can nang"<<endl;
    for (  int i = 0; i < n; i++)
    {
        if (ct[i]->hoten == ht && ct[i]->quoctich==q_tich)
        {
          
            ct[i]->output();
            find = 1;
        }
    }
    if (find == 0)
    {
        cout << "\nKhong tim thay !";
    }
}

void tim_kiem_cmnd(cauthu *ct[], int n){
    string cm;
    int i;
    int find = 0;
    cout << "\nNhap so cmnd can tim: "; fflush(stdin); getline(cin,cm);
    cout<<setw(30)<<left<<"Ho ten"<<setw(30)<<left<<"Ngay sinh"<<setw(30)<<
    left<<"CMND"<<setw(30)<<left<<"Quoc tich" <<setw(15)<<left<<"Vi tri dau"<<setw(15)<<left<<"Chieu cao "<<setw(10)<<left<<"Can nang"<<endl;
    for (i = 0; i < n; i++)
    {
        if (ct[i]->cmnd == cm)
        {
           
            ct[i]->output();
            find = 1;
        }
    }
    if (find == 0)
    {
        cout << "\nKhong tim thay !";
    }
}

void sua_thongtin_cthu(cauthu *ct[], int n){
    string cm;
    int i;
    int find = 0;
    cout << "\nNhap so cmnd can sua: "; fflush(stdin); getline(cin,cm);
    for (i = 0; i < n; i++)
    {
        if (ct[i]->cmnd == cm)
        {
            
            ct[i]->input();
            find = 1;
        }
    }
    if (find == 0)
    {
        cout << "\nKhong tim thay !";
    }
}
void xoa_cthu(cauthu *ct[], int &n){
    string cm;
    int i;
    int find = 0;
    cout << "\nNhap so cmnd cthu can xoa: "; fflush(stdin); getline(cin,cm);

    for (int i = 0; i < n; i++)
    {
        if (ct[i]->cmnd==cm)
        {
             find = 1;
            for (int j = i; j < n; j++)
            {
                ct[j] = ct[j+1];
               
            }
        }
    }
    if (find == 1)
    {
        cout << "\nDa xoa cau thu co cmnd"<<cm;
        
    }
    else
    {
        cout << "\nXoa khong thanh cong";
    }
    n--;
}

void sort_cthu(cauthu *ct[], int  n){
    for( int i=0; i<n;i++){
        for( int j=i;j<n;j++){
            if( ct[i]->hoten<ct[j]->hoten){
                swap(ct[i],ct[j]);
            }
        }
    }
    cout<<setw(30)<<left<<"Ho ten"<<setw(30)<<left<<"Ngay sinh"<<setw(30)<<
    left<<"CMND"<<setw(30)<<left<<"Quoc tich" <<setw(15)<<left<<"Vi tri dau"<<setw(15)<<left<<"Chieu cao "<<setw(10)<<left<<"Can nang"<<endl;
    for(int i=0;i<n;i++){
        ct[i]->output();
    }
}

void sort_cthu_chieucao(cauthu *ct[], int  n){
    for( int i=0; i<n;i++){
        for( int j=i;j<n;j++){
            if( ct[i]->chieucao<ct[j]->chieucao){
                swap(ct[i],ct[j]);
            }
        }
    }
    cout<<setw(30)<<left<<"Ho ten"<<setw(30)<<left<<"Ngay sinh"<<setw(30)<<
    left<<"CMND"<<setw(30)<<left<<"Quoc tich" <<setw(15)<<left<<"Vi tri dau"<<setw(15)<<left<<"Chieu cao "<<setw(10)<<left<<"Can nang"<<endl;
    for(int i=0;i<n;i++){
        ct[i]->output();
    }
}

void sort_cthu_can_nang(cauthu *ct[], int  n){
    for( int i=0; i<n;i++){
        for( int j=i;j<n;j++){
            if(ct[i]->cannang<ct[j]->cannang){
                swap(ct[i],ct[j]);
            }
        }
    }
    cout<<setw(30)<<left<<"Ho ten"<<setw(30)<<left<<"Ngay sinh"<<setw(30)<<
    left<<"CMND"<<setw(30)<<left<<"Quoc tich" <<setw(15)<<left<<"Vi tri dau"<<setw(15)<<left<<"Chieu cao "<<setw(10)<<left<<"Can nang"<<endl;
    for(int i=0;i<n;i++){
        ct[i]->output();
    }
}