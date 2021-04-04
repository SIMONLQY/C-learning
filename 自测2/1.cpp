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
			cout<<"小房间的信息如下："<<endl;
			cout<<"长："<<a<<"  宽："<<b<<"  高"<<c<<endl; 
			cout<<"面积："<<gets()<<"  "<<"体积："<<getv()<<endl;
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
			cout<<"公寓的信息如下："<<endl;
			cout<<"长："<<a<<"  宽："<<b<<"  高"<<c<<endl; 
			cout<<"共包含"<<roomNumber<<"个如上的小房间"<<endl; 
			cout<<"面积："<<gets()<<"  "<<"体积："<<getv()<<endl;
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
			cout<<"建筑的信息如下："<<endl;
			cout<<"长："<<a<<"  宽："<<b<<"  高"<<c<<endl; 
			cout<<"每个公寓共包含"<<roomNumber<<"个如上的小房间"<<endl; 
			cout<<"建筑共包含"<<flatNumber<<"个如上的公寓"; 
			cout<<"面积："<<gets()<<"  "<<"体积："<<getv()<<endl;
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
	cout<<"房间一:"<<endl;
	r.showData();
	cout<<"房间二："<<endl;
	r1.showData();
	if(r==r1){
		cout<<"两个房间相同"<<endl; 
	}else{
		cout<<"两个房间不同"<<endl;
	}
	cout<<"公寓一："<<endl;
	f.showData();
	cout<<"公寓二："<<endl;
	f1.showData();
	if(r==r1){
		cout<<"两个公寓相同"<<endl; 
	}else{
		cout<<"两个公寓不同"<<endl;
	}
	cout<<"建筑一："<<endl;
	b.showData();
	cout<<"建筑二："<<endl;
	b1.showData();
	if(r==r1){
		cout<<"两个建筑相同"<<endl; 
	}else{
		cout<<"两个建筑不同"<<endl;
	}
} 
