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
		{0,"zero","��","Ling"},
		{1,"one","һ","Yi"},
		{2,"two","��","Er"},
		{3,"three","��","San"},
		{4,"four","��","Si"},
		{5,"five","��","Wu"},
		{6,"six","��","Liu"},
		{7,"seven","��","Qi"},
		{8,"eight","��","Ba"},
		{9,"nine","��","Jiu"},
		{10,"ten","ʮ","Shi"},
		{11,"eleven","ʮһ","Shi Yi"},
		{12,"twelve","ʮ��","Shi Er"},
		{20,"twenty","��ʮ","Er Shi"},
		{100,"hundred","һ��","Yi Bai"},
		{1000,"thousand","һǧ","Yi Qian"},
		{1000000,"million","һ����","Yi Bai Wan"},
		{1000000000,"billion","ʮ��","Shi Yi"},
		{1,"january","һ��","Yi Yue"},
		{12,"december","ʮ����","Shi Er Yue"},
		{1,"monday","����һ","Xing Qi Yi"},
		{7,"sunday","������","Xing Qi Ri"}};
//��������ȫ���ַ�ָ�����飬��ȡ����ĵ���
//num1��Ϊ1��19���ճ���0�����Կ���ֱ����num1 [n]���ã��õ�n��Ӧ����
static const char *num1[]=
{
       "","one ","two ","three ","four ","five ","six ","seven ","eight ","nine ","ten ","eleven ","twelve ",
       "thirteen ","fourteen ","fifteen ","sixteen ","seventeen ","eighteen ","nineteen "
};
//num10��Ϊ20-90���ճ���0��1�����Կ���ֱ����num10[n/10]���ã��õ�n��Ӧ����
static const char *num10[]=
{
       "","","twenty ","thirty ","forty ","fifty ","sixty ","seventy ","eighty ","ninety "
};
class person
{		
protected:
	char *name;			//����
	char sex;			//�Ա�
	char pid[19];		//���֤����
    dictionary *mymem;	//���Լ���ռ�ָ�� 
	int sum; 			//���Լ��䵥������ 
	char *speekn;
public:
	person();   //�޲ι��캯��
	person(char *n,char s,char *p,dictionary *my,int k);  //�вι��캯��
	void change_data(char *n,char s,char *p,dictionary *my,int k);	//�޸�����
	void walking(int k,int v);		//��v�ٶ�����k��
	void hearing(char *sentence);	//�������ַ���Сд���д����д��Сд���   
	void speek(int n);				//˵������n��Ӣ��
	void speek(char *han_p);		//˵������ƴ��
	void reading(char *eng_p);		//�Ķ����ʡ�������ӣ�д����غ��֣�˵�����ƴ��
	void writing(char *han_p);		//д������	
	void showme();					//����˵�����ֵ
	void out(int a);				//����С��1000������
	char* speek_n(int n);
	~person();						//��������
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
		//����λ��Ϊ�㣬�����λ����hundred������ʱʮλ��λ��Ϊ0������and
     if(a/100!=0)
     {
                 cout<<num1[a/100]<<"hundred ";
                 if(b!=0)
                 cout<<"and ";
     }
		//������λ��20����ʱ��ֱ�ӵ���num1[n]�����
     if(b<20)
     cout<<num1[b];
		//������λ����20ʱ
     else 
     {
			  //�ȵ���num10�����ʮλ��
          cout<<num10[b/10];
			  //��λ��Ϊ0ʱӦ���"-"��λ��
          if(b%10!=0)
          cout<<"\b-"<<num1[b%10];
     }
}
void person::walking(int k,int v)
{
	cout<<"\n"<<name<<"ˮƽֱ������"<<k<<"��"<<endl;
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
		cout<<"dev C++ƽ̨�޷��������1999999999λ������"<<endl; 
	else
	{
		//��λ��λȡ��������abcd��
		int a=n/1000000000,b=(n%1000000000)/1000000,c=(n%1000000)/1000,d=n%1000;
		//������0ʱ�����������million��thousand
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
            //��Ӣ���﷨���������λǰһ����and
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
	cout<<endl<<"������"<<name<<' '<<"�Ա�";
	if (sex=='m')
		cout<<"��"<<' ';
	else 
		cout<<"Ů"<<' ';
	cout<<"���֤���룺"<<pid<<' ';
	cout<<"�ʻ�����"<<sum<<endl;	
}
person::~person()               //��������
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
	cryptographist Jack(name_,sex_,PID_,my_,12,3);	//��������ܿ� 
	Jack.showme();                         //����˵�����ֵ
//	Jack.hearing((char *)"Hi! You are simple!");     //��Ӣ�ľ���
//	Jack.speek(1006);                    //˵������num��Ӣ�ľ���
//	Jack.reading((char *)"eleven"); 
    int l;
    cout<<"����������������������";
    cin>>l;
    cin.get();
    cout<<Jack.speek_n(l)<<endl;
    cout<<"���������ģ�"<<endl;
    char mingwen[20];
    cin.get(mingwen,19);
    cin.get();
    cout<<"�����ǣ�"<<Jack.cipher(mingwen)<<endl;
    cout<<"���������ģ�"<<endl;
    char miwen[20];
    cin.get(miwen,19);
    cin.get();
    cout<<"�����ǣ�"<<Jack.decipher(miwen);
	return 0;
}

