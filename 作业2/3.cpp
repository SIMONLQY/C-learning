#include<iostream>
#include<cmath>
#include<math.h>
using namespace std;
int main(){
	int shour,sminute,ssecond,uhour,uminute,usecond;
	long ss,us,t,thour,tminute,tsecond;
	cout<<"���������ʼСʱ��";
	cin>>shour;
	cout<<"���������ʼ���ӣ�";
	cin>>sminute;
	cout<<"���������ʼ���ӣ�";
	cin>>ssecond;
	cout<<"���������ʱСʱ��";
	cin>>uhour;
	cout<<"���������ʱ���ӣ�";
	cin>>uminute;
	cout<<"���������ʱ���ӣ�";
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
	cout<<"        ��ӭ�μӴ�ѧ���ļ�����"<<endl;
	cout<<"\r";
	cout<<"        ������ʼʱ�䣺"<<shour<<":"<<sminute<<":"<<ssecond<<endl;
	cout<<"        ������ʱ��"<<uhour<<":"<<uminute<<":"<<usecond<<endl;
	cout<<"        ����ʱ��ʱ�䣺"<<thour<<":"<<tminute<<":"<<tsecond<<endl; 
	cout<<"\r";
	cout<<"\r";
	cout<<"-------------------------------------"<<endl;
	return 0;
}
