#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int a[100];
	int n;
	int charu=false; // 判断是否已经插入 
	cout<<"请输入插入整数的个数(不大于100)：";
	cin>>n;
	for(int i=0;i<n;i++){
		if(i==99){
			cout<<"数组已满"<<endl;
		}else{
			cout<<"请输入第"<<i+1<<"个插入整数：";
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
			cout<<"数组有序元素为：";
			for(int p=0;p<=i;p++){
				cout<<a[p]<<" ";
			}
			cout<<"\n";
		}
	}
	return 0;
} 

