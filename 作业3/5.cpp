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
		i = n/100;            // ȡ��n�İ�λ��
		j = (n/10)%10;     // ȡ��n��ʮλ��
		k = n%10;           // ȡ��n�ĸ�λ��
		if ( n==i*i*i+j*j*j+k*k*k ){
			cout <<n<<" = "<<i<<"^3 + "<<j<<"^3 + "<<k<<"^3"<<endl;
		    t=t+1;
		    sum=sum+n;
		}	
	}
	ave=sum/t;
	cout<<"����ˮ�ɻ����ĺ�Ϊ"<<sum<<endl;
	cout<<"���ǵ�ƽ����Ϊ"<<ave;
	return 0;
}

