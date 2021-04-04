#include<iostream>
using namespace std;
class func{
	private:
		double a,b,c,d,e,f,x,y;
		bool tp=true; // �ж��Ƿ�ֻ��һ���� 
		double solvex();
		double solvey();
	public:
		func(double a,double b,double c,double d,double e,double f);
		void add(func f);
		void de(func f);
		void init(double a0,double b0,double c0,double d0,double e0,double f0);
		void scfcz();
		void scfczg();
		~func(){}
};
func::func(double a,double b,double c,double d,double e,double f){
	init(a,b,c,d,e,f);
}
void func::add(func f){
	a+=f.a;
	b+=f.b;
	c+=f.c;
	d+=f.d;
	e+=f.e;
	this->f+=f.f;
	cout<<"��Ӻ�ķ�����Ϊ:";
	scfcz();
	cout<<"��Ӻ�ķ������Ϊ:";
	scfczg();
}
void func::de(func f){
	a-=f.a;
	b-=f.b;
	c-=f.c;
	d-=f.d;
	e-=f.e;
	this->f-=f.f;
	cout<<"�����ķ�����Ϊ:";
	scfcz();
	cout<<"�����ķ������Ϊ:";
	scfczg();
}
double func::solvex(){
	double d1=a*e-b*d;
	double d0=c*e-b*f;
	if(d1==0){
		cout<<"����������������޽�"<<endl;
		tp=false;
	}else{
		x=d0/d1;
	}
}
double func::solvey(){
	double d1=a*e-b*d;
	double d0=a*f-c*d;
	if(d1==0){
		cout<<"����������������޽�"<<endl;
		tp=false;
	}else{
		y=d0/d1;
	}
}
void func::scfcz(){
	if(a!=1&&a!=0){
		cout<<a<<"x+";
	}else if(a==1){
		cout<<"x+";
	}
	if(b!=1&&b!=0){
		cout<<b<<"y"; 
	}else if(b==1){
		cout<<"y=";
	}
	cout<<"="<<c<<endl;
	
	if(d!=1&&d!=0){
		cout<<d<<"x+";
	}else if(d==1){
		cout<<"x+";
	}
	if(e!=0&&e!=1){
		cout<<e<<"y";
	}else if(e==1){
		cout<<"y";
	}
	cout<<"="<<f<<endl; 
}
void func::init(double a0,double b0,double c0,double d0,double e0,double f0){
	a=a0;
	b=b0;
	c=c0;
	d=d0;
	e=e0;
	f=f0;
}
void func::scfczg(){
	solvex();
	solvey();
	if(tp==true){
		cout<<"x="<<x<<endl;
		cout<<"y="<<y<<endl;
	}
}
int main(){
	cout<<"�������һ���������6��ϵ��:";
	double a0,b0,c0,d0,e0,f0;
	cin>>a0>>b0>>c0>>d0>>e0>>f0;
	func a(a0,b0,c0,d0,e0,f0);
	cout<<"������ڶ����������6��ϵ��:";
	double a1,b1,c1,d1,e1,f1;
	cin>>a1>>b1>>c1>>d1>>e1>>f1;
	func b(a1,b1,c1,d1,e1,f1);
	cout<<"��һ��������Ϊ��"<<endl; 
	a.scfcz();
	cout<<"��һ���������Ϊ��"<<endl; 
	a.scfczg();
	cout<<"�ڶ���������Ϊ��"<<endl; 
	b.scfcz();
	cout<<"�ڶ����������Ϊ��"<<endl; 
	b.scfczg();
	func temp=a;
	a.add(b);
	temp.de(b);
}
