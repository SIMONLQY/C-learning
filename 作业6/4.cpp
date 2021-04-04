#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
char *mystrspc(char *string,int n);
int main(){
	int n;
	cout<<"请输入您想要的空白字符串长度：";
	cin>>n;
	char *string=new char[n+1];
	cout<<"结果为："; 
	cout<<"\""<<mystrspc(string,n)<<"\"";
	return 0;
} 

char *mystrspc(char *string,int n){
	for(int i=0;i<n;i++){
		string[i]=' ';
	}
	string[n]='\0';
	return string;
}

