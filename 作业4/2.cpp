#include<iostream>
using namespace std;
int main(){
	const int COUNT=16;
	int list[COUNT]=
	{
		503,87,512,61,908,170,897,275,
		653,426,154,509,612,677,765,703
	};
	for(int i=COUNT-1;i>0;i--){
		for(int j=0;j<i;j++){
			if(list[j+1]<list[j]){
				int tmp=list[j+1];
				list[j+1]=list[j];
				list[j]=tmp;	
			}
		}
	}
	cout<<"The result is:"<<endl;
	for(int k=0;k<COUNT;k++){
		cout<<list[k]<<" ";
	}
	cout<<endl;
	return 0;
}
