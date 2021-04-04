#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int fabonaci( int n );
 int sum_f( int *pi, int n );
int main(){
	int n;
	cout<<"ÇëÊäÈën:";
	cin>>n; 
	int *sum=new int[n];
	for(int i=0;i<n;i++){
		sum[i]=fabonaci(i);
	}
	cout<<"result=";
	for(int i=0;i<n;i++){
		if(i!=n-1){
			cout<<fabonaci(i)<<"^2+";
		}else{
			cout<<fabonaci(i)<<"^2="<<sum_f(sum,n);
		}
	}
	delete []sum; 
	return 0;
} 

int fabonaci( int n ){
	if(n==0){
		return 0;
	} else if(n==1){
		return 1;
	} else if(n==2){
		return 1;
	}else{
		return fabonaci(n-2)+fabonaci(n-1);
	}
}

int sum_f( int *pi, int n ){
	int sum=0;
 	for(int i=0;i<n;i++){
 		sum=sum+pow(pi[i],2);
	 }
	return sum;
 }
