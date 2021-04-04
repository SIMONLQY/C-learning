#include<iostream>
#include<cstring>
using namespace std;
class z_int{
	private:
		bool t;
	    int num[100];
	    int j; // 位数 
	public:
		z_int(){
			char p[100]={'0'};
			set_data(p);
		}
		z_int(char*pi){
			set_data(pi);
		}
		~z_int(){}
		void set_data(char*pi);
		z_int operator +(z_int b);
		z_int operator -(z_int b);
		bool operator >(z_int b);
		bool operator <(z_int b);
		void sc();
		int* getnum();
		int getj();
};

bool z_int::operator >(z_int b){
	if(j>b.j){
		return true;
	}else if(j<b.j){
		return false;
	}else{
		for(int i=0;i<100;i++){
			if(num[i]>b.num[i]){
				return true;
			}else if(num[i]<b.num[i]){
				return false;
			}
		}
		return false;
	}
}
bool z_int::operator <(z_int b){
	if(j<b.j){
		return true;
	}else if(j>b.j){
		return false;
	}else{
		for(int i=0;i<100;i++){
			if(num[i]<b.num[i]){
				return true;
			}
		}
		return false;
	}
}
z_int z_int::operator +(z_int b){
	z_int temp=*this;
	int l;
	for(int i=99;i>=0;i--){
		l=temp.num[i]+b.getnum()[i];
		if(l>=0&&l<=9){
			temp.num[i]+=b.getnum()[i];
		}else{
			temp.num[i]=l%10;
			temp.num[i-1]++;
		}
	}
	return temp;
}
z_int z_int::operator -(z_int b){
	z_int temp,max,min;
	int l=0;
	if((*this)>b){
		max=(*this);
		min=b;
	}else if(*this<b){
		max=b;
		min=*this;
	}else{
		char p[100]={'0'};
		temp.set_data(p);
		return temp;
	}
	for(int i=99;i>=0;i--){
		l=max.num[i]-min.num[i];
		if(l>=0&&l<=9){
			temp.num[i]=max.num[i]-min.num[i];
		}else{
			temp.num[i]=max.num[i]+10-min.num[i];
			int j=i;
			while(max.num[j]==0){
				j--;
			}
			max.num[j]--;
		}
	}
	for(int k=0;k<100;k++){
		if(temp.num[k]!=0){
			temp.j=100-k;
			break;
		}
	}
	if(*this<b){
		temp.t=false;
	}
	return temp;
}
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
	t=true;
}
void z_int::sc(){
	if(t!=true){
		cout<<"-";
	}
	for(int i=100-j;i<100;i++){
		cout<<num[i];
	} 
}

int main(){
	cout<<"请输入第一个大整数：";
	char p1[100];
	cin>>p1;
	cout<<"\n请输入第二个大整数：";
	char p2[100];
	cin>>p2;
	z_int t1(p1),t2(p2);
	if(t1>t2){
		cout<<"第一个整数大"<<endl;
	} else if(t1<t2){
		cout<<"第二个整数大"<<endl; 
	}else{
		cout<<"两个数一样大"<<endl; 
	}
	cout<<"第一个整数减第二个整数结果为";
	(t1-t2).sc();
}
