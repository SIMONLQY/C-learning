#include<iostream>
using namespace std;
int main(){
	double a,b,c;
	cout<<"����������С��:";
	cin>>a>>b>>c;
	double sum=a+b+c;
	cout<<"������С����ӵĽ����:"<<sum;
	if((int)(sum*10)%10>=5){
		sum=(int)sum+1;
	} else{
		sum=(int)sum;
	}
	cout<<"�����������Ϊ����Ϊ:"<<sum;
	return 0;
}
