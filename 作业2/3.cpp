#include<iostream>
#include<cmath>
#include<math.h>
using namespace std;
int main(){
	int shour,sminute,ssecond,uhour,uminute,usecond;
	long ss,us,t,thour,tminute,tsecond;
	cout<<"输入比赛开始小时：";
	cin>>shour;
	cout<<"输入比赛开始分钟：";
	cin>>sminute;
	cout<<"输入比赛开始秒钟：";
	cin>>ssecond;
	cout<<"输入比赛用时小时：";
	cin>>uhour;
	cout<<"输入比赛用时分钟：";
	cin>>uminute;
	cout<<"输入比赛用时秒钟：";
	cin>>usecond;
	ss=shour*3600+sminute*60+ssecond;
	us=uhour*3600+uminute*60+usecond;
	t=us+ss;
	if(t>3600*23+60*59+59){
		thour=t/3600-24;
	}else{
		thour=t/3600;
	}
	tminute=t%3600/60;
	tsecond=t%60;
	cout<<"-------------------------------------"<<endl;
	cout<<"\r";
	cout<<"\r";
	cout<<"        欢迎参加大学生蹦极比赛"<<endl;
	cout<<"\r";
	cout<<"        比赛开始时间："<<shour<<":"<<sminute<<":"<<ssecond<<endl;
	cout<<"        比赛用时："<<uhour<<":"<<uminute<<":"<<usecond<<endl;
	cout<<"        现在时钟时间："<<thour<<":"<<tminute<<":"<<tsecond<<endl; 
	cout<<"\r";
	cout<<"\r";
	cout<<"-------------------------------------"<<endl;
	return 0;
}
