#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream in("e:\\demo.cpp");
	if (!in)
	{
		cout << "无法打开demo.cpp文件" << endl;
		return 1;
	}
	char len[999];
	in.getline(len, 999);
	int i = 1;
	ofstream out("e:\\demo1.prn");
	if (!out)
	{
		cout << "无法创建demo1.prn文件" << endl;
	}
	while(in)
	{
		out << i++ << ". " << len << endl;
		in.getline(len, 999);
	} 
	return 0;
}	