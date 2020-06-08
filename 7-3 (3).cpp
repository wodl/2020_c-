#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo
{
private:
	char * name;
	int age;
public:
	MyFriendInfo(const char * fname, const int fage) :age(fage)
	{
		name = new char[strlen(fname) + 1];
		strcpy(name, fname);
	}
	~MyFriendInfo()
	{
		delete[]name;
	}
	void ShowmyFriendInfo() const
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
};

class MyfriendDetailInfo : public MyFriendInfo
{
private:
	char * addr;
	char * phone;
public: 
	MyfriendDetailInfo(const char* fname, const int fage, const char * faddr, const char * fphone) : MyFriendInfo(fname,fage)
	{
		addr = new char[strlen(faddr) + 1];
		phone = new char[strlen(fphone) + 1];
		strcpy(addr, faddr);
		strcpy(phone, fphone);

	}
	void ShowMyFriendDetailInfo() const
	{
		ShowmyFriendInfo();
		cout << "주소: " << addr << endl;
		cout << "전화: " << phone << endl << endl;
	}
	~MyfriendDetailInfo() 
	{
		delete []addr;
		delete []phone;
	}
};
int main()
{
	MyfriendDetailInfo fren1("이재이", 22, "전주", "010-2818-xxxx");
	fren1.ShowMyFriendDetailInfo();
	return 0;
}