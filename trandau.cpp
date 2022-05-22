#include<iostream>
#include <string>
using namespace std;

class trandau{

    private:
        string ngay_thi_dau, san_thi_dau, ten_hai_doi_bong, ti_so;
    
    public:
    trandau(){}
    void input(){
            cout<<" Ngay thi dau: ";
            fflush(stdin);
            getline(cin, this->ngay_thi_dau);
            cout<<" San thi dau: ";
            fflush(stdin);
            getline(cin,this->san_thi_dau);
            cout<<" ten hai doi bong: ";
            fflush(stdin);
            getline(cin,this->ten_hai_doi_bong);
            cout<<" Ti so: ";
            fflush(stdin);
            getline(cin,this->ti_so);
            
        }
        void output(){
           
            
            cout<< ngay_thi_dau<<"\t "<<san_thi_dau<<"\t"<<ten_hai_doi_bong<<"\t\t"<<ti_so<<"\n";

        }
        friend void tim_kiem_ngay_thi_dau(trandau *td[], int  n);
        friend void tim_kiem_san_thi_dau(trandau *td[], int  n);
        friend void tim_kiem_ten_hai_doi_bong(trandau *td[], int  n);
        friend void  sua_thong_tin_tran_dau(trandau *td[], int  n);
        friend void xoa_trandau(trandau *td[], int  n);
        friend void sort_san_thi_dau(trandau *td[], int  n);
        friend void sort_ngay_thi_dau(trandau *td[], int  n);
        friend void read_data(ifstream &filein,trandau *td[],int n);
    
    
};
void tim_kiem_ngay_thi_dau(trandau *td[], int  n){
    string ngay_dau;
    int i;
    int find = 0;
    cout << "\nNhap ngay thi dau  doi can tim: "; fflush(stdin); getline(cin,ngay_dau);
    for (i = 0; i < n; i++)
    {
        if (td[i]->ngay_thi_dau == ngay_dau)
        {
            cout << "\nDa tim thay\n";
            td[i]->output();
            find = 1;
        }
    }
    if (find == 0)
    {
        cout << "\nKhong tim thay !";
    }
}

void tim_kiem_san_thi_dau(trandau *td[], int  n){

    string san_dau;
    int i;
    int find = 0;
    cout << "\nNhap san dau can tim: "; fflush(stdin); getline(cin,san_dau);
    for (i = 0; i < n; i++)
    {
        if (td[i]->san_thi_dau == san_dau)
        {
            cout << "\nDa tim thay\n";
            td[i]->output();
            find = 1;
        }
    }
    if (find == 0)
    {
        cout << "\nKhong tim thay !";
    }
}

void tim_kiem_ten_hai_doi_bong(trandau *td[], int  n){
    string ten2doi;
    int i;
    int find = 0;
    cout << "\nNhap san dau can tim: "; fflush(stdin); getline(cin,ten2doi);
    for (i = 0; i < n; i++)
    {
        if (td[i]->ten_hai_doi_bong == ten2doi)
        {
            cout << "\nDa tim thay\n";
            td[i]->output();
            find = 1;
        }
    }
    if (find == 0)
    {
        cout << "\nKhong tim thay !";
    }
}

void  sua_thong_tin_tran_dau(trandau *td[], int  n){
    string tendoi, ngay_dau;
    
    int find = 0;
    cout << "\nNhap ten 2 doi can tim: "; fflush(stdin); getline(cin,tendoi);
    cout << "\nNhap ngay dau doi can tim: "; fflush(stdin); getline(cin,tendoi);
    for (int i = 0; i < n; i++)
    {
        if (td[i]->ten_hai_doi_bong == tendoi  && td[i]->ngay_thi_dau==ngay_dau)
        {
            
            td[i]->input();
            find = 1;
        }
    }
    if (find == 0)
    {
        cout << "\nKhong tim thay !";
    }
}

//sort
void sort_ngay_thi_dau(trandau *td[], int  n){
     for( int i=0; i<n;i++){
        for( int j=i;j<=n;j++){
            if( td[i]->ngay_thi_dau<td[j]->ngay_thi_dau){
                swap(td[i],td[j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        td[i]->output();
    }
}
void sort_san_thi_dau(trandau *td[], int  n){

     for( int i=0; i<n;i++){
        for( int j=i;j<=n;j++){
            if( td[i]->san_thi_dau<td[j]->san_thi_dau){
                swap(td[i],td[j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        td[i]->output();
    } 
}
void xoa_trandau(trandau *td[], int  n){
    string tendoi, ngay_dau;
    
    int find = 0;
    cout << "\nNhap ten 2 doi can tim: "; fflush(stdin); getline(cin,tendoi);
    cout << "\nNhap ngay dau doi can tim: "; fflush(stdin); getline(cin,tendoi);
    for (int i = 0; i < n; i++)
    {
        if (td[i]->ten_hai_doi_bong == tendoi  && td[i]->ngay_thi_dau==ngay_dau)
        {
              find = 1;
            for (int j = i; j <= n; j++)
            {
                td[j] = td[j+1];
               
            }
        }
    }
    
    
    if (find == 1)
    {
        cout << "\nDa xoa tran dau  : "<<tendoi<<" vao ngay: "<<ngay_dau;
        
    }
    else
    {
        cout << "\nXoa khong thanh cong";
    }
}

