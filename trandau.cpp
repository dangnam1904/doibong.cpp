#include<iostream>
#include <string>
#include <iomanip>
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
           
            
            cout<<setw(30)<<left<<ngay_thi_dau<<setw(30)<<left<<san_thi_dau<<setw(30)<<left<<ten_hai_doi_bong<<setw(30)<<left<<ti_so<<"\n";

        }
        friend void tim_kiem_ngay_thi_dau(trandau *td[], int  k);
        friend void tim_kiem_san_thi_dau(trandau *td[], int  k);
        friend void tim_kiem_ten_hai_doi_bong(trandau *td[], int  k);
        friend void  sua_thong_tin_tran_dau(trandau *td[], int  k);
        friend void xoa_trandau(trandau *td[], int  &k);
        friend void sort_san_thi_dau(trandau *td[], int  k);
        friend void sort_ngay_thi_dau(trandau *td[], int  k);
        friend void read_data_trandau(ifstream &filein,trandau *td[],int &k);
        friend void write_data_trandau(ofstream &fileout,trandau *td[],int &k);
        friend void write_data_cauthu_cuoifile(ofstream &fileout,trandau *td[],int &k);
    
};

void read_data_trandau(ifstream &filein,trandau *td[],int &k){
     int i=0;
    while (filein.eof()==false){
        td[i]= new trandau();
       getline(filein,td[i]->ngay_thi_dau,',');
       getline(filein,td[i]->san_thi_dau,',');
       getline(filein,td[i]->ten_hai_doi_bong,',');
       getline(filein,td[i]->ti_so,'\n');
       i++;
       k++;
    }
}

void write_data_trandau(ofstream &fileout,trandau *td[],int &k){
    for( int i=0; i<k;i++){
        if(k-i==1){
        fileout<< td[i]->ngay_thi_dau<<","<<td[i]->san_thi_dau<<","<<td[i]->ten_hai_doi_bong<<","<<td[i]->ti_so;
        }
        else{
        fileout<< td[i]->ngay_thi_dau<<","<<td[i]->san_thi_dau<<","<<td[i]->ten_hai_doi_bong<<","<<td[i]->ti_so<<endl;        }
    }
}


void write_data_cauthu_cuoifile(ofstream &fileout,trandau *td[],int &k){
     fileout<<"\n";
     for( int i=0; i<k;i++){
        if(k-i==1){
        fileout<< td[i]->ngay_thi_dau<<","<<td[i]->san_thi_dau<<","<<td[i]->ten_hai_doi_bong<<","<<td[i]->ti_so;
        }
        else{
        fileout<< td[i]->ngay_thi_dau<<","<<td[i]->san_thi_dau<<","<<td[i]->ten_hai_doi_bong<<","<<td[i]->ti_so<<endl;        }
    }
}
void tim_kiem_ngay_thi_dau(trandau *td[], int  k){
    string ngay_dau;
    int i;
    int find = 0;
    cout << "\nNhap ngay thi dau  doi can tim: "; fflush(stdin); getline(cin,ngay_dau);
    cout<<setw(30)<<left<<"Ngay thi dau"<<setw(30)<<left<<"San thi dau"<<setw(30)<<left<<"Ten hai doi"<<setw(30)<<left<<"Ti so"<<"\n"; 
    for (i = 0; i < k; i++)
    {
        if (td[i]->ngay_thi_dau == ngay_dau)
        {
          
            td[i]->output();
            find = 1;
        }
    }
    if (find == 0)
    {
        cout << "\nKhong tim thay !";
    }
}

void tim_kiem_san_thi_dau(trandau *td[], int  k){

    string san_dau;
    int i;
    int find = 0;
    cout << "\nNhap san dau can tim: "; fflush(stdin); getline(cin,san_dau);
    cout<<setw(30)<<left<<"Ngay thi dau"<<setw(30)<<left<<"San thi dau"<<setw(30)<<left<<"Ten hai doi"<<setw(30)<<left<<"Ti so"<<"\n"; 
    for (i = 0; i < k; i++)
    {
        if (td[i]->san_thi_dau == san_dau)
        {
          
            td[i]->output();
            find = 1;
        }
    }
    if (find == 0)
    {
        cout << "\nKhong tim thay !";
    }
}

void tim_kiem_ten_hai_doi_bong(trandau *td[], int  k){
    string ten2doi;
    int i;
    int find = 0;
    cout << "\nNhap san dau can tim: "; fflush(stdin); getline(cin,ten2doi);
    cout<<setw(30)<<left<<"Ngay thi dau"<<setw(30)<<left<<"San thi dau"<<setw(30)<<left<<"Ten hai doi"<<setw(30)<<left<<"Ti so"<<"\n"; 
    for (i = 0; i < k; i++)
    {
        if (td[i]->ten_hai_doi_bong == ten2doi)
        {
          
            td[i]->output();
            find = 1;
        }
    }
    if (find == 0)
    {
        cout << "\nKhong tim thay !";
    }
}

void  sua_thong_tin_tran_dau(trandau *td[], int  k){
    string tendoi, ngay_dau;
    
    int find = 0;
    cout << "\nNhap ten 2 doi can tim: "; fflush(stdin); getline(cin,tendoi);
    cout << "\nNhap ngay dau doi can tim: "; fflush(stdin); getline(cin,tendoi);
    
    for (int i = 0; i < k; i++)
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
void sort_ngay_thi_dau(trandau *td[], int  k){
     for( int i=0; i<k;i++){
        for( int j=i;j<=k;j++){
            if( td[i]->ngay_thi_dau<td[j]->ngay_thi_dau){
                swap(td[i],td[j]);
            }
        }
    }
    cout<<setw(30)<<left<<"Ngay thi dau"<<setw(30)<<left<<"San thi dau"<<setw(30)<<left<<"Ten hai doi"<<setw(30)<<left<<"Ti so"<<"\n"; 
    for(int i=0;i<k;i++){
        td[i]->output();
    }
}
void sort_san_thi_dau(trandau *td[], int k){

     for( int i=0; i<k;i++){
        for( int j=i;j<=k;j++){
            if( td[i]->san_thi_dau<td[j]->san_thi_dau){
                swap(td[i],td[j]);
            }
        }
    }
    cout<<setw(30)<<left<<"Ngay thi dau"<<setw(30)<<left<<"San thi dau"<<setw(30)<<left<<"Ten hai doi"<<setw(30)<<left<<"Ti so"<<"\n"; 
    for(int i=0;i<k;i++){
        td[i]->output();
    } 
}
void xoa_trandau(trandau *td[], int  &k){
    string tendoi, ngay_dau;
    
    int find = 0;
    cout << "\nNhap ten 2 doi can tim: "; fflush(stdin); getline(cin,tendoi);
    cout << "\nNhap ngay dau doi can tim: "; fflush(stdin); getline(cin,tendoi);
    for (int i = 0; i < k; i++)
    {
        if (td[i]->ten_hai_doi_bong == tendoi  && td[i]->ngay_thi_dau==ngay_dau)
        {
              find = 1;
            for (int j = i; j <=k; j++)
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
    k--;
}

