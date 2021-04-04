#include<iostream>
#include<time.h>
#include<windows.h>
#include<cstring>
// 当有动态内存在对象内部时，对象之间的复制要重新定义函数，否则出错. 
using namespace std;
static char *num1[]=
{
       "","one ","two ","three ","four ","five ","six ","seven ","eight ","nine ","ten ","eleven ","twelve ",
       "thirteen ","fourteen ","fifteen ","sixteen ","seventeen ","eighteen ","nineteen "
};
//num10中为20-90，空出了0和1，所以可以直接用num10[n/10]调用，得到n对应单词
static char *num10[]=
{
       "","","twenty ","thirty ","forty ","fifty ","sixty ","seventy ","eighty ","ninety "
};
static char *months[]={
	"",
	"January ",
	"February ",
	"March ",
	"April ",
	"May ",
	"June ",
	"July ",
	"August ",
	"September ",
	"October ",
	"November ",
	"December "
};
class Date
{
private:	
	int year,month,day;
	void SetSystemDate();                //取得系统日期
	char *d;
	char *out(int a);                    //翻译千以内整数 
	void tran_date();                  //翻译日期 
	long p;                            //用于排序 
public:
	friend ostream &operator<<(ostream&output,const Date &d){
		output<<months[d.month]<<" "<<d.day<<","<<d.year;
		return output;
	}
	friend istream &operator>>(istream&input,Date &d){
		int a,b,c;
		input>>a>>b>>c;
		d.year=a;
		d.month=b;
		d.day=c;
		return input;
	}
	char *tran_int(int n);              //翻译整数
	Date(Date &a){
		year=a.year;
		month=a.month;
		day=a.day;
		char *m=new char[strlen(a.d)];
		strcpy(m,a.d);
		d=m;
	}
	Date()
	{  
		year=rand()%9999+1;
		month=rand()%12+1;
		day=rand()%31+1;
		tran_date();
	}
	Date(int year,int month,int day){
		init(year,month,day);
		tran_date();
	}
	void init(int,int,int );             //设置年月日数据 
	void print_ymd();                    //显示年月日 
	void print_mdy();                    //显示月日年
	char *getd();                        //得到翻译的日期 
	int get_year() { return year; }      //得到年份值 
	int get_month() { return month; }    //得到月份值 
	int get_day() { return day; }        //得到日值 
	bool IsLeapYear();                   //判断是否为闰年
	long getp();
	void fuzhi(Date &a){
		year=a.year;
		month=a.month;
		day=a.day;
		char *m=new char[strlen(a.d)];
		strcpy(m,a.d);
		d=m;
	}
	~Date(){
		delete []d;
	}
};
long Date::getp(){
	p=year*12*31+month*12+day;
	return p;
}
char *Date::getd(){
	return d;
}
char *Date::out(int a){
	char result[100];
	result[0]='\0';
	int b=a%100;
		//若百位不为零，输出百位数加hundred，若此时十位个位均为0，不加and
	if(a/100!=0)
	{
		strcat(result,num1[a/100]);
		strcat(result,"hundred ");
	    if(b!=0)
	    strcat(result,"and ");
	}
		//当后两位在20以内时，直接调用num1[n]，输出
	if(b<20)
	strcat(result,num1[b]);
		//当后两位大于20时
	else 
	{
			//先调用num10，输出十位数
        strcat(result,num10[b/10]);
		    //个位不为0时应输出"-"个位数
        if(b%10!=0)
        strcat(result,"\b-");
		strcat(result,num1[b%10]);
	}
	return result;
}
char *Date::tran_int(int n){
	char result[1000];
	result[0]='\0';
	if(n>1999999999)
		strcat(result,"dev C++平台无法处理大于1999999999位的数！\n");
	else
	{
		//三位三位取出，存入abcd中
		int a=n/1000000000,b=(n%1000000000)/1000000,c=(n%1000000)/1000,d=n%1000;
		//不等于0时，输出并加上million或thousand
		if(a!=0)
	    {
	    	strcat(result,out(a));
	    	strcat(result,"billion ");
	    }
	
		if(b!=0)
	    {
	    	strcat(result,out(b));
	    	strcat(result,"million ");
	    }
	   	if(c!=0)
	    {
	    	strcat(result,out(c));
	    	strcat(result,"thousand ");
	    }
	   	if(d!=0)
	   	{
            //据英文语法规则，最后两位前一定有and
			if(d<100&&(a!=0||b!=0||c!=0))
            	strcat(result,"and ");
            strcat(result,out(d));
	    }
    }
    return result;
}
void Date::tran_date(){
	char result[1000];
	result[0]='\0';
	strcat(result,months[month]);
	strcat(result,tran_int(day));
	strcat(result,",");
	strcat(result,tran_int(year));
	char *r=new char[strlen(result)];
	strcpy(r,result);
	d=r;
}
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
{	cout<<"年月日：";
cout<<year<<"-"<<month<<"-"<<day<<endl;}
void Date::print_mdy()
{	cout<<"月日年：";
cout<<month<<"-"<<day<<"-"<<year<<endl;}
bool Date::IsLeapYear() 
{
	if ( year % 400 == 0 || ( year % 100 != 0 && year % 4 == 0 ) )
		return true;
		return false;
}
int main()
{	
    Date d;
    cout<<"请按照年月日输入一个对象:";
	cin>>d; 
	cout<<"这个对象为：";
	cout<<d;
	return 0;
}

