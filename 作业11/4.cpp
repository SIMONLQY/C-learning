#include<iostream>//取消构造函数
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
	void SetSystemDate();                //取得系统日期
public:
	Date(int y=1900,int m=1,int d=1)	//构造函数 
	{  
		year = y;  month = m;  day = d; 
	}
	void init(int,int,int );             //设置年月日数据 
	void print_ymd();                    //显示年月日 
	void print_mdy();                    //显示月日年 
	int get_year() { return year; }      //得到年份值 
	int get_month() { return month; }    //得到月份值 
	int get_day() { return day; }        //得到日值 
	bool IsLeapYear();                   //判断是否为闰年 
};
void Date::SetSystemDate()
{	
	//取得系统日期
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

