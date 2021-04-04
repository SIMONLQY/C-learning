#include<iostream>//取消构造函数
#include<time.h>
#include<windows.h>
using namespace std;
class Date
{
protected:	
	int year,month,day;
	Date getSystemDate();                //取得系统日期
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
	bool operator == (Date d);
	bool operator >(Date d);
	bool operator <(Date d);
	int operator -(Date d);
	bool judge();                  //判断一个日期是否是系统当前日期 
	void birthday();
};
bool Date::operator == (Date d){
	if(year==d.year&&month==d.month&&day==d.day){
		return true;
    }else {
    	return false;
	}
} 
bool Date::operator > (Date d){
	int d1=year*10000+month*100+day;
	int d2=d.year*10000+d.month*100+day;
	if(d1>d2){
		return true;
	}else{
		return false;
	}
}
bool Date::operator <(Date d){
	int d1=year*10000+month*100+day;
	int d2=d.year*10000+d.month*100+day;
	if(d1<d2){
		return true;
	}else{
		return false;
	}
}
int Date::operator -(Date d){
	long long int d1=(year-2000)*365+month*31+day;
	long long int d2=(d.year-2000)*365+d.month*31+d.day;
	return (int)(d1-d2);
}
Date Date::getSystemDate()
{	
	//取得系统日期
	tm *gm;
	time_t t=time(NULL);
	gm = gmtime(&t);
	Date temp;
	temp.year = 1900 + gm->tm_year;
	temp.month = gm->tm_mon +1;
	temp.day = gm->tm_mday;
	return temp;
}
void Date::init(int  yy,int  mm,int  dd)
{	
	if (yy>=1900&&yy<=9999) 
		year = yy;
	else
		{
			*this=getSystemDate();
			return;
		}
	if (mm>=1&&mm<=12) 
		month = mm;
	else
		{
			*this=getSystemDate();
			return;
		}
	if (dd>=1&&dd<=31) 
		day = dd;
	else
		{
			*this=getSystemDate();
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
bool Date::judge(){
	if(*this==getSystemDate()){
		return true;
	}else{
		return false;
	}
}
void Date::birthday(){
	Date temp=*this;
	temp.year=0;
	Date now=getSystemDate();
	now.year=0;
	if(temp-now==0){
		cout<<"Happy Birthday!"<<endl;
	}else if(temp-now>0){
		cout<<"还有"<<temp-now<<"天是你的生日";
	}else{
		cout<<"你的生日已经过去了"<<now-temp<<"天，明年的生日还要再等"<<365-(now-temp)<<"天"<<endl; 
	}
}
int main()
{	
    Date a;
    int y,m,d;
    cout<<"请输入你的生日（年月日）:";
    cin>>y>>m>>d;
    a.init(y,m,d);
    a.birthday();
	return 0;
}

