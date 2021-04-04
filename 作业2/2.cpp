#include<iostream>
#include<cmath>
#include<math.h>
using namespace std;
int main(){
	float x,y,result;
	cout<<"请输入两个角度值：";
	cin>>x>>y;
	if(cos(fabs(x+y)*M_PI/180)==0){
		cout<<"这时分母为零，请更换角度值。";
	} else if(cos(fabs(x+y)*M_PI/180)<0){
		cout<<"这时有负数开根号的情况，请更换角度值。";
	}else{
		result=sin((fabs(x)+fabs(y))*M_PI/180)/sqrt(cos(fabs(x+y)*M_PI/180));
	    cout<<"sin(|x|+|y|)/(cos(|x+y|))^0.5="<<result;
	}
	return 0;
}
