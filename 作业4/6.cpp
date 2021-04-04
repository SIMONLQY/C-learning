#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int all[8][8];
	int k=0;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			all[i][j]=(i+1)*(j+1);
			cout<<all[i][j]<<"\t";
			k++;
			if(k==8){
				k=0;
				cout<<"\n";
			}
		}
	}
	int zsum=0;
	int fsum=0;
	for(int i=0;i<8;i++){
		zsum=zsum+all[i][i];
		fsum=fsum+all[i][7-i];
	}
	cout<<"主对角线元素和为："<<zsum<<endl;
	cout<<"副对角线元素和为："<<fsum<<endl;
	cout<<"第一行加上主对角线元素和之后的值为："<<endl;
	for(int i=0;i<8;i++){
		all[0][i]+=zsum;
		cout<<all[0][i]<<"\t";
	}
	return 0;
}
