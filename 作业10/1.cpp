#include<iostream>
#include<cmath>
using namespace std;
class Ellipse{
	private:
		double x0;
		double y0;
		double a;
		double b;
		double s;
	public:
		Ellipse(double x0,double y0,double a,double b){
			this->x0=x0;
			this->y0=y0;
			this->a=a;
			this->b=b;
		}
		double gets(){
			s=M_PI*a*b;
			return s;
		}
		~Ellipse(){}
};
int main(){
	double x0,y0,a,b;
	cout<<"��������Բ��Բ�����꣬�볤�᳤������᳤��";
	cin>>x0>>y0>>a>>b;
	Ellipse e(x0,y0,a,b);
	cout<<"��Բ���Ϊ��"<<e.gets();
} 
