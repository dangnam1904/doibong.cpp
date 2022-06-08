#include<iostream>
#include "cauthu.cpp"
#include<vector>
#include <iomanip>
#include<fstream>
using namespace std;

class doibong:public cauthu{

    
    public: 
        string ten_doi;
        string dia_phuong;
        string huan_luyen_vien;
        cauthu ** ds_ct;
        int max_ct;

    public:

        doibong(){
            this->dia_phuong="";
            this->huan_luyen_vien="";
            this->ten_doi="";
            this->max_ct=0;
            ds_ct= new cauthu*();
        }
        ~doibong(){
            delete ds_ct;
        }
        void input(){
                    cout<<" Ten doi: ";
                    fflush(stdin);
                    getline(cin, this->ten_doi);
                    cout<<" Dia phuong: ";
                    fflush(stdin);
                    getline(cin, this->dia_phuong);
                    cout<<" Huan luyen vien: ";
                    fflush(stdin);
                    getline(cin, this->huan_luyen_vien);
                    
                    cout<<"So luong cau thu:"; cin>>max_ct;
                    for (int i=0; i<max_ct;i++){
                        cauthu::input();
                        ds_ct[i]=new cauthu(hoten,cmnd,ngaysinh,quoctich,vtri_dau,chieucao,cannang);
                        
                    }         
                }
        void output()
        {        
            cout<<setw(30)<<left <<ten_doi<<setw(30)<<left <<dia_phuong<<setw(30)<<left <<huan_luyen_vien<<"\n";
            cout<<"========================Danh sach cau thu=================="<<endl;
            cout<<setw(30)<<left<<"Ho ten"<<setw(30)<<left<<"Ngay sinh"<<setw(30)<<left<<"CMND"<<setw(30)<<left<<"Quoc tich" <<setw(15)<<left<<"Vi tri dau"<<setw(15)<<left<<"Chieu cao "<<setw(10)<<left<<"Can nang"<<endl;
            cout<<"------------------------------------------------------------------------------------------------"<<endl;
            for( int i=0; i<max_ct;i++){
                ds_ct[i]->output();
            }
        }
        friend void tim_kiem_ten_doi(doibong *db[], int  m);
        friend void tim_kiem_huanluyenvien(doibong *db[], int  m);
        friend void tim_kiem_dia_phuong(doibong *db[], int  m);
        friend void sua_thongtin_db(doibong *db[], int  m);
        friend void xoa_doibong(doibong *db[], int  &m);
        friend void sort_doibong_ten_doi(doibong *db[], int  m);
        friend void sort_doibong_ten_dia_phuong(doibong *db[], int  m);
        friend void sort_doibong_HLV(doibong *db[], int  m);
        friend void read_data_doibong(ifstream &filein,doibong *db[],int &m);
       friend void write_data_doibong(ofstream &fileout,doibong *db[],int &m);
        friend void write_data_cauthu_cuoifile(ofstream &fileout,doibong *db[],int &m);
};
void read_data_doibong(ifstream &filein,doibong *db[],int &m){
    
    int i=0;
    while (filein.eof()==false){
        db[i]= new doibong();
       getline(filein,db[i]->ten_doi,',');
       getline(filein,db[i]->dia_phuong,',');
       getline(filein,db[i]->huan_luyen_vien,'\n');
       //db[i]->ds_ct.hoten;
       //filein.ignore(); //xuong dòng
       filein>>db[i]->max_ct;
       cauthu ** ds_ct;
       int j=0;
       for( j=0; j<db[i]->max_ct; j++)
       {
       ds_ct[j]= new cauthu();
       getline(filein,ds_ct[j]->hoten,',');
       getline(filein,ds_ct[j]->cmnd,',');
       getline(filein,ds_ct[j]->ngaysinh,',');
       getline(filein,ds_ct[j]->quoctich,',');
       getline(filein,ds_ct[j]->vtri_dau,',');
       filein>>ds_ct[j]->cannang;
       filein.ignore(); // bỏ dau ,
       filein>>ds_ct[j]->chieucao;
       filein.ignore(); //xuong dòng
       }
       
       i++;
       m++;
    }
    
}

