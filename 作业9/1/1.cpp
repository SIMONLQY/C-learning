#include<iostream>
#include<windows.h>
using namespace std;
class autocar
{
private:
	char type[20]; 		//�����ͺ�
	char shape[20];		//������״
	int v;			//ָ��1000/v���ٶ���һ��
	int  meleage;		//�����
	char way;			//Aˮƽ�˶���B������C��ֱ�½���Dб���½����ո�յ�
	char sl[10][40];		//10�׸�������	
	float price;		//�۸�
	int oil;			//������
	int  outdate;		//��������
	int carry_customer; 		//�ؿ���
	void movecar(int l,int k);			//ˮƽ�����˶�L��
	void downcar(int l,int k);			//��ֱ�½��˶�
	void invcar(int l,int k);			//ˮƽ��������L��
	void down45car(int l,int k);			//б����������
public:
	void set_datas(char *, char *, char *gq[], float, int, int, int, char, int, int);	//��ʼ�����ݳ�Ա
	void play_mp3(int p);			//���Ÿ���
	void show_info();				//��ʾ�γ���Ϣ
	void car_run();					//�γ����� 
};
void autocar::set_datas(char *ty, char *sh, char *gq[], float pr=0.0, int od=0, int vv=1, int ml=0, char ww=' ', int oo=0, int cc=3)	
{//��ʼ�����ݳ�Ա
	strcpy(type,ty);
	strcpy(shape,sh);
	for(int i=0;i<10;i++) strcpy(sl[i],gq[i]);
	v=vv;
	meleage=ml;
	way=ww;
	price=pr;
	oil=oo;
	outdate=od;
	carry_customer=cc;
}
void autocar::show_info()	
{//��ʾ�γ���Ϣ
	cout<<endl<<"�γ��ͺţ�"<<type<<endl;
	cout<<"�γ���״��"<<shape<<endl;
	cout<<"����̣�"<<meleage<<"����"<<endl;
	cout<<"��������"<<oil<<"��"<<endl;
	cout<<"�γ��۸�"<<price<<"Ԫ"<<endl;
	cout<<"�������ڣ�"<<outdate/10000<<"��"<<(outdate%10000)/100<<"��"<<outdate%100<<"��"<<endl;
	cout<<"�ؿ�����"<<carry_customer<<endl;
	cout<<"�����б�"<<endl;
	for(int i=0;i<10;i++) cout<<sl[i]<<endl;
}
void autocar::play_mp3(int p)
{
	int i,j;
	do
	{	
		for(i=0;i<10;i++)
			cout<<i<<"\t"<<sl[i]<<endl;
		cout<<i<<"\t"<<"�˳�����"<<endl;	
		cout<<"�����������������֣�";
		cin>>j; 
	} while(j<0||j>10);
	if (j==10)	return;
	char str[100]="play ";		//play���пո�
	strcat(str,sl[j]);
	char c[]=" repeat";
	cout<<str;
	strcat(str,c);
	mciSendString(str,NULL,0,NULL);
	//��Dec-C++�����л�Ҫ�������ã�
	//����\������ѡ��\������\�����������������������\-lwinmm 
	//mciSendStringA(str,NULL,0,NULL);	//��VC2008���ô˺���
	//mciSendString(str,NULL,0,NULL);	//��VC6.0���ô˺���
	if(p==1){ // �������ֱ��˶� 
		car_run();
	}
	cout<<endl<<"�����κ��ַ��������ţ�";
	char a;
	cin>>a;
	str[0]='s';
    str[1]='t';
    str[2]='o';
    str[3]='p';
    mciSendString(str,NULL,0,NULL);
}
void autocar::car_run() 
{
	int dl;
	do
    {

	  	cout<<"\n�����˶���ʽ(A-����,B-��ֱ����,C-����,D-б������,E-ͣ��)��";
	  	cin>>way;
	  	if (way>='A' && way<='D')
	  	{
		  	cout<<"\n�����ٶ�(1,2,3,4,5)��";
		  	cin>>v;
		  	cout<<"�����˶���̣�";
		  	cin>>dl;
	  		if(way=='A') movecar(dl,v);
			if(way=='B') downcar(dl,v);
			if(way=='C') invcar(dl,v);
			if(way=='D') down45car(dl,v);		
		}
    }while(way!='E');
}
void autocar::movecar( int l, int k )
{	//ˮƽ��������
	int i, j, b;
	char del_car[80];
	for (i = 0; i<strlen(shape); i++) del_car[i] = '\b';
	del_car[i] = '\0';
	cout<<type<<"��������"<<meleage<<endl;
	cout << "ˮƽ��������" << l << "��" << endl;
	for (i = 0; i < l; i++)
	{
		cout << ' ' << shape;
		Sleep(1000 / k);
		cout << del_car;
	}
	meleage+=l;
	cout<<endl<<type<<"��������"<<meleage<<endl;
}
void autocar::downcar(int l, int k)
{	//��ֱ�½��˶�
	int i, j, b;	
	char del_car[80];
	for (i = 0; i<strlen(shape); i++) del_car[i] = '\b';
	del_car[i] = '\0';
	cout<<type<<"��������"<<meleage<<endl;
	cout << "��ֱ���½���" << l << "��" << endl;
	for (i = 0; i < l; i++)
	{
		cout << shape;
		Sleep(1000 / k);
		cout << del_car;
		for (j = 0; j < strlen(shape); j++) cout << ' ';
		cout << endl;
	}
	meleage+=l;
	cout<<endl<<type<<"��������"<<meleage<<endl;
}
void autocar::invcar(int l, int k){
	int i,j,b; // ���� 
	char del_car[80];
	for(int i=0;i<strlen(shape);i++)del_car[i]='\b';
	del_car[i]='\0';
	cout<<type<<"��������"<<meleage<<endl;
	cout<<"����"<<l<<"��"<<endl;
	for(i=0;i<l;i++)cout<<" ";
	for(i=0;i<l;i++){
		cout<<shape;
		Sleep(1000.0/k);
		cout<<del_car;
		for(j=0;j<strlen(shape);j++)cout<<' ';
		cout<<del_car<<'\b';
	}
	meleage+=l;
	cout<<endl<<type<<"��������"<<meleage<<endl;
}
void autocar::down45car(int l,int k){
	int i,j,b=0; // б���½� 
	char del_car[80];
	for(i=0;i<strlen(shape);i++)del_car[i]='\b';
	del_car[i]='\0';
	cout<<type<<"��������"<<meleage<<endl;
	cout<<"б���½�"<<l<<"��"<<endl;
	for(i=0;i<l;i++){
		cout<<shape;
		Sleep(1000/k);
		cout<<del_car;
		for(j=0;j<strlen(shape);j++)cout<<" ";
		cout<<endl;
		b++;
		for(int u=0;u<b;u++)cout<<' ';
	}
	meleage+=l;
	cout<<endl<<type<<"��������"<<meleage<<endl;
}
int main()
{
	char *gqlb[10]={"11111","22222","33333","c:\\work.mp3","55555","66666","77777","88888","99999","1010101010"};
	autocar nison;
	nison.set_datas("gugang","O_O_O_O_O_O_O_O",gqlb,200000.0,20190630); //�������ó�ʼ���ݺ���
    nison.show_info();
    cout<<"��������С��(A:�����֣�B:�˶� C:�������ֱ��˶�)";
    char a;
    cin>>a;
    if(a=='A'){
    	nison.play_mp3(0);
	}else if(a=='B'){
		nison.car_run();
	}else{
		nison.play_mp3(1);
	}
	
	return 0;
}

