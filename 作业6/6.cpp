#include <iostream>
using namespace std;
void selectsort(int *array, int n)
{	
    int count =n;
	for(int i=count-1;i>=0;i--)
	{	int k=i;     //先记录最大元素的下标
		for(int j=i-1;j>=0;j--)
			if(*(array+j)>*(array+k)) k=j;  //先记录下标
		if(k!=i)   //本趟找完最大元素，再交换
		{	
			int tmp=*(array+i);
			*(array+i)=*(array+k);
			*(array+k)=tmp;
		}
	}
}
int main()
{	
	int list[6]={4,8,6,3,2,1};
	cout<<"排序前结果:"<<endl;
	for(int i=0;i<6;i++)    cout<<list[i]<<"   ";
	cout<<endl;
	selectsort(list,6);
	cout<<"排序后结果:"<<endl;
	for(int i=0;i<6;i++)    cout<<list[i]<<"   ";
	cout<<endl;
	return 0;
}

