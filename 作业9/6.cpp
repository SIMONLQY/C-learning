#include<iostream>
using namespace std;
class func{
	private:
		double a,b,c,d,e,f,x,y;
		bool tp=true; // 判断是否只有一个解 
		double solvex();
		double solvey();
	public:
		void init(double a0,double b0,double c0,double d0,double e0,double f0);
		void scfcz();
		void scfczg();
};
double func::solvex(){
	double d1=a*e-b*d;
	double d0=c*e-b*f;
	if(d1==0){
		cout<<"方程组有无穷多解或无解";
		tp=false;
	}else{
		x=d0/d1;
	}
}
double func::solvey(){
	double d1=a*e-b*d; 
	double d0=a*f-c*d;
	if(d1==0){
		cout<<"方程组有无穷多解或无解";
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
		cout<<"方程组的解为："<<endl;
		cout<<"x="<<x<<endl;
		cout<<"y="<<y<<endl;
	}
}
int main(){
	func a;
	cout<<"请输入方程组的6个系数:";
	double a0,b0,c0,d0,e0,f0;
	cin>>a0>>b0>>c0>>d0>>e0>>f0;
	a.init(a0,b0,c0,d0,e0,f0); 
	a.scfcz();
	a.scfczg();
}
