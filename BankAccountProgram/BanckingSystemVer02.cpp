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
	Account(const Account &ref) : accID(ref.accID), balance(ref.balance) //깊은 복사생성자
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
		std::cout << "계좌ID: " << accID << std::endl;
		std::cout << "이 름: " << cusNAME << std::endl;
		std::cout << "잔액: " << balance << std::endl;
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
			std::cout << "illegal selection."; //메뉴선택 잘못
		}
	}
}


void ShowMenu()
{
	std::cout << "-----Menu-----" << std::endl;
	std::cout << "1. 계좌개설" << std::endl;
	std::cout << "2. 입 금" << std::endl;
	std::cout << "3. 출 금" << std::endl;
	std::cout << "4. 계좌정보 전체 출력" << std::endl;
	std::cout << "5. 프로그램 종료" << std::endl;
	std::cout << "선택: ";
}

void MakeAccount()
{
	int id;
	int cash;
	char name[NAME_LEN];
	std::cout << "[개좌개설]" << std::endl;
	std::cout << "계좌ID: "; std::cin >> id;
	std::cout << "이 름: "; 	std::cin >> name;
	std::cout << "입금액: "; std::cin >> cash;
	accArr[accNum++] = new Account(id, cash, name);
}

void DepositMoney()
{
	int id, money;
	std::cout << "[입  금]" << std::endl;
	std::cout << "계좌ID: "; std::cin >> id;
	std::cout << "입금액: "; std::cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);
			std::cout << "입금완료" << std::endl;
			return;
		}
	}
	std::cout << "유효하지않은 id입니다." << std::endl;
}
void WithdrawMoney()
{
	int id, money;
	std::cout << "[출  금]" << std::endl;
	std::cout << "계좌ID: "; std::cin >> id;
	std::cout << "출금액: "; std::cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Withdraw(money);
			std::cout << "출금완료" << std::endl;
			return;
		}
	}
	std::cout << "유효하지않은 id입니다." << std::endl;
}
void ShowAccInfo()
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowInfo();
	}
}