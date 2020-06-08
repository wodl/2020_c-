#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

const int NAME_LEN = 20;
void ShowMenu();
void MakeAccount();
void DepositMoney();
void WithdrawMoney();
void ShowAccInfo();

enum {MAKE=1,DEPOSIT,WITHDRAW,INQUIRE,EXIT};

class Account
{
	int accID;
	char *cusNAME;
	int balance;
public:
	Account(int ID, int money, char * name) :accID(ID), balance(money)
	{
		cusNAME = new char[strlen(name) + 1];
		strcpy(cusNAME, name);
	}
	Account(const Account &ref) : accID(ref.accID), balance(ref.balance) //���� ���������
	{
		cusNAME = new char[strlen(ref.cusNAME) + 1];
		strcpy(cusNAME, ref.cusNAME);
	}
	int GetAccID() const { return accID; }
	void Deposit(int money)
	{
		balance += money;
	}
	void Withdraw(int money)
	{
		if (balance < money)
			return;
		balance -= money;

	}
	void ShowInfo() const
	{
		std::cout << "����ID: " << accID << std::endl;
		std::cout << "�� ��: " << cusNAME << std::endl;
		std::cout << "�ܾ�: " << balance << std::endl;
	}
	~Account()
	{
		delete[]cusNAME;
	}
};

Account *accArr[100];
int accNum = 0;

int main()
{
	int choice;
	while (true)
	{
		ShowMenu();
		std::cin >> choice;

		switch (choice)
		{
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INQUIRE:
			ShowAccInfo();
			break;
		case EXIT:
			for (int i = 0; i < accNum; i++)
			{
				delete accArr[i];
			}
			return 0;
		default:
			std::cout << "illegal selection."; //�޴����� �߸�
		}
	}
}


void ShowMenu()
{
	std::cout << "-----Menu-----" << std::endl;
	std::cout << "1. ���°���" << std::endl;
	std::cout << "2. �� ��" << std::endl;
	std::cout << "3. �� ��" << std::endl;
	std::cout << "4. �������� ��ü ���" << std::endl;
	std::cout << "5. ���α׷� ����" << std::endl;
	std::cout << "����: ";
}

void MakeAccount()
{
	int id;
	int cash;
	char name[NAME_LEN];
	std::cout << "[���°���]" << std::endl;
	std::cout << "����ID: "; std::cin >> id;
	std::cout << "�� ��: "; 	std::cin >> name;
	std::cout << "�Աݾ�: "; std::cin >> cash;
	accArr[accNum++] = new Account(id, cash, name);
}

void DepositMoney()
{
	int id, money;
	std::cout << "[��  ��]" << std::endl;
	std::cout << "����ID: "; std::cin >> id;
	std::cout << "�Աݾ�: "; std::cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);
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
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Withdraw(money);
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
		accArr[i]->ShowInfo();
	}
}