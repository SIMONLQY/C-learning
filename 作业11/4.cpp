#include<iostream>//ȡ�����캯��
#include<time.h>
#include<windows.h>
using namespace std;
class Time{
	protected:
		int hour;
		int minute;
		int second;
	public:
		Time(int hour=0,int minute=0,int second=0){
			this->hour=hour;
			this->minute=minute;
			this->second=second;
		}
		void show(){
			cout<<hour<<":"<<minute<<":"<<second;
		}
		~Time(){}
};
class Date
{
protected:	
	int year,month,day;
	void SetSystemDate();                //ȡ��ϵͳ����
public:
	Date(int y=1900,int m=1,int d=1)	//���캯�� 
	{  
		year = y;  month = m;  day = d; 
	}
	void init(int,int,int );             //�������������� 
	void print_ymd();                    //��ʾ������ 
	void print_mdy();                    //��ʾ������ 
	int get_year() { return year; }      //�õ����ֵ 
	int get_month() { return month; }    //�õ��·�ֵ 
	int get_day() { return day; }        //�õ���ֵ 
	bool IsLeapYear();                   //�ж��Ƿ�Ϊ���� 
};
void Date::SetSystemDate()
{	
	//ȡ��ϵͳ����
	tm *gm;
	time_t t=time(NULL);
	gm = gmtime(&t);
	year = 1900 + gm->tm_year;
	month = gm->tm_mon +1;
	day = gm->tm_mday;
}
void Date::init(int  yy,int  mm,int  dd)
{	
	if (yy>=1900&&yy<=9999) 
		year = yy;
	else
		{
			SetSystemDate();
			return;
		}
	if (mm>=1&&mm<=12) 
		month = mm;
	else
		{
			SetSystemDate();
			return;
		}
	if (dd>=1&&dd<=31) 
		day = dd;
	else
		{
			SetSystemDate();
			return;
		}
};
void Date::print_ymd()
{	cout<<year<<"-"<<month<<"-"<<day;}
void Date::print_mdy()
{	cout<<month<<"-"<<day<<"-"<<year;}
bool Date::IsLeapYear() 
{
	if ( year % 400 == 0 || ( year % 100 != 0 && year % 4 == 0 ) )
		return true;
		return false;
}

class DateAndTime:public Date,public Time{
	public:
		DateAndTime(int y,int m,int d,int h,int mi,int s);
		void init(int,int,int,int,int,int);
		void showDateAndTime();
		void timeUp();
		~DateAndTime(){}
}; 
DateAndTime::DateAndTime(int y,int m,int d,int h,int mi,int s):Date(y,m,d),Time(h,mi,s){
	timeUp();
}
void DateAndTime::init(int yy,int mm,int dd,int h,int mi,int s){
	if (yy>=1900&&yy<=9999) 
		year = yy;
	else
		{
			SetSystemDate();
			return;
		}
	if (mm>=1&&mm<=12) 
		month = mm;
	else
		{
			SetSystemDate();
			return;
		}
	if (dd>=1&&dd<=31) 
		day = dd;
	else
		{
			SetSystemDate();
			return;
		}
	this->hour=hour;
	this->minute=minute;
	this->second=second;
	timeUp();
}
void DateAndTime::timeUp(){
	for(int i=0;;i++){
		Sleep(1000);
		second++;
		if(second==60){
			second=0;
			minute++;
			if(minute==60){
				minute=0;
				hour++;
				if(hour==24){
					hour=0;
					day++;
					if(day==31){
						month++;
						if(month==12){
							year++;
						} 
					}
				}
			}
		}
		showDateAndTime();
	}
	
}
void DateAndTime::showDateAndTime(){
	print_ymd();
	cout<<"  ";
	show();
	cout<<endl;
}
int main()
{	
    DateAndTime t(1999,10,10,23,59,50);
    t.timeUp();
	return 0;
}

