#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
void  myfor( int  *sum_p , int  n );
int main(){
	int sum=0;
	myfor(&sum,999);
	return 0;
}

void  myfor( int  *sum_p , int  n ){
	int k=100*(n%10)+10*(n%100/10)+n/100;
	*sum_p=*sum_p+k; 
	if(n!=100){
		myfor(sum_p,n-1);	
	}
	cout<<"������"<<n<<"\t"<<"����������"<<k<<endl;
	if(n==999){
		cout<<"�ܼƣ�"<<*sum_p;
	}
}
