#include<iostream>
#include<cstring>
using namespace std;
class z_int{
	private:
	    int num[100];
	    int j; // λ�� 
	public:
		void set_data(char*pi);
		void add(z_int b);
		void sc();
		int* getnum();
		int getj();
};
int* z_int::getnum(){
	return num;
}
int z_int::getj(){
	return j;
}
void z_int::set_data(char*pi){
	int i;
	int k=0;
	for(i=100-strlen(pi);i<100;i++,k++){
		num[i]=pi[k]-'0';
	}
	j=strlen(pi);
	for(i=0;i<100-strlen(pi);i++){
		num[i]=0;
	}
}
void z_int::add(z_int b){
	int l;
	for(int i=99;i>=0;i--){
		l=num[i]+b.getnum()[i];
		if(l>=0&&l<=9){
			num[i]+=b.getnum()[i];
		}else{
			num[i]=l/10;
			num[i-1]++;
		}
	}
}
void z_int::sc(){
	for(int i=100-j;i<100;i++){
		cout<<num[i];
	} 
}
int main(){
	char a[100],b[100];
	cout<<"������һ������������";
	cin>>a;
	z_int k1,k2;
	k1.set_data(a);
	cout<<"�����������Ϊ��";
	k1.sc();
	cout<<"�����������������϶��٣�";
	cin>>b;
	k2.set_data(b);
	k1.add(k2);
	cout<<"��֮�����Ϊ��";
	k1.sc();
}
