#include<iostream>
#include <cmath>
using namespace std;
int main(){
	double a=-1, b=1;
	double h;
	double sum=0;
	int n=1000;
	int i=0;
	h = (b-a)/n;
	while(i<n)
	{
		sum=sum+(sin(a+i*h)+exp(a+i*h)+sin(a+(i+1)*h)+exp(a+(i+1)*h))*h/2;
		i=i+1;
	}
	cout<<"sin(x)+e^x 在-1到1区间上的定积分值为： " << sum << endl;
	return 0;
}
 
