#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int judgeT(int a[],int N);
void sc(int a[],int N);
int main(){
	const int n=5;
	int a[n*n];
	for(int i=0;i<n*n;i++){
		a[i]=i;
	}
	sc(a,n*n);
	if(judgeT(a,n*n)==1){
		cout<<"此矩阵为对称矩阵"<<endl;
	} else{
		cout<<"此矩阵为非对称矩阵"<<endl;
	}
	for(int i=0;i<n;i++){
		a[i*n+i]+=a[i*n+i*n+n-1-(i*n+i)];
	}
	cout<<"\n主对角线元素加上副对角线元素后的结果为:"<<endl;
	sc(a,n*n);
	return 0;
} 
void sc(int a[],int N){
	int n=sqrt(N);
	int k=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<a[i*n+j]<<"\t";
			k++;
			if(k==n){
				k=0;
				cout<<"\n";
			}
		}
	}
}
int judgeT(int a[],int N){
	int n=sqrt(N);
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(a[i*n+j]!=a[j*n+i]){
				return 0;
			}
		}
	}
	return 1;
}


