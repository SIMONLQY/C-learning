#include <iostream> 
using namespace std;
int main()
{	
	int n, i, j, k;
	double sum=0.0;
	double ave;
	int t=0;
	for(n=100.0; n<=999.0; n=n+1)
	{	
		i = n/100;            // 取出n的百位数
		j = (n/10)%10;     // 取数n的十位数
		k = n%10;           // 取出n的个位数
		if ( n==i*i*i+j*j*j+k*k*k ){
			cout <<n<<" = "<<i<<"^3 + "<<j<<"^3 + "<<k<<"^3"<<endl;
		    t=t+1;
		    sum=sum+n;
		}	
	}
	ave=sum/t;
	cout<<"所有水仙花数的和为"<<sum<<endl;
	cout<<"他们的平均数为"<<ave;
	return 0;
}

