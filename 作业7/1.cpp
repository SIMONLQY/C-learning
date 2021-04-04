#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
double cf(double x, int k);
int main(){
	double x;
	int k;
	cout<<"ÇëÊäÈëx:";
	cin>>x;
	cout<<"ÇëÊäÈëk:";
	cin>>k;
	cout<<x<<"^"<<k<<"="<<cf(x,k);
	return 0;
} 

double cf(double x, int k){
	if(k>1){
		x=x*cf(x,k-1);
	}
	return x;
}
