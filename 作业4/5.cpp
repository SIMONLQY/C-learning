#include<iostream>
#include<cstring>
using namespace std;
int main(){
	const int COUNT=30;
	char all[COUNT];
	cout<<"请输入密文：";
	cin.get(all,COUNT-1);
	for(int i=0;i<COUNT;i++){
		if(all[i]>=97&&all[i]<=122){
			if(all[i]-3<97){
				all[i]=all[i]-3+26;
			}else{
				all[i]=all[i]-3;
			}
		} else if(all[i]>=65&&all[i]<=90){
			if(all[i]-3<65){
				all[i]=all[i]-3+26;
			}else{
				all[i]=all[i]-3;
			}
		} else if(all[i]>=48&&all[i]<=57){
			if(all[i]-3<48){
				all[i]=all[i]-3+10;
			}else{
				all[i]=all[i]-3;
			}
		}
	}
	cout<<"明文为："<<all;
	return 0;
}
