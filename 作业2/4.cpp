#include<iostream>
using namespace std;
int main(){
	char a,b,c,am,bm,cm;
	cout<<"������һ����3����ĸ�ĵ���(Сд):";
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
	cout<<"����:"<<am<<bm<<cm;
	return 0;
}
