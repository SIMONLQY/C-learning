#include<iostream>
#include<windows.h>
using namespace std;
class autocar
{
private:
	char type[20]; 		//汽车型号
	char shape[20];		//汽车形状
	int v;			//指以1000/v秒速度走一步
	int  meleage;		//总里程
	char way;			//A水平运动、B倒车、C垂直下降、D斜线下降、空格空挡
	char sl[10][40];		//10首歌曲名称	
	float price;		//价格
	int oil;			//耗油量
	int  outdate;		//出厂日期
	int carry_customer; 		//载客量
	void movecar(int l,int k);			//水平向右运动L步
	void downcar(int l,int k);			//垂直下降运动
	void invcar(int l,int k);			//水平向左行走L步
	void down45car(int l,int k);			//斜线向下行走
public:
	void set_datas(char *, char *, char *gq[], float, int, int, int, char, int, int);	//初始化数据成员
	void play_mp3(int p);			//播放歌曲
	void show_info();				//显示轿车信息
	void car_run();					//轿车运行 
};
void autocar::set_datas(char *ty, char *sh, char *gq[], float pr=0.0, int od=0, int vv=1, int ml=0, char ww=' ', int oo=0, int cc=3)	
{//初始化数据成员
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
{//显示轿车信息
	cout<<endl<<"轿车型号："<<type<<endl;
	cout<<"轿车形状："<<shape<<endl;
	cout<<"总里程："<<meleage<<"公里"<<endl;
	cout<<"耗油量："<<oil<<"升"<<endl;
	cout<<"轿车价格："<<price<<"元"<<endl;
	cout<<"出厂日期："<<outdate/10000<<"年"<<(outdate%10000)/100<<"月"<<outdate%100<<"日"<<endl;
	cout<<"载客量："<<carry_customer<<endl;
	cout<<"歌曲列表："<<endl;
	for(int i=0;i<10;i++) cout<<sl[i]<<endl;
}
void autocar::play_mp3(int p)
{
	int i,j;
	do
	{	
		for(i=0;i<10;i++)
			cout<<i<<"\t"<<sl[i]<<endl;
		cout<<i<<"\t"<<"退出播放"<<endl;	
		cout<<"输入歌曲名单左边数字：";
		cin>>j; 
	} while(j<0||j>10);
	if (j==10)	return;
	char str[100]="play ";		//play后有空格
	strcat(str,sl[j]);
	char c[]=" repeat";
	cout<<str;
	strcat(str,c);
	mciSendString(str,NULL,0,NULL);
	//在Dec-C++环境中还要进行设置：
	//工具\编译器选项\编译器\在连接器命令加入以下命令\-lwinmm 
	//mciSendStringA(str,NULL,0,NULL);	//在VC2008调用此函数
	//mciSendString(str,NULL,0,NULL);	//在VC6.0调用此函数
	if(p==1){ // 边听音乐边运动 
		car_run();
	}
	cout<<endl<<"输入任何字符结束播放：";
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

	  	cout<<"\n输入运动方式(A-向右,B-垂直向下,C-倒车,D-斜线向下,E-停车)：";
	  	cin>>way;
	  	if (way>='A' && way<='D')
	  	{
		  	cout<<"\n输入速度(1,2,3,4,5)：";
		  	cin>>v;
		  	cout<<"输入运动里程：";
		  	cin>>dl;
	  		if(way=='A') movecar(dl,v);
			if(way=='B') downcar(dl,v);
			if(way=='C') invcar(dl,v);
			if(way=='D') down45car(dl,v);		
		}
    }while(way!='E');
}
void autocar::movecar( int l, int k )
{	//水平向右行走
	int i, j, b;
	char del_car[80];
	for (i = 0; i<strlen(shape); i++) del_car[i] = '\b';
	del_car[i] = '\0';
	cout<<type<<"总里数："<<meleage<<endl;
	cout << "水平向右行走" << l << "步" << endl;
	for (i = 0; i < l; i++)
	{
		cout << ' ' << shape;
		Sleep(1000 / k);
		cout << del_car;
	}
	meleage+=l;
	cout<<endl<<type<<"总里数："<<meleage<<endl;
}
void autocar::downcar(int l, int k)
{	//垂直下降运动
	int i, j, b;	
	char del_car[80];
	for (i = 0; i<strlen(shape); i++) del_car[i] = '\b';
	del_car[i] = '\0';
	cout<<type<<"总里数："<<meleage<<endl;
	cout << "垂直向下降落" << l << "步" << endl;
	for (i = 0; i < l; i++)
	{
		cout << shape;
		Sleep(1000 / k);
		cout << del_car;
		for (j = 0; j < strlen(shape); j++) cout << ' ';
		cout << endl;
	}
	meleage+=l;
	cout<<endl<<type<<"总里数："<<meleage<<endl;
}
void autocar::invcar(int l, int k){
	int i,j,b; // 倒车 
	char del_car[80];
	for(int i=0;i<strlen(shape);i++)del_car[i]='\b';
	del_car[i]='\0';
	cout<<type<<"总里数："<<meleage<<endl;
	cout<<"倒车"<<l<<"步"<<endl;
	for(i=0;i<l;i++)cout<<" ";
	for(i=0;i<l;i++){
		cout<<shape;
		Sleep(1000.0/k);
		cout<<del_car;
		for(j=0;j<strlen(shape);j++)cout<<' ';
		cout<<del_car<<'\b';
	}
	meleage+=l;
	cout<<endl<<type<<"总里数："<<meleage<<endl;
}
void autocar::down45car(int l,int k){
	int i,j,b=0; // 斜线下降 
	char del_car[80];
	for(i=0;i<strlen(shape);i++)del_car[i]='\b';
	del_car[i]='\0';
	cout<<type<<"总里数："<<meleage<<endl;
	cout<<"斜线下降"<<l<<"步"<<endl;
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
	cout<<endl<<type<<"总里数："<<meleage<<endl;
}
int main()
{
	char *gqlb[10]={"11111","22222","33333","c:\\work.mp3","55555","66666","77777","88888","99999","1010101010"};
	autocar nison;
	nison.set_datas("gugang","O_O_O_O_O_O_O_O",gqlb,200000.0,20190630); //测试设置初始数据函数
    nison.show_info();
    cout<<"您想先让小车(A:放音乐；B:运动 C:边听音乐边运动)";
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

