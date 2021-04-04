#include<iostream>
#include<cmath>
using namespace std;
class fc{
	protected:
		double* fcp;
	public:
		virtual void setd(double *,int)=0;
		virtual void out_fc()=0;
		virtual void out_root()=0;
		virtual double root()=0;
};
class fc1:public fc{
	public:
		fc1(){
			fcp=NULL;
		}
		fc1(double *aa,int bb=2){
			fcp=new double[bb];
			for(int i=0;i<bb;i++){
				fcp[bb-i-1]=aa[i];
			}
		}
		void setd(double *aa,int bb=2){
			if(fcp!=NULL){
				delete []fcp;
				fcp=new double[bb];
				for(int i=0;i<bb;i++){
					fcp[bb-i-1]=aa[i];
				}
			}
		}
		fc1 operator =(fc1 &tt){
			// 避免自赋值
			if(this!=&tt){
				//避免内存泄漏
				if(fcp!=NULL){
					delete []fcp;
					fcp=NULL;
				} 
				fcp=new double[2];
				for(int i=0;i<2;i++){
					fcp[i]=tt.fcp[i];
				}
				return *this;
			} 
		} 
		fc1 operator +(fc1 &tt){
			fc1 temp;
			temp.fcp=new double[2];
			temp.fcp[1]=fcp[1]+tt.fcp[1];
			temp.fcp[0]=fcp[0]+tt.fcp[0];
			return temp;
		}
		fc1 operator -(fc1 &tt){
			fc1 temp;
			temp.fcp=new double[2];
			temp.fcp[1]=fcp[1]-tt.fcp[1];
			temp.fcp[0]=fcp[0]-tt.fcp[0];
			return temp;
		}
		void out_fc(){
			cout<<"一元一次方程：";
			if(fcp[1]!=0&&fcp[1]!=1&&fcp[1]!=-1){
				cout<<fcp[1]<<"";
				cout<<"x";
			}else if(fcp[1]==1){
				cout<<"x";
			}else if(fcp[1]==-1){
				cout<<"-x";
			}
			if(fcp[0]>0){
				cout<<"+"<<fcp[0];
			}else if(fcp[0]<0){
				cout<<fcp[0];
			}
			cout<<"="<<"0";
			cout<<endl;
		}
		void out_root(){
			if(fcp[1]!=0){
				fc1::out_fc();
				cout<<"\nx="<<root()<<endl;
			}else{
				if(fcp[0]!=0){
					fc1:out_fc();
					cout<<"不是一元一次方程，无根！"<<endl;
				}else{
					cout<<"0.0=0.0,无穷根！\n";
				}
			}
		}
		double root(){
			return -fcp[0]/fcp[1];
		}
		~fc1(){
			if(fcp!=NULL){
				delete []fcp;
				fcp=NULL;
			} 
		}
};
class fc2:public fc1{
	public:
		fc2():fc1(){};
		fc2(double *aa,int bb=3):fc1(aa,bb){}
		void setb(double *aa,int bb=3){
			fc1::setd(aa,3);
		}
		fc2 operator =(fc2 &tt){
			//避免自赋值
			if(this!=&tt){
				//避免内存泄露
				delete []fcp;
				fcp=NULL; 
			} 
			fcp=new double[3];
			for(int i=0;i<3;i++){
				fcp[i]=tt.fcp[i];
			}
			return *this;
		}
		fc2 operator +(fc2 &tt){
			fc2 temp;
			temp.fcp=new double[3];
			temp.fcp[2]=fcp[2]+tt.fcp[2];
			temp.fcp[1]=fcp[1]+tt.fcp[1];
			temp.fcp[0]=fcp[0]+tt.fcp[0];
			return temp;
		}
		fc2 operator -(fc2 &tt){
			fc2 temp;
			temp.fcp=new double[3];
			temp.fcp[2]=fcp[2]-tt.fcp[2];
			temp.fcp[1]=fcp[1]-tt.fcp[1];
			temp.fcp[0]=fcp[0]-tt.fcp[0];
			return temp;
		}
		void out_fc(){
			cout<<"\n一元二次方程：";
			if(fcp[2]!=0&&fcp[2]!=1&&fcp[2]!=-1){
				cout<<fcp[2]<<"x^2";
			}else if(fcp[2]==1){
				cout<<"x^2";
			}else if(fcp[2]==-1){
				cout<<"-x^2";
			}
			if(fcp[1]!=0&&fcp[1]!=1&&fcp[1]!=-1){
				if(fcp[1]<0){
					cout<<fcp[1];
				}else{
					cout<<"+"<<fcp[1];
				}
				cout<<"x";
			}else if(fcp[1]==1){
				cout<<"x";
			}else if(fcp[1]==-1){
				cout<<"-x";
			}
			if(fcp[0]>0){
				cout<<"+"<<fcp[0];
			}else if(fcp[0]<0){
				cout<<fcp[0];
			}
			cout<<"="<<"0";
			cout<<endl;
		}
		void out_root(){
			if(fcp[2]==0.0){
				fc1::out_root();
			}else{
				double temp=fcp[1]*fcp[1]-4*fcp[2]*fcp[0];
				if(temp<0){
					fc2::out_fc();
					cout<<"无根！\n";
				}else{
					fc2::out_fc();
					if(temp!=0){
						cout<<"\nx1="<<root1();
						cout<<"\nx2="<<root2();
					}else{
						cout<<"\nx="<<root1();
					}
				}
			}
		}
		double root1(){
			return (-fcp[1]+sqrt(fcp[1]*fcp[1]-4*fcp[2]*fcp[0]))/(2*fcp[2]);
		}
		double root2(){
			return (-fcp[1]-sqrt(fcp[1]*fcp[1]-4*fcp[2]*fcp[0]))/(2*fcp[2]);
		}
		~fc2(){
			if(fcp!=NULL){
				delete []fcp;
				fcp=NULL;
			} 
		}
};
class fc3:public fc2{
	public:
		fc3():fc2(){};
		fc3(double *aa,int bb=4):fc2(aa,bb){}
		void setd(double *aa,int bb=4){
			fc2::setd(aa,bb);
		}
		fc3 operator =(fc3 &tt){
			//避免自赋值
			if(this!=&tt){
				//避免内存泄露
				delete []fcp;
				fcp=NULL; 
			} 
			fcp=new double[4];
			for(int i=0;i<4;i++){
				fcp[i]=tt.fcp[i];
			}
			return *this;
		}
		fc3 operator +(fc3 &tt){
			fc3 temp;
			temp.fcp=new double[4];
			for(int i=0;i<4;i++){
				temp.fcp[i]=fcp[i]+tt.fcp[i];
			}
			return temp;
		}
		fc3 operator -(fc3 &tt){
			fc3 temp;
			temp.fcp=new double[4];
			for(int i=0;i<4;i++){
				temp.fcp[i]=fcp[i]-tt.fcp[i];
			}
			return temp;
		}
		void out_fc(){
			cout<<"\n一元三次方程：";
			if(fcp[3]!=0&&fcp[3]!=1&&fcp[3]!=-1){
				cout<<fcp[3];
				cout<<"x^3";
			}else if(fcp[3]==1){
				cout<<"x^3";
			}else if(fcp[3]==-1){
				cout<<"-x^3";
			}
			if(fcp[2]!=0&&fcp[2]!=1&&fcp[2]!=-1){
				if(fcp[2]<0){
					cout<<fcp[2];
				}else{
					cout<<"+"<<fcp[2];
				}
				cout<<"x^2";
			}else if(fcp[2]==1){
				cout<<"+x^2";
			}else if(fcp[2]==-1){
				cout<<"-x^2";
			}
			if(fcp[1]!=0&&fcp[1]!=1&&fcp[1]!=-1){
				if(fcp[1]<0){
					cout<<fcp[1];
				}else{
					cout<<"+"<<fcp[1];
				}
				cout<<"x";
			}else if(fcp[1]==1){
				cout<<"+x";
			}else if(fcp[1]==-1){
				cout<<"-x";
			}
			if(fcp[0]>0){
				cout<<"+"<<fcp[0];
			}else if(fcp[0]<0){
				cout<<fcp[0];
			}
			cout<<"="<<"0";
			cout<<endl;
		}
		void out_root(double x0){
			if(fcp[3]==0.0){
				fc2::out_root();
			}else{
				fc3::out_fc();
				cout<<"\nx="<<root(x0);
			}
		}
		double root(double x0){
			double aa=x0; //将x0赋值给a（即xn） 
			x0=aa-qiuzhi(aa)/qiudao(aa);
			if(fabs(qiuzhi(x0))>=pow(10,-9)||fabs(x0-aa)>=pow(10,-9)){
				root(x0);
			}
			return x0;
		}
		double qiuzhi(double x){
			return fcp[3]*x*x*x+fcp[2]*x*x+fcp[1]*x+fcp[0];
		}
		double qiudao(double x){
			return 3*fcp[3]*x*x+2.0*fcp[2]*x+fcp[1];
		}
		~fc3(){
			if(fcp!=NULL){
				delete []fcp;
				fcp=NULL;
			} 
		}
};
class fc4:public fc3{
	public:
		fc4():fc3(){};
		fc4(double *aa,int bb=5):fc3(aa,bb){}
		void setd(double *aa,int bb=5){
			fc2::setd(aa,bb);
		}
		fc4 operator =(fc4 &tt){
			//避免自赋值
			if(this!=&tt){
				//避免内存泄露
				delete []fcp;
				fcp=NULL; 
			} 
			fcp=new double[5];
			for(int i=0;i<5;i++){
				fcp[i]=tt.fcp[i];
			}
			return *this;
		}
		fc4 operator +(fc4 &tt){
			fc4 temp;
			temp.fcp=new double[5];
			for(int i=0;i<5;i++){
				temp.fcp[i]=fcp[i]+tt.fcp[i];
			}
			return temp;
		}
		fc4 operator -(fc4 &tt){
			fc4 temp;
			temp.fcp=new double[5];
			for(int i=0;i<5;i++){
				temp.fcp[i]=fcp[i]-tt.fcp[i];
			}
			return temp;
		}
		void out_fc(){
			cout<<"\n一元四次方程：";
			if(fcp[4]>0){
				if(fcp[4]==1){
					cout<<"x^4";
				}else{
					cout<<fcp[4]<<"x^4";
				}
			}else if(fcp[4]<0){
				if(fcp[4]==-1){
					cout<<"-x^4";
				}else{
					cout<<fcp[4]<<"x^4";
				}
			}
			if(fcp[3]!=0&&fcp[3]!=1&&fcp[3]!=-1){
				cout<<fcp[3];
				cout<<"x^3";
			}else if(fcp[3]==1){
				cout<<"x^3";
			}else if(fcp[3]==-1){
				cout<<"-x^3";
			}
			if(fcp[2]!=0&&fcp[2]!=1&&fcp[2]!=-1){
				if(fcp[2]<0){
					cout<<fcp[2];
				}else{
					cout<<"+"<<fcp[2];
				}
				cout<<"x^2";
			}else if(fcp[2]==1){
				cout<<"+x^2";
			}else if(fcp[2]==-1){
				cout<<"-x^2";
			}
			if(fcp[1]!=0&&fcp[1]!=1&&fcp[1]!=-1){
				if(fcp[1]<0){
					cout<<fcp[1];
				}else{
					cout<<"+"<<fcp[1];
				}
				cout<<"x";
			}else if(fcp[1]==1){
				cout<<"+x";
			}else if(fcp[1]==-1){
				cout<<"-x";
			}
			if(fcp[0]>0){
				cout<<"+"<<fcp[0];
			}else if(fcp[0]<0){
				cout<<fcp[0];
			}
			cout<<"="<<"0";
			cout<<endl;
		}
		void out_root(double x0){
			if(fcp[4]==0.0){
				fc3::out_root(x0);
			}else{
				fc4::out_fc();
				cout<<"\nx="<<root(x0);
			}
		}
		double root(double x0){
			double aa; 
			aa=x0-qiuzhi(x0)/qiudao(x0);
			if(fabs(qiuzhi(aa))>=pow(10,-7)||fabs(x0-aa)>=pow(10,-7)){
				root(aa);
			}
			return aa;
		}
		double qiuzhi(double x){
			return fcp[4]*pow(x,4)+fcp[3]*x*x*x+fcp[2]*x*x+fcp[1]*x+fcp[0];
		}
		double qiudao(double x){
			return 4*fcp[4]*pow(x,3)+3*fcp[3]*x*x+2*fcp[2]*x+fcp[1];
		}
		~fc4(){
			if(fcp!=NULL){
				delete []fcp;
				fcp=NULL;
			} 
		}
};
int main(){
	double a[4]={2,-4,3,-6};
	double b[4]={1,12,48,64};
	double c[5]={1,-10,35,-50,24};
	fc3 fa(a);
	fc3 fb(b);
	fc3 f=fa+fb;
	fc4 f4(c);
	fa.out_root(1.5);
	fb.out_root(-4.5);
	cout<<"\n这两个方程相加为"<<endl;
	f.out_root(-1);
	f4.out_root(4.5);
	return 0;
}
