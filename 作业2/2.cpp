#include<iostream>
#include<cmath>
#include<math.h>
using namespace std;
int main(){
	float x,y,result;
	cout<<"�����������Ƕ�ֵ��";
	cin>>x>>y;
	if(cos(fabs(x+y)*M_PI/180)==0){
		cout<<"��ʱ��ĸΪ�㣬������Ƕ�ֵ��";
	} else if(cos(fabs(x+y)*M_PI/180)<0){
		cout<<"��ʱ�и��������ŵ������������Ƕ�ֵ��";
	}else{
		result=sin((fabs(x)+fabs(y))*M_PI/180)/sqrt(cos(fabs(x+y)*M_PI/180));
	    cout<<"sin(|x|+|y|)/(cos(|x+y|))^0.5="<<result;
	}
	return 0;
}
