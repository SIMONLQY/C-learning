#include<iostream>
#include<cstring>
using namespace std;
int imax(int array[],int count);
int imin(int array[],int count);

int main(){
	const int count=6;
	int a[count]={1,2,5,6,4,6};
	cout<<"����Ԫ���ǣ�"<<endl;
	for(int i=0;i<count;i++) cout<<a[i]<<"\t";
	cout<<"\n";
	int max=imax(a,count);
	int min=imin(a,count);
	cout<<"��������������:"<<max<<endl;
	cout<<"��������С������:"<<min<<endl;
	return 0;
} 

int imax(int array[],int count){
	int max=array[0];
	for(int i=0;i<count;i++){
		if(array[i]>=max){
			max=array[i];
		}
	}
	return max;
}

int imin(int array[],int count){
	int min=array[0];
	for(int i=0;i<count;i++){
		if(array[i]<=min){
			min=array[i];
		}
	}
	return min;
}
