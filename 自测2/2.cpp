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
			cout<<"长："<<a;
			cout<<"  宽："<<b;
			cout<<"  高："<<c;
			cout<<endl;
			cout<<"表面积："<<gets();
			cout<<"   体积："<<getv();
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
	cout<<"第一个长方体信息为："<<endl;
	b1.showData();
	cout<<"第二个长方体信息为："<<endl;
	b2.showData();
	cuboid b3;
	b3=b1+b2;
	if(b1==b2){
		cout<<"两个长方体相同"<<endl;
	}else{
		cout<<"两个长方体不同"<<endl;
	}
	cout<<"两个长方体相加为："<<endl;
	b3.showData();
}
