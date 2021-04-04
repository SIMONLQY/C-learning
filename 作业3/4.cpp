#include<iostream>
#include<stdlib.h>
#include<windows.h>
#include<stdio.h>
#include<cmath>
using namespace std;
int main(){
	double x0=2.0,x1=1.0,xm=0.0;
	double sum=0;
	int n;
	cout<<"请输入n"<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		sum=sum+x0/x1;
		xm=x1;
		x1=x0;
		x0=x0+xm;
	}
	cout<<"前"<<n<<"项和为"<<sum;
	return 0;
}
