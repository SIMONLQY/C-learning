#include<iostream>//包含头文件cout,cin需要
#include<stdlib.h>//包含头文件,rand()需要
#include<ctime> 
using namespace std;//名字空间
int main()//主函数
{
	srand(time(0));
	int a,b,c;//分别表示两个数及它们的和
	int input;//存放用户输入的和
	char cont;
	do{
		a=rand()%100;//产生小于100的随机数
		b=rand()%100;//产生小于100的随机数
		c=a+b;//计算和
		cout<<a<<"+"<<b<<"=?"<<endl;//显示两个数并提示用户输入
		cin>>input;//用户输入的和
		while(input!=c){
			cout<<"答案错误，请再仔细算一遍并输入结果"<<endl;
			cin>>input;
		}
		cout<<"恭喜你，回答正确，请问您想继续练习还是退出，继续请输入\'y\',退出请输入\'n\'."<<endl;
		cin>>cont;
	}while(cont=='y');
	return 0;
}


