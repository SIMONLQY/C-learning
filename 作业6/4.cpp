#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
char *mystrspc(char *string,int n);
int main(){
	int n;
	cout<<"����������Ҫ�Ŀհ��ַ������ȣ�";
	cin>>n;
	char *string=new char[n+1];
	cout<<"���Ϊ��"; 
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

