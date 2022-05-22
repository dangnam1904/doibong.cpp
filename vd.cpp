
#include <iostream>
#include <conio.h>
#include<string.h>
#include<stdio.h>
using namespace std;

class Date{

int ngay, thang, nam;
public:
Date(int d=0, int m=0, int y=0);
void hienthi() const;
void nhap();
int operator >(Date);
Date cong (int songay);
Date cong_n (Date);
void set(int d, int m, int y);
int layngay() {return ngay;}
int laythang() {return thang;}
int laynam() {return nam;}
void chuanhoa();
static int songay(int m, int y);
};

Date::Date(int d, int m, int y)
{
ngay = d;
thang = m;
nam = y;
}

void Date::hienthi() const
{
    cout<< ngay << "/" << thang <<"/" << nam;
    
}

void Date::nhap()
{
cout<< "Nhap ngay: ";cin >> ngay;
cout<< "Nhap thang: ";cin >> thang;
cout<< "Nhap nam: ";cin >> nam;
}

Date Date::cong(int songay)
{
Date kq(ngay+songay, thang, nam);
kq.chuanhoa();
return kq;
}

Date Date::cong_n (Date d)
{
Date kq(ngay + d.ngay, thang + d.thang, nam + d.nam);
kq.chuanhoa();
return kq;
}

int Date ::operator > (Date d)
{
    if (nam != d.nam)
        return (nam > d.nam);
    else if (thang != d.thang)
        return (thang > d.thang);
        return (ngay > d.ngay);
}

void Date::chuanhoa()
{
while (songay(thang, nam) < ngay)
{
ngay -= songay(thang ,nam);
thang++;
}
nam += (thang / 12);
thang %= 12;
}

int Date::songay(int m, int y)
{
switch (m)
{
case 1:
case 3:
case 5:
case 7:
case 8:
case 10:
case 12:
return 31;

case 4:
case 6:
case 9:
case 11:
return 30;

default:
if ((y % 4) == 0)
return 29;
else
return 28;
}
}


class Cauthu
{
char socmnd[9];
char *hoten;
char *quoctich;
Date ngaysinh;
float chieucao;
float cannang;
char *vtthidau;
public:

Cauthu()
: ngaysinh(){
strcpy(socmnd, "");
hoten = new char[50];strcpy(hoten, "");
quoctich = new char[50];strcpy(quoctich, "");
chieucao = cannang=0;
vtthidau = new char[50];strcpy(vtthidau,"");
}

Cauthu(char* cm, char* ht, char* qt, Date ns, float c,float n,char*vt): ngaysinh(ns){

    strcpy(socmnd,cm);
    hoten = strdup(ht);
    qt = strdup(quoctich);
    chieucao = c;
    cannang = n;
    vt = strdup(vtthidau);
}

Cauthu(const Cauthu& ct)
: ngaysinh(ct.ngaysinh){

strcpy(socmnd,ct.socmnd);
hoten = strdup(ct.hoten);
quoctich = strdup(ct.quoctich);
chieucao = ct.chieucao;
cannang = ct.cannang;
vtthidau = strdup(ct.vtthidau);
}


void operator= (const Cauthu& ct){

strcpy(socmnd,ct.socmnd);
hoten = strdup(ct.hoten);
quoctich = strdup(ct.quoctich);
ngaysinh = ct.ngaysinh;
chieucao = ct.chieucao;
cannang = ct.cannang;
vtthidau = strdup(ct.vtthidau);

}

~Cauthu()
{ delete[] hoten; delete[] quoctich; delete[] vtthidau; }

void Nhap(){
cout<< "\nNhap so chung minh nhan dan: ";gets_s(socmnd);
cout<< "\nNhap ho ten: ";gets_s(hoten);
cout<< "\nNhap quoc tich :";gets(quoctich);
cout<< "\nNhap ngay sinh: " << endl;
fflush(stdin);
ngaysinh.nhap();
cout<< "\nChieu cao: ";cin >> chieucao;
cout<<"\nNhap can nang: ";cin>>cannang;
cout<<"Nhap vi tri thi dau: ";gets(vtthidau);
}

void In(){

cout<<socmnd<<"\t"<<hoten<<"\t"<<quoctich<<"\t"<<chieucao<<"\t"<<cannang<<"\t"<<vtthidau<<"\n";
}


char* laysocmnd() { return socmnd; }
char* layhoten() { return hoten; }
char* layquoctich() { return quoctich; }
Date layngaysinh() { return ngaysinh; }
float laychieucao() { return chieucao; }
float laycannang() { return cannang; }
char* layvtthidau() { return vtthidau; }
};

class Doibong
{
char* ten;
char* diaphuong;
char* huanluyenvien;
Cauthu danhsach;
public:
    Doibong():danhsach(){

    ten = new char[50];
    diaphuong = new char[50];
    huanluyenvien = new char[50];

    }
    Doibong(char* t,char* dp,char* hlv,Cauthu ds)
    :danhsach(ds){

    ten = new char[50]; strcpy(ten,t);
    diaphuong = new char[50]; strcpy(diaphuong,dp);
    huanluyenvien = new char[50]; strcpy(huanluyenvien,hlv);

    }
    Doibong(const Doibong & db):danhsach(db.danhsach){

    ten = new char[50]; strcpy(ten,db.ten);
    diaphuong = new char[50]; strcpy(diaphuong,db.diaphuong);
    huanluyenvien = new char[50]; strcpy(huanluyenvien,db.huanluyenvien);

    }
    void operator=(const Doibong & db){
    ten = new char[50]; strcpy(ten,db.ten);
    diaphuong = new char[50]; strcpy(diaphuong,db.diaphuong);
    huanluyenvien = new char[50]; strcpy(huanluyenvien,db.huanluyenvien);
    danhsach=db.danhsach;
    }
void Nhap(){
cout<< "\nNhap so chung minh nhan dan: ";gets(socmnd);
cout<< "\nNhap ho ten: ";gets(hoten);
cout<< "\nNhap quoc tich :";gets(quoctich);
cout<< "\nNhap ngay sinh: " << endl;
fflush(stdin);
ngaysinh.nhap();
cout<< "\nChieu cao: ";cin >> chieucao;
cout<<"\nNhap can nang: ";cin>>cannang;
cout<<"Nhap vi tri thi dau: ";gets(vtthidau);
}

};

class Trandau
{
};



int main(){

    int n;
    cout << "Nhap so cau thu: "; cin >> n;
    Cauthu *ds=new Cauthu[n];
    for (int i=0; i<n; i++)
    {
    cout << endl << " Nhap thong tin cho cau thu " << (i+1) << endl;
    ds[i].Nhap(); }
//tim cau thu cao nhat trong danh sach

// float maxChieucao=0;
// for ( i=1; i<n; i++)
// if (ds[i].laychieucao() > ds[maxChieucao].laychieucao())
// maxChieucao = i;

// cout << "-----------------------" << endl;
// cout << "Cau thu cao nhat la: " << endl;
// // ds[maxChieucao].In();
  cout<<"\n CMND\t Ho ten\t quoctich\t ngay sinh \tchieu cao\t can nang\t vtr thi dau\t\n";
     for (int i=0; i<n; i++)
    {
    
    ds[i].In();
    }
    Doibong bn;
    
return 0;
}