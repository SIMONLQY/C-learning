#include <iostream>
using namespace std;
void selectsort(int *array, int n)
{	
    int count =n;
	for(int i=count-1;i>=0;i--)
	{	int k=i;     //�ȼ�¼���Ԫ�ص��±�
		for(int j=i-1;j>=0;j--)
			if(*(array+j)>*(array+k)) k=j;  //�ȼ�¼�±�
		if(k!=i)   //�����������Ԫ�أ��ٽ���
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
	cout<<"����ǰ���:"<<endl;
	for(int i=0;i<6;i++)    cout<<list[i]<<"   ";
	cout<<endl;
	selectsort(list,6);
	cout<<"�������:"<<endl;
	for(int i=0;i<6;i++)    cout<<list[i]<<"   ";
	cout<<endl;
	return 0;
}

