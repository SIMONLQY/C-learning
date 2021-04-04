#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
class yzdg{
	protected:
		double r1;
		double h1;
		double v1;
		double s1;
		char words[50];
		void volume();
		void area();
	public:
		yzdg(char *words,double r1,double h1);
		void init(char *words,double r1,double h1);
		void output();
		bool operator >(yzdg);
		~yzdg(){}
};
bool yzdg::operator >(yzdg a){
	if(this->v1>a.v1){
		return true;
	}else{
		return false;
	}
}
yzdg::yzdg(char *words=(char*)"happy birthday",double r1=1,double h1=1){
	init(words,r1,h1);
}
void yzdg::init(char *words=(char*)"happy birthday",double r1=1,double h1=1){
	this->r1=r1;
	this->h1=h1;
	strcpy(this->words,words);
	volume();
	area();
}
void yzdg::volume(){
	v1=M_PI*r1*r1*h1;
}
void yzdg::area(){
	s1=2*M_PI*r1*h1+2*M_PI*r1*r1;
}
void yzdg::output(){
	cout<<"������Ϣ���£�"<<endl;
	cout<<"����ף�ʣ�"<<words<<endl;
	cout<<"Բ���ε�����Ϣ���£�"<<endl;
	cout<<"�뾶��"<<r1<<"  "<<"�ߣ�"<<h1<<"  "<<"���"<<v1<<endl; 
}
class doubleLayer:public yzdg{
	protected:
		double r2,h2,v2,s2,v,s;
		void volume();
		void area();
	public:
		doubleLayer(char *words=(char*)"happy",double r1=1,double h1=1,double r2=1,double h2=1){
			init(words,r1,h1,r2,h2);
		}
		void init(char *words,double r1,double h1,double r2,double h2);
		void output();
		bool operator >(doubleLayer);
		~doubleLayer(){}
};
bool doubleLayer::operator >(doubleLayer a){
	if(this->v1>a.v1){
		return true;
	}else{
		return false;
	}
}
void doubleLayer::init(char *words,double r1,double h1,double r2=1,double h2=1){
	this->r1=r1;
	this->h1=h1;
	strcpy(this->words,words);
	this->r2=r2;
	this->h2=h2;
	volume();
	area();
}
void doubleLayer::volume(){
	v1=M_PI*r1*r1*h1;
	v2=r2*r2*h2;
	v=v1+v2;
}
void doubleLayer::area(){
	s1=2*M_PI*r1*h1+2*M_PI*r1*r1;
	s2=2*r2*r2+4*r2*h2;
	s=s1+s2-r2*r2;
}
void doubleLayer::output(){
	cout<<"���㵰����Ϣ���£�"<<endl;
	cout<<"����ף�ʣ�"<<words<<endl;
	cout<<"Բ���ε�����Ϣ���£�"<<endl;
	cout<<"�뾶��"<<r1<<"  "<<"�ߣ�"<<h1<<"  "<<"�����"<<v1<<endl;
	cout<<"�����ε�����Ϣ���£�"<<endl;
	cout<<"�����α߳���"<<r2<<"  "<<"�ߣ�"<<h2<<"  "<<"�����"<<v2<<endl;
	cout<<"�������"<<v; 
}
class three:public doubleLayer{
	protected:
		double cz,dz,h3,v3,s3;
		void volume();
		void area();
	public:
		three(char *words=(char*)"happy",double r1=1,double h1=1,double r2=1,double h2=1,double cz=1,double dz=1,double h3=1){
			init(words,r1,h1,r2,h2,cz,dz,h3);
		}
		void init(char *words,double r1,double h1,double r2,double h2,double cz,double dz,double h3);
		void output();
		bool operator >(three);
		~three(){}
};
bool three::operator >(three a){
	if(this->v1>a.v1){
		return true;
	}else{
		return false;
	}
}
void three::init(char *words,double r1,double h1,double r2,double h2,double cz=4,double dz=2,double h3=1)
{
	this->r1=r1;
	this->h1=h1;
	strcpy(this->words,words);
	this->r2=r2;
	this->h2=h2;
	this->cz=cz;
	this->dz=dz;
	this->h3=h3;
	volume();
	area();
}
void three::volume(){
	v1=M_PI*r1*r1*h1;
	v2=r2*r2*h2;
	v3=cz*dz/2.0*h3;
	v=v1+v2+v3;
}
void three::area(){
	s1=2*M_PI*r1*h1+2*M_PI*r1*r1;
	s2=2*r2*r2+4*r2*h2;
	s3=cz*dz+4*sqrt((cz/2)*(cz/2)+(dz/2)*(dz/2))*h3;
	s=s1+s2+s3-r2*r2-cz*dz/2;
}
void three::output(){
	cout<<"���㵰����Ϣ���£�"<<endl;
	cout<<"����ף�ʣ�"<<words<<endl;
	cout<<"Բ���ε�����Ϣ���£�"<<endl;
	cout<<"�뾶��"<<r1<<"  "<<"�ߣ�"<<h1<<"  "<<"�����"<<v1<<endl;
	cout<<"�����ε�����Ϣ���£�"<<endl;
	cout<<"�����α߳���"<<r2<<"  "<<"�ߣ�"<<h2<<"  "<<"�����"<<v2<<endl;
	cout<<"���ε�����Ϣ���£�"<<endl;
	cout<<"���᣺"<<cz<<"  "<<"���᣺"<<dz<<"  "<<"�����" <<v3<<endl;
	cout<<"�������"<<v; 
}
int main(){
	three t;
	cout<<"�������һ�����⣺ף�ʣ��뾶���ߣ������α߳����ߣ����γ��ᣬ���ᣬ��:"<<endl;
	char happy[50];
	cin.get(happy,49);
	cin.get();
	double a[7];
	for(int i=0;i<7;i++){
		cin>>a[i];
	}
	t.init(happy,a[0],a[1],a[2],a[3],a[4],a[5],a[6]);
	t.output();
	cin.get();
	cout<<"\n������ڶ������⣺ף�ʣ��뾶���ߣ������α߳����ߣ����γ��ᣬ���ᣬ��:"<<endl;
	three t1;
	char happy1[50];
	cin.get(happy1,49);
	cin.get();
	double a1[7];
	for(int i=0;i<7;i++){
		cin>>a1[i];
	}
	t1.init(happy1,a1[0],a1[1],a1[2],a1[3],a1[4],a1[5],a1[6]);
	t1.output();
	if(t>t1){
		cout<<"\n��һ�������";
	}else{
		cout<<"�ڶ��������";
	}
}
