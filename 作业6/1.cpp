#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
	int n;
	cout<<"请输入正整数：";
	cin>>n;
	int i=0,k=1; // i存储位数 
	while(k>0){
		k=n/pow(10,i);
		if(k!=0){
			i++;
		}
	}
	int *p=new int[i];
	for(int j=0;j<i;j++){
		p[j]=n%10;
		n=n/10;
	}
	cout<<"结果为：";
	for(int j=i-1;j>=0;j--){
		cout<<p[j];
		if(j%3==0&&j!=0){
			cout<<",";
		}
	}
	return 0;
} 


