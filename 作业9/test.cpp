#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;
char *ge(int n)              //��λ������ 
{   static char *ge[]=
    {   " zero",        // �� 
        " one",     // һ
        " two",     // ��
        " three",       // ��
        " four",            // ��
        " five",            // ��
        " six",         // ��
        " seven",           // ��
        " eight",       // ��
        " nine"     // ��
    };
    return ge[n];
}
char *shi1(int n)                     //ʮλ�����루��Ϊ10-19ʱ�� 
{   static char *shi1[]=
    {   " ",        // �� 
        " ",           //һ 
        " twenty",      // ��
        " thrirth",     // ��
        " forty",           // ��
        " fifty",           // ��
        " sixty",           // ��
        " seventy",         // ��
        " eighty",      // ��
        " ninty",       // ��
    };
    return shi1[n];
}
char *shi2(int n)             //ʮλ�����루Ϊ10-19ʱ�� 
{   
    static char *shi2[]=
    {" ",   
    " eleven",      // һ 
        " twelve",      // ��
        " thirteen",        // ��
        " forteen",         // ��
        " fifteen",         // ��
        " sixteen",         // ��
        " seventeen",           // ��
        " eighteen",        // ��
        " ninteen",     // ��
    };
    return shi2[n];
}
char *bai(int n)          //��λ������
{   static char *bai[]=
    {   " ",        // �� 
        " one hundred and",     // һ
        " two hundred and",     // ��
        " three hundred and",       // ��
        " four hundred and",            // ��
        " five hundred and",            // ��
        " six hundred and",         // ��
        " seven hundred and",           // ��
        " eight hundred and",       // ��
        " nine hundred and",        // ��
    };
    return bai[n];
}
char *lian(int n)                   //���ӵ���
{   static char *lian[]=
    {   
        " ",
        " thousand",        
        " million",     
        " billion",     
    };
    return lian[n];
}
char *trans_int( long long unsigned int k )
{
    
    int n,s=0,m,i,j;
    long long int k1=k,k2=k;
    //cout<<" k1"<<k1;
    while(k1)       //�󳤶�s 
    {
        s++;
        k1/=10;
    }
    //cout<<" s"<<s;
    int *a=new int[s];        //��Ÿ�����λ���ֵ��������� 
    for(i=0;i<s;i++)
    {
        if(i>8)    // ����8λʱ����ֹ�������� 
        {
            k2=k/pow(10,9);           //��ȥ��9λ�� 
            *(a+i)=k2%int(pow(10,(i+1-9)))/pow(10,i-9);     // ��������λ���ָ�ֵ���������� 
        }
        else
        {
            *(a+i)=k%int(pow(10,(i+1)))/pow(10,i);     // ��������λ���ָ�ֵ���������� 
        }
    }
    n=(s+2)/3; //ÿ��������Ϊһ�飬nΪ���� 
    m=n;
    string b;     //����string b 
    while(m)          //��m=n��Ϊ0ʱ 
    {
        for(i=n;i>0;i--)
        {   
            if(s<=i*3-1)  *(a+i*3-1)=0;   // ���i*3-1С�ڳ��ȣ�����*(a+i*3-1)=0����ֹ�����޷��ж� 
            if(*(a+i*3-1)!=0)      //�����λ����Ϊ0����ʼ���� 
            {
                b+=bai(*(a+i*3-1));       
            }
            if(s<=i*3-2)  *(a+i*3-2)=0;            // ���i*3-2С�ڳ��ȣ�����*(a+i*3-2)=0����ֹ�����޷��ж� 
            if(*(a+i*3-2)!=0)            // ���ʮλ����Ϊ0����ʼ���� 
            {
                if(*(a+i*3-2)==1)    //10-19 
                {
                    b+=shi2(*(a+i*3-3));
                    *(a+i*3-3)=0;
                }
                else          //��10-19 
                {
                    b+=shi1(*(a+i*3-2));
                }
            
            }
            if(*(a+i*3-3)!=0) //�����λ����Ϊ0����ʼ����  
            {
            b+=ge (*(a+i*3-3));
            }
            if((m-1)!=0)   //���m-1��Ϊ0����ʼ���� 
            {
            b+=lian(m-1);
            }
            m=m-1;
        }
        
    } 
    char *result=new char [b.length()+1];
    strcpy(result,b.c_str());
    result[b.length()]='\0';
    int l=strlen(result);      //stringת��Ϊchar 
    return result;
    
}
int main()
{
    long long int k;
    cout<<"������һ��������"<<endl;
    cin>>k;
    cout<<"Ӣ��Ϊ��"<<endl<<trans_int(k);
    return 0;
}

