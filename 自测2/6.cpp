#include<iostream>
#include<fstream>
using namespace std;
int main(){
	char source[50];
	cout<<"Please input filename:";
	cin>>source;
	ifstream in(source);
	ofstream out("t_data.txt");
	if(!in){
		cout<<" 文件读取失败，请重试"<<endl;
		return 1;
	}
	if(!out){
		cout<<" 输出时文件打开失败"<<endl;
		return 1;
	}
	int n=4;
	int a[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			in>>a[i][j];
		}
	}
	in.close();
	int k=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			out<<a[j][i]<<" ";
			k++;
			if(k==n){
				k=0;
				out<<'\n';
			}
		}
	}
	out.close();
}
