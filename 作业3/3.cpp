#include<iostream>
#include<stdlib.h>
#include<windows.h>
#include<stdio.h>
#include<cmath>
using namespace std;
int main(){
	int n;
	cout<<"���������ɸ���������һ������ָʾ��֮�����ֵ������"<<endl;
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
	cout<<"������������е���С����Ϊ"<<min;
	return 0;
}
