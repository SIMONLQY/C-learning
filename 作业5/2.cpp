#include<iostream>
#include<cstring>
using namespace std;
int imax(int array[],int count);
int imin(int array[],int count);

int main(){
	const int count=6;
	int a[count]={1,2,5,6,4,6};
	cout<<"数组元素是："<<endl;
	for(int i=0;i<count;i++) cout<<a[i]<<"\t";
	cout<<"\n";
	int max=imax(a,count);
	int min=imin(a,count);
	cout<<"数组中最大的数是:"<<max<<endl;
	cout<<"数组中最小的数是:"<<min<<endl;
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
