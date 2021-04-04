#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
double fun(double *xs,int count,double x);
double fum(double *xs,int count,double x);
double qiugen(double *xs,int count,double x);
void sc(double *xs,int count);
int main(){
	int count;
	cout<<"请输入方程阶数：";
	cin>>count;
	double *xs=new double[count+1];
	cout<<"请从高次到低次输入多项式系数：";
	for(int i=0;i<count+1;i++){
		cin>>xs[i];
	}
	sc(xs,count);
	double x;
	cout<<"请输入你要求方程在哪个值附件的根：";
	cin>>x;
	cout<<"方程在"<<"附近的解为："<<qiugen(xs,count,x); 
	delete []xs;
	return 0;
}

double fun(double *xs,int count,double x){
	int n=count+1;
	double result=0;
	for(int i=0;i<n;i++){
		result+=xs[i]*pow(x,n-1-i);
	}
	return result;
}

double fum(double *xs,int count,double x){
	int n=count+1;
	double xx[count+1];
	for(int i=0;i<n-1;i++){
		xx[i]=(n-1-i)*xs[i];
	}
	xx[n-1]=0;
	count=count-1;
	double result=fun(xx,count,x);
	return result;
}

void sc(double *xs,int count){
	for(int i=0;i<count;i++){
		if(i!=0&&xs[i]>0&&xs[i]!=1){
			cout<<"+"<<xs[i]<<"x^"<<count-i;
		} else if(xs[i]<0&&xs[i]!=-1){
			cout<<xs[i]<<"x^"<<count-i;
		} else if(xs[i]==1){
			cout<<"x^"<<count-i;
		}else if(xs[i]==-1){
			cout<<"-x^"<<count-i;
		}else if(i==0){
			cout<<xs[i]<<"x^"<<count-i;
		}
	}
	cout<<"+"<<xs[count]<<"=0"<<endl;
}
double qiugen(double *xs,int count,double x){
	double e=pow(10.0,-7);
	double m=x;
	x=x-fun(xs,count,x)/fum(xs,count,x);
	if(fabs(fun(xs,count,x))>=e||fabs(x-m)>=e){
		x=qiugen(xs,count,x);
	}
	return x;
}

