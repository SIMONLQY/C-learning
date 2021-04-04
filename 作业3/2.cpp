#include<iostream>
#include<windows.h>
#include<cmath>
using namespace std;
int main(){
	double x0=2.0;
	double x1=6.0;
	double fx0=pow(x0,3)-5*pow(x0,2)+16*x0-80;
	double fx1=pow(x1,3)-5*pow(x1,2)+16*x1-80;
	double x2=x0-(((x0-x1)/(fx0-fx1))*fx0);
	double fx2=pow(x2,3)-5*pow(x2,2)+16*x2-80;
	if(fx2==0){
			cout<<"方程解为x="<<x2<<endl;
	} else{
		while(fabs(x2-x0)>=0.001&&fabs(x2-x1)>=0.001){
		    if(fx2*fx0>0){
		    	x0=x2;
		    	x2=x0-(((x0-x1)/(fx0-fx1))*fx0);
		    	fx0=pow(x0,3)-5*pow(x0,2)+16*x0-80;
		    	fx2=pow(x2,3)-5*pow(x2,2)+16*x2-80;
			}else{
				x1=x2;
				x2=x0-(((x0-x1)/(fx0-fx1))*fx0);
		    	fx1=pow(x1,3)-5*pow(x1,2)+16*x1-80;
		    	fx2=pow(x2,3)-5*pow(x2,2)+16*x2-80;
				
			}
	    }
	    cout<<"方程解为x="<<x2;
	}
	return 0;
}
