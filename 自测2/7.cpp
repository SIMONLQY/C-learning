#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ifstream in("data.txt");
	if(!in){
		cout<<"�ļ���ȡʧ�ܣ�������."<<endl;
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
	cout<<"��д��ĸ"<<big<<"��"<<endl;
	cout<<"Сд��ĸ"<<small<<"��"<<endl;
	cout<<"����"<<number<<"��"<<endl;
	cout<<"�����ַ�"<<other<<"��"<<endl;
	cout<<"���������"<<bigline<<endl;
}
