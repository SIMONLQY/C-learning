#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int  statistic(char *string);
int main(){
	char string[]="i love you,but i dont like you.I have 2 dogs.";
	cout<<string<<endl;
	cout<<"�����¹��е��ʣ�"<<statistic(string)<<"��";
	return 0;
} 

int  statistic(char *string){
	int num;
	int count = strlen(string);
	for(int i=0;i<count;i++){
		if(string[i]==' '||string[i]==','||string[i]=='.'){
			num++;
		}
	}
	return num;
}

