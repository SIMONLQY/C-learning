#include<iostream>

using namespace std;

main()

{

    int i,j,a[5][5],sum1,sum2;
    int k=0;
    for(i=0;i<=4; i++){
    	for(j=0;j<=4;j++){
         	a[i][j]=i*j;
         	cout<<a[i][j]<<"\t";
         	k++;
         	if(k==5){
         		k=0;
         		cout<<"\n";
			 }
		  } 
	}
	cout<<"\n";
    sum1=sum2=0;

    for(i=0;i<5;i++)

    {   sum1+=a[i][i];

        sum2+=a[i][5-1-i];

    }

    cout<<sum1<<" "<<sum2;

}
