#include<iostream>
#include<cmath>
using namespace std;
class Fraction
{
private:
	int a;//分子
	int b;//分母
	int divisor(int p,int q);//求最大公约数
public:
	double l; //计算值 
	Fraction(){ a=0;b=1; }	//无参构造函数 
	Fraction(int,int);		//有参构造函数 
	void set(int aa,int bb);//设置分子分母
	void show();//显示分数
	Fraction add(Fraction b);//加一个分数
	Fraction operator+(Fraction u);	//运算符+重载
	bool operator==(Fraction u);	//运算符==重载
	Fraction operator-();			//求负运算符重载
	~Fraction(){ };		//析构函数 
};
//有参数构造函数
Fraction::Fraction(int x,int y)
{
	set(x,y);
} 
//设置分子、分母
void Fraction:: set(int aa,int bb)
{
	a=aa;
	if (bb!=0) b=bb; else { a=0;	b=1;}  //分母有效性检验
	l=(double)a/(double)b;
}
//显示分数
void Fraction::show()
{
	cout<<a<<"/"<<b;
}
//分数相加，本类对象加u
Fraction Fraction::add(Fraction u)
{
	int tmp;
	Fraction v;

	v.a=a*u.b+b*u.a;   //分母
	v.b=b*u.b;//分子
	tmp=divisor(v.a ,v.b);//计算分子、分母的公约数
	v.a=v.a/tmp;//约去公约数
	v.b=v.b/tmp;//约去公约数
	return v;	//返回结果
}
//运算符+重载
Fraction Fraction::operator+(Fraction u)	//运算符+重载
{
	int tmp;
	Fraction v;

	v.a=a*u.b+b*u.a;   //分母
	v.b=b*u.b;//分子
	tmp=divisor(v.a ,v.b);//计算分子、分母的公约数
	v.a=v.a/tmp;//约去公约数
	v.b=v.b/tmp;//约去公约数
	return v;	//返回结果
}
//运算符==重载
bool Fraction::operator==(Fraction u)	//运算符==重载
{
	float x,y;
	x=(float)a/b;
	y=(float)u.a/u.b;
	if(x==y)
		return true;
	else
		return false;
}
//求负运算符重载
Fraction Fraction::operator-()			//求负运算符重载
{
	a=a*(-1);
	return *this;
}
//计算公约数，私有成员
int Fraction::divisor(int p,int q)
{
	int r;
	if(p<q)
	{
		int tmp;
		tmp=p;
		p=q;
		q=tmp;
	}
	r=p%q;
	while(r!=0)
	{
		p=q;
		q=r;
		r=p%q;
	}
	return q;
}
class xushu{
	private:
		double shibu;
		double xubu;
	public:
		xushu(double a=0,double b=0){
			shibu=a;
			xubu=b;
		}
		~xushu(){}
		void out(){
			cout<<shibu<<"+"<<xubu<<"*i"<<endl;
		}
		xushu operator +(xushu a){
			xushu temp;
			temp.shibu=shibu+a.shibu;
			temp.xubu=xubu+a.xubu;
			return temp;
		}
		xushu operator +(Fraction a){
			xushu temp;
			temp.shibu=shibu+a.l;
			temp.xubu=xubu;
			return temp;
		}
		xushu operator *(xushu a){
			xushu temp;
			temp.shibu=shibu*a.shibu-xubu*a.xubu;
			temp.xubu=xubu*a.shibu+shibu*a.xubu;
			return temp;
		}
		xushu operator /(xushu a){
			if(a.shibu==0||a.xubu==0){
				cout<<"分母不能为零"<<endl;
			}else{
				xushu temp;
				temp.shibu=(shibu*a.shibu+xubu*a.xubu)/(a.shibu*a.shibu+a.xubu*a.xubu);
				temp.xubu=(xubu*a.shibu-shibu*a.xubu)/(a.shibu*a.shibu+a.xubu*a.xubu);
				return temp;
			}
		}
		bool operator ==(xushu a){
			if(shibu==a.shibu&&xubu==a.xubu){
				return true;
			}else{
				return false;
			}
		}
		xushu operator ++(){
			shibu++;
			return *this;
		}
		xushu operator ++(int){
			shibu++;
			return *this;
		}
		xushu operator --(){
			shibu--;
			return *this;
		}
		xushu operator --(int){
			shibu--;
			return *this;
		}
};
int main(){
	xushu a(12.3,20);
	cout<<"第一个虚数为";
	a.out();
	xushu b(10.7,20);
	cout<<"第二个虚数为";
	b.out();
	xushu c;
	c=a+b;
	cout<<"他们相加结果为";
	c.out();
	cout<<"结果自加1为";
	(++c).out();
	cout<<"再自减1为";
	(--c).out();
	xushu d=a*b;
	cout<<"第一个虚数乘以第二个虚数结果为";
	d.out();
	cout<<"结果再除以第二个虚数结果为";
	(d/b).out();
	Fraction f(1,2);
	cout<<"第一个虚数加上分数1/2结果为";
	(a+f).out();
}
