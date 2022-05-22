#include<iostream>
#include <string>
using namespace std;
class quanly{
    private:
        string hoten;
        int ngaysinh;
        string gioitinh;
        string quequan;
        string trinhdo;
    public:
        virtual void input(){
            cout<<"\n thong tin:";
            cin.ignore();
            cout<<"\n  ho ten:";fflush(stdin);getline(cin,hoten);
            cout<<"\n ngay sinh:";cin>>ngaysinh;
            cin.ignore();
            cout<<"\n gioi tinh:";fflush(stdin);getline(cin,gioitinh);
            cout<<"\n que quan:";fflush(stdin);getline(cin,quequan);
            cout<<"\n trinh do:";fflush(stdin);getline(cin,trinhdo);
        }
        virtual void output(){
            cout<<endl<<"ho ten:"<<hoten<<"\t"<<"ngay sinh:"<<ngaysinh<<"\t"<<"gioi tinh:"<<gioitinh<<"\t"<<"que quan:"<<quequan<<"\t"<<"trinh do:"<<trinhdo<<endl;
        }
};
class nhanvienchinhthuc:public quanly{
    private:
        int manhanvien;
        string chucvu;
        float hesoluong;
        int phucapchucvu;
        int tienantrua;
        int thuclinh;
    public:
        void input(){
            quanly::input();
            cout<<"\n ma nhan vien:";cin>>manhanvien;
            cin.ignore();
            cout<<"\n chuc vu:";fflush(stdin);getline(cin,chucvu);
            cout<<"\n he so luong:";cin>>hesoluong;
            cout<<"\n phu cap chuc vu:";cin>>phucapchucvu;
            cout<<"\n tien an trua:";cin>>tienantrua;
            cout<<"\n thuc linh:";cin>>thuclinh;
            cout<<"\n ----------------------------";
        }
        void output(){
            quanly::output();
            cout<<endl<<"ma nhan vien:"<<manhanvien<<"\t"<<"chuc vu:"<<chucvu<<"\t"<<":"<<hesoluong<<"\t"<<"phu cap chuc vu:"<<phucapchucvu<<"\t"<<"tien an trua:"<<tienantrua<<"\t"<<"thuc linh:"<<thuclinh<<endl;
        }
        bool operator > (nhanvienchinhthuc &c){
            return(thuclinh > c.thuclinh);
        }
};
class nhanvienhopdong:public quanly{
    private:
        int tienluong;
        int ngay,thang,nam;
        
    public:
        void input(){
            quanly::input();
            cout<<"\n tien luong:";cin>>tienluong;
            cout<<"\n thoi gian ky ket hop dong:",cin>>ngay>>thang>>nam;
            cout<<"\n thoi gian ket thuc hop dong:";cin>>ngay>>thang>>nam;
            cout<<"\n ----------------------------";
        }
        void output(){
            quanly::output();
            cout<<endl<<"tien luong:"<<tienluong<<"\t"<<"thoi han dang ky hop dong:"<<ngay<<"-"<<thang<<"-"<<nam<<"\t"<<"thoi han ket thuc hop dong:"<<ngay<<"-"<<thang<<"-"<<nam<<endl;
        }
        bool operator > (nhanvienhopdong &p){
            return(tienluong > p.tienluong);
        }
};
int main(){
    int i,j,n=3;
    quanly *p1[3],*p2[3];
    for(i=0; i<n; i++)
    {
        p1[i]= new nhanvienchinhthuc;
        p1[i]->input();
    }
    // sap xep
    for(i=0; i<n-1; i++)
    for(j=i+1; j<n; j++)
    if((nhanvienchinhthuc&)*p1[i] > (nhanvienchinhthuc&)*p1[j])
    swap(p1[i],p1[j]);
    cout<<"\n sau khi sap xep:";
    for(i=0; i<n; i++)
    {
        p1[i]->output();
    }

    for(i=0; i<n; i++)
    {
        p2[i]= new nhanvienhopdong;
        p2[i]->input();
    }
    // sap xep
    for(i=0; i<n-1; i++)
    for(j=i+1; j<n; j++)
    if((nhanvienhopdong&)*p2[i] > (nhanvienhopdong&)*p2[j])
    swap(p2[i],p2[j]);
    cout<<"\n sau khi sap xep luong:";
    for(i=0; i<n; i++)
    {
        p2[i]->output();
    }
    return 0;
};
