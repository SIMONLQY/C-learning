#include<iostream>
#include<cstring>
#include<cmath> 
using namespace std;
void scdxs(double a[],int n);
double dxs(double a[],double x,int n);
double dxsds(double a[],double x,int n);
int main(){
	int n;
	cout<<"���������ʽ������";
	cin>>n;
	double a[n+1]; //����ʽ 
	double b[n];  //����ʽ���� 
	cout<<"���������ʽϵ�����ߴε��ʹˣ���"; 
	for(int i=0;i<n+1;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		b[i]=a[i]*(n-i);
	}
	scdxs(a,n);
	scdxs(b,n-1); 
	cout<<"�������������ĵ㣺";
	double x;
	cin>>x;
	cout<<"����㺯��ֵΪ��"<<dxs(a,x,n)<<endl;
	cout<<"�����ĵ���ֵΪ��"<<dxsds(a,x,n)<<endl;
	return 0;
} 
void scdxs(double a[],int n){
	cout<<"�˶���ʽΪ��";
	for(int i=0;i<n+1;i++){
		if(a[i]==1){
			cout<<"x^"<<n-i<<"+"; 
		}else if(n!=i&&a[i]!=0){
			cout<<a[i]<<"x^"<<n-i<<"+";
		} else if(n==i&&a[i]!=0){
			cout<<a[i];
		}
	}
	cout<<"\n";
}
double dxs(double a[],double x,int n){
	double f=0;
	for(int i=0;i<n+1;i++){
		f=f+a[i]*pow(x,n-i);
	}
	return f;
}


double dxsds(double a[],double x,int n){
	double f1=0;
	double b[n-1];
	for(int i=0;i<n-1;i++){
		b[i]=a[i]*(n-i);
	}
	for(int i=0;i<n+1;i++){
		f1=f1+b[i]*pow(x,n-1-i);
	}
	return f1;
}
