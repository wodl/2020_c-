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
int accNum = 0; //저장된 계좌수

int ChooseMenu()
{
	int menu;
	std::cout << "-----Menu-----" << std::endl;
	std::cout << "1. 계좌개설" << std::endl;
	std::cout << "2. 입 금" << std::endl;
	std::cout << "3. 출 금" << std::endl;
	std::cout << "4. 계좌정보 전체 출력" << std::endl;
	std::cout << "5. 프로그램 종료" << std::endl;
	std::cout << "선택: ";
	std::cin >> menu;

	return menu;
}

void MakeAccount()
{
	int id;
	int cash;
	char name[NAME_LEN];

	std::cout << "[개좌개설]" << std::endl;
	std::cout << "계좌ID: " ; std::cin >> id;
	std::cout << "이 름: "; 	std::cin >> name;
	std::cout << "입금액: "; std::cin >> cash;

	accArr[accNum].accID = id;
	accArr[accNum].balance = cash;
//	accArr[accNum].cusNAME =name;  X =>문자열이므로 strcpy사용
	strcpy(accArr[accNum].cusNAME, name);
	accNum++;
}

void DepositMoney()
{
	int id, money;
	std::cout << "[입  금]" << std::endl;
	std::cout << "계좌ID: "; std::cin >> id;
	std::cout << "입금액: "; std::cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			accArr[i].balance += money;
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
		if (accArr[i].accID == id)
		{
			accArr[i].balance -= money;
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
		std::cout << "계좌ID: " << accArr[i].accID << std::endl;
		std::cout << "이 름: " << accArr[i].cusNAME << std::endl;
		std::cout << "잔액: " << accArr[i].balance << std::endl;
	}
}*/