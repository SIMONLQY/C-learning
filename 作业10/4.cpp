#include<iostream>
#include<cmath>
using namespace std;
class tube{
	private:
		double r1,r2,h,p;
	public:
		tube(){
			r1=1;
			r2=2;
			h=1;
			p=1;
		}
		tube(double r1,double r2,double h,double p){
			this->r1=r1;
			this->r2=r2;
			this->h=h;
			this->p=p;
		}
		double contian(){
			double c;
			c=M_PI*r1*r1*h;
			return c;
		}
		double v(){
			double v;
			v=M_PI*r2*r2*h;
			return v;
		}
		double weight(){
			double w;
			w=p*M_PI*h*(r2*r2-r1*r1);
			return w;
		}
		double surface(){
			double s;
			s=2*M_PI*r2*h;
			return s;
		}
		void sc(){
			cout<<"Բ���ھ���"<<r1<<endl;
			cout<<"Բ���⾶��"<<r2<<endl;
			cout<<"Բ�ܸ߶ȣ�"<<h<<endl;
			cout<<"Բ���ܶȣ�"<<p<<endl;
			cout<<"Բ���ݻ���"<<this->contian()<<endl;
			cout<<"Բ�������"<<this->v()<<endl;
			cout<<"Բ��������"<<this->weight()<<endl;
			cout<<"Բ�ܱ������"<<this->surface()<<endl;
		}
		~tube(){}
};
int main(){
	tube t(2,4,5,2);
	t.sc();
}
