#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int atoi(char *string);
int main(){
	char string[15];
	cout<<"�������ַ���(����������)";
	cin>>string;
	cout<<"���ֽ��Ϊ��"<<atoi(string);
	return 0;
} 

int atoi(char *string){
	int n=strlen(string);
	int result=0;
	int *num=new int(n-1);
	for(int i=n-1;i>0;i--){
		num[i]=string[i]-'0';
		result=result+num[i]*pow(10,n-i-1);
	}
	if(string[0]=='-'){
		result=-1*result;
	}
	return result;
}

