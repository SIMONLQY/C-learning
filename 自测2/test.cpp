#include<iostream>
#include<ctime>
using namespace std;
int main(){
	tm*a; // �ṹ��tmָ�� 
	time_t t=time(NULL); //��ȡʱ�� 
	a=localtime(&t); //��ʱ��ͽṹ���� 
	//�ӽṹ���л�������գ�ע���º��յĵõ������� 
	int year=a->tm_year+1900; 
	int month=a->tm_mon+1;
	int day=a->tm_mday;
	cout<<year<<":"<<month<<":"<<day;
} 
