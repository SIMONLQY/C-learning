#include<iostream>
#include<cmath>
using namespace std;
class circ{
	private:
		double r1,r2;
	public:
		circ(double r1=1,double r2=2){
			this->r1=r1;
			this->r2=r2;
		}
		double getRj(){
			return 4.0/3.0*M_PI*pow(r1,3);
		}
		double getTj(){
			return 4.0/3.0*M_PI*pow(r2,3);
		}
		double getWmj(){
			return 4.0*M_PI*r1*r1;
		}
		double getNmj(){
			return 4.0*M_PI*r2*r2;
		}
		bool operator ==(circ& c){
			if(r1==c.r1&&r2==c.r2){
				return true; 
			} else{
				return false;
			}
		}
		void showInfo(){
			cout<<" 内半径为："<<r1<<"  ";
			cout<<" 外半径为："<<r2<<endl;
			cout<<" 容积为："<<getRj()<<"  ";
			cout<<" 体积为："<<getTj()<<endl;
			cout<<" 外表面积为："<<getWmj()<<"  ";
			cout<<" 内表面积为："<<getNmj()<<endl;
		}
		~circ(){}
};
int main(){
	circ c1(1,2),c2(2,3),c3(1,2);
	cout<<" 第一个空心球的信息如下："<<endl;
	c1.showInfo();
	cout<<" 第二个空心球的信息如下："<<endl;
	c2.showInfo();
	cout<<" 第三个空心球的信息如下："<<endl;
	c3.showInfo();
	if(c1==c2){
		cout<<" 第一个圆球与第二个圆球相同"<<endl;
	}else{
		cout<<" 第一个圆球与第二个圆球不同"<<endl;
	}
	if(c1==c3){
		cout<<" 第二个圆球与第三个圆球相同"<<endl;
	}else{
		cout<<" 第二个圆球与第三个圆球不同"<<endl;
	}
} 
