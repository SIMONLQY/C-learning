#include<iostream>
#include<cstring>
#define n 7
using namespace std;
int main(){
	int a[n];
	int b[n];
	cout<<"请输入第一个数组的"<<n<<"个元素:";
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	cout<<"请输入第二个数组的"<<n<<"个元素:";
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	int d=0;
	bool judge=true;
	cout<<"不是两个数组共有的元素有："<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i]==b[j]){
				judge=false;
			}
		}
		if(judge==true){
			cout<<a[i]<<"  ";
		}
		judge=true;
	}
	judge=true;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(b[i]==a[j]){
				judge=false;
			}
		}
		if(judge==true){
			cout<<b[i]<<"  ";
		}
		judge=true;
	}
	return 0;
}
