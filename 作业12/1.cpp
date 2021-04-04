#include<iostream>
using namespace std;
class Base{
	public:
		virtual void display(){
			cout<<"Base's display"<<endl;
		}
};
class FirstB:public Base{
	public:
		void display(){
			cout<<"FirstB's display"<<endl;
		}
};
class SecondB:public Base{
	public:
		void display(){
			cout<<"SecondB's display"<<endl;
		}
};

int main(){
	Base* a;
	Base b1;
	FirstB b2;
	SecondB b3;
	a=&b1;
	a->display();
	a=&b2;
	a->display();
	a=&b3;
	a->display();
} 
