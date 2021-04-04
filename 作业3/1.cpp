#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"请输入n"<<endl;
	cin>>n; 
	long jk0=1;
	long jk1=1;
	long jk2=2;
	long sum=2;
	for(int i=3;i<=n;i++) {
		jk2=jk0+jk1;
		sum=sum+jk2;
		jk0=jk1;
		jk1=jk2;
	}
	cout<<"斐波那契数列的第"<<n<<"项为"<<jk2<<endl;
	cout<<"斐波那契数列的前"<<n<<"项和为"<<sum; 
	return 0;
}
