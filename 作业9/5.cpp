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
	cout<<"�����������ε����߳�:";
	cin>>a>>b>>c;
	while(a+b<=c||a+c<=b||b+c<=a){
		cout<<"���������鲻�������Σ�����������:";
		cin>>a>>b>>c;
	}
	getS();
}
void tri::getS(){
	double p=(a+b+c)/2.0;
	s=sqrt(p*(p-a)*(p-b)*(p-c));
}
void tri::scS(){
	cout<<"��������ε����Ϊ��"<<s;
}
int main(){
	tri a;
	a.init();
	a.scS(); 
}
