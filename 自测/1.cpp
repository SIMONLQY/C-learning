#include<iostream>
#include<cstring>
using namespace std;

int main(){
	int m;
	int n;
	cout<<"������m��n��";
	cin>>m;
	cin>>n;
	for(int i=m;i<=n;i++){
		cout<<"\n"<<i<<"�ķ�ƽ�����ӣ�";
		int k=0;
		for(int j=2;j<i;j++){
			if(i%j==0){
				cout<<j<<" ";
				k++;
			}
		}
		if(k==0){
			cout<<"��"; 
		}
	}
	return 0;
} 


