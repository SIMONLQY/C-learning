#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;
char *ge(int n)              //个位数翻译 
{   static char *ge[]=
    {   " zero",        // 零 
        " one",     // 一
        " two",     // 二
        " three",       // 三
        " four",            // 四
        " five",            // 五
        " six",         // 六
        " seven",           // 七
        " eight",       // 八
        " nine"     // 九
    };
    return ge[n];
}
char *shi1(int n)                     //十位数翻译（不为10-19时） 
{   static char *shi1[]=
    {   " ",        // 零 
        " ",           //一 
        " twenty",      // 二
        " thrirth",     // 三
        " forty",           // 四
        " fifty",           // 五
        " sixty",           // 六
        " seventy",         // 七
        " eighty",      // 八
        " ninty",       // 九
    };
    return shi1[n];
}
char *shi2(int n)             //十位数翻译（为10-19时） 
{   
    static char *shi2[]=
    {" ",   
    " eleven",      // 一 
        " twelve",      // 二
        " thirteen",        // 三
        " forteen",         // 四
        " fifteen",         // 五
        " sixteen",         // 六
        " seventeen",           // 七
        " eighteen",        // 八
        " ninteen",     // 九
    };
    return shi2[n];
}
char *bai(int n)          //百位数翻译
{   static char *bai[]=
    {   " ",        // 零 
        " one hundred and",     // 一
        " two hundred and",     // 二
        " three hundred and",       // 三
        " four hundred and",            // 四
        " five hundred and",            // 五
        " six hundred and",         // 六
        " seven hundred and",           // 七
        " eight hundred and",       // 八
        " nine hundred and",        // 九
    };
    return bai[n];
}
char *lian(int n)                   //连接单词
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
    while(k1)       //求长度s 
    {
        s++;
        k1/=10;
    }
    //cout<<" s"<<s;
    int *a=new int[s];        //存放各个数位数字的整形数组 
    for(i=0;i<s;i++)
    {
        if(i>8)    // 大于8位时，防止溢出的情况 
        {
            k2=k/pow(10,9);           //消去后9位数 
            *(a+i)=k2%int(pow(10,(i+1-9)))/pow(10,i-9);     // 将各个数位数字赋值到整形数组 
        }
        else
        {
            *(a+i)=k%int(pow(10,(i+1)))/pow(10,i);     // 将各个数位数字赋值到整形数组 
        }
    }
    n=(s+2)/3; //每三个数字为一组，n为组数 
    m=n;
    string b;     //定义string b 
    while(m)          //当m=n不为0时 
    {
        for(i=n;i>0;i--)
        {   
            if(s<=i*3-1)  *(a+i*3-1)=0;   // 如果i*3-1小于长度，则令*(a+i*3-1)=0，防止后面无法判断 
            if(*(a+i*3-1)!=0)      //如果百位数不为0，开始翻译 
            {
                b+=bai(*(a+i*3-1));       
            }
            if(s<=i*3-2)  *(a+i*3-2)=0;            // 如果i*3-2小于长度，则令*(a+i*3-2)=0，防止后面无法判断 
            if(*(a+i*3-2)!=0)            // 如果十位数不为0，开始翻译 
            {
                if(*(a+i*3-2)==1)    //10-19 
                {
                    b+=shi2(*(a+i*3-3));
                    *(a+i*3-3)=0;
                }
                else          //非10-19 
                {
                    b+=shi1(*(a+i*3-2));
                }
            
            }
            if(*(a+i*3-3)!=0) //如果个位数不为0，开始翻译  
            {
            b+=ge (*(a+i*3-3));
            }
            if((m-1)!=0)   //如果m-1不为0，开始翻译 
            {
            b+=lian(m-1);
            }
            m=m-1;
        }
        
    } 
    char *result=new char [b.length()+1];
    strcpy(result,b.c_str());
    result[b.length()]='\0';
    int l=strlen(result);      //string转换为char 
    return result;
    
}
int main()
{
    long long int k;
    cout<<"请输入一个整数："<<endl;
    cin>>k;
    cout<<"英文为："<<endl<<trans_int(k);
    return 0;
}

