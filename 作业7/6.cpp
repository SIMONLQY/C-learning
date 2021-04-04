#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
double myatof(char *num);
int main(){
	char a[]="-3.1569";
	cout<<"字符串"<<"\t"<<"自编函数结果"<<"\t"<<"系统函数结果"<<endl;
	cout<<a<<"\t\t"<<myatof(a)<<"\t\t"<<atof(a);
	return 0;
}
 double myatof(char *num){
 	double result=0.0;
 	const int N=strlen(num);
 	int k=strlen(num);
 	double xs=0.0;
 	for(int i=0;i<N;i++){
 		if(num[i]=='.'){
 			k=i;
		}
	}
	for(int i=k-1;i>=0&&num[i]!='-';i--){
		result+=(num[i]-'0')*(pow(10.0,k-1-i));
	}
	if(k!=N){
		for(int i=N-1;i>k;i--){
			xs+=(num[i]-'0')*pow(10,N-1-i);
		}
	}
	xs=xs/pow(10.0,N-1-k);
	result=result+xs;
	if(num[0]=='-'){
		result=(-1)*result;
	}
	return result;
 }
