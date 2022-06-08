#include<iostream>
#include "doibong.cpp"
#include "trandau.cpp"
#include <iomanip>
#include<fstream>
using namespace std;

void menu(cauthu *ct[], int &n, doibong *db[], int &m, trandau *td[],int &k)
{

  int choice;
  while(true){
       system("cls");
        cout << "\t---------------QUAN LY GIAI BONG---------------";
        cout << "\n\t1. QUAN LY CAU THU";
        cout << "\n\t2. QUAN LY DOI BONG";
        cout<<"\n\t3. QUAN LY TRAN DAU";
        cout << "\n\t0. THOAT";
        cout << "\nNhap lua chon: "; cin >> choice;
        if(choice==1)
        {
          while (true)
          {
            int choice_1;
            system("cls");
                cout << "\t---------------QUAN LY CAU THU---------------";
                cout << "\n\t1. Them cau thu";
                cout << "\n\t2. Hien thi danh sach cau thu";
                cout << "\n\t3. Tim kiem thong tin cau thu";
                cout << "\n\t4. Sua thong tin  cau thu";
                cout << "\n\t5. Sap xep cau thu";
                cout << "\n\t6. Doc danh sach cau thu tu file";
                cout << "\n\t7. Ghi vao file";
                cout << "\n\t8. Xoa cau thu";
                cout << "\n\t9. ket thuc";

                cout << "\nNhap lua chon: "; cin >> choice_1;
                if( choice_1==1)
                {
                   int a;
                    cout<<"Slg cau thu:";
                    cin>>a;
                    
                    for(int i=0; i<a; i++){
                      cout<<"Cau thu so: "<<i+1<<"\n";
                      cauthu *ct1= new cauthu();
                      ct1->input();
                      ct[n]= ct1;
                      n++;
                    }
                }
                else if( choice_1==2){
                  cout<<"\n-------------------------Danh sach cau thu---------------\n";
                  cout<<setw(30)<<left<<"Ho ten"<<setw(30)<<left<<"Ngay sinh"<<setw(30)<<left<<"CMND"<<setw(30)<<left<<"Quoc tich" <<setw(15)<<left<<"Vi tri dau"<<setw(15)<<left<<"Chieu cao "<<setw(10)<<left<<"Can nang"<<endl;
                    for(int i=0; i<n; i++){
                    
                      ct[i]->output();
                    }
                    system("pause");
                }
                else if(choice_1==3){

                  while (true)
                  {
                        int choice_2;
                        system("cls");
                        cout << "\t---------------TIM KIEM CAU THU---------------";
                        cout << "\n\t1. Theo ten";
                        cout << "\n\t2. Theo CMND";
                        cout << "\n\t3. Theo ten va quoc tich";
                        cout << "\n\t4. Thoat";
                       
                       cout<<"\n Lua chon: "; cin>>choice_2;
                       if(choice_2==1){
                         
                         tim_kiem_ten(ct,n);
                         system("pause");
                       }
                       else if( choice_2==2){
                         tim_kiem_cmnd(ct,n);
                          system("pause");
                       }
                       else if(choice_2==3){
                         tim_kiem_ten_vs_qtich(ct,n);
                         system("pause");
                       }
                       else if(choice_2==4){
                         break;
                         system("pause");
                       }

                  }
                }
                else if(choice_1==4){
                  sua_thongtin_cthu(ct,n);
                  system("pause");
                }
                else if(choice_1==5){
                  while (true)
                  {
                        int choice_2;
                        system("cls");
                        cout << "\t---------------SAP XEP CAU THU---------------";
                        cout << "\n\t1. Theo ten";
                        cout << "\n\t2. Theo can nang";
                        cout << "\n\t3. Theo chieu cao";
                        cout << "\n\t4. Thoat";
                       
                       cout<<"\n Lua chon: "; cin>>choice_2;
                       if(choice_2==1){
                         sort_cthu(ct,n);
                         system("pause");
                       }
                       else if( choice_2==2){
                         sort_cthu_can_nang(ct,n);
                          system("pause");
                       }
                       else if(choice_2==3){
                         sort_cthu_chieucao(ct,n);
                         system("pause");
                       }
                       else if(choice_2==4){
                         break;
                         system("pause");
                       }

                  }
                }
                else if(choice_1==6){
                  ifstream FileIn;
	                FileIn.open("C:\\Code\\C++\\doibong.cpp\\cauthu.txt", ios_base::in);
                  if(!FileIn)
                  {
                  cout << "Error: file not opened." << endl;
                  
                  }
                  else{
                    cout << "Succes" << endl;

                    read_data_cauthu(FileIn,ct,n);
                    FileIn.close();
                  }
                  system("pause");
                }
                
                else if(choice_1==7){
                  ofstream fileout;
                  while (true){
                      int choice_3;
                        system("cls");
                        cout << "\t---------------GHI DU LIEU---------------";
                        cout << "\n\t1. GHI DE";
                        cout << "\n\t2. THEM CUOI FILE";
                         cout << "\n\t0. THOAT";
                       cout<<"\n Lua chon: "; cin>>choice_3;
                       if( choice_3==1){
                          fileout.open("C:\\Code\\C++\\doibong.cpp\\c.txt", ios_base::out);
                  
                          write_data_cauthu(fileout,ct,n);
                          fileout.close();
                       }
                       else if(choice_3==2){
                          fileout.open("C:\\Code\\C++\\doibong.cpp\\c.txt", ios_base::app);
                  
                          write_data_cauthu_cuoifile(fileout,ct,n);
                          fileout.close();
                       }
                       else if(choice_3==0){
                         break;
                       }
                  }
	                
                  system("pause");
                }
                 else if(choice_1==8){
                  xoa_cthu(ct,n);
                  system("pause");
                }
                else if(choice_1==9){
                  break;
                }
          }

        }
        else if(choice==2)
        {
          while(true)
          {
              int choice_1;
              system("cls");
                cout << "\t---------------QUAN LY DOI BONG---------------";
                cout << "\n\t1. Them doi bong";
                cout << "\n\t2. Hien thi danh sach doi bong";
                cout << "\n\t3. Tim kiem thong tin doi bong";
                cout << "\n\t4. Sua thong tin  doi bong";
                cout << "\n\t5. Sap xep doi bong";
                cout << "\n\t6. Doc danh sach doi bong tu file";
                cout << "\n\t7. Ghi vao file";
                cout << "\n\t8. Xoa doi bong";
                cout << "\n\t9. ket thuc";

                cout << "\nNhap lua chon: "; cin >> choice_1;

              if( choice_1==1)
                {
                   int a;
                    cout<<"So luong doi bong:";
                    cin>>a;
                    
                    for(int i=0; i<a; i++){
                      cout<<"Doi bong so: "<<i+1<<"\n";
                      doibong *db1 = new doibong();
                      db1->input();
                      db[m]=db1;
                      m++;
                    }
                }
                else if( choice_1==2){
                  cout<<"\n-------------------------Danh sach doi bong---------------\n";
                  //cout<<setw(30)<<left<<"Ten doi"<<setw(30)<<left<<" Dia phuong "<<setw(30)<<left <<"Huan luyen vien"<<"\n"; 
                    for(int i=0; i<m; i++){
                      cout<<setw(30)<<left<<"Ten doi"<<setw(30)<<left<<" Dia phuong "<<setw(30)<<left <<"Huan luyen vien"<<"\n"; 

                      db[i]->output();
                    }
                    system("pause");
                    
                }
                else if(choice_1==3){

                  while (true)
                  {
                        int choice_2;
                        system("cls");
                        cout << "\t---------------TIM KIEM DOI BONG---------------";
                        cout << "\n\t1. Theo ten doi";
                        cout << "\n\t2. Theo dia phuong";
                        cout << "\n\t3. Theo huan luyen vien";
                        cout << "\n\t4. Thoat";
                       
                       cout<<"\n Lua chon: "; cin>>choice_2;
                       if(choice_2==1){
                         tim_kiem_ten_doi(db,m);
                         system("pause");
                       }
                       else if( choice_2==2){
                         tim_kiem_dia_phuong(db,m);
                          system("pause");
                       }
                       else if(choice_2==3){
                         tim_kiem_huanluyenvien(db,m);
                         system("pause");
                       }
                       else if(choice_2==4){
                         break;
                         system("pause");
                       }

                  }
                }
                else if(choice_1==4){
                  sua_thongtin_db(db,m);
                  system("pause");
                }
                else if(choice_1==5){
                  while (true)
                  {
                        int choice_2;
                        system("cls");
                        cout << "\t---------------SAP XEP DOI BONG---------------";
                       cout << "\n\t1. Theo ten doi";
                        cout << "\n\t2. Theo dia phuong";
                        cout << "\n\t3. Theo huan luyen vien";
                        cout << "\n\t4. Thoat";
                       
                       cout<<"\n Lua chon: "; cin>>choice_2;
                       if(choice_2==1){
                         sort_doibong_ten_doi(db,m);
                         system("pause");
                       }
                       else if( choice_2==2){
                         sort_doibong_ten_dia_phuong(db,m);
                          system("pause");
                       }
                       else if(choice_2==3){
                         sort_doibong_HLV(db,m);
                         system("pause");
                       }
                       else if(choice_2==4){
                         break;
                         system("pause");
                       }

                  }
                }
                else if(choice_1==6){
                  
                  ifstream FileIn;
	                FileIn.open("C:\\Code\\C++\\doibong.cpp\\doibong.txt", ios_base::in);
                  if(!FileIn)
                  {
                  cout << "Error: file not opened." << endl;
                  
                  }
                  else{
                    cout << "Succes" << endl;

                   read_data_doibong(FileIn,db,m);
                    FileIn.close();
                  }
                  system("pause");
                  
                }
                
                else if(choice_1==7){
                  ofstream fileout;
                  while (true){
                      int choice_3;
                        system("cls");
                        cout << "\t---------------GHI DU LIEU---------------";
                        cout << "\n\t1. GHI DE";
                        cout << "\n\t2. THEM CUOI FILE";
                         cout << "\n\t0. THOAT";
                       cout<<"\n Lua chon: "; cin>>choice_3;
                       if( choice_3==1){
                          fileout.open("C:\\Code\\C++\\doibong.cpp\\w_trandau.txt", ios_base::out);
                  
                          write_data_trandau(fileout,td,n);
                          fileout.close();
                       }
                       else if(choice_3==2){
                          fileout.open("C:\\Code\\C++\\doibong.cpp\\w_trandau.txt", ios_base::app);
                  
                          write_data_cauthu_cuoifile(fileout,td,n);
                          fileout.close();
                       }
                       else if(choice_3==0){
                         break;
                       }
                  }
                  system("pause");
                }
                 else if(choice_1==8){
                  xoa_doibong(db,m);
                  system("pause");
                }
                else if(choice_1==9){
                  break;
                }
          }
              
        }
        else if(choice==3){
          while (true)
          {
            int choice_1;
            system("cls");
                cout << "\t---------------QUAN LY TRAN DAU---------------";
                cout << "\n\t1. Them tran dau";
                cout << "\n\t2. Hien thi danh sach tran dau";
                cout << "\n\t3. Tim kiem thong tin tran dau";
                cout << "\n\t4. Sua thong tin  tran dau";
                cout << "\n\t5. Sap xep tran dau";
                cout << "\n\t6. Doc danh sach tran dau tu file";
                cout << "\n\t7. Ghi vao file";
                cout << "\n\t8. Xoa tran dau";
                cout << "\n\t9. ket thuc";

                cout << "\nNhap lua chon: "; cin >> choice_1;
                if( choice_1==1)
                {
                   int a;
                    cout<<"So luong tran dau:";
                    cin>>a;
                    
                    for(int i=0; i<a; i++){
                      cout<<"Doi bong so: "<<i+1<<"\n";
                     trandau *tr1 = new trandau();
                      tr1->input();
                      td[k]=tr1;
                      k++;
                    }
                }
                else if( choice_1==2){
                  cout<<"\n-------------------------Danh sach tran dau---------------\n";
                  cout<<setw(30)<<left<<"Ngay thi dau"<<setw(30)<<left<<"San thi dau"<<setw(30)<<left<<"Ten hai doi"<<setw(30)<<left<<"Ti so"<<"\n"; 
                    for(int i=0; i<k; i++){
                    
                      td[i]->output();
                    }
                    system("pause");
                }
                else if(choice_1==3){

                  while (true)
                  {
                        int choice_2;
                        system("cls");
                        cout << "\t---------------TIM KIEM TRAN DAU---------------";
                        cout << "\n\t1. Theo ngay thi dau";
                        cout << "\n\t2. Theo san thi dau";
                        cout << "\n\t3. Theo ten hai doi";
                        cout << "\n\t4. Thoat";
                       
                       cout<<"\n Lua chon: "; cin>>choice_2;
                       if(choice_2==1){
                         tim_kiem_ngay_thi_dau(td,k);
                         system("pause");
                       }
                       else if( choice_2==2){
                         tim_kiem_san_thi_dau(td,k);
                          system("pause");
                       }
                       else if(choice_2==3){
                         tim_kiem_ten_hai_doi_bong(td,k);
                         system("pause");
                       }
                       else if(choice_2==4){
                         break;
                         system("pause");
                       }

                  }
                }
                else if(choice_1==4){
                 sua_thong_tin_tran_dau(td,k);
                  system("pause");
                }
                else if(choice_1==5){
                  while (true)
                  {
                        int choice_2;
                        system("cls");
                        cout << "\t---------------SAP XEP TRAN DAU---------------";
                        cout << "\n\t1. Theo ngay";
                        cout << "\n\t2. Theo san thi dau";
                        
                        cout << "\n\t3. Thoat";
                       
                       cout<<"\n Lua chon: "; cin>>choice_2;
                       if(choice_2==1){
                         sort_ngay_thi_dau(td,k);
                         system("pause");
                       }
                       else if( choice_2==2){
                         sort_san_thi_dau(td,k);
                          system("pause");
                       }
                      
                       else if(choice_2==3){
                         break;
                         system("pause");
                       }

                  }
                }
                else if(choice_1==6){
                  ifstream FileIn;
	                FileIn.open("C:\\Code\\C++\\doibong.cpp\\trandau.txt", ios_base::in);
                  if(!FileIn)
                  {
                  cout << "Error: file not opened." << endl;
                  
                  }
                  else{
                    cout << "Succes" << endl;

                   read_data_trandau(FileIn,td,k);
                    FileIn.close();
                  }
                  system("pause");
                 
                }
                
                else if(choice_1==7){
                  
                  system("pause");
                }
                else if(choice_1==8){
                  xoa_trandau(td,k);
                  system("pause");
                }
                else if(choice_1==9){
                  break;
                }
          }
          
              
        }
        else if(choice==0){
          delete td,db,td;
          break;
        }

  }
}

int main(){
  cauthu *ct[100];
  doibong *db[100];
  trandau *td[100];
  int n=0;
  int m=0;
  int k=0;
  menu(ct,n,db,m,td,k);
  return 0;
}