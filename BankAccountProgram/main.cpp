#include <iostream>
#include "function.h"

int main()
{
	while (1)
	{
		int menu = ChooseMenu();
		switch (menu)
		{
		case 1:
			MakeAccount();
			break;
		case 2:
			DepositMoney();
			break;
		case 3:
			WithdrawMoney();
			break;
		case 4:
			ShowAccInfo();
			break;
		case 5:
			return 0;
		default:
			std::cout << "�߸��� �����Դϴ�." << std::endl;
		}

	}

	return 0;
}