#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int search(char *t,char *s);
int main(){
	char a[]="i love you i love you";
	char b[]="i love you";
	cout<<"ԭ�ַ����ǣ�"<<a<<endl;
	cout<<"�Ӵ��ǣ�"<<b<<endl;
	cout<<"ԭ�ַ����й����Ӵ�"<<search(a,b)<<"��";
	return 0;
}

int search(char *t,char *s){
	int t0=strlen(t);
	int s0=strlen(s);
	bool m=false;
	int k=0;
	for(int i=0;i<t0;i++){
		if(t[i]==s[0]){
			m=true;
			for(int j=i;j<m+i;j++){
				if(t[j]!=s[j-i]){
					m=false;
				}
			}
			if(m==true){
				k++;
			}
		}
	}
	return k;
}
