#include <iostream>
#include<windows.h>
using namespace std;
void walking(char car[],int n,int k,char m)
{
	int i;
	int j;
	char del_car[80];    //�������С�����ַ���
	for(i=0;i<strlen(car);i++) {
		del_car[i]='\b';    //�γ���С��ͬ�������ַ���
	}
	del_car[i]='\0';	//�ַ���β����ӽ�����
	switch(m){
		case 'A':
			for(int i=0;i<n;i++){
				cout<<' '<<car;
				Sleep(1000/k);
				cout<<del_car;	
			}
			break;
		case 'B':
			for(int i=0;i<n;i++){
				cout<<car;
				Sleep(1000/k);
				cout<<del_car;
				for(int j=0;j<strlen(car);j++){
					cout<<" ";
				}
				cout<<"\n";
			}
			break;
		case 'C':
			for(int j=0;j<n+2;j++){
				cout<<" ";
			}
			cout<<car;
			for(int i=0;i<n;i++){
				cout<<del_car<<"\b";
				Sleep(1000/k);
				cout<<car<<" "<<"\b";
			}
			break;
		case 'D':
			cout<<car;
			for(int i=0;i<n;i++){
				Sleep(1000/k);
				cout<<del_car;
				for(int j=0;j<strlen(car);j++){
					cout<<" ";
				}
				cout<<"\n";
				for(int j=0;j<i+1;j++){
					cout<<" ";
				}
				cout<<car;
			}
			break;
	}
}
int main( )   // ���Ժ���walking() �õ�������
{	
	walking("0-0-0-0-0-0-0-0",10,2,'D');
	return 0;
}

