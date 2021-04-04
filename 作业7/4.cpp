#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int mymax( int a,int b,int c){
	int max=a;
	int p[3]={a,b,c};
	for(int i=0;i<3;i++){
		if(max<p[i]){
			max=p[i];
		}
	}
	return max;
}

double mymax( double a,double b,double c){
	double max=a;
	double p[3]={a,b,c};
	for(int i=0;i<3;i++){
		if(max<p[i]){
			max=p[i];
		}
	}
	return max;
}

char mymax( char a,char b,char c){
	char max=a;
	char p[3]={a,b,c};
	for(int i=0;i<3;i++){
		if(max<p[i]){
			max=p[i];
		}
	}
	return max;
}
int main(){
	int a=1,b=2,c=3;
	double d=1.1,e=1.2,f=1.3;
	char k='a',j='b',l='c';
	cout<<a<<" "<<b<<" "<<c<<"中最大的是"<<mymax(a,b,c)<<endl;
	cout<<d<<" "<<e<<" "<<f<<"中最大的是"<<mymax(d,e,f)<<endl;
	cout<<k<<" "<<j<<" "<<l<<"中最大的是"<<mymax(k,j,l)<<endl;
	return 0;
}

