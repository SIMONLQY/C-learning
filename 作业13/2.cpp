#include<iostream>
using namespace std;
int main(){
	cout.setf(ios::left);
	cout.width(12);
	cout<<"�����¶�";
	cout.width(12);
	cout<<"�����¶�"<<endl;
//	cout.unsetf(ios::left);
//	cout.setf(ios::left);
	for(int i=0;i<=212;i++){
		cout.width(12);
		cout<<i;
		double c=5.0/9.0*((double)i-32.0);
		cout.precision(3);
		cout.width(12);
		cout<<c;
		cout<<endl;
	}
	cout.unsetf(ios::left);
}
