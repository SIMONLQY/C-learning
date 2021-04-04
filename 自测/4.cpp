#include<iostream>
#include<cstring>
using namespace std;
int judgeT(int a,int b);
int main(){
	int k=0;
	cout<<"所有满足条件的数为："<<endl; 
	for(int i=99;i>=10;i--){
		for(int j=10;j<=99;j++){
			if(judgeT(i,j)==1){
				cout<<"("<<i<<"\t";
				cout<<j<<")"<<"\t";
				k++;
				if(k==3){
					k=0;
					cout<<"\n";
				}
			}
		}
	}
	cout<<"\n满足条件的数对共有"<<k<<"对";
	return 0;
} 

int judgeT(int a,int b){
	int da=(a%10)*10+(a/10);
	int db=(b%10)*10+(b/10);
	if(a%10==a/10&&b%10==b/10){
		return 0;
	} else if(da*db==a*b){
		return 1;
	}
}


