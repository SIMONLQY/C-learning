#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
int main(){
	char a[30];
	cout<<"请输入你想要复制的cpp文件地址：";
	cin>>a;
	ifstream in(a);
	if(!in){
		cout<<"文件不存在";
		return 1;
	}
	for(int i=0;i<strlen(a);i++){
		if(a[i]=='.'){
			a[i]='\0';
			break;
		}
	}
	char b[35];
	b[0]='\0';
	strcat(b,a);
	strcat(b,".prn");
	ofstream out(b);
	char cpp;
	while(in){
		in.get(cpp);
		out<<cpp;
	}
//	in.get(cpp,500,'[[\]]');
	in.close();
	out.close();
}
