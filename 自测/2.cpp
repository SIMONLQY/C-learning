#include<iostream>
#include<cstring>
using namespace std;
int judgeT(int a); // �ж�ͬ�����ĺ��� 
int main(){
	cout<<"1��1000�������е�ͬ����Ϊ��"<<endl; 
	int k=0; // ������ 
	for(int i=1;i<=1000;i++){
		if(judgeT(i)==1){
			cout<<i<<"\t";
			k++;
			if(k==8){
				k=0;
				cout<<"\n";
			}
		}
	}
	return 0;
} 

int judgeT(int a){
	if(a>=1&&a<=9){
		if((a*a)%10==a){
			return 1;
		} else{
			return 0;
		}
	} else if(a>=10&&a<=99){
		if((a*a)%100==a){
			return 1;
		} else{
			return 0;
		}
	} else if(a>=100&&a<=999){
		if((a*a)%1000==a){
			return 1;
		} else{
			return 0;
		}
	}
}

