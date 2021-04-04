#include<iostream>
#include<windows.h>
#include<ctime>
using namespace std;
class zheng{
	private:
		int r;
		int* a;
		double zfx[100][100];
	public:
		zheng(){
			r=0;
			a=NULL;
		}
		zheng(zheng &g){
			r=g.r;
			a=new int[4*(r-1)];
			for(int i=0;i<4*(r-1);i++){
				a[i]=g.a[i];
			}
			for(int i=0;i<100;i++){
				for(int j=0;j<100;j++){
					zfx[i][j]=g.zfx[i][j];
				}
			}
		}
		zheng(int n){
			r=n;
			a=new int[4*(r-1)];
			for(int i=0;i<4*(r-1);i++){
				a[i]=rand()%100;
			}
			f_zfx();
		}
		void f_zfx(){
			int k=0;
			for(int j=0;j<=r-2;j++){
				zfx[0][j]=a[k]+0.001*j;
				k++;
			}
			for(int i=0;i<=r-2;i++){
				zfx[i][r-1]=a[k]+0.01*i+0.001*(r-1);
				k++;
			}
			for(int j=r-1;j>=1;j--){
				zfx[r-1][j]=a[k]+0.01*(r-1)+0.001*j;
				k++;
			}
			for(int i=r-1;i>=1;i--){
				zfx[i][0]=a[k]+0.01*i;
				k++;
			}
		}
		void out(){
			int k=0;
			for(int i=0;i<r;i++){
				for(int j=0;j<r;j++){
					if(i==0||j==0||i==r-1||j==r-1){
						cout.width(8);
						cout.fill(' ');
						cout<<left<<zfx[i][j];
					}else{
						cout.width(8);
						cout<<' ';
					}
					k++;
					if(k==r){
						k=0;
						cout<<'\n';
					}
				}
			}
		}
		bool operator ==(zheng& z){
			bool t=true;
			for(int i=0;i<4*(r-1);i++){
				if(a[i]!=z.a[i]){
					t=false;
				}
			}
			if(r==z.r&&t==true){
				return true;
			}else {
				return false;
			}
		}
		~zheng(){
			if(a!=NULL){
				delete []a;
			}
		}
};
int main(){
	srand(time(0));
	zheng b(10);
	b.out();
} 
