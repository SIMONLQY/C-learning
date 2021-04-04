#include<iostream>
#include<cstring>
using namespace std;
class Person{ // 人 
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
class Teacher:public Person{ // 老师 
    protected:
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
void Teacher::change_data(char *name=(char*)"wu",int age=1, char sex='m',char *major=(char*)"math",char *pro=(char*)"math",char *course=(char*)"math"){
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
class Student:public Person{ // 学生 
    protected:
		char Id[12];
		char Class[12];
	public:
		Student(char *name,int age,char sex,char *id,char *Class);
		void show_sdata();
		~Student(){}
};
Student::Student(char *name=(char*)"simon",int age=1,char sex='m',char *id=(char*)"12345678912",char *Class="class 2"):Person(name,age,sex){
	strcpy(Id,id);
	strcpy(this->Class,Class);
}
void Student::show_sdata(){
	ShowMe();
	cout<<"ID:"<<Id<<endl;
	cout<<"Class:"<<Class<<endl; 
}
class Graduates:public Student,public Teacher{
	private:
		char subject[10];
	public:
		Graduates(char *name,int age,char sex,char *id,char *Class,char *major,char *pro,char *course,char *subject)
		:Student(name,age,sex,id,Class),Teacher(name,age,sex,major,pro,course){
			strcpy(this->subject,subject);
		}
		void show();
		~Graduates(){}
};
void Graduates::show(){
	show_sdata();
	cout<<"专业："<<major<<endl;
	cout<<"职称："<<pro<<endl;
	cout<<"主讲课程："<<course<<endl;
	cout<<"研究课题："<<subject<<endl;
}
int main(){
	Graduates g("Simon",25,'m',"123456","class 2","math","graduate","math","high level math");
	g.show();
	return 0;
}
