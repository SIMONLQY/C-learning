#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"����������N��"<<endl;
	cin>>n;
	int number[n];
	int fnumber=0;
	int znumber=0;
	int zero=0;
	int fun=0;
	int zn=0;
	cout<<"������"<<n<<"��������"<<endl;
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
	cout<<"������"<<znumber<<"��"<<endl;
	cout<<"������"<<fnumber<<"��"<<endl;
	cout<<"�����ĺ���"<<fun<<endl;
	cout<<"�����ĺ���"<<zn<<endl;
	return 0;
}
