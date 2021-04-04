#include<iostream>
#include<cmath>
using namespace std;
class three{
	protected:
		double d,c,b,a;
		double qiuzhi(double t);
		double dao(double t);
	public:
		three(double d,double c,double b,double a);
		void scfc();
		double qiugen(double t);
		void scgen(double t);
		void xj(three t);
		~three(){}
};
three::three(double d=1,double c=1,double b=1,double a=1){
	this->a=a;
	this->b=b;
	this->c=c;
	this->d=d;
}
void three::scfc(){
	if(d!=0&&d!=1&&d!=-1){
		cout<<d;
		cout<<"x^3";
	}else if(d==1){
		cout<<"x^3";
	}else if(d==-1){
		cout<<"-x^3";
	}
	if(c!=0&&c!=1&&c!=-1){
		if(c<0){
			cout<<c;
		}else{
			cout<<"+"<<c;
		}
		cout<<"x^2";
	}else if(c==1){
		cout<<"+x^2";
	}else if(c==-1){
		cout<<"-x^2";
	}
	if(b!=0&&b!=1&&b!=-1){
		if(b<0){
			cout<<b;
		}else{
			cout<<"+"<<b;
		}
		cout<<"x";
	}else if(b==1){
		cout<<"+x";
	}else if(b==-1){
		cout<<"-x";
	}
	if(a>0){
		cout<<"+"<<a;
	}else if(a<0){
		cout<<a;
	}
	cout<<"="<<"0";
	cout<<endl;
}
double three::qiuzhi(double t){
	double result=d*pow(t,3)+c*pow(t,2)+b*t+a;
	return result;
}
double three::dao(double t){
	double result=3*d*pow(t,2)+2*c*t+b;
	return result;
}
double three::qiugen(double t){
	double gen;
	gen=t-qiuzhi(t)/dao(t);
	if(fabs(qiuzhi(gen))>=pow(10,-7)&&fabs(gen-t)>=pow(10,-7)){
		gen=qiugen(gen);
	}
	return gen;
}
void three::scgen(double t){
	cout<<"方程在"<<t<<"附近的根为"<<qiugen(t)<<endl;
}
void three::xj(three t){
	d+=t.d;
	c+=t.c;
	b+=t.b;
	a+=t.a;
}
class four:public three{
	protected:
		double e;
		double qiuzhi(double t);
		double dao(double t);
	public:
		four(double,double,double,double,double);
		void scfc();
		void xj(four t);
		void scgen(double t);
		double qiugen(double t);
		~four(){}
};
four::four(double e,double d,double c,double b,double a):three(d,c,b,a){
	this->e=e;
}
double four::qiugen(double t){
	double gen;
	gen=t-qiuzhi(t)/dao(t);
	if(fabs(qiuzhi(gen))>=pow(10,-7)&&fabs(gen-t)>=pow(10,-7)){
		gen=qiugen(gen);
	}
	return gen;
}
void four::scgen(double t){
	cout<<"方程在"<<t<<"附近的根为"<<qiugen(t)<<endl;
}
double four::qiuzhi(double t){
	double result=e*pow(t,4)+d*pow(t,3)+c*pow(t,2)+b*t+a;
	return result;
}
double four::dao(double t){
	double result=4*e*pow(t,3)+3*d*pow(t,2)+2*c*t+b;
	return result;
}
void four::scfc(){
	if(e!=0&&e!=1&&e!=-1){
		cout<<e<<"x^4";
	}else if(e==1){
		cout<<"x^4";
	}else if(e==-1){
		cout<<"-x^4";
	}
	if(d!=0&&d!=1&&d!=-1){
		if(d<0){
			cout<<d;
		}else{
			cout<<"+"<<d;
		}
		cout<<"x^3";
	}else if(d==1){
		cout<<"+x^3";
	}else if(d==-1){
		cout<<"-x^3";
	}
	if(c!=0&&c!=1&&c!=-1){
		if(c<0){
			cout<<c;
		}else{
			cout<<"+"<<c;
		}
		cout<<"x^2";
	}else if(c==1){
		cout<<"+x^2";
	}else if(c==-1){
		cout<<"-x^2";
	}
	if(b!=0&&b!=1&&b!=-1){
		if(b<0){
			cout<<b;
		}else{
			cout<<"+"<<b;
		}
		cout<<"x";
	}else if(b==1){
		cout<<"+x";
	}else if(b==-1){
		cout<<"-x";
	}
	if(a>0){
		cout<<"+"<<a;
	}else if(a<0){
		cout<<a;
	}
	cout<<"="<<"0";
	cout<<endl;
}
void four::xj(four t){
	e+=t.e;
	d+=t.d;
	c+=t.c;
	b+=t.b;
	a+=t.a;
}
int main(){
	three m(1,12,48,64);
	m.scfc();
	m.scgen(-4.5);
	four m1(1,-10,35,-50,24);
	m1.scfc();
	m1.scgen(4.5);
}
