#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ifstream in("data.txt");
	if(!in){
		cout<<"文件读取失败，请重试."<<endl;
	}
	int nowline=1;
	int bigline=1;
	int lineNum=0;
	int biglineNum=0;
	int big=0;
	int small=0;
	int number=0;
	int other=0;
	char a;
	while(in){
		in.get(a);
		if(a>='A'&&a<='Z'){
			big++;
		}else if(a>='a'&&a<='z'){
			small++;
		}else if(a>='0'&&a<='9'){
			number++;
		}else if(a!='\n'){
			other++;
		}
		lineNum++;
		if(a=='\n'){
			if(lineNum>=biglineNum){
				biglineNum=lineNum;
				bigline=nowline;
			}
			nowline++;
			lineNum=0;
		}
	}
	in.close();
	cout<<"大写字母"<<big<<"个"<<endl;
	cout<<"小写字母"<<small<<"个"<<endl;
	cout<<"数字"<<number<<"个"<<endl;
	cout<<"其他字符"<<other<<"个"<<endl;
	cout<<"最长行行数："<<bigline<<endl;
}
