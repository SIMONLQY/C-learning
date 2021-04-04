#include<iostream>
using namespace std;
enum Color{
	red,
	yellow,
	blue,
	white,
	black
};
void sc(int i);
int main(){
	Color a[3];
	int num=0;
	for(int i=red;i<=blue;i++){
		for(int j=i+1;j<=white;j++){
			for(int k=j+1;k<=black;k++){
				sc(i);
				sc(j);
				sc(k);
				cout<<endl;
				num++;
			}
		}
	}
	cout<<"共有"<<num<<"种组合"; 
}

void sc(int i){
	switch(i){
		case red:
			cout<<"red"<<"\t";
			break;
		case yellow:
		    cout<<"yellow"<<"\t";
			break;
		case blue:
		    cout<<"blue"<<"\t";
		    break;
		case white:
		    cout<<"white"<<"\t";
		    break;
		case black:
			cout<<"black"<<"\t";
			break;
	}
}
