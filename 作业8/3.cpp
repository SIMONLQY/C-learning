#include<iostream>
#include<cstring>
#define n 7
using namespace std;
int main(){
	int a[n];
	int b[n];
	cout<<"�������һ�������"<<n<<"��Ԫ��:";
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	cout<<"������ڶ��������"<<n<<"��Ԫ��:";
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	int d=0;
	bool judge=true;
	cout<<"�����������鹲�е�Ԫ���У�"<<endl;
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
