#include <iostream>
#include<windows.h>
using namespace std;
void walking(char car[],int n,int k,char m)
{
	int i;
	int j;
	char del_car[80];    //存放消除小车的字符串
	for(i=0;i<strlen(car);i++) {
		del_car[i]='\b';    //形成与小车同样长度字符串
	}
	del_car[i]='\0';	//字符串尾部添加结束符
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
int main( )   // 测试函数walking() 用的主函数
{	
	walking("0-0-0-0-0-0-0-0",10,2,'D');
	return 0;
}

