#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main(){
	ifstream a("mingwen.txt");
	ofstream b("miwen.txt");
	char mingwen[50];
	a.get(mingwen,49);
	a.close();
	char miwen[50];
	strcpy(miwen,mingwen);
	for(int i=0;i<strlen(mingwen);i++){
		if((miwen[i]>='a'&&miwen[i]<='v')||(miwen[i]>='A'&&miwen[i]<='V')){
			miwen[i]+=4;
		}else if((miwen[i]>'v'&&miwen[i]<='z')||(miwen[i]>'V'&&miwen[i]<='Z')){
			miwen[i]='a'-1+4-('z'-miwen[i]);
		}else if(miwen[i]>='0'&&miwen[i]<='5'){
			miwen[i]+=4;
		}else if(miwen[i]>'5'&&miwen[i]<='9'){
			miwen[i]='0'-1+4-('9'-miwen[i]);
		}
	}
	b<<miwen;
	b.close();
}
