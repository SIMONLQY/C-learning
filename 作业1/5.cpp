#include<cmath>
#include<iostream>
using namespace std;
int main(){
	cout<<"�˳������x/sqrt(x*x-3x+2)\n";
	double x;
	cout<<"������x:";
	cin>>x;
	if(x*x-3*x+2==0){
		cout<<"��ĸ����Ϊ0����ı�x��ֵ\n";
	} else if(x*x-3*x+2<0){
		cout<<"��ʱ������ʽ��ֵΪ���������ܿ�ƽ������ı�x��ֵ\n";
	} else {
		cout<<"x/sqrt(x*x-3x+2)="<<x/sqrt(x*x-3*x+2);
	}
	return 0;
}
 
