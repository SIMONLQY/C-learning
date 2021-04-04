#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int ifadd(long a);

int main(){
	int k=0;
	for(long i=0;i<=9999999;i++){
		if(ifadd(i)==1){
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

int ifadd(long a){
	for(int i=0;i<=8;i++){
		long jkl=pow(10,i);
		long jkll=pow(10,i+1);
		if(a<jkl){
			break;
		}else if(a/jkl%10<a/jkll%10){
			return 0;
		}
	}
	return 1;
}
