#include<iostream>
#include "doibong.cpp"
#include "trandau.cpp"
using namespace std;

void menu(cauthu *ct[], int n, doibong *db[], int m, trandau *td[],int k)
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
                      ct[i]=new cauthu();
                      
                      ct[i]->input();
                      n++;
                    }
                }
                else if( choice_1==2){
                  cout<<"\n-------------------------Danh sach cau thu---------------\n";
                  cout<<"\n Ho ten \t Ngay sinh \t CMND \t\t Quoc tich \t\t Vi tri dau: \t Chieu cao \t Can nang"<<endl;
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

                  system("pause");
                }
                
                else if(choice_1==7){

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
                      db[i]=new doibong();
                      
                      db[i]->input();
                      m++;
                    }
                }
                else if( choice_1==2){
                  cout<<"\n-------------------------Danh sach doi bong---------------\n";
                  cout<<"Ten doi\t Dia phuong \t huan luyen vien\n"; 
                    for(int i=0; i<n; i++){
                    
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

                  system("pause");
                }
                
                else if(choice_1==7){

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
                      td[i]=new trandau();
                      
                      td[i]->input();
                      k++;
                    }
                }
                else if( choice_1==2){
                  cout<<"\n-------------------------Danh sach tran dau---------------\n";
                  cout<<"Ngay thi dau\tSan thi dau\tTen hai doi \t Ti so\n"; 
                    for(int i=0; i<n; i++){
                    
                      db[i]->output();
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
  int n,m,k;
  menu(ct,n,db,m,td,k);
  return 0;
}