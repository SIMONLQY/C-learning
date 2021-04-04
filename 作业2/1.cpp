#include<iostream>
using namespace std;
int main(){
	double a,b,c;
	cout<<"请输入三个小数:";
	cin>>a>>b>>c;
	double sum=a+b+c;
	cout<<"这三个小数相加的结果是:"<<sum;
	if((int)(sum*10)%10>=5){
		sum=(int)sum+1;
	} else{
		sum=(int)sum;
	}
	cout<<"结果四舍五入为整数为:"<<sum;
	return 0;
}
