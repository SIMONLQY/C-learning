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
			cout<<" �ڰ뾶Ϊ��"<<r1<<"  ";
			cout<<" ��뾶Ϊ��"<<r2<<endl;
			cout<<" �ݻ�Ϊ��"<<getRj()<<"  ";
			cout<<" ���Ϊ��"<<getTj()<<endl;
			cout<<" ������Ϊ��"<<getWmj()<<"  ";
			cout<<" �ڱ����Ϊ��"<<getNmj()<<endl;
		}
		~circ(){}
};
int main(){
	circ c1(1,2),c2(2,3),c3(1,2);
	cout<<" ��һ�����������Ϣ���£�"<<endl;
	c1.showInfo();
	cout<<" �ڶ������������Ϣ���£�"<<endl;
	c2.showInfo();
	cout<<" ���������������Ϣ���£�"<<endl;
	c3.showInfo();
	if(c1==c2){
		cout<<" ��һ��Բ����ڶ���Բ����ͬ"<<endl;
	}else{
		cout<<" ��һ��Բ����ڶ���Բ��ͬ"<<endl;
	}
	if(c1==c3){
		cout<<" �ڶ���Բ���������Բ����ͬ"<<endl;
	}else{
		cout<<" �ڶ���Բ���������Բ��ͬ"<<endl;
	}
} 
