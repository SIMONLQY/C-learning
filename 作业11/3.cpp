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
class Line:public Point{
	private:
		Point startPoint;
		Point endPoint;
		double length;
	public:
		Line(double x1,double y1,double x2,double y2){
			setLine(x1,y1,x2,y2);
		};
		void setLine(double,double,double,double);
		void EndPoint();
		void show();
		~Line(){}
};
void Line::setLine(double x1,double y1,double x2,double y2){
	startPoint.setPoint(x1,y1);
	endPoint.setPoint(x2,y2);
}
void Line::EndPoint(){
	double x1=startPoint.getX();
	double x2=endPoint.getX();
	double y1=startPoint.getY();
	double y2=endPoint.getY();
	length=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
void Line::show(){
	cout<<"起点为：";
	startPoint.print();
	cout<<"终点为：";
	endPoint.print();
	cout<<"长度为："<<length;
}
int main(){
	Line l(2,3,4,5);
	l.show();
}
