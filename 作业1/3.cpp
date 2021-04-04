#include<iostream>
using namespace std;
int main(){
	int a,b;
	cout<<"请输入整数1（二位）：";
	cin>>a;
	cout<<"\n请输入整数2（二位）：";
	cin>>b;
	if(a>b){
		cout<<"\n"<<a*100+b;
	} else {
		cout<<"\n"<<b*100+a;
	}
	return 0;
}
 
