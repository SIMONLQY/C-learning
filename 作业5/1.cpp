#include<iostream>
#include<cstring>
using namespace std;
void mystrrev(char string[]);
int main(){
	char a[80];
	cout<<"ÇëÊäÈë×Ö·û´®£º";
	cin.get(a,80);
	mystrrev(a);
	cout<<"º¯Êý´¦Àíºó×Ö·û´®:"<<a;
	return 0;
} 

void mystrrev(char string[]){
	char restring[strlen(string)+2];
	for(int i=0;i<strlen(string)/2;i++){
		char cmp='a';
		cmp=string[i];
		string[i]=string[strlen(string)-1-i];
		string[strlen(string)-1-i]=cmp;
	}
}
