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
	cout<<"���Խ���Ԫ�غ�Ϊ��"<<zsum<<endl;
	cout<<"���Խ���Ԫ�غ�Ϊ��"<<fsum<<endl;
	cout<<"��һ�м������Խ���Ԫ�غ�֮���ֵΪ��"<<endl;
	for(int i=0;i<8;i++){
		all[0][i]+=zsum;
		cout<<all[0][i]<<"\t";
	}
	return 0;
}
