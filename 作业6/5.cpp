#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
char *f(char *p, char *s);
int main(){
	char p[51];
	char s[50];
	cout<<"请输入目标字符串:";
	cin>>p;
	cout<<"请输入你想要删除的子字符串：";
	cin>>s;
	cout<<"删除结果为："<<f(p,s);
	return 0;
} 

char* f(char *p, char *s){
	int n=strlen(p);
	int m=strlen(s);
	bool t=false;
	int i=0;
	for(i=0;i<n;i++){
		if(p[i]==s[0]){
			t=true;
			for(int j=0;j<m;j++){
				if(p[i+j]!=s[j]){
					t=false;
				}
			}
			if(t==true){
				int j=i;
				for(;j<n;j++){
					p[j]=p[j+m];
				}
				p[j]='\0';
				i=i-1;
			}
		}
	}
	return p;
}

