/*#include "function.h"
#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

const int NAME_LEN = 20;

typedef struct
{
	int accID;
	char cusNAME[NAME_LEN];
	int balance;
} Account;

Account accArr[100];
int accNum = 0; //����� ���¼�

int ChooseMenu()
{
	int menu;
	std::cout << "-----Menu-----" << std::endl;
	std::cout << "1. ���°���" << std::endl;
	std::cout << "2. �� ��" << std::endl;
	std::cout << "3. �� ��" << std::endl;
	std::cout << "4. �������� ��ü ���" << std::endl;
	std::cout << "5. ���α׷� ����" << std::endl;
	std::cout << "����: ";
	std::cin >> menu;

	return menu;
}

void MakeAccount()
{
	int id;
	int cash;
	char name[NAME_LEN];

	std::cout << "[���°���]" << std::endl;
	std::cout << "����ID: " ; std::cin >> id;
	std::cout << "�� ��: "; 	std::cin >> name;
	std::cout << "�Աݾ�: "; std::cin >> cash;

	accArr[accNum].accID = id;
	accArr[accNum].balance = cash;
//	accArr[accNum].cusNAME =name;  X =>���ڿ��̹Ƿ� strcpy���
	strcpy(accArr[accNum].cusNAME, name);
	accNum++;
}

void DepositMoney()
{
	int id, money;
	std::cout << "[��  ��]" << std::endl;
	std::cout << "����ID: "; std::cin >> id;
	std::cout << "�Աݾ�: "; std::cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			accArr[i].balance += money;
			std::cout << "�ԱݿϷ�" << std::endl;
			return;
		}
	}
	std::cout << "��ȿ�������� id�Դϴ�." << std::endl;
}

void WithdrawMoney()
{
	int id, money;
	std::cout << "[��  ��]" << std::endl;
	std::cout << "����ID: "; std::cin >> id;
	std::cout << "��ݾ�: "; std::cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			accArr[i].balance -= money;
			std::cout << "��ݿϷ�" << std::endl;
			return;
		}
	}
	std::cout << "��ȿ�������� id�Դϴ�." << std::endl;
}

void ShowAccInfo()
{
	for (int i = 0; i < accNum; i++)
	{
		std::cout << "����ID: " << accArr[i].accID << std::endl;
		std::cout << "�� ��: " << accArr[i].cusNAME << std::endl;
		std::cout << "�ܾ�: " << accArr[i].balance << std::endl;
	}
}*/