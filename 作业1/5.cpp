#include<cmath>
#include<iostream>
using namespace std;
int main(){
	cout<<"此程序计算x/sqrt(x*x-3x+2)\n";
	double x;
	cout<<"请输入x:";
	cin>>x;
	if(x*x-3*x+2==0){
		cout<<"分母不能为0，请改变x的值\n";
	} else if(x*x-3*x+2<0){
		cout<<"此时根号下式子值为负数，不能开平方，请改变x的值\n";
	} else {
		cout<<"x/sqrt(x*x-3x+2)="<<x/sqrt(x*x-3*x+2);
	}
	return 0;
}
 
