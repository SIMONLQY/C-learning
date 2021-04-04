#include<iostream>
#include<windows.h>
#include<string.h>
#include<cmath>
using namespace std;
struct dictionary
{
	int number;
	char eng[50];
	char han[25];
	char spell[30];
};
dictionary my_[]={
		{0,"zero","零","Ling"},
		{1,"one","一","Yi"},
		{2,"two","二","Er"},
		{3,"three","三","San"},
		{4,"four","四","Si"},
		{5,"five","五","Wu"},
		{6,"six","六","Liu"},
		{7,"seven","七","Qi"},
		{8,"eight","八","Ba"},
		{9,"nine","九","Jiu"},
		{10,"ten","十","Shi"},
		{11,"eleven","十一","Shi Yi"},
		{12,"twelve","十二","Shi Er"},
		{20,"twenty","二十","Er Shi"},
		{100,"hundred","一百","Yi Bai"},
		{1000,"thousand","一千","Yi Qian"},
		{1000000,"million","一百万","Yi Bai Wan"},
		{1000000000,"billion","十亿","Shi Yi"},
		{1,"january","一月","Yi Yue"},
		{12,"december","十二月","Shi Er Yue"},
		{1,"monday","星期一","Xing Qi Yi"},
		{7,"sunday","星期日","Xing Qi Ri"}};
