#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char all[15];
	char allNumber[15];
	char X[3];
	X[0]='-';
	X[2]='\0';
	cout<<"������11 λ�ַ���� ISBN �ַ�����"<<endl;
	cin.get(all,15);
	//��ȡ���� 
	int j=0;
	for(int i=0;i<15;i++){
		if(all[i]>=48&&all[i]<=57){
			allNumber[j]=all[i]-48;
			j++;
		}
	}
	//����S��N 
	int S=0;
	for(int i=0;i<9;i++){
		S=S+allNumber[i]*(10-i);	
	}
	int N=11-S%11;
	//����У��ֵ 
	if(N==10){
		X[1]='X';
	} else if(N==11){
		X[1]='0';
	} else{
		X[1]=N+48;
	}
	cout<<"У����Ϊ��"<<X[1]<<endl;
	strcat(all,X);
	cout<<"������ ISBN �ַ���:"<<all;
	return 0;
}
