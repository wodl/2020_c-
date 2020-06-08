#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

namespace COMP_POS
{
	enum { CLERK, SENIOR, ASSIST, MANAGER };
	void ShowPositionInfo(int n)
	{
		std::cout << "����: ";
		switch (n)
		{
		case 0:
			std::cout << "���"<<std::endl;
			break;
		case 1:
			std::cout << "����"<<std::endl;
			break;
		case 2:
			std::cout << "�븮" << std::endl;
			break;
		case 3:
			std::cout << "����" << std::endl;
			break;
		}
	}
}
class NameCard
{
	char * name, * company, * number;
	int position;
public:
	NameCard(const char * _name, const char * _company, const char * _number, int pos):position(pos)
	{
		name = new char[strlen(_name) + 1];
		company = new char[strlen(_company) + 1];
		number = new char[strlen(_number) + 1];
		strcpy(name, _name);
		strcpy(company, _company);	
		strcpy(number, _number);
	}
	void ShowNameCardInfo()
	{
		std::cout << "�̸�: " << name << std::endl;
		std::cout << "ȸ��: " << company << std::endl;
		std::cout << "��ȭ��ȣ: " << number << std::endl;
		std::cout << "����: ";
		COMP_POS::ShowPositionInfo(position);
	}
	~NameCard()
	{
		delete[]name;
		delete[]company;
		delete[]number;
	}
};

int main()
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Lee", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
	manClerk.ShowNameCardInfo();
	manSENIOR.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();
	return 0;

}