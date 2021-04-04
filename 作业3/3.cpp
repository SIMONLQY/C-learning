#include<iostream>
#include<stdlib.h>
#include<windows.h>
#include<stdio.h>
#include<cmath>
using namespace std;
int main(){
	int n;
	cout<<"请输入若干个整数，第一个整数指示了之后的数值个数："<<endl;
	cin>>n;
	int min;
	for(int i=0;i<n;i++){
		int j;
		cin>>j;
		if(i==0){
			min=j;
		} else{
			if(j<min){
				min=j;
			}
		}
	}
	cout<<"您输入的数字中的最小数字为"<<min;
	return 0;
}
