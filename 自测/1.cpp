#include<iostream>
#include<cstring>
using namespace std;

int main(){
	int m;
	int n;
	cout<<"请输入m和n：";
	cin>>m;
	cin>>n;
	for(int i=m;i<=n;i++){
		cout<<"\n"<<i<<"的非平凡因子：";
		int k=0;
		for(int j=2;j<i;j++){
			if(i%j==0){
				cout<<j<<" ";
				k++;
			}
		}
		if(k==0){
			cout<<"无"; 
		}
	}
	return 0;
} 


