#include<iostream>
using namespace std;
class cuboid{
	private:
		double a,b,c;
	public:
		cuboid(){
			a=1;b=1;c=1;
		}
		cuboid(int a,int b,int c){
			this->a=a;
			this->b=b;
			this->c=c;
		}
		void showData(){
			cout<<"����"<<a;
			cout<<"  ��"<<b;
			cout<<"  �ߣ�"<<c;
			cout<<endl;
			cout<<"�������"<<gets();
			cout<<"   �����"<<getv();
			cout<<endl;
		}
		double gets();
		double getv();
		cuboid operator +(cuboid &cub){
			cuboid temp(a+cub.a,b+cub.b,c+cub.c);
			return temp;
			
		}
		bool operator ==(cuboid &cub){
			if(a==cub.a&&b==cub.c&&c==cub.c){
				return true;
			}else{
				return false;
			}
		}
		~cuboid(){}
};
double cuboid::gets(){
	return a*b*2+b*c*2+a*c*2;
}
double cuboid::getv(){
	return a*b*c;
}
int main(){
	cuboid b1(1,2,3);
	cuboid b2(2,3,4);
	cout<<"��һ����������ϢΪ��"<<endl;
	b1.showData();
	cout<<"�ڶ�����������ϢΪ��"<<endl;
	b2.showData();
	cuboid b3;
	b3=b1+b2;
	if(b1==b2){
		cout<<"������������ͬ"<<endl;
	}else{
		cout<<"���������岻ͬ"<<endl;
	}
	cout<<"�������������Ϊ��"<<endl;
	b3.showData();
}
