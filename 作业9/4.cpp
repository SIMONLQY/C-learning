#include<iostream>
using namespace std;
class Time{
	private:
		int hour,minute,second;
	public:
		void print_sfm();
		void print_smf();
		void print_fsm();
		void print_fms();
		void print_msf();
		void print_mfs();
		void printall();
		void init(int h,int m,int s);
};
void Time::print_sfm(){
	cout<<"ʱ����:"<<hour<<"-"<<minute<<"-"<<second<<endl; 
}
void Time::print_smf(){
	cout<<"ʱ���:"<<hour<<"-"<<second<<"-"<<minute<<endl; 
}
void Time::print_fsm(){
	cout<<"��ʱ��:"<<minute<<"-"<<hour<<"-"<<second<<endl; 
}
void Time::print_fms(){
	cout<<"����ʱ:"<<minute<<"-"<<second<<"-"<<hour<<endl; 
}
void Time::print_msf(){
	cout<<"��ʱ��:"<<second<<"-"<<hour<<"-"<<minute<<endl; 
}
void Time::print_mfs(){
	cout<<"���ʱ:"<<second<<"-"<<minute<<"-"<<hour<<endl; 
}
void Time::init(int h,int m,int s){
	bool t=true; // �ж������Ƿ����Ҫ�� 
	if(h>=0&&h<=24){
		hour=h;
	}else{
		cout<<"Сʱ��������Χ"<<endl;
		t=false;
	}
	if(m>=0&&m<=60){
		minute=m;
	}else{
		cout<<"������������Χ"<<endl;
		t=false;
	}
	if(s>=0&&s<=60){
		second=s;
	}else{
		cout<<"����������Χ"<<endl;
		t=false;
	}
	if(t==true){
		printall();
	}
}
void Time::printall(){
	print_sfm();
	print_smf();
	print_fsm();
	print_fms();
	print_msf();
	print_mfs();
}
int main(){
	int a,b,c;
	cout<<"������ʱ�䣬����ʱ�����ʽ:";
	cin>>a>>b>>c;
	Time time;
	time.init(a,b,c);
}
