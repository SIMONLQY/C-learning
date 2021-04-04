#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char all[15];
	char allNumber[15];
	char X[3];
	X[0]='-';
	X[2]='\0';
	cout<<"请输入11 位字符组成 ISBN 字符串："<<endl;
	cin.get(all,15);
	//提取数字 
	int j=0;
	for(int i=0;i<15;i++){
		if(all[i]>=48&&all[i]<=57){
			allNumber[j]=all[i]-48;
			j++;
		}
	}
	//计算S和N 
	int S=0;
	for(int i=0;i<9;i++){
		S=S+allNumber[i]*(10-i);	
	}
	int N=11-S%11;
	//计算校验值 
	if(N==10){
		X[1]='X';
	} else if(N==11){
		X[1]='0';
	} else{
		X[1]=N+48;
	}
	cout<<"校验码为："<<X[1]<<endl;
	strcat(all,X);
	cout<<"完整的 ISBN 字符串:"<<all;
	return 0;
}
