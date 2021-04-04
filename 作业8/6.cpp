#include<iostream>
#include<cstring>
using namespace std;
struct Word{
	char word[20];
	int frep;
};
int main(){
	char a[5000];
	Word w[2000];
	cout<<"请输入字符串：";
	cin.get(a,4999);
	int num=0; // 已经存放的单词数 
	int k=0;
	for(int i=0;i<strlen(a);i++){
		if(a[i]==' '||a[i]=='.'||a[i]==','){ // 分隔单词 
			char temp[i-k+3];
			int ll=0;
			for(;k<i;k++){
				temp[ll]=a[k];
				ll++;
			}
			temp[ll]='\0';
			k++; // 跳过空格逗号等 
			int j=0;
			for(;j<num;j++){ // 对比查找是否已出现 
				if(strcmp(w[j].word,temp)==0){
					w[j].frep++;
					break;
				}
			}
			if(j>=num){
				strcpy(w[num].word,temp);
				w[num].frep=1; 
				num++;
			}
		}
	}
	for(int i=num-1;i>=0;i--){ // 冒泡排序 
		for(int j=0;j<i;j++){
			if(strcmp(w[j].word,w[j+1].word)>0){
				Word tem=w[j];
				w[j]=w[j+1];
				w[j+1]=tem;
			}
		}
	}
	for(int i=0;i<num;i++){ // 输出 
		cout<<w[i].word<<"  "<<w[i].frep<<endl;
	}
}
