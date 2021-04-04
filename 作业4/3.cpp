#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"请输入整数N："<<endl;
	cin>>n;
	int number[n];
	int fnumber=0;
	int znumber=0;
	int zero=0;
	int fun=0;
	int zn=0;
	cout<<"请输入"<<n<<"个整数："<<endl;
	for(int i=0;i<n;i++){
		cin>>number[i];
	} 
	for(int i=0;i<n;i++){
		if(number[i]>0){
			znumber++;
			zn=zn+number[i];
		} else if(number[i]<0){
			fnumber++;
			fun=fun+number[i];
		} else{
			zero++;
		}
	}
	cout<<"正数有"<<znumber<<"个"<<endl;
	cout<<"负数有"<<fnumber<<"个"<<endl;
	cout<<"负数的和是"<<fun<<endl;
	cout<<"正数的和是"<<zn<<endl;
	return 0;
}
