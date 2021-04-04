#include<iostream>
using namespace std;
class room{
	protected:
	    double a,b,c;
	    double s,v;
	public:
		room(double a=1,double b=1,double c=1){
			setData(a,b,c);
		}
		virtual void setData(double a=1,double b=1,double c=1){
			this->a=a;
			this->b=b;
			this->c=c;
			s=gets();
			v=getv();
		}
		virtual void showData(){
			cout<<"С�������Ϣ���£�"<<endl;
			cout<<"����"<<a<<"  ��"<<b<<"  ��"<<c<<endl; 
			cout<<"�����"<<gets()<<"  "<<"�����"<<getv()<<endl;
		}
		~room(){}
		virtual bool operator ==(room r){
			if(a==r.a&&b==r.b&&c==r.c){
				return true;
			}else{
				return false;
			}
		}
		virtual double gets();
		virtual double getv();
};
double room::gets(){
	return a*b;
}
double room::getv(){
	return a*b*c;
}
class flat:public room{
	protected:
		int roomNumber;
	public:
		flat(double a=1,double b=1,double c=1,int roomNumber=2){
			setData(a,b,c,roomNumber);
		}
		~flat(){}
		bool operator ==(flat r){
			if(a==r.a&&b==r.b&&c==r.c&&roomNumber==r.roomNumber){
				return true;
			}else{
				return false;
			}
		}
		void showData(){
			cout<<"��Ԣ����Ϣ���£�"<<endl;
			cout<<"����"<<a<<"  ��"<<b<<"  ��"<<c<<endl; 
			cout<<"������"<<roomNumber<<"�����ϵ�С����"<<endl; 
			cout<<"�����"<<gets()<<"  "<<"�����"<<getv()<<endl;
		}
		void setData(double a=1,double b=1,double c=1,int roomNumber=2){
			room::setData(a,b,c);
			this->roomNumber=roomNumber;
			s=gets();
			v=getv();
		}
		double gets();
		double getv();		
};
double flat::gets(){
	return a*b*roomNumber;
}
double flat::getv(){
	return a*b*c*roomNumber;
}
class building:public flat{
	private:
		int flatNumber;
	public:
		building(double a=1,double b=1,double c=1,int roomNumber=2,int flatNumber=2){
			setData(a,b,c,roomNumber,flatNumber);
		}
		void showData(){
			cout<<"��������Ϣ���£�"<<endl;
			cout<<"����"<<a<<"  ��"<<b<<"  ��"<<c<<endl; 
			cout<<"ÿ����Ԣ������"<<roomNumber<<"�����ϵ�С����"<<endl; 
			cout<<"����������"<<flatNumber<<"�����ϵĹ�Ԣ"; 
			cout<<"�����"<<gets()<<"  "<<"�����"<<getv()<<endl;
		}
		bool operator==(building r){
			if(a==r.a&&b==r.b&&c==r.c&&roomNumber==r.roomNumber&&flatNumber==r.flatNumber){
				return true;
			}else{
				return false;
			}
		} 
		void setData(double a=1,double b=1,double c=1,int roomNumber=2,int flatNumber=2){
			flat::setData(a,b,c,roomNumber);
			this->flatNumber=flatNumber;
			s=gets();
			v=getv();
		}
		double gets();
		double getv();
		~building(){}
};
double building::gets(){
	return a*b*roomNumber*flatNumber;
}
double building::getv(){
	return a*b*c*roomNumber*flatNumber;
}
int main(){
	room r(2,3,4);
	room r1(1,2,3);
	flat f(2,3,4,5);
	flat f1(2,3,4,5);
	building b(2,3,4,5,6);
	building b1(2,3,4,5,5);
	cout<<"����һ:"<<endl;
	r.showData();
	cout<<"�������"<<endl;
	r1.showData();
	if(r==r1){
		cout<<"����������ͬ"<<endl; 
	}else{
		cout<<"�������䲻ͬ"<<endl;
	}
	cout<<"��Ԣһ��"<<endl;
	f.showData();
	cout<<"��Ԣ����"<<endl;
	f1.showData();
	if(r==r1){
		cout<<"������Ԣ��ͬ"<<endl; 
	}else{
		cout<<"������Ԣ��ͬ"<<endl;
	}
	cout<<"����һ��"<<endl;
	b.showData();
	cout<<"��������"<<endl;
	b1.showData();
	if(r==r1){
		cout<<"����������ͬ"<<endl; 
	}else{
		cout<<"����������ͬ"<<endl;
	}
} 
