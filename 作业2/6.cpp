#include<iostream>
#include<cmath>
#include<math.h>
using namespace std;
int main(){
	double a,b,c,d,e,f;
	double x,y;
	cout<<"�������һ�����̵�����ϵ����";
	cin>>a>>b>>c;
	cout<<"������ڶ������̵�����ϵ����";
	cin>>d>>e>>f;
	cout<<a<<"x+"<<b<<"y="<<c<<endl;
	cout<<d<<"x+"<<e<<"y="<<f<<endl;
	//��������Ψһ�� ��r1=2 
	if(a*e-b*d!=0) {
		cout<<"x="<<(c*e-b*f)/(a*e-b*d)<<endl;
	    cout<<"y="<<(a*f-c*d)/(a*e-b*d)<<endl;
	} else{ 
		if(a==0&&b==0&&d==0&&e==0){//r1=0 
			if(c==0&&f==0){//r2=0
				cout<<"��ʱx��yΪ���ⳣ������";
			} else{//r2=1����2 
				cout<<"��ʱ�������޽�";
			}
		} else{//r1=1
			if(a*f-c*d!=0||b*f-c*e!=0){//r2=2
				cout<<"��ʱ�������޽�";
			} else{//r2=1
				if(a==0&&b==0&&c==0){
					if(d==0){
						cout<<"xȡ���ⳣ��"<<endl;
						cout<<"y="<<f/e<<endl;
					} else if(e==0){
						cout<<"yȡ���ⳣ��"<<endl;
						cout<<"x="<<f/d<<endl;
					} else{
						cout<<"xȡ���ⳣ��"<<endl;
						cout<<"y="<<"("<<f<<"-"<<d<<"x"<<")"<<"/"<<e<<endl;
					}
				} else if(d==0&&e==0&&f==0){
					if(a==0){
						cout<<"xȡ���ⳣ��"<<endl;
						cout<<"y="<<c/b<<endl;
					} else if(b==0){
						cout<<"yȡ���ⳣ��"<<endl;
						cout<<"x="<<c/a<<endl;
					} else{
						cout<<"xȡ���ⳣ��"<<endl;
						cout<<"y="<<"("<<c<<"-"<<a<<"x"<<")"<<"/"<<b<<endl;
					}
				}else {
					if(d==0){
						cout<<"xȡ���ⳣ��"<<endl;
						cout<<"y="<<f/e<<endl;
					} else if(e==0){
						cout<<"yȡ���ⳣ��"<<endl;
						cout<<"x="<<f/d<<endl;
					} else{
						cout<<"xȡ���ⳣ��"<<endl;
						cout<<"y="<<"("<<f<<"-"<<d<<"x"<<")"<<"/"<<e<<endl;
					}
				}
			}
		}
	}
	return 0;
}
