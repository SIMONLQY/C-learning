#include<iostream>
#include<stdlib.h>
#include<windows.h>
#include<stdio.h>
#include<ctime>
using namespace std;
int main(){
	srand(time(0));
	long N=rand();
	cout<<"Ëæ»úÊýÎª:"<<N<<endl;
	int M=N%10;
	if(N%2==0){
		cout<<"          0-0";
		Sleep(5000/(M+1));
		cout<<"\b\b\b\b";
		cout<<"0-0 ";
		cout<<"\b";
		cout<<"\007";
		Sleep(5000/(M+1));
		cout<<"\b\b\b\b";
		cout<<"0-0  ";
		cout<<"\b\b";
		cout<<"\007";
		Sleep(5000/(M+1));
		cout<<"\b\b\b\b";
		cout<<"0-0   ";
		cout<<"\b\b\b";
		cout<<"\007";
		Sleep(5000/(M+1));
		cout<<"\b\b\b\b";
		cout<<"0-0    ";
		cout<<"\b\b\b\b";
		cout<<"\007";
	}else {
		cout<<"          0-0";
		Sleep(5000/M);
		cout<<"\b\b\b\b";
		cout<<"0-0 ";
		cout<<"\b";
		cout<<"\007";
		Sleep(5000/M);
		cout<<"\b\b\b\b";
		cout<<"0-0  ";
		cout<<"\b\b";
		cout<<"\007";
		Sleep(5000/M);
		cout<<"\b\b\b\b";
		cout<<"0-0   ";
		cout<<"\b\b\b";
		cout<<"\007";
		Sleep(5000/M);
		cout<<"\b\b\b\b";
		cout<<"0-0    ";
		cout<<"\b\b\b\b";
		cout<<"\007";
		Sleep(5000/M);
		cout<<"\b\b\b\b";
		cout<<"0-0     ";
		cout<<"\b\b\b\b\b";
		cout<<"\007";
	}
	return 0;
}
