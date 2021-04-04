#include<iostream>
#include<ctime>
using namespace std;
int main(){
	tm*a; // 结构体tm指针 
	time_t t=time(NULL); //获取时间 
	a=localtime(&t); //将时间和结构体结合 
	//从结构体中获得年月日（注意月和日的得到方法） 
	int year=a->tm_year+1900; 
	int month=a->tm_mon+1;
	int day=a->tm_mday;
	cout<<year<<":"<<month<<":"<<day;
} 
