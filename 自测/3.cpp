#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int judgeT(int a);
int main(){
	cout<<"����������������Ϊ��"<<endl;
	for(int i=1000;i<=9999;i++){
		if(judgeT(i)==1){
			cout<<i<<"\t";
		}
	}
	return 0;
} 
int judgeT(int a){
	int a1=a/100;
	int a0=a%100;
	if((a1+a0)*(a1+a0)==a){
		return 1;
	} else{
		return 0;
	}
}


