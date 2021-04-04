#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
//��������ȫ���ַ�ָ�����飬��ȡ����ĵ���
//num1��Ϊ1��19���ճ���0�����Կ���ֱ����num1 [n]���ã��õ�n��Ӧ����
static char *num1[]=
{
       "","one ","two ","three ","four ","five ","six ","seven ","eight ","nine ","ten ","eleven ","twelve ",
       "thirteen ","fourteen ","fifteen ","sixteen ","seventeen ","eighteen ","nineteen "
};
//num10��Ϊ20-90���ճ���0��1�����Կ���ֱ����num10[n/10]���ã��õ�n��Ӧ����
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
			s[0]="��";
			s[1]="��";
			s[2]="��";
			s[3]="��";
			s[4]="˧";
		}
		robot(char *name,int age,int num){
			strcpy(this->name,name);
			this->age=age;
			this->num=num;
			s[0]="��";
			s[1]="��";
			s[2]="��";
			s[3]="��";
			s[4]="˧";
		}
		void write(char *a); // д���ֺ���
		void judge(); // �ж��������ĺ��� 
		void out(int a);//Ӣ����ÿ��λ��������ͬ�����Զ���out��������С��1000������ 
		void tran_int();//��1��1999999999�����������Ӣ�ľ��� 
		void info();
		~robot(){};//�������� 
};
void robot::info(){
	cout<<"��ã�������Ļ�����"<<name<<",";
	cout<<"�ҽ���"<<age<<"����"<<endl;
	cout<<"��ղ����������";
	judge();
	tran_int();
	cout<<"��������������д�ĺ��֣�"<<endl;
	char a[10];
	cin>>a;
	write(a);
}
int robot::jiou(){
	if(num%2==0){ // �ж���ż 
		return 0;
	}else{
		return 1;
	}
}
int robot::ss(){
	int a=num;
	bool ss=true; // �ж����� 
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
int robot::dizeng(){ // �жϵ����� 
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
int robot::huiwen(){ // �жϻ�����
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
	cout<<num<<"��һ��";
	if(jiou()==1){
		cout<<"����";
	}else{
		cout<<"ż��"; 
	}
	if(ss()==1){
		cout<<",����";
	}
	if(dizeng()==1){
		cout<<",������"; 
	}
	if(huiwen()==1){
		cout<<",������";
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
		cout<<"��Ǹ������ʱд�����������"<<endl;
	}
}
void robot::out(int a)
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
void robot::tran_int()
{
	int n=num;
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
int main()
{
	int n;
	cout<<"������n��";
	cin>>n;
	robot Simon("Simon",10,n);
	Simon.info();
    return 0;
}


