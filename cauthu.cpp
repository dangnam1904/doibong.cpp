#include<iostream>
#include <string>
#include<fstream>
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
           
            
            cout<< hoten<<"\t "<<ngaysinh<<"\t"<<cmnd<<"\t\t"<<quoctich<<"\t\t"<<vtri_dau<<"\t "<<chieucao<<"\t "<<cannang<<"\n";

        }
      // hàm bạn  
        friend void tim_kiem_ten(cauthu *ct[], int  n);
        friend void tim_kiem_cmnd(cauthu *ct[], int  n);
        friend void tim_kiem_ten_vs_qtich(cauthu *ct[], int  n);
        friend void sua_thongtin_cthu(cauthu *ct[], int  n);
        friend void xoa_cthu(cauthu *ct[], int  n);
        friend void sort_cthu(cauthu *ct[], int  n);
        friend void sort_cthu_chieucao(cauthu *ct[], int  n);
        friend void sort_cthu_can_nang(cauthu *ct[], int  n);
        friend void read_data(ifstream &filein,cauthu *ct[],int n);
   
};
void read_data(ifstream &filein,cauthu *ct[],int n){
   string ht;
    // for(int i=0; i<n;i++){
    //     getline(filein,ct[i]->hoten,"\t");
    // }
   
}

void tim_kiem_ten(cauthu *ct[], int n){
    string ht;
    int i;
    int find = 0;
    cout << "\nNhap ten can tim: "; fflush(stdin); getline(cin,ht);
    for (i = 0; i < n; i++)
    {
        if (ct[i]->hoten == ht)
        {
            cout << "\nDa tim thay\n";
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
    for (  int i = 0; i < n; i++)
    {
        if (ct[i]->hoten == ht && ct[i]->quoctich==q_tich)
        {
            cout << "\nDa tim thay\n";
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
    for (i = 0; i < n; i++)
    {
        if (ct[i]->cmnd == cm)
        {
            cout << "\nDa tim thay\n";
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
void xoa_cthu(cauthu *ct[], int n){
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
}

void sort_cthu(cauthu *ct[], int  n){
    for( int i=0; i<n;i++){
        for( int j=i;j<n;j++){
            if( ct[i]->hoten<ct[j]->hoten){
                swap(ct[i],ct[j]);
            }
        }
    }
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
    for(int i=0;i<n;i++){
        ct[i]->output();
    }
}