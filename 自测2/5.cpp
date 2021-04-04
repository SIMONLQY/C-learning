#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ofstream out("mytest.txt");
	ifstream in;
	if(!in||!out){
		cout<<" 文件打开失败，请重试"<<endl;
		return 1;
	}
	int k=0;
	for(int i=0;i<1;i++){
		out<<"word";
		k++;
		if(k==5){
			k=0;
			out<<'\n'; 
			continue;
		}
		out<<' ';
	}
	out.close();
	int j=0;
	int l=0;
	char s;
	in.open("mytest.txt");
	while(in){
		in.get(s);
		cout<<1;
		l+=2;
		if(s==' '||s=='\n'){
			j++;
		}
	}
	in.close();
	out.open("mytest.txt",ios::app);
	out<<'\n';
	out<<"总单词数："<<j<<"个"<<endl;
	out<<"总文件长度："<<l<<endl;
	out.close();
}
