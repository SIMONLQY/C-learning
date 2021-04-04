#include<iostream>

using namespace std;

 main()
 

{  int swap() ;

  int a,b;

  a=3;

  b=10;

  swap(a,b);

  cout<<"a= " <<a<<" b= " <<b<<endl;

}

int swap(int a,int b)

{ int temp; temp=a; a=b; b=temp; }
