#include<iostream>//����ͷ�ļ�cout,cin��Ҫ
#include<stdlib.h>//����ͷ�ļ�,rand()��Ҫ
#include<ctime> 
using namespace std;//���ֿռ�
int main()//������
{
	srand(time(0));
	int a,b,c;//�ֱ��ʾ�����������ǵĺ�
	int input;//����û�����ĺ�
	char cont;
	do{
		a=rand()%100;//����С��100�������
		b=rand()%100;//����С��100�������
		c=a+b;//�����
		cout<<a<<"+"<<b<<"=?"<<endl;//��ʾ����������ʾ�û�����
		cin>>input;//�û�����ĺ�
		while(input!=c){
			cout<<"�𰸴���������ϸ��һ�鲢������"<<endl;
			cin>>input;
		}
		cout<<"��ϲ�㣬�ش���ȷ���������������ϰ�����˳�������������\'y\',�˳�������\'n\'."<<endl;
		cin>>cont;
	}while(cont=='y');
	return 0;
}


