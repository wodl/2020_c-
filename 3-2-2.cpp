#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Printer
{
	char str[100];
public:
	void SetString(const char * s);
	void ShowString();
};

void Printer::SetString(const char * s)
{
	strcpy(str, s);
}
void Printer::ShowString()
{
	cout << str << endl;
}


int main()
{
	Printer pnt;
	pnt.SetString("Hello world!");
	pnt.ShowString();

	pnt.SetString("I love C++");
	pnt.ShowString();
	return 0;
}