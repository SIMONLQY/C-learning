#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int a[100];
	int n;
	int charu=false; // �ж��Ƿ��Ѿ����� 
	cout<<"��������������ĸ���(������100)��";
	cin>>n;
	for(int i=0;i<n;i++){
		if(i==99){
			cout<<"��������"<<endl;
		}else{
			cout<<"�������"<<i+1<<"������������";
			int az;
			cin>>az;
			if(i==0){
				a[i]=az;
			} else{
				for(int l=0;l<=i;l++){
					if(az<=a[l]){
						for(int k=i;k>l;k--){
							a[k]=a[k-1];
						}
						a[l]=az;
						charu=true;
						break;
					} 
				}
				if(charu==false){
					a[i]=az;
				}
			}
			cout<<"��������Ԫ��Ϊ��";
			for(int p=0;p<=i;p++){
				cout<<a[p]<<" ";
			}
			cout<<"\n";
		}
	}
	return 0;
} 

