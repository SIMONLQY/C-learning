#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
void my_static( char * str,int *count,int *upper,int *lower,int *digit,int *other);
int main(){
	char c[101];
	cout<<"�������ַ�����";
	cin.get(c,100);
	int count=strlen(c);
	int upper=0,lower=0,digit=0,other=0;
	my_static(c,&count,&upper,&lower,&digit,&other);
	cout<<"�ַ���������"<<count<<"���ַ�"<<endl;
	cout<<"��д��ĸ����"<<upper<<"��"<<endl;
	cout<<"Сд��ĸ����"<<lower<<"��"<<endl;
	cout<<"���ֹ���"<<digit<<"��"<<endl;
	cout<<"�����ַ�����"<<other<<"��"<<endl;
	return 0;
} 


void my_static( char * str,int *count,int *upper,int *lower,int *digit,int *other){
	for(int i=0;i<*count;i++){
		if(str[i]>='0'&&str[i]<='9'){
			(*digit)++;
		} else if(str[i]>='a'&&str[i]<='z'){
			(*lower)++;
		} else if(str[i]>='A'&&str[i]<='Z'){
			(*upper)++;
		} else{
			(*other)++;
		}
	}
}

