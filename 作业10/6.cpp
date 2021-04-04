#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
//定义两个全局字符指针数组，存取所需的单词
//num1中为1到19，空出了0，所以可以直接用num1 [n]调用，得到n对应单词
static char *num1[]=
{
       "","one ","two ","three ","four ","five ","six ","seven ","eight ","nine ","ten ","eleven ","twelve ",
       "thirteen ","fourteen ","fifteen ","sixteen ","seventeen ","eighteen ","nineteen "
};
//num10中为20-90，空出了0和1，所以可以直接用num10[n/10]调用，得到n对应单词
static char *num10[]=
{
       "","","twenty ","thirty ","forty ","fifty ","sixty ","seventy ","eighty ","ninety "
};
class robot
{
	private:
		char name[20];
		int age;
		int num;
		char *s[5];
		int jiou();
		int ss();
		int dizeng();
		int huiwen();
	public:
		robot()
		{
			strcpy(name,"XXXXXX");
			age=0;
			num=0;
			s[0]="顾";
			s[1]="刚";
			s[2]="可";
			s[3]="真";
			s[4]="帅";
		}
		robot(char *name,int age,int num){
			strcpy(this->name,name);
			this->age=age;
			this->num=num;
			s[0]="顾";
			s[1]="刚";
			s[2]="可";
			s[3]="真";
			s[4]="帅";
		}
		void write(char *a); // 写汉字函数
		void judge(); // 判断整数类别的函数 
		void out(int a);//英文中每三位数读法相同，所以定义out函数翻译小于1000的整数 
		void tran_int();//将1至1999999999的整数翻译成英文句子 
		void info();
		~robot(){};//析构函数 
};
void robot::info(){
	cout<<"你好，我是你的机器人"<<name<<",";
	cout<<"我今年"<<age<<"岁了"<<endl;
	cout<<"你刚才输入的数字";
	judge();
	tran_int();
	cout<<"请输入你想让我写的汉字："<<endl;
	char a[10];
	cin>>a;
	write(a);
}
int robot::jiou(){
	if(num%2==0){ // 判断奇偶 
		return 0;
	}else{
		return 1;
	}
}
int robot::ss(){
	int a=num;
	bool ss=true; // 判断素数 
	for(int i=2;i<sqrt(a);i++){
		if(a%i==0){
			ss=false;
		}
	}
	if(ss==true){
		return 1;
	}
	return 0;
}
int robot::dizeng(){ // 判断递增数 
	int k=1;
	bool judge=true;
	while(num/k!=0){
		int l0=num%(k*10)/k;
		int l1=num%(k*100)/(k*10);
		if(l0<l1) judge=false; 
		k*=10;
	}
	if(judge==true){
		return 1;
	}
	return 0;
}
int robot::huiwen(){ // 判断回文数
    int n=num; 
	int i=0;
	int k=10;
	do{
		n=n/k;
		i++;
	}while(n!=0);
	k=1;
	int gewei[i];
	for(int j=0;j<i;j++){
		gewei[j]=(num%(k*10))/k;
		k*=10;
	}
	for(int j=0;j<i/2;j++){
		if(gewei[j]!=gewei[i-1-j]){
			return 0;
		}
	}
	return 1;
}
void robot::judge(){
	cout<<num<<"是一个";
	if(jiou()==1){
		cout<<"奇数";
	}else{
		cout<<"偶数"; 
	}
	if(ss()==1){
		cout<<",素数";
	}
	if(dizeng()==1){
		cout<<",递增数"; 
	}
	if(huiwen()==1){
		cout<<",回文数";
	}
	cout<<endl;
}
void robot::write(char* a){
	bool t=false;
	for(int i=0;i<5;i++){
		if(strcmp(a,s[i])==0){
			cout<<s[i]<<endl;
			t=true;
		}
	}
	if(t==false){
		cout<<"抱歉，我暂时写不了这个汉字"<<endl;
	}
}
void robot::out(int a)
{
     int b=a%100;
		//若百位不为零，输出百位数加hundred，若此时十位个位均为0，不加and
     if(a/100!=0)
     {
                 cout<<num1[a/100]<<"hundred ";
                 if(b!=0)
                 cout<<"and ";
     }
		//当后两位在20以内时，直接调用num1[n]，输出
     if(b<20)
     cout<<num1[b];
		//当后两位大于20时
     else 
     {
			  //先调用num10，输出十位数
          cout<<num10[b/10];
			  //个位不为0时应输出"-"个位数
          if(b%10!=0)
          cout<<"\b-"<<num1[b%10];
     }
}
void robot::tran_int()
{
	int n=num;
	if(n>1999999999)
		cout<<"dev C++平台无法处理大于1999999999位的数！"<<endl; 
	else
	{
		//三位三位取出，存入abcd中
		int a=n/1000000000,b=(n%1000000000)/1000000,c=(n%1000000)/1000,d=n%1000;
		//不等于0时，输出并加上million或thousand
		if(a!=0)
	    {
            out(a);
            cout<<"billion ";
	    }
	
		if(b!=0)
	    {
            out(b);
            cout<<"million ";
	    }
	   	if(c!=0)
	    {
            out(c);
            cout<<"thousand ";
	    }
	   	if(d!=0)
	   	{
            //据英文语法规则，最后两位前一定有and
			if(d<100&&(a!=0||b!=0||c!=0))
            	cout<<"and ";
            out(d);
	    }
    cout<<endl;
    }
}
int main()
{
	int n;
	cout<<"请输入n：";
	cin>>n;
	robot Simon("Simon",10,n);
	Simon.info();
    return 0;
}


