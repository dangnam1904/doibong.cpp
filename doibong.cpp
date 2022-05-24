#include<iostream>
#include "cauthu.cpp"
#include<vector>
#include <iomanip>
using namespace std;

class doibong:public cauthu{

    
    public: 
        string ten_doi;
        string dia_phuong;
        string huan_luyen_vien;
        cauthu * ds_ct;

    public:

        doibong(){
            this->dia_phuong="";
            this->huan_luyen_vien="";
            this->ten_doi="";
            ds_ct= new cauthu();
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
                    int n;
                    // cout<<"So luong cau thu:"; cin>> n;
                    // cauthu ct[30];
                    // for (int i=0; i<n;i++){
                        
                    //     ct[i].input();
                    // }
                    // for (int i=0; i<n;i++){
                        
                    //    ds_ct->hoten=ct[i].hoten;
                    // }
                    
                    
                    
        }
        void output(){        
         
        cout<<setw(30)<<left <<ten_doi<<setw(30)<<left <<dia_phuong<<setw(30)<<left <<huan_luyen_vien<<"\n";
    

        }
        friend void tim_kiem_ten_doi(doibong *db[], int  n);
        friend void tim_kiem_huanluyenvien(doibong *db[], int  n);
        friend void tim_kiem_dia_phuong(doibong *db[], int  n);
        friend void sua_thongtin_db(doibong *db[], int  n);
        friend void xoa_doibong(doibong *db[], int  n);
        friend void sort_doibong_ten_doi(doibong *db[], int  n);
        friend void sort_doibong_ten_dia_phuong(doibong *db[], int  n);
        friend void sort_doibong_HLV(doibong *db[], int  n);
       
};

void tim_kiem_ten_doi(doibong *db[], int  n){
    string tendoi;
    int i;
    int find = 0;
    cout << "\nNhap ten  doi can tim: "; fflush(stdin); getline(cin,tendoi);
    for (i = 0; i < n; i++)
    {
        if (db[i]->ten_doi == tendoi)
        {
            cout << "\nDa tim thay\n";
            db[i]->output();
            find = 1;
        }
    }
    if (find == 0)
    {
        cout << "\nKhong tim thay !";
    }
}
void tim_kiem_huanluyenvien(doibong *db[], int  n){
    string hlv;
    
    int find = 0;
    cout << "\nNhap ten HLV can tim: "; fflush(stdin); getline(cin,hlv);
    for (int i = 0; i < n; i++)
    {
        if (db[i]->huan_luyen_vien == hlv)
        {
            cout << "\nDa tim thay\n";
            db[i]->output();
            find = 1;
        }
    }
    if (find == 0)
    {
        cout << "\nKhong tim thay !";
    }
}

void sua_thongtin_db(doibong *db[], int  n){
    string tendoi;
    
    int find = 0;
    cout << "\nNhap ten HLV can tim: "; fflush(stdin); getline(cin,tendoi);
    for (int i = 0; i < n; i++)
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

void xoa_doibong(doibong *db[], int  n){
    string ten_doi_bong;
    int i;
    int find = 0;
    cout << "\nNhap so cmnd cthu can xoa: "; fflush(stdin); getline(cin,ten_doi_bong);

    for (int i = 0; i < n; i++)
    {
        if (db[i]->ten_doi==ten_doi_bong)
        {
             find = 1;
            for (int j = i; j < n; j++)
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
}

void sort_doibong_HLV(doibong *db[], int  n){
     for( int i=0; i<n;i++){
        for( int j=i;j<=n;j++){
            if( db[i]->huan_luyen_vien<db[j]->huan_luyen_vien){
                swap(db[i],db[j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        db[i]->output();
    }
}
void sort_doibong_ten_dia_phuong(doibong *db[], int  n){
    for( int i=0; i<n;i++){
        for( int j=i;j<=n;j++){
            if( db[i]->dia_phuong<db[j]->dia_phuong){
                swap(db[i],db[j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        db[i]->output();
    }
}

void sort_doibong_ten_doi(doibong *db[], int  n){
    for( int i=0; i<n;i++){
        for( int j=i;j<=n;j++){
            if(db[i]->ten_doi<db[j]->ten_doi){
                swap(db[i],db[j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        db[i]->output();
    }
}

void tim_kiem_dia_phuong(doibong *db[], int  n){
    string ten_dia_phuong;
    
    int find = 0;
    cout << "\nNhap ten dia phuong can tim: "; fflush(stdin); getline(cin,ten_dia_phuong);
    for (int i = 0; i < n; i++)
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