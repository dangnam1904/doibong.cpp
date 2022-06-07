#include<iostream>
#include<conio.h>
#include<string.h>
#include<string>
// NGUYỄN ĐÌNH QUỐC CƯỜNG
// LƯƠNG HỮU QUYẾT
// ĐẶNG VĂN NAM
using namespace std;
class ThuVien
{
private:
    int SoNgayMuonSach;
public:
    virtual int TinhTienThueSach()
    {
        return 0;
    }
};

class QuanLyThueSach 
{
private:
    string TenSach;
    string TacGia;
    int MaSach;
    int SoLuong;
    int SoSachChoMuon;
public:
    //Ham thiet lap
    QuanLyThueSach()
    {
        this->TenSach = "";
        this->TacGia = "";
        this->MaSach = 0;
        this->SoLuong = 0;
        this->SoSachChoMuon = 0;
    }
     // nhap du lieu sach
    void NhapThongTinSach()
    {
        while (getchar() != '\n');
        cout << "\nNhap ma sach: "; cin >> MaSach;
        while (getchar() != '\n');
        cout << "Nhap ten sach: "; getline(cin, TenSach);
        cout << "Nhap ten tac gia: "; getline(cin, TacGia);
        cout << "Nhap tong so sach: "; cin >> SoLuong;
        cout << "Nhap so sach da cho muon: "; cin >> SoSachChoMuon;
    }
    // in ra thong tin sach
    void XuatThongTin()
    {
        cout << "\n--------------------------------";
        cout << "\nMa sach: " << MaSach;
        cout << "\nTen sach: " << TenSach;
        cout << "\nTen tac gia:"<<TacGia;
        cout << "\nTong so sach: " << SoLuong;
        cout << "\nSo sach cho muon: " << SoSachChoMuon;
        cout << "\nSo sach con lai: " << SoSachConLai();
    }
    int SoSachConLai()
    {
        return (SoLuong - SoSachChoMuon);
    }
    friend void Tim_Sach(QuanLyThueSach *ds_ql[], int n);
    friend void Xoa_1_sach(QuanLyThueSach* ds_ql[], int n);
    friend void capnhatsach(QuanLyThueSach*ds_ql[], int n);
};
void XuatThongTinSach(QuanLyThueSach* ds_ql[], int n)
{
    cout << "\n\n\t\t--DANH SACH THONG TIN SACH--\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\n\t\t------THONG TIN SACH " << i + 1 << "------\n";
        ds_ql[i]->XuatThongTin();
    }
}
void Tim_Sach(QuanLyThueSach *ds_ql[], int n)
{
    int Tim;
    int i;
    int find = 0;
    cout << "\nNhap ma sach can tim: "; cin >> Tim;
    for (i = 0; i < n; i++)
    {
        if (ds_ql[i]->MaSach == Tim)
        {
            cout << "\nDa tim thay";
            ds_ql[i]->XuatThongTin();
            find = 1;
        }
    }
    if (find == 0)
    {
        cout << "\nKhong tim thay sach co ma nay!";
    }
}
void Xoa_1_sach(QuanLyThueSach* ds_ql[], int n)
{
    int sai = 0;
    int masach;
    cout << "\nNhap ma sach can xoa: "; cin >> masach;
    for (int i = 0; i < n; i++)
    {
        if (ds_ql[i]->MaSach == masach)
        {
            for (int j = i + 1; j < n; j++)
            {
                ds_ql[i - 1] = ds_ql[i];
                sai = 1;
            }
        }
    }
    if (sai == 1)
    {
        cout << "\nDa xoa tai khoan thanh cong";
        n--;
    }
    else
    {
        cout << "\nNhap ma sach sai! Xoa khong thanh cong";
    }
}

void capnhatsach(QuanLyThueSach *ds_ql[],int n)
{
    int found =1;
    int ma;
    cout<<" nhap ma sach can cap nhat:"; cin >>ma;
    for (int i=0; i<n; i++)
    {
          if (ds_ql[i]->MaSach=ma)
          {
              found=0;
              cout<<"\n Cap nhat thong tin ma sach:\n"<<ma;
              ds_ql[i]->NhapThongTinSach();
          }
          else
          {
              found = 1;
          cout <<"\n  khong tim thay ma sach\n ";
          }
    }
}







class KhachHangThueSach :public QuanLyThueSach
{
private:
    
    string Ten;
    string NgaySinh;
    int CMND;
    string SDT;
    string QueQuan;
    string UserName;
    string Password;
public:
    KhachHangThueSach()
    {
        this->Ten = "";
        this->NgaySinh = "";
        this->CMND = 0;
        this->SDT = "";
        this->QueQuan = "";
        this->UserName = "";
        this->Password = "";
    }
    void Input()
    {
        while (getchar() != '\n');
        cout << "\nNhap ho ten: "; getline(cin, Ten);
        cout << "\nNhap ngay sinh: "; getline(cin, NgaySinh);
        cout << "\nNhap chung minh nhan dan: "; cin>>CMND;
        while (getchar() != '\n');
        cout << "\nNhap so dien thoai: "; getline(cin, SDT);
        cout << "\nNhap que quan: "; getline(cin, QueQuan);
        cout << "\nNhap ten dang nhap: "; getline(cin, UserName);
        cout << "\nNhap mat khau: "; getline(cin, Password);
    }
    void Output()
    {
        cout << "\nHo ten: " << Ten;
        cout << "\nNgay sinh: " << NgaySinh;
        cout << "\nCMND: " << CMND;
        cout << "\nSo dien thoai: " << SDT;
        cout << "\nQue quan: " << QueQuan;
    }
    void login(string user,string pass)
    {
        if (UserName == user || Password == pass)
        {
            cout << "\nDang nhap thanh cong";
            cout << "\n--------" << UserName << "---------";
        }
        else
        {
            cout<<"\n Khong tim thay account\n ";
        }
    }
    void DangNhap(KhachHangThueSach* ds_kh[], int m);
    friend void XoaTaiKhoan(KhachHangThueSach* ds_kh[], int m);
    friend void capnhat_tk(KhachHangThueSach *ds_kh[], int m);
    friend  void cap_tk(KhachHangThueSach * ds_kh[], int m);
    
};

void KhachHangThueSach::DangNhap(KhachHangThueSach* ds_kh[], int m)
{
    int i;
    int find = 0;
    string user;
    while (getchar() != '\n');
    cout << "\nTai Khoan: "; getline(cin, user);
    string pass;
    cout << "\nMat Khau: "; getline(cin, pass);
    for (i = 0; i < m; i++)
    {
        ds_kh[i]->login(user,pass);
        find = 1;
    }    
    if (find == 0)
    {
        cout << "\nThong tin Tai khoan hoac Mat khau sai!";
    }
}

void capnhat_tk(KhachHangThueSach* ds_kh[], int m)
{
    int so_cmm;
    cout<<"nhap so cmnd:";  cin >>so_cmm;
    int find =0;
 for (int i=0; i<m; i++)
 {
     if  (ds_kh[i]->CMND==so_cmm)
     {
         find =1;
         cout<<"\n ========TRUNG KHOP=======\n";
         ds_kh[i]->Input();
     }
     else
     {
         find =0;
         cout<<" \n khong co so cmnd trung khop\n";
     }
 }

 
}


void XoaTaiKhoan(KhachHangThueSach* ds_kh[], int m)
{
    int sai = 0;
    string user;
    cout << "\nNhap tai khoan va mat khau can xoa";
    while (getchar() != '\n');
    cout << "\nTai Khoan: "; getline(cin, user);
    string pass;
    cout << "\nMat Khau: "; getline(cin, pass);
    for (int i = 0; i < m; i++)
    {
        if (ds_kh[i]->UserName == user || ds_kh[i]->Password == pass)
        {
            for (int j = i + 1; j < m; j++)
            {
                ds_kh[i - 1] = ds_kh[i];
                sai = 1;
            }
        }
    }
    if (sai == 1)
    {
        cout << "\nDa xoa tai khoan thanh cong";
        m--;
    }
    else
    {
        cout << "\nNhap sai! Xoa khong thanh cong";
    }

}


void XuatThongTinTaiKhoan(KhachHangThueSach* ds_kh[], int m)
{
    for (int i = 0; i < m; i++)
    {
        cout << "\n\t\t------TAI KHOAN THU  " << i + 1 << "------\n";
        ds_kh[i]->Output();
    }
}


void menu(QuanLyThueSach *ds_ql[], int &n, KhachHangThueSach *ds_kh[], int &m)
{
    int luachon;

    while (true)
    {
        system("cls");
        cout << "\t---------------THU VIEN---------------";
        cout << "\n\t1. QUAN LY THUE SACH";
        cout << "\n\t2. KHACH HANG THUE SACH";
        cout << "\n\t0. THOAT";

        cout << "\nNhap lua chon: "; cin >> luachon;

        if (luachon == 1)
        {
            int luachon1;

            while (true)
            {
                system("cls");
                cout << "\t---------------QUAN LY THUE SACH---------------";
                cout << "\n\t1. Nhap thong tin quyen sach";
                cout << "\n\t2. Hien thi thong tin quyen sach";
                cout << "\n\t3. Tim kiem thong tin 1 quyen sach";
                cout << "\n\t4. Sua thong tin cac quyen sach";
                cout << "\n\t5. Cap tai khoan cho thue sach";
                cout << "\n\t6. Xac nhan va in hoa don cho thue sach";
                cout << "\n\t7. Xac nhan tra sach";
                cout << "\n\t8. Hien thi thong tin nhung nguoi thue sach";
                cout << "\n\t9. ket thuc";

                cout << "\nNhap lua chon: "; cin >> luachon1;

                if (luachon1 == 1)
                {
                    QuanLyThueSach *x = new QuanLyThueSach();
                    cout << "\n\n\t\t--NHAP THONG TIN SACH--\n";
                    x->NhapThongTinSach();
                    ds_ql[n] = x;
                    n++;
                }
                else if (luachon1 == 2)
                {
                    XuatThongTinSach(ds_ql, n);
                    system("pause");
                }
                else if (luachon1 == 3)
                {
                    Tim_Sach(ds_ql, n);
                    system("pause");
                }
                else if (luachon1 == 4)
                {
                    int luachon2;
                    while (true)
                    {
                        system("cls");
                        cout << "\n\t1.Xoa sach";
                        cout << "\n\t2.Them sach";
                        cout <<"\n\t3.Cap nhat";
                        cout << "\n\t0.Thoat";

                        cout << "\nNhap lua chon: "; cin >> luachon2;

                        if (luachon2 == 1)
                        {
                            Xoa_1_sach(ds_ql, n);
                            system("pause");
                        }
                        else if (luachon2 == 2)
                        {
                            QuanLyThueSach* x = new QuanLyThueSach();
                            cout << "\n\n\t\t--NHAP THONG TIN SACH--\n";
                            x->NhapThongTinSach();
                            ds_ql[n] = x;
                            n++;
                        }
                        
                        else if (luachon2 ==3)
                        {
                            QuanLyThueSach * x= new QuanLyThueSach();
                            cout<<"\n\n\t\t-- CAP NHAT THONG TIN SACH----\n";
                            capnhatsach(ds_ql, n);
                            ds_ql[n] = x;
                        }
                        
                        else
                        {
                            break;
                        }
                    }
                }
                else if (luachon1 == 5)
                {
                    KhachHangThueSach *x = new KhachHangThueSach();
                    cout << "\n\n\t\t--CAP TAI KHOAN--\n";
                    x->Input();
                    ds_kh[m] = x;
                    m++;
                    system("pause");
                }
                else if (luachon1 == 6)
                {

                }
                else if (luachon1 == 7)
                {

                }
                else if (luachon1 == 8)
                {

                }
                else
                {
                    break;
                }

            }
        }
        else if (luachon == 2)
        {
            int luachon1;

            while (true)
            {
                system("cls");
                cout << "\t---------------KHACH HANG THUE SACH---------------";
                cout << "\n\t1. Tao tai khoan thue sach";
                cout << "\n\t2. Dang nhap tai khoan";
                cout << "\n\t3. Sua thong tin tai khoan";
                cout << "\n\t4. Hien thi thong tin quyen sach";
                cout << "\n\t5. Tim kiem sach";
                cout << "\n\t6. Dat thue sach";
                cout << "\n\t7. Tra sach thue";
                cout << "\n\t8. Hien thi lich su thue/tra sach";
                cout << "\n\t9. Ket thuc";

                cout << "\nNhap lua chon: "; cin >> luachon1;
                if (luachon1 == 1)
                {
                    KhachHangThueSach *x = new KhachHangThueSach();
                    cout << "\n\n\t\t--DANG KY TAI KHOAN--\n";
                    x->Input();
                    ds_kh[m] = x;
                    m++;
                }
                else if (luachon1 == 2)
                {
                    KhachHangThueSach *x = new KhachHangThueSach();
                    x->DangNhap(ds_kh, m);
                    system("pause");
                }
                else if (luachon1 == 3)
                {
                    int luachon2;
                    while (true)
                    {
                        system("cls");
                        cout << "\n\t1.Xoa 1 Tai Khoan";
                        cout << "\n\t2.Them 1 Tai Khoan";
                        cout <<"\n\t3. Cap nhat tai khoan";
                        cout << "\n\t0.Thoat";

                        cout << "\nNhap lua chon: "; cin >> luachon2;

                        if (luachon2 == 1)
                        {                            
                            XoaTaiKhoan(ds_kh, m);
                            cout << "\n\t\t\n---DANH SACH TAI KHOAN CON LAI---";
                            XuatThongTinTaiKhoan(ds_kh, m);
                            system("pause");
                        }
                        else if (luachon2 == 2)
                        {
                            KhachHangThueSach* x = new KhachHangThueSach();
                            cout << "\n\n\t\t--DANG KY TAI KHOAN--\n";
                            x->Input();
                            ds_kh[m] = x;
                            m++;
                        }
                        else if (luachon2 ==3)
                        {
                            KhachHangThueSach *x= new KhachHangThueSach();
                            cout <<"\n\n\t\t---CAP NHAT THONG TIN--\n";
                              capnhat_tk(ds_kh,m);
                              ds_kh[m]=x;
                        }

                        else
                        {
                            break;
                        }
                    }
                }
                else if (luachon1 == 4)
                {
                    XuatThongTinSach(ds_ql, n);
                    system("pause");
                }
                else if (luachon1 == 5)
                {
                    Tim_Sach(ds_ql, n);
                    system("pause");
                }
                else if (luachon1 == 6)
                {  Tim_Sach(ds_ql,n);
                    int sl_can_muon;
                    cout <<"\n so luong can muon:"; cin >> sl_can_muon;


                }
                else if (luachon1 == 7)
                {

                }
                else if (luachon1 == 8)
                {

                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            break;
        }
    }
}

int main()
{
    QuanLyThueSach *ds_ql[100];
    KhachHangThueSach *ds_kh[100];
    int n = 0;
    int m = 0;
    menu(ds_ql, n, ds_kh, m);
    system("pause");
    delete ds_ql;
    delete ds_kh;
    return 0;
}
