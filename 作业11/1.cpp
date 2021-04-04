#include<iostream>
#include<cstring>
using namespace std;
class Person{
	protected:
		char Name[20];
		char Sex;
		int Age;
	public:
		Person(char *name,int age,char sex){
			Register(name,age,sex);
		}
		void Register(char *name,int age, char sex){
			strcpy(Name,name);
			Age=age;
			Sex=(sex=='m'?'m':'f');
		} 
		void ShowMe(){
			cout<<Name<<'\t'<<Age<<'\t'<<Sex<<endl;
		}
		~Person(){} 
};
class Teacher:public Person{
	char major[20];
	char pro[20];
	char course[20];
	public:
		Teacher(char *name,int age, char sex,char *major,char *pro,char *course):Person(name,age,sex){
			strcpy(this->major,major);
			strcpy(this->pro,pro);
			strcpy(this->course,course);
		}
		void change_data(char *name,int age, char sex,char *major,char *pro,char *course);
		void show_data();
		~Teacher(){}
};
void Teacher::change_data(char *name="wu",int age=1, char sex='m',char *major="math",char *pro="math",char *course="math"){
	Register(name,age,sex);
	strcpy(this->major,major);
	strcpy(this->pro,pro);
	strcpy(this->course,course);
}
void Teacher::show_data(){
	ShowMe();
	cout<<"专业："<<major<<endl;
	cout<<"职称："<<pro<<endl;
	cout<<"主讲课程："<<course<<endl;
}
int main(){
	Teacher t("Simon",24,'m',"math","professor","math");
	cout<<"初始值："<<endl;
	t.show_data();
	t.change_data("Simon",30,'m',"math","professor","math");
	cout<<"修改之后："<<endl;
	t.show_data();
}
