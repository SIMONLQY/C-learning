#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream in("e:\\demo.cpp");
	if (!in)
	{
		cout << "�޷���demo.cpp�ļ�" << endl;
		return 1;
	}
	char len[999];
	in.getline(len, 999);
	int i = 1;
	ofstream out("e:\\demo1.prn");
	if (!out)
	{
		cout << "�޷�����demo1.prn�ļ�" << endl;
	}
	while(in)
	{
		out << i++ << ". " << len << endl;
		in.getline(len, 999);
	} 
	return 0;
}	