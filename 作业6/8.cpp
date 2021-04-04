#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
char *jiami(char *mingwen);
int main(){
	char mingwen[51];
	cout<<"请输入字符串明文：";
	cin.get(mingwen,50);
	cout<<"明文是："<<mingwen<<endl;
	cout<<"密文是："<<jiami(mingwen)<<endl;
	return 0;
} 

char *jiami(char *mingwen){
	int n=strlen(mingwen);
	int a=n/2;
	int b=(n+1)/2;
	char *ji=new char[n+2];
	char *ou=new char[n+2];
	int i;
	for(i=0;i<a;i++){
		ou[a-1-i]=mingwen[2*i+1];
	}
	for(i=0;i<b;i++){
		ji[b-1-i]=mingwen[2*i];
	}
	strcat(ou,ji);
	return ou;
}

