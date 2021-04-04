#include<iostream>
#include<windows.h>
using namespace std;
class Dog{
	private:
		char name[30];
		int age;
		double weight;
		int sex;
	public:
		void setData(char *n,int a,double w,int s);
		void showInfo();
		void changeName();
		void changeAge();
		void changeWeight();
		void changeSex();
};
void Dog::setData(char *n,int a,double w,int s){
	strcpy(name,n);
	age=a;
	weight=w;
	sex=s;
}
void Dog::showInfo(){
	cout<<"当前小狗的信息如下："<<endl;
	cout<<"名字："<<name<<endl;
	cout<<"性别：";
	if(sex==1){
		cout<<"公"; 
	}else{
		cout<<"母";
	}
	cout<<endl;
	cout<<"年龄："<<age;
	cout<<"体重："<<weight<<"kg";
}
void Dog::changeName(){
	cout<<"你想把小狗的名字改成："<<endl;
	char a[30];
	cin.get();
	cin.get(a,30);
	strcpy(name,a);
}
void Dog::changeAge(){
	int a;
	cout<<"你想把小狗的年龄改成："<<endl;
	cin>>a;
	age=a;
}
void Dog::changeSex(){
	int a;
	cout<<"你想把小狗的性别改成(1:公 2:母)：";
	cin>>a;
	sex=a;
}
void Dog::changeWeight(){
	double a;
	cout<<"你想把小狗的体重改成："<<endl;
	cin>>a;
	weight=a;
}
int main(){
	Dog dog;
	dog.setData("Juddy",2,20,1);
	dog.showInfo();
	char a;
	do{
		cout<<"\n\n你想要改变小狗的(A:名字 B:年龄 C:体重 D:性别 E:我很满意它，什么都不改):";
	    cin>>a;
		switch(a){
			case 'A':
				dog.changeName();
				break;
			case 'B':
				dog.changeAge();
				break;
			case 'C':
				dog.changeWeight();
				break;
			case 'D':
				dog.changeSex();
				break;
		}
		dog.showInfo();
	}while(a!='E');
	dog.showInfo();
}
