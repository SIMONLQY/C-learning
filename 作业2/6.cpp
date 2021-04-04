#include<iostream>
#include<cmath>
#include<math.h>
using namespace std;
int main(){
	double a,b,c,d,e,f;
	double x,y;
	cout<<"请输入第一个方程的三个系数：";
	cin>>a>>b>>c;
	cout<<"请输入第二个方程的三个系数：";
	cin>>d>>e>>f;
	cout<<a<<"x+"<<b<<"y="<<c<<endl;
	cout<<d<<"x+"<<e<<"y="<<f<<endl;
	//方程组有唯一解 ，r1=2 
	if(a*e-b*d!=0) {
		cout<<"x="<<(c*e-b*f)/(a*e-b*d)<<endl;
	    cout<<"y="<<(a*f-c*d)/(a*e-b*d)<<endl;
	} else{ 
		if(a==0&&b==0&&d==0&&e==0){//r1=0 
			if(c==0&&f==0){//r2=0
				cout<<"此时x和y为任意常数均可";
			} else{//r2=1或者2 
				cout<<"此时方程组无解";
			}
		} else{//r1=1
			if(a*f-c*d!=0||b*f-c*e!=0){//r2=2
				cout<<"此时方程组无解";
			} else{//r2=1
				if(a==0&&b==0&&c==0){
					if(d==0){
						cout<<"x取任意常数"<<endl;
						cout<<"y="<<f/e<<endl;
					} else if(e==0){
						cout<<"y取任意常数"<<endl;
						cout<<"x="<<f/d<<endl;
					} else{
						cout<<"x取任意常数"<<endl;
						cout<<"y="<<"("<<f<<"-"<<d<<"x"<<")"<<"/"<<e<<endl;
					}
				} else if(d==0&&e==0&&f==0){
					if(a==0){
						cout<<"x取任意常数"<<endl;
						cout<<"y="<<c/b<<endl;
					} else if(b==0){
						cout<<"y取任意常数"<<endl;
						cout<<"x="<<c/a<<endl;
					} else{
						cout<<"x取任意常数"<<endl;
						cout<<"y="<<"("<<c<<"-"<<a<<"x"<<")"<<"/"<<b<<endl;
					}
				}else {
					if(d==0){
						cout<<"x取任意常数"<<endl;
						cout<<"y="<<f/e<<endl;
					} else if(e==0){
						cout<<"y取任意常数"<<endl;
						cout<<"x="<<f/d<<endl;
					} else{
						cout<<"x取任意常数"<<endl;
						cout<<"y="<<"("<<f<<"-"<<d<<"x"<<")"<<"/"<<e<<endl;
					}
				}
			}
		}
	}
	return 0;
}
