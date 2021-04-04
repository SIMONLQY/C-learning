#include<iostream>
#include <windows.h>
using namespace std;
int main(){
	for(int i=0;i<10;i++){
		cout<<"0-0";
		Sleep(1000);
		cout<<"\b\b\b"<<"   "<<"\n";
		if(i==9){
			cout<<"0-0";
		}
	}
	return 0;
}
 
