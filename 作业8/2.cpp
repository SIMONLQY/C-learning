#include<iostream>
#include<cstring>
using namespace std;
struct Clients{
	char name[20];
	char phoneNumber[12];
};
void Sort(Clients *s,int count){
	for(int i=count-1;i>=0;i--){
		for(int j=0;j<i;j++){
			if(strcmp(s[j].name,s[j+1].name)>0){
				Clients tmp=s[j];
				s[j]=s[j+1];
				s[j+1]=tmp;
			}
		}
	}
}
int main(){
	Clients s[5];
	cout<<"请输入5个用户的姓名和电话号码:"<<endl;
	for(int i=0;i<5;i++){
		cin>>s[i].name>>s[i].phoneNumber;
	}
	Sort(s,5);
	cout<<"\n"; 
	for(int i=0;i<5;i++){
		cout<<s[i].name<<"  "<<s[i].phoneNumber<<endl;
	}
	return 0;
}
