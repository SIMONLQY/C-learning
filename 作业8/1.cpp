#include<iostream>
using namespace std;
enum sex{Man, Woman};
struct Student{
	char name[20];
	sex s;
	int birthyear;
};
int main(){
	Student s[5];
	cout<<"请输入5位同学的姓名，性别(男（M），女（F）)，出生年份:"<<endl;
	for(int i=0;i<5;i++){
		cin>>s[i].name;
		char sex;
		cin>>sex;
		if(sex=='M'){
			s[i].s=Man;
		}else{
			s[i].s=Woman;
		}
		cin>>s[i].birthyear;
	}
	int m=0,f=0,d=0;
	for(int i=0;i<5;i++){
		if(s[i].s==Man){
			m++;
		}else{
			f++;
		}
		if(s[i].birthyear>=1988){
			d++;
		}
	}
	cout<<"这五个人中,男人共有"<<m<<"个"<<"女人共有"<<f<<"个。"<<endl;
	cout<<"1988年之后（含1988年）出生的人有"<<d<<"个"; 
	return 0; 
} 
