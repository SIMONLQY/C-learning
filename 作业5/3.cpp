#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int isprime(int a);

int main(){
	int n;
	cout<<"请输入n:";
	cin>>n;
	int k=0;
	cout<<"\n"<<n<<"以下所有素数为："<<endl;
	for(int i=2;i<=n;i++){
		if(isprime(i)==1){
			cout<<i<<"\t";
			k++;
			if(k==8){
				k=0;
				cout<<"\n";
			}
		}
	}
	return 0;
} 

int isprime(int a){
	for(int i=2;i<=sqrt(a);i++){
		if(a%i==0){
			return 0;
		}
	}
	return 1;
}
