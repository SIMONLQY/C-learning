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
	cout<<"时分秒:"<<hour<<"-"<<minute<<"-"<<second<<endl; 
}
void Time::print_smf(){
	cout<<"时秒分:"<<hour<<"-"<<second<<"-"<<minute<<endl; 
}
void Time::print_fsm(){
	cout<<"分时秒:"<<minute<<"-"<<hour<<"-"<<second<<endl; 
}
void Time::print_fms(){
	cout<<"分秒时:"<<minute<<"-"<<second<<"-"<<hour<<endl; 
}
void Time::print_msf(){
	cout<<"秒时分:"<<second<<"-"<<hour<<"-"<<minute<<endl; 
}
void Time::print_mfs(){
	cout<<"秒分时:"<<second<<"-"<<minute<<"-"<<hour<<endl; 
}
void Time::init(int h,int m,int s){
	bool t=true; // 判断输入是否符合要求 
	if(h>=0&&h<=24){
		hour=h;
	}else{
		cout<<"小时数超出范围"<<endl;
		t=false;
	}
	if(m>=0&&m<=60){
		minute=m;
	}else{
		cout<<"分钟数超出范围"<<endl;
		t=false;
	}
	if(s>=0&&s<=60){
		second=s;
	}else{
		cout<<"秒数超出范围"<<endl;
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
	cout<<"请输入时间，按照时分秒格式:";
	cin>>a>>b>>c;
	Time time;
	time.init(a,b,c);
}
