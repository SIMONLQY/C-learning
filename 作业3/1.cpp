#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"������n"<<endl;
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
	cout<<"쳲��������еĵ�"<<n<<"��Ϊ"<<jk2<<endl;
	cout<<"쳲��������е�ǰ"<<n<<"���Ϊ"<<sum; 
	return 0;
}
