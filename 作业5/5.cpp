#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
double mysqrl(double x);
double mycube(double x);
int main(){
	cout<<"整数"<<"\t" <<"自编开方"<<"\t"<<"系统开方"<<"\t"<<"自编开立方"<<"\t"<<"系统开立方"<<endl;
	for(int i=1;i<=30;i++){
		cout<<i<<"\t"<<mysqrl((double)i)<<"\t"<<"\t"<<pow(i,1.0/2)<<"\t"<<"\t"<<mycube((double)i)<<"\t"<<"\t"<<pow(i,1.0/3)<<endl;
	}
	return 0;
} 

double mysqrl(double x){
	double x0=x/2.0;
	double fmd=x0;
	do{
		fmd=x0;
		x0=(x0+x/x0)/2.0;
	}while(fabs(fmd-x0)>pow(10,-7));
	return x0;
}

double mycube(double x){
	double x0=x/2.0;
	double fmd=x0;
	do{
		fmd=x0;
		x0=x0-(x0*x0*x0-x)/(3*x0*x0);
	}while(fabs(fmd-x0)>pow(10,-7));
	return x0;
}
