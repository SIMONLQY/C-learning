#include<iostream>
#include<cstring>
#include<stdlib.h>//包含头文件,rand()需要
#include<ctime> 
#include<windows.h>
using namespace std;
int main(){
	int alltime[100][3];
	srand(time(0));
	for(int i=0;i<100;i++){
		alltime[i][0]=rand()%24;
		alltime[i][1]=rand()%60;
		alltime[i][2]=rand()%60;
	}
	for(int i=0;i<100;i++){
		cout<<alltime[i][0]<<":"<<alltime[i][1]<<":"<<alltime[i][2]<<endl;
	}
	int mintime[3]={24,60,60};
	for(int i=0;i<100;i++){
		if(alltime[i][0]<mintime[0]){
			mintime[0]=alltime[i][0];
		}
		if(alltime[i][1]<mintime[1]){
			mintime[1]=alltime[i][1];
		}
		if(alltime[i][2]<mintime[2]){
			mintime[2]=alltime[i][2];
		}
	}
	cout<<"其中最小时间为："<<mintime[0]<<":"<<mintime[1]<<":"<<mintime[2]<<endl;
	cout<<mintime[0]<<":"<<mintime[1]<<":"<<mintime[2];
	for(int i=0;i<10;i++)      //只模拟运行秒钟
	{	
	    if(mintime[2]==0&&mintime[1]==0){
	    	for(int i=0;i<mintime[0];i++){
	    		cout<<"\007";
			}
		}
		mintime[2]++;
		if(mintime[2]==60)
		{	
			mintime[2]=0;
			mintime[1]++;
			if(mintime[1]==60)
			{	
				mintime[1]=0;
				mintime[0]++;
				if(mintime[0]==24) mintime[0]=0;
			}
		}
		cout<<'\r';		//不换行，返回当前行的首位
		Sleep(1000);  	//程序暂停运行秒
		cout<<mintime[0]<<":"<<mintime[1]<<":"<<mintime[2];
	}
	return 0;
}
