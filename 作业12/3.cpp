#include<iostream>//ȡ�����캯��
#include<time.h>
#include<windows.h>
using namespace std;
class Date
{
protected:	
	int year,month,day;
	Date getSystemDate();                //ȡ��ϵͳ����
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
	bool operator == (Date d);
	bool operator >(Date d);
	bool operator <(Date d);
	int operator -(Date d);
	bool judge();                  //�ж�һ�������Ƿ���ϵͳ��ǰ���� 
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
	//ȡ��ϵͳ����
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
		cout<<"����"<<temp-now<<"�����������";
	}else{
		cout<<"��������Ѿ���ȥ��"<<now-temp<<"�죬��������ջ�Ҫ�ٵ�"<<365-(now-temp)<<"��"<<endl; 
	}
}
int main()
{	
    Date a;
    int y,m,d;
    cout<<"������������գ������գ�:";
    cin>>y>>m>>d;
    a.init(y,m,d);
    a.birthday();
	return 0;
}