//定义两个全局字符指针数组，存取所需的单词
//num1中为1到19，空出了0，所以可以直接用num1 [n]调用，得到n对应单词
static const char *num1[]=
{
       "","one ","two ","three ","four ","five ","six ","seven ","eight ","nine ","ten ","eleven ","twelve ",
       "thirteen ","fourteen ","fifteen ","sixteen ","seventeen ","eighteen ","nineteen "
};
//num10中为20-90，空出了0和1，所以可以直接用num10[n/10]调用，得到n对应单词
static const char *num10[]=
{
       "","","twenty ","thirty ","forty ","fifty ","sixty ","seventy ","eighty ","ninety "
};
class person
{		
protected:
	char *name;			//人名
	char sex;			//性别
	char pid[19];		//身份证号码
    dictionary *mymem;	//人脑记忆空间指针 
	int sum; 			//人脑记忆单词数量 
	char *speekn;
public:
	person();   //无参构造函数
	person(char *n,char s,char *p,dictionary *my,int k);  //有参构造函数
	void change_data(char *n,char s,char *p,dictionary *my,int k);	//修改数据
	void walking(int k,int v);		//以v速度行走k步
	void hearing(char *sentence);	//将句子字符串小写变大写，大写变小写输出   
	void speek(int n);				//说出整数n的英文
	void speek(char *han_p);		//说出汉字拼音
	void reading(char *eng_p);		//阅读单词、短语、句子，写出相关汉字，说出相关拼音
	void writing(char *han_p);		//写出汉字	
	void showme();					//输出人的属性值
	void out(int a);				//翻译小于1000的整数
	char* speek_n(int n);
	~person();						//析构函数
};
char* person::speek_n(int n){
	int k=0,i=fabs(n);
	int l[20];
	while(i){
		l[k]=i%10;
		i/=10;
		k++;
	}
	char *p=new char[5*k+10];
	if(n<0){
		p[0]='F';
		p[1]='u';
		p[2]=' ';
		p[3]='\0';
	}else{
		p[0]='\0';
	}
	for(int j=0;j<k;j++){
		strcat(p,my_[l[k-1-j]].spell);
		strcat(p," ");
	}
	speekn=p;
	return p;
}
person::person()
{
	name = NULL;
	mymem = NULL;
	pid[0] = sex = sum = '\0';
	speekn=NULL;
}
person::person(char *n,char s,char *p,dictionary *my,int k)
{
	name=new char[strlen(n)+1];
	strcpy(name,n);
	strcpy(pid,p);
	sex=s;
	sum=k;
	mymem=new dictionary[sum];
	for(int i=0;i<sum;i++) *(mymem+i)=*(my+i);
}
void person::change_data(char *n,char s,char *p,dictionary *my,int k)
{
	if(name!=NULL) delete []name;
	name=new char[strlen(n)];
	strcpy(name,n);
	strcpy(pid,p);
	sex=s;
	sum=k;
	if (mymem!=NULL) delete []mymem;
	mymem=new dictionary[sum];
	for(int i=0;i<sum;i++) *(mymem+i)=*(my+i);	
}
void person::out(int a)
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
void person::walking(int k,int v)
{
	cout<<"\n"<<name<<"水平直线行走"<<k<<"步"<<endl;
	for(int i=0;i<k;i++)
	{
		cout<<' '<<"o_o";
		Sleep(1000/v);
		cout<<"\b\b\b";
	}
}
void person::hearing(char *sentence)
{
	cout<<endl<<sentence<<endl;
	char *p=new char[strlen(sentence)+1];
	strcpy(p,sentence);
	char *pp=p;
	while(*p)
	{
		if(*p>='a' && *p<='z')
			*p='A'+(*p-'a'+0);
		else if(*p>='A' && *p<='Z')
				*p='a'+(*p-'A');
			
		p++;
	}
	cout<<pp<<endl;
	delete pp;
}
void person::speek(char *han_p)
{
	cout<<han_p;
}
void person::speek(int n)
{
	cout<<n<<" --> ";
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
void person::reading(char *eng_p)
{
	int i;
	cout<<endl<<eng_p<<" --> ";
	for(i=0;i<sum;i++)
		if (strcmp(eng_p,mymem[i].eng)==0)
		{
			writing(mymem[i].han);
			cout<<" --> ";
			speek(mymem[i].spell);
			if (mymem[i].number!=-1) 
			{
				cout<<" --> ";
				speek(mymem[i].number);
			}
			break;
		}
	if (i==sum) cout<<" not understanding!\n";	
}
void person::writing(char *han_p)
{
	cout<<han_p;
}
void person::showme()
{
	cout<<endl<<"姓名："<<name<<' '<<"性别：";
	if (sex=='m')
		cout<<"男"<<' ';
	else 
		cout<<"女"<<' ';
	cout<<"身份证号码："<<pid<<' ';
	cout<<"词汇量："<<sum<<endl;	
}
person::~person()               //析构函数
{
	if (name!=NULL) delete []name;
	if (mymem!=NULL) delete []mymem;
	if(speekn!=NULL) delete []speekn;
}
class cryptographist:public person{
	char *mingwen;
	char *miwen;
	int key;
	public:
	    char *cipher(char *Plaintext);
		char *decipher(char *ciphertext);
		void change_data(char *n,char s,char *p,dictionary *my,int k,int key);
		cryptographist(char *n,char s,char *p,dictionary *my,int k,int key);
		cryptographist():person(){
			mingwen=NULL;
			miwen=NULL;
			key=0;
		}
		~cryptographist(){
			if (name!=NULL) delete []name;
			if (mymem!=NULL) delete []mymem;
			if(speekn!=NULL) delete []speekn;
			if(mingwen!=NULL) delete []mingwen;
			if(miwen!=NULL) delete []miwen;
		};
};
cryptographist::cryptographist(char *n,char s,char *p,dictionary *my,int k,int key)
:person(n,s,p,my,k){
	if(key>9){
		this->key=9;
	}else if(key<3){
		this->key=3;
	}else{
		this->key=key;
	}
	mingwen=NULL;
	miwen=NULL;
}
void cryptographist::change_data(char *n,char s,char *p,dictionary *my,int k,int key){
	if(name!=NULL) delete []name;
	name=new char[strlen(n)];
	strcpy(name,n);
	strcpy(pid,p);
	sex=s;
	sum=k;
	if (mymem!=NULL) delete []mymem;
	mymem=new dictionary[sum];
	for(int i=0;i<sum;i++) *(mymem+i)=*(my+i);	
	this->key=key;
}
char*cryptographist::cipher(char *Plaintext){
	if(miwen!=NULL){
		delete []miwen;
	}
	if(mingwen!=NULL){
		delete []mingwen;
	}
	int n=strlen(Plaintext);
	miwen=new char[n];
	mingwen=new char[n];
	strcpy(mingwen,Plaintext);
	strcpy(miwen,Plaintext);
	for(int i=0;i<n;i++){
		if(miwen[i]>='a'&&miwen[i]<='z'-key){
			miwen[i]+=key;
		}else if(miwen[i]>'z'-key&&miwen[i]<='z'){
			miwen[i]='a'+key-('z'-miwen[i]);
		}
		if(miwen[i]>='0'&&miwen[i]<='9'-key){
			miwen[i]+=key;
		}else if(miwen[i]>'9'-key&&miwen[i]<='9'){
			miwen[i]='a'+key-('9'-miwen[i]);
		}
		if(miwen[i]>='A'&&miwen[i]<='Z'-key){
			miwen[i]+=key;
		}else if(miwen[i]>'Z'-key&&miwen[i]<='Z'){
			miwen[i]='A'+key-('Z'-miwen[i]);
		}
	}
	return miwen;
}
char *cryptographist::decipher(char *ciphertext){
	if(miwen!=NULL){
		delete []miwen;
	}
	if(mingwen!=NULL){
		delete []mingwen;
	}
	int n=strlen(ciphertext);
	miwen=new char[n];
	mingwen=new char[n];
	strcpy(mingwen,ciphertext);
	strcpy(miwen,ciphertext);
	for(int i=0;i<n;i++){
		if(mingwen[i]>='a'+key&&miwen[i]<='z'){
			mingwen[i]-=key;
		}else if(mingwen[i]>='a'&&miwen[i]<'a'+key){
			mingwen[i]='z'-(key-(mingwen[i]-'a'));
		}
		if(mingwen[i]>='0'+key&&mingwen[i]<='9'){
			mingwen[i]-=key;
		}else if(mingwen[i]>='0'&&mingwen[i]<'0'+key){
			miwen[i]='9'-(key-(mingwen[i]-'0'));
		}
		if(mingwen[i]>='A'+key&&mingwen[i]<='Z'){
			mingwen[i]-=key;
		}else if(mingwen[i]>='A'&&mingwen[i]<'A'+key){
			miwen[i]='Z'-(key-(mingwen[i]-'Z'));
		}
	}
	return mingwen;
}
int main()
{
	char name_[20],sex_,PID_[19];
	cout<<"input name,sex,PID:  ";
	cin>>name_>>sex_>>PID_;
	cin.get();
	cryptographist Jack(name_,sex_,PID_,my_,12,3);	//创建对象杰克 
	Jack.showme();                         //输出人的属性值
//	Jack.hearing((char *)"Hi! You are simple!");     //听英文句子
//	Jack.speek(1006);                    //说出整数num的英文句子
//	Jack.reading((char *)"eleven"); 
    int l;
    cout<<"请输入你想让他读的数：";
    cin>>l;
    cin.get();
    cout<<Jack.speek_n(l)<<endl;
    cout<<"请输入明文："<<endl;
    char mingwen[20];
    cin.get(mingwen,19);
    cin.get();
    cout<<"密文是："<<Jack.cipher(mingwen)<<endl;
    cout<<"请输入密文："<<endl;
    char miwen[20];
    cin.get(miwen,19);
    cin.get();
    cout<<"明文是："<<Jack.decipher(miwen);
	return 0;
}

