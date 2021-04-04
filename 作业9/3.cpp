#include<iostream>
#include<cmath>
using namespace std;
class Ellipse{
	private:
		double x0;
		double y0;
		double x1;
		double y1;
		double s;
		void getS();
	public:
	    void setInfo(double x0,double y0,double x1,double y1);
		void showInfo(); 
};
void Ellipse::getS(){
	double a=(x1-x0)/2.0;
	double b=(y0-y1)/2.0;
	s=M_PI*a*b;
}
void Ellipse::setInfo(double x01,double y01,double x11,double y11){
	x0=x01;
	y0=y01;
	x1=x11;
	y1=y11;
}
void Ellipse::showInfo(){
	cout<<"这个椭圆左上角点的坐标为："<<"("<<x0<<","<<y0<<"),";
	cout<<"右下角点的坐标为："<<"("<<x1<<","<<y1<<")"<<endl;
	cout<<"它的面积为："<<s;
}
int main(){
	Ellipse e;
	e.setInfo(1,1,2,2);
	e.showInfo();
} 
