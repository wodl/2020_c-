#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;


int main()
{
	const char * str1 = "every day is like a battle.";
	const char * str2 = "But every night with us is like a dream.";
	char str3[68];
	
	cout << strlen(str1)<<endl;
	cout << strlen(str2)<<endl;
	strcpy(str3, str1);
	strcat(str3, str2);
	cout << str3 << endl;

	if ((strcmp(str1, str2)) == 0)
		cout << "두문장은 같다"<<endl;
	else
		cout << "같지않다."<<endl;

	return 0;
}