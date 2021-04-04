#include<iostream>
using namespace std;
int main(){
	char a,b,c,am,bm,cm;
	cout<<"请输入一个含3个字母的单词(小写):";
	cin>>a>>b>>c;
	if(a+5>122){
		am=a-26+5;
		bm=b+5;
	    cm=c+5;
	}else if(b+5>122){
		am=a+5;
		bm=b-26+5;
		cm=c+5;
	}else if(c+5>122){
		am=a+5;
	    bm=b+5;
		cm=c-26+5;
	}else{
		am=a+5;
	    bm=b+5;
	    cm=c+5;
	}
	cout<<"密文:"<<am<<bm<<cm;
	return 0;
}
