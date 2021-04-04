#include<iostream>
using namespace std;
class Rational{
	private:
		int n;
		int d;
		int maxinzi(int n,int d){
			int min=((n<d)?n:d);
			int max=1;
			for(int i=1;i<=min;i++){
				if(n%i==0&&d%i==0&&i>max){
					max=i;
				}
			}
			return max;
		}
	public:
		Rational(){
			n=0;
			d=1;
		}
		Rational(int n,int d){
			int k=maxinzi(n,d);
			n=n/k;
			d=d/k;
			this->n=n;
			this->d=d;
		}
		Rational plus(Rational &a){
			int k=maxinzi(d,a.d);
			int l1=a.d/k;
			int l2=d/k;
			n=n*l1+a.n*l2;
			d=d*l1;
			k=maxinzi(n,d);
			n=n/k;
			d=d/k;
			Rational t(n,d);
			return t;
		}
		Rational mut(Rational &a){
			n=n*a.n;
			d=d*a.d;
			int k=maxinzi(n,d);
			n=n/k;
			d=d/k;
			Rational t(n,d);
			return t;
		}
		Rational mi(Rational &a){
			int k=maxinzi(d,a.d);
			int l1=a.d/k;
			int l2=d/k;
			n=n*l1-a.n*l2;
			d=d*l1;
			k=maxinzi(n,d);
			n=n/k;
			d=d/k;
			Rational t(n,d);
			return t;
		}
		Rational chu(Rational &a){
			n=n*a.d;
			d=d*a.n;
			int k=maxinzi(n,d);
			n=n/k;
			d=d/k;
			Rational t(n,d);
			return t;
		}
		void fsxs(){
			cout<<n<<"/"<<d<<endl;
		}
		void xsxs(){
			double a=(double)n/(double)d;
			cout<<a<<endl;
		}
		~Rational(){}
};
int main(){
	Rational r1(4,6),r2(7,2);
	cout<<"r1以分数形式输出为："; 
	r1.fsxs();
	cout<<"r1以小数形式输出为："; 
	r1.xsxs();
	cout<<"r2以分数形式输出为："; 
	r2.fsxs();
	cout<<"r2以小数形式输出为："; 
	r2.xsxs();
	
	cout<<"\n相加：r1=r1+r2=";
	r1.plus(r2).xsxs();
	cout<<"此时r1=";
	r1.xsxs();
	cout<<"  r2=";
	r2.xsxs(); 
	
	cout<<"\n相乘：r1=r1*r2=";
	r1.mut(r2).xsxs();
	cout<<"此时r1=";
	r1.xsxs();
	cout<<"  r2=";
	r2.xsxs(); 
	
	cout<<"\n相减：r1=r1-r2=";
	r1.mi(r2).xsxs();
	cout<<"此时r1=";
	r1.xsxs();
	cout<<"  r2=";
	r2.xsxs(); 
	
	cout<<"\n相除：r1=r1/r2=";
	r1.chu(r2).xsxs();
	cout<<"此时r1=";
	r1.xsxs();
	cout<<"  r2=";
	r2.xsxs(); 
}
