#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
void my_static( char * str,int *count,int *upper,int *lower,int *digit,int *other);
int main(){
	char c[101];
	cout<<"请输入字符串：";
	cin.get(c,100);
	int count=strlen(c);
	int upper=0,lower=0,digit=0,other=0;
	my_static(c,&count,&upper,&lower,&digit,&other);
	cout<<"字符串共包含"<<count<<"个字符"<<endl;
	cout<<"大写字母共有"<<upper<<"个"<<endl;
	cout<<"小写字母共有"<<lower<<"个"<<endl;
	cout<<"数字共有"<<digit<<"个"<<endl;
	cout<<"其他字符共有"<<other<<"个"<<endl;
	return 0;
} 


void my_static( char * str,int *count,int *upper,int *lower,int *digit,int *other){
	for(int i=0;i<*count;i++){
		if(str[i]>='0'&&str[i]<='9'){
			(*digit)++;
		} else if(str[i]>='a'&&str[i]<='z'){
			(*lower)++;
		} else if(str[i]>='A'&&str[i]<='Z'){
			(*upper)++;
		} else{
			(*other)++;
		}
	}
}

