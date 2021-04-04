#include<iostream>
using namespace std;
class Time{
	private:
		int hour;
		int minute;
		int second;
	public:
		Time(){
			hour=0;
			minute=0;
			second=0;
		}
		Time(int hour,int minute,int second){
			this->hour=hour;
			this->minute=minute;
			this->second=second;
			cout<<"��ʼ��Ϊ��"<<endl;
			cout<<"ʱ���룺"<<this->hour<<":"<<this->minute<<":"<<this->second<<endl;
		}
		Time(Time &t1,Time &t2){
			cout<<"��ʱ�����Ϊ��"<<endl;
			int s=t1.hour*3600+t1.minute*60+t1.second+t2.hour*3600+t2.minute*60+t2.second;
			this->hour=s/3600%24;
			this->minute=s%3600/60;
			this->second=s%60;
			cout<<"ʱ���룺"<<this->hour<<":"<<this->minute<<":"<<this->second<<endl;
		}
		Time(Time &t){
			this->hour=t.hour;
			this->minute=t.minute;
			this->second=t.second;
			cout<<"�����ֿ��ܸ�ʽ���ʱ�䣺"<<endl;
			cout<<"ʱ����"<<t.hour<<"-"<<t.minute<<"-"<<t.second<<endl; 
			cout<<"ʱ���"<<t.hour<<"-"<<t.second<<"-"<<t.minute<<endl; 
			cout<<"����ʱ"<<t.minute<<"-"<<t.second<<"-"<<t.hour<<endl; 
			cout<<"��ʱ��"<<t.minute<<"-"<<t.hour<<"-"<<t.second<<endl; 
			cout<<"��ʱ��"<<t.second<<"-"<<t.hour<<"-"<<t.minute<<endl; 
			cout<<"���ʱ"<<t.second<<"-"<<t.minute<<"-"<<t.hour<<endl; 
		}
		~Time(){}
};
int main(){
	Time t1(12,23,35),t2(13,32,32);
	Time t(t1,t2);
	Time t0(t);
}
