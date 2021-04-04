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
	cout<<"��ǰС������Ϣ���£�"<<endl;
	cout<<"���֣�"<<name<<endl;
	cout<<"�Ա�";
	if(sex==1){
		cout<<"��"; 
	}else{
		cout<<"ĸ";
	}
	cout<<endl;
	cout<<"���䣺"<<age;
	cout<<"���أ�"<<weight<<"kg";
}
void Dog::changeName(){
	cout<<"�����С�������ָĳɣ�"<<endl;
	char a[30];
	cin.get();
	cin.get(a,30);
	strcpy(name,a);
}
void Dog::changeAge(){
	int a;
	cout<<"�����С��������ĳɣ�"<<endl;
	cin>>a;
	age=a;
}
void Dog::changeSex(){
	int a;
	cout<<"�����С�����Ա�ĳ�(1:�� 2:ĸ)��";
	cin>>a;
	sex=a;
}
void Dog::changeWeight(){
	double a;
	cout<<"�����С�������ظĳɣ�"<<endl;
	cin>>a;
	weight=a;
}
int main(){
	Dog dog;
	dog.setData("Juddy",2,20,1);
	dog.showInfo();
	char a;
	do{
		cout<<"\n\n����Ҫ�ı�С����(A:���� B:���� C:���� D:�Ա� E:�Һ���������ʲô������):";
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