void tim_kiem_ten_doi(doibong *db[], int  m){
    string tendoi;
    int i;
    int find = 0;
    cout << "\nNhap ten  doi can tim: "; fflush(stdin); getline(cin,tendoi);
    cout<<setw(30)<<left<<"Ten doi"<<setw(30)<<left<<" Dia phuong "<<setw(30)<<left <<"Huan luyen vien"<<"\n"; 
    for (i = 0; i < m; i++)
    {
        if (db[i]->ten_doi == tendoi)
        {
            
            db[i]->output();
            find = 1;
        }
    }
    if (find == 0)
    {
        cout << "\nKhong tim thay !";
    }
}
void tim_kiem_huanluyenvien(doibong *db[], int  m){
    string hlv;
    
    int find = 0;
    cout << "\nNhap ten HLV can tim: "; fflush(stdin); getline(cin,hlv);
      cout<<setw(30)<<left<<"Ten doi"<<setw(30)<<left<<" Dia phuong "<<setw(30)<<left <<"Huan luyen vien"<<"\n"; 
    for (int i = 0; i < m; i++)
    {
        if (db[i]->huan_luyen_vien == hlv)
        {
           
            db[i]->output();
            find = 1;
        }
    }
    if (find == 0)
    {
        cout << "\nKhong tim thay !";
    }
}

void sua_thongtin_db(doibong *db[], int  m){
    string tendoi;
    
    int find = 0;
    cout << "\nNhap ten HLV can tim: "; fflush(stdin); getline(cin,tendoi);
    cout<<setw(30)<<left<<"Ten doi"<<setw(30)<<left<<" Dia phuong "<<setw(30)<<left <<"Huan luyen vien"<<"\n"; 
    for (int i = 0; i < m; i++)
    {
        if (db[i]->ten_doi == tendoi)
        {
            
            db[i]->input();
            find = 1;
        }
    }
    if (find == 0)
    {
        cout << "\nKhong tim thay !";
    }
}

void xoa_doibong(doibong *db[], int  &m){
    string ten_doi_bong;
    int i;
    int find = 0;
    cout << "\nNhap so cmnd cthu can xoa: "; fflush(stdin); getline(cin,ten_doi_bong);

    for (int i = 0; i < m; i++)
    {
        if (db[i]->ten_doi==ten_doi_bong)
        {
             find = 1;
            for (int j = i; j < m; j++)
            {
                db[j] = db[j+1];
               
            }
        }
    }
    if (find == 1)
    {
        cout << "\nDa xoa doi bong co ten: "<<ten_doi_bong;
        
    }
    else
    {
        cout << "\nXoa khong thanh cong";
    }
    m--;
}

void sort_doibong_HLV(doibong *db[], int m){
     for( int i=0; i<m;i++){
        for( int j=i;j<=m;j++){
            if( db[i]->huan_luyen_vien<db[j]->huan_luyen_vien){
                swap(db[i],db[j]);
            }
        }
    }
      cout<<setw(30)<<left<<"Ten doi"<<setw(30)<<left<<" Dia phuong "<<setw(30)<<left <<"Huan luyen vien"<<"\n"; 
    for(int i=0;i<m;i++){
        db[i]->output();
    }
}
void sort_doibong_ten_dia_phuong(doibong *db[], int  m){
    for( int i=0; i<m;i++){
        for( int j=i;j<=m;j++){
            if( db[i]->dia_phuong<db[j]->dia_phuong){
                swap(db[i],db[j]);
            }
        }
    }
      cout<<setw(30)<<left<<"Ten doi"<<setw(30)<<left<<" Dia phuong "<<setw(30)<<left <<"Huan luyen vien"<<"\n"; 
    for(int i=0;i<m;i++){
        db[i]->output();
    }
}

void sort_doibong_ten_doi(doibong *db[], int m){
    for( int i=0; i<m;i++){
        for( int j=i;j<=m;j++){
            if(db[i]->ten_doi<db[j]->ten_doi){
                swap(db[i],db[j]);
            }
        }
    }
      cout<<setw(30)<<left<<"Ten doi"<<setw(30)<<left<<" Dia phuong "<<setw(30)<<left <<"Huan luyen vien"<<"\n"; 
    for(int i=0;i<m;i++){
        db[i]->output();
    }
}

void tim_kiem_dia_phuong(doibong *db[], int  m){
    string ten_dia_phuong;
    
    int find = 0;
    cout << "\nNhap ten dia phuong can tim: "; fflush(stdin); getline(cin,ten_dia_phuong);
      cout<<setw(30)<<left<<"Ten doi"<<setw(30)<<left<<" Dia phuong "<<setw(30)<<left <<"Huan luyen vien"<<"\n"; 
    for (int i = 0; i < m; i++)
    {

        if (db[i]->dia_phuong == ten_dia_phuong)
        {
            
            db[i]->output();
            find = 1;
        }
    }
    if (find == 0)
    {
        cout << "\nKhong tim thay !";
    }
}