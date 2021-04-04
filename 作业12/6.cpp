#include<iostream>
#include<cmath>
using namespace std;
class Fraction
{
private:
	int a;//����
	int b;//��ĸ
	int divisor(int p,int q);//�����Լ��
public:
	double l; //����ֵ 
	Fraction(){ a=0;b=1; }	//�޲ι��캯�� 
	Fraction(int,int);		//�вι��캯�� 
	void set(int aa,int bb);//���÷��ӷ�ĸ
	void show();//��ʾ����
	Fraction add(Fraction b);//��һ������
	Fraction operator+(Fraction u);	//�����+����
	bool operator==(Fraction u);	//�����==����
	Fraction operator-();			//�����������
	~Fraction(){ };		//�������� 
};
//�в������캯��
Fraction::Fraction(int x,int y)
{
	set(x,y);
} 
//���÷��ӡ���ĸ
void Fraction:: set(int aa,int bb)
{
	a=aa;
	if (bb!=0) b=bb; else { a=0;	b=1;}  //��ĸ��Ч�Լ���
	l=(double)a/(double)b;
}
//��ʾ����
void Fraction::show()
{
	cout<<a<<"/"<<b;
}
//������ӣ���������u
Fraction Fraction::add(Fraction u)
{
	int tmp;
	Fraction v;

	v.a=a*u.b+b*u.a;   //��ĸ
	v.b=b*u.b;//����
	tmp=divisor(v.a ,v.b);//������ӡ���ĸ�Ĺ�Լ��
	v.a=v.a/tmp;//Լȥ��Լ��
	v.b=v.b/tmp;//Լȥ��Լ��
	return v;	//���ؽ��
}
//�����+����
Fraction Fraction::operator+(Fraction u)	//�����+����
{
	int tmp;
	Fraction v;

	v.a=a*u.b+b*u.a;   //��ĸ
	v.b=b*u.b;//����
	tmp=divisor(v.a ,v.b);//������ӡ���ĸ�Ĺ�Լ��
	v.a=v.a/tmp;//Լȥ��Լ��
	v.b=v.b/tmp;//Լȥ��Լ��
	return v;	//���ؽ��
}
//�����==����
bool Fraction::operator==(Fraction u)	//�����==����
{
	float x,y;
	x=(float)a/b;
	y=(float)u.a/u.b;
	if(x==y)
		return true;
	else
		return false;
}
//�����������
Fraction Fraction::operator-()			//�����������
{
	a=a*(-1);
	return *this;
}
//���㹫Լ����˽�г�Ա
int Fraction::divisor(int p,int q)
{
	int r;
	if(p<q)
	{
		int tmp;
		tmp=p;
		p=q;
		q=tmp;
	}
	r=p%q;
	while(r!=0)
	{
		p=q;
		q=r;
		r=p%q;
	}
	return q;
}
class xushu{
	private:
		double shibu;
		double xubu;
	public:
		xushu(double a=0,double b=0){
			shibu=a;
			xubu=b;
		}
		~xushu(){}
		void out(){
			cout<<shibu<<"+"<<xubu<<"*i"<<endl;
		}
		xushu operator +(xushu a){
			xushu temp;
			temp.shibu=shibu+a.shibu;
			temp.xubu=xubu+a.xubu;
			return temp;
		}
		xushu operator +(Fraction a){
			xushu temp;
			temp.shibu=shibu+a.l;
			temp.xubu=xubu;
			return temp;
		}
		xushu operator *(xushu a){
			xushu temp;
			temp.shibu=shibu*a.shibu-xubu*a.xubu;
			temp.xubu=xubu*a.shibu+shibu*a.xubu;
			return temp;
		}
		xushu operator /(xushu a){
			if(a.shibu==0||a.xubu==0){
				cout<<"��ĸ����Ϊ��"<<endl;
			}else{
				xushu temp;
				temp.shibu=(shibu*a.shibu+xubu*a.xubu)/(a.shibu*a.shibu+a.xubu*a.xubu);
				temp.xubu=(xubu*a.shibu-shibu*a.xubu)/(a.shibu*a.shibu+a.xubu*a.xubu);
				return temp;
			}
		}
		bool operator ==(xushu a){
			if(shibu==a.shibu&&xubu==a.xubu){
				return true;
			}else{
				return false;
			}
		}
		xushu operator ++(){
			shibu++;
			return *this;
		}
		xushu operator ++(int){
			shibu++;
			return *this;
		}
		xushu operator --(){
			shibu--;
			return *this;
		}
		xushu operator --(int){
			shibu--;
			return *this;
		}
};
int main(){
	xushu a(12.3,20);
	cout<<"��һ������Ϊ";
	a.out();
	xushu b(10.7,20);
	cout<<"�ڶ�������Ϊ";
	b.out();
	xushu c;
	c=a+b;
	cout<<"������ӽ��Ϊ";
	c.out();
	cout<<"����Լ�1Ϊ";
	(++c).out();
	cout<<"���Լ�1Ϊ";
	(--c).out();
	xushu d=a*b;
	cout<<"��һ���������Եڶ����������Ϊ";
	d.out();
	cout<<"����ٳ��Եڶ����������Ϊ";
	(d/b).out();
	Fraction f(1,2);
	cout<<"��һ���������Ϸ���1/2���Ϊ";
	(a+f).out();
}
