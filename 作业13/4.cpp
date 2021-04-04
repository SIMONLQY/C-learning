#include<iostream>
#include<time.h>
#include<windows.h>
#include<cstring>
// ���ж�̬�ڴ��ڶ����ڲ�ʱ������֮��ĸ���Ҫ���¶��庯�����������. 
using namespace std;
static char *num1[]=
{
       "","one ","two ","three ","four ","five ","six ","seven ","eight ","nine ","ten ","eleven ","twelve ",
       "thirteen ","fourteen ","fifteen ","sixteen ","seventeen ","eighteen ","nineteen "
};
//num10��Ϊ20-90���ճ���0��1�����Կ���ֱ����num10[n/10]���ã��õ�n��Ӧ����
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
	void SetSystemDate();                //ȡ��ϵͳ����
	char *d;
	char *out(int a);                    //����ǧ�������� 
	void tran_date();                  //�������� 
	long p;                            //�������� 
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
	char *tran_int(int n);              //��������
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
	void init(int,int,int );             //�������������� 
	void print_ymd();                    //��ʾ������ 
	void print_mdy();                    //��ʾ������
	char *getd();                        //�õ���������� 
	int get_year() { return year; }      //�õ����ֵ 
	int get_month() { return month; }    //�õ��·�ֵ 
	int get_day() { return day; }        //�õ���ֵ 
	bool IsLeapYear();                   //�ж��Ƿ�Ϊ����
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
		//����λ��Ϊ�㣬�����λ����hundred������ʱʮλ��λ��Ϊ0������and
	if(a/100!=0)
	{
		strcat(result,num1[a/100]);
		strcat(result,"hundred ");
	    if(b!=0)
	    strcat(result,"and ");
	}
		//������λ��20����ʱ��ֱ�ӵ���num1[n]�����
	if(b<20)
	strcat(result,num1[b]);
		//������λ����20ʱ
	else 
	{
			//�ȵ���num10�����ʮλ��
        strcat(result,num10[b/10]);
		    //��λ��Ϊ0ʱӦ���"-"��λ��
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
		strcat(result,"dev C++ƽ̨�޷��������1999999999λ������\n");
	else
	{
		//��λ��λȡ��������abcd��
		int a=n/1000000000,b=(n%1000000000)/1000000,c=(n%1000000)/1000,d=n%1000;
		//������0ʱ�����������million��thousand
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
            //��Ӣ���﷨���������λǰһ����and
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
{	cout<<"�����գ�";
cout<<year<<"-"<<month<<"-"<<day<<endl;}
void Date::print_mdy()
{	cout<<"�����꣺";
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
    cout<<"�밴������������һ������:";
	cin>>d; 
	cout<<"�������Ϊ��";
	cout<<d;
	return 0;
}

