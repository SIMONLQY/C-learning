#include<iostream>
#include<cmath>
#include<math.h>
using namespace std;
int main(){
	long a,sum;
	cout<<"������һ����λ����";
	cin>>a;
	sum=pow(a/1000,3)+pow((a%1000)/100,3)+pow((a%100)/10,3)+pow(a%10,3);
	cout<<pow(a/1000,3)<<"+"<<pow((a%1000)/100,3)<<"+"<<pow((a%100)/10,3)<<"+"<<pow(a%10,3)<<"="<<sum;
	return 0;
}
