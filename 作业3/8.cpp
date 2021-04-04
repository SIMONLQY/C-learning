#include<iostream>
#include<stdlib.h>
#include<windows.h>
#include<stdio.h>
#include<cmath>
using namespace std;
int main(){
	int n,g,s,b,q;
	cout<<"请输入一个四位数"<<endl;
	cin>>n;
	g=n%10;
	s=(n/10)%10;
	b=(n/100)%10;
	q=n/1000;
	int k;
	cout<<"0-0";
	Sleep(500);
	if(g==0||s==0||b==0||q==0){
		cout<<"此时不运动";
	} else{
		for(int i=0;i<g+30;i++){
			k=g+1;
			cout<<"\b\b\b";
			cout<<" "<<"0-0";
			Sleep(1000.0/k);
		}
		for(int i=0;i<s+20;i++){
			k=s+1;
			cout<<"\b\b\b\b";
			cout<<"0-0"<<" ";
			cout<<"\b";
			cout<<"\007";
			Sleep(1000.0/k);
		}
		for(int i=0;i<b+10;i++){
			k=b+1;
			cout<<"\b\b\b";
			cout<<"   "<<"\n";
			for(int j=0;j<g+30-(s+20);j++){
				cout<<" ";
			}
			cout<<"0-0";
			Sleep(1000.0/k);
		}
		for(int i=0;i<q+10;i++){
			k=q+1;
			cout<<"\b\b\b";
			cout<<"   "<<"\n";
			for(int j=0;j<g+30-(s+20)+i+1;j++){
				cout<<" ";
			}
			cout<<" "<<"0-0";
			Sleep(1000.0/k);
		}
	}
	
	return 0;
}
