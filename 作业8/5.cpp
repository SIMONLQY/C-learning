#include<iostream>
using namespace std;
int judge(long a);
void sc(long a); // 传的就是完全数 
int main(){
	for(long i=2;i<=100000;i++){
		if(judge(i)==1){
			sc(i);
		}else{
			continue;
		}
	}
}

int judge(long a){
	long sum=0;
	for(long i=1;i<a;i++){
		if(a%i==0){
			sum=sum+i;
		}
	}
	if(sum==a){
		return 1;
	}else{
		return 0;
	}
}

void sc(long a){
	cout<<a<<"=";
	for(int i=1;i<a;i++){
		if(a%i==0){
			if(i==1){
				cout<<1;
			}else{
				cout<<"+"<<i;
			}
		}
	}
	cout<<endl;
}


