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
		cout<<" �ļ���ȡʧ�ܣ�������"<<endl;
		return 1;
	}
	if(!out){
		cout<<" ���ʱ�ļ���ʧ��"<<endl;
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
