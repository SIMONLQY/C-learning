#include<iostream>
using namespace std;
class a{
	public:
		double b;
	public:
		a(){
			b=0;
		}
		void operator ++(){
			b++;
		}
};
int main(){
	a c;
	c.operator ++(1);
	cout<<c.b;
}
