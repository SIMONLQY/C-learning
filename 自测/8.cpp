#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int count(int m);
int zuo(int m);
int main(){
	int a;
	cout<<"请输入你想验证的数字";
	cin>>a;
	cout<<"\n左端连续相同的数字"<<zuo(a)<<"的个数为"<<count(a)<<"个";
	return 0;
} 
int zuo(int m){
	int n=0;
	int w;
	if(m>0){
		n=m;
	} else {
		n=(-1)*m;
	}
	for(int i=0;i<100;i++){
		if(n<pow(10,i)){
			w=i;
			break;
		}
	}
	int z1=(n%(long)pow(10,w))/pow(10,w-1);
	return z1;
}
int count(int m){
	int n=0;
	int w;
	if(m>0){
		n=m;
	} else {
		n=(-1)*m;
	}
	for(int i=0;i<100;i++){
		if(n<pow(10,i)){
			w=i;
			break;
		}
	}
	int k=1;
	for(int j=w;j>1;j--){
		int z1=(n%(long)pow(10,j))/pow(10,j-1);
		int z2=(n%(long)pow(10,j-1))/pow(10,j-2);
		if(z1==z2){
			k++;
		} else{
			break;
		}
	}
	return k;
}

