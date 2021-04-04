#include <iostream> 
using namespace std;
int main()
{	
    long n,g,s,b,q;
    int t=0;
    int h=0;
	for(n=1000;n<=2000;n++){
		g=n%10;
		s=(n/10)%10;
		b=(n/100)%10;
		q=n/1000;
		if(g+s==b+q){
			cout<<n<<"\t";
			t=t+1;
			h=h+1;
			if(h==8){
				cout<<endl;
				h=0; 
			}
		}
	}
	cout<<"\n满足条件的数共有"<<t<<"个";
	return 0;
}

