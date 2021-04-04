#include<iostream>
#include<cstring>
using namespace std;
int panduan(char ccc[]);
int main(){
	char a[]="hjojoj";
	cout<<a<<endl;
	if(panduan(a)==0){
		cout<<"¸Ã×Ö·û´®·Ç¶Ô³Æ"<<endl;
	}else{
		cout<<"¸Ã×Ö·û´®Îª¶Ô³Æ×Ö·û´®"<<endl;
	}
	return 0;
} 

int panduan(char ccc[]){
	int len=strlen(ccc);
	if(len%2==0){
		for(int i=0;i<len/2;i++){
			if(ccc[i]!=ccc[len-i-1]){
				return 0;
			}
		}
		return 1;
	} else{
		for(int i=0;i<len/2-1;i++){
			if(ccc[i]!=ccc[len-i-1]){
				return 0;
			}
		}
		return 1;
	}
}


