#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int panduan(long a);
int main(){
	int k=0;
	int a[9999];
	int j=0;
	int sum=0;
	for(long i=1;i<=9999;i++){
		if(panduan(i)==1){
			k++;
			a[j]=i;
			j+=1;
		}
	}
	int o=0;
	cout<<"(";
	for(int i=0;i<j;i++){
		sum=sum+a[i];
		if(i!=j-1){
			cout<<a[i]<<"+"<<" ";
		} else{
			cout<<a[i]<<" ";
		}
		o++;
		if(o==10){
			o=0;
			cout<<"\n";
		}
	}
	cout<<")/"<<k<<"="<<(double)(sum)/k<<endl;
	return 0;
} 

int panduan(long a){
	int w;
	for(int i=0;i<100;i++){
		if(a<pow(10,i)){
			w=i;
			break;
		}
	}
	for(int j=w;j>1;j--){
		int z1=(a%(long)pow(10,j))/pow(10,j-1);
		int z2=(a%(long)pow(10,j-1))/pow(10,j-2);
		if(z1<z2){
			return 0;
		}
	}
	return 1;
}

