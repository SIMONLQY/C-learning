#include<iostream>
using namespace std;
int main(){
	char a;
	cout.width(12);
	cout<<"十进制";
	cout.width(12);
	cout<<"八进制";
	cout.width(12);
	cout<<"十六进制";
	cout.width(12);
	cout<<"字符";
	cout<<endl;
	for(int i=33;i<=126;i++){
		a=i;
		cout.width(12);
		cout<<dec<<i;
		cout.width(12);
		cout<<oct<<i;
		cout.width(12);
		cout<<hex<<i<<dec;
		cout.width(12);
		cout<<a;
		cout<<endl;
	}
	return 0;
}
