#include<iostream>
#include<cmath>
using namespace std;
class Point{
	double x,y;
	public:
		Point(double x,double y);
		void setPoint(double,double);
		double getX(){
			return x;
		}
		double getY(){
			return y;
		}
		void print();
		~Point(){}
};
void Point::setPoint(double a,double b){
	x=a;
	y=b;
}
Point::Point(double x=0.0,double y=0.0){
	this->x=x;
	this->y=y;
}
void Point::print(){
	cout<<'['<<x<<","<<y<<']'<<endl;
}
class Circle:public Point{
	double radius;
	public:
		Circle(int x=0,int y=0,double r=0):Point(x,y){
			SetRadius(r);
		}
		virtual void SetRadius(double r){
			this->radius=r;
		}
		virtual double GetRadius(){
			return radius;
		}
		virtual double Area(){
			return M_PI*radius*radius;
		}
		virtual void Print(){
			cout<<"Center=";
			Point::print();
			cout<<"; Radius="<<radius<<endl;
		}
		~Circle(){}
};
class zfx:public Circle{
	public:
		zfx(int x=0,int y=0,double r=0):Circle(x,y,r){};
		double Area(){
			return GetRadius()*GetRadius();
		}
		void Print(){
			cout<<"正方形的边长为："<<GetRadius();
			cout<<";正方形的面积为："<<Area()<<endl;
		}
		~zfx(){}
};
class cylinder:public Circle{
	Circle cir;
	double h;
	public:
		cylinder(Circle r,double h=0):cir(r){
			this->h=h;
		}
		double V(){
			return M_PI*cir.GetRadius()*cir.GetRadius()*h;
		}
		void Print(){
			cout<<"圆柱体的底面半径为："<<cir.GetRadius();
			cout<<";圆柱体的高为："<<h;
			cout<<";圆柱体的体积为："<<V();
		}
		~cylinder(){}
};
int main(){
	Circle t(0,0,5);
	zfx a(0,0,5);
	cylinder c(t,5);
	a.Print();
	c.Print();
}
