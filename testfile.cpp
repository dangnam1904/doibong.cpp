#include<iostream>
#include <string>
#include<fstream>
using namespace std;

int main(){
                    ifstream FileIn;
	            FileIn.open("C:\\code\\c++\\BongDa\\cauthu.txt", ios_base::in);
                  if(!FileIn){
                  cout << "Error: file not opened." << endl;
                  
                  }
                  else{
                    cout << "Succes" << endl;
                  }


    int n;
    FileIn >>n;
    string kq;
    for( int i=0; i<n;i++){
         getline(FileIn,kq,',');
    cout<<kq<<endl;
    }
   FileIn.close();
}