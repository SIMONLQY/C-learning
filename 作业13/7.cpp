#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
int main(){
	ofstream out("gouke");
	for(int i=1;i<=100;i++){
		for(int j=i+1;j<=100;j++){
			if((sqrt(i*i+j*j)==(int)sqrt(i*i+j*j))&&(sqrt(i*i+j*j)>=1)&&(sqrt(i*i+j*j)<=100)){
				out<<i<<"^2+"<<j<<"^2="<<(int)sqrt(i*i+j*j)<<"^2";
				out<<"  ";
				out<<i*i<<"+"<<j*j<<"="<<i*i+j*j;
				out<<endl;
			}
		}
	}
	out.close();
}
