#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
double my_arctg(double x);
int main(){
	cout<<"测试数据值"<<"\t"<<"自变函数结果"<<"\t"<<"系统自带函数结果"<<endl;
	for(double i=-0.1;i<1.5;i+=0.1){
		cout<<i<<"\t\t"<<my_arctg(i)<<"\t\t"<<atan(i)<<endl;
	}
	return 0;
} 

double my_arctg(double x){
	double arc=0;
	double an0;
	double an1;
	int n=1;
	double temp=x;
	if(x>1||x<-1){
		x=1.0/x;
	}
	do{
		an0=(pow(-1.0,n-1)*pow(x,2.0*n-1))/(double)(2*n-1);
		an1=(pow(-1.0,n)*pow(x,2*n+1))/(double)(2*n+1);
		arc=arc+an0;
		n++;
	}while(fabs(fabs(an1)-fabs(an0))>pow(10,-7));
	if(temp>1){
		arc=M_PI_2-arc;
	}else if(temp<-1){
		arc=-M_PI_2-arc;
	}
	return arc;
}


