#include <iostream>  //�����ַ���������N��
using namespace std;
int main()
{   
    int N,i=1;
    char resultc=1;
    short results=1;
    int resulti=1;
    double result=1;
    while ( i<=1000 )
    {
    	if(resulti*i!=result*i){
    		cout<<"����NΪ"<<i-2; 
    		break;
		}else{
			resulti=resulti*i;
			result=result*i;
		    cout<<i<<"!="<<result+0<<endl;
		    i=i+1;
		}	
    }
	return 0;
}

