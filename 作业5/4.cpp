#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
double arcsin(float a);

int main(){
	cout<<"������һ�����Ǻ���ֵ������ֵС��1����";
	float s;
	cin>>s;
	cout<<"�Զ��庯����������"<<arcsin(s)<<endl;
	cout<<"ϵͳ�Դ�������������"<<asin(s)<<endl;
	return 0;
} 

long jie(int a){
	int n=1;
	for(int i=1;i<=a;i++){
		n=i*n;
	}
	return n;
}
double arcsin(float a){
    double arc=a+(a*a)/(2.0*3);
	int n=2;
	while((jie(2*n)*pow(a,2*n+1))/(double)(pow(2,2*n)*pow(jie(n),2)*(2*n+1))>0.0001){
		arc=arc+(jie(2*n)*pow(a,2.0*n+1))/(double)(pow(2,2*n)*pow(jie(n),2)*(2*n+1));
		n++;
	}
	return arc;
}
