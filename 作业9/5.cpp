#include<iostream>
#include<cmath>
using namespace std;
class tri{
	private:
		double a;
		double b;
		double c;
		double s;
		void getS();
	public:
		void init();
		void scS();
};
void tri::init(){
	cout<<"请输入三角形的三边长:";
	cin>>a>>b>>c;
	while(a+b<=c||a+c<=b||b+c<=a){
		cout<<"输入数据组不成三角形，请重新输入:";
		cin>>a>>b>>c;
	}
	getS();
}
void tri::getS(){
	double p=(a+b+c)/2.0;
	s=sqrt(p*(p-a)*(p-b)*(p-c));
}
void tri::scS(){
	cout<<"这个三角形的面积为："<<s;
}
int main(){
	tri a;
	a.init();
	a.scS(); 
}
