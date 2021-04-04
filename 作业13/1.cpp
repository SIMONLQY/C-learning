#include<iostream>
using namespace std;
int main(){
	for(int i=0;i<=10;i++){
		cout.width(i);
		cout<<12345<<endl;
		cout.width(i);
		cout<<1.2345<<endl;
	}
}
