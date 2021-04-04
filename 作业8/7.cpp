#include<iostream>
using namespace std;
struct song{
	char music[50];
	char singer[20];
	int freq;
};
int main(){
	song a[5];
	cout<<"请输入5首歌的歌名、歌手和点击率:"<<endl;
	for(int i=0;i<5;i++){
		cin>>a[i].music>>a[i].singer>>a[i].freq;
	}
	for(int i=4;i>=0;i--){
		for(int j=0;j<5;j++){
			if(a[j].freq<a[j+1].freq){
				song tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		}
	}
	cout<<"\n";
	for(int i=0;i<5;i++){
		cout<<a[i].music<<"  "<<a[i].singer<<"  "<<a[i].freq<<endl;
	}
} 
