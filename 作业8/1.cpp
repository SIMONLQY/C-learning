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
	cout<<"������5λͬѧ���������Ա�(�У�M����Ů��F��)���������:"<<endl;
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
	cout<<"���������,���˹���"<<m<<"��"<<"Ů�˹���"<<f<<"����"<<endl;
	cout<<"1988��֮�󣨺�1988�꣩����������"<<d<<"��"; 
	return 0; 
} 
