#include <iostream>
using namespace std;

class FruitSeller
{
	int APPLE_PREICE;
	int numOfApples;
	int myMoney;

public:
	void InitMembers( int price, int num, int money)
	{
		APPLE_PREICE = price;
		numOfApples = num;
		myMoney = money;
	}
	int SaleApples(int money)
	{
		if (money < 0)
		{
			cout << "구매에 실패했습니다." << endl;
			return 0;
		}
		int num = money / APPLE_PREICE;
		numOfApples -= num;
		myMoney += money;
		return num;	
	}
	void ShowalesResult() const
	{
		cout << "남은 사과: " << numOfApples << endl;
		cout << "판매 수익: " << myMoney << endl << endl;
	}
};

class FruitBuyer
{
	int myMoney;
	int numOfApples;

public:
	void initMembers(int money)
	{
		myMoney = money;
		numOfApples = 0;
	}
	void BuyApples(FruitSeller &seller, int money)
	{
		if (money < 0)
		{
			cout << "구매에 실패했습니다." << endl;
			return ;
		}
		numOfApples += seller.SaleApples(money);
		myMoney -= money;
	}
	void ShowBuyResult() const
	{
		cout << "현재 잔액: " << myMoney << endl;
		cout << "사과 개수: " << numOfApples << endl << endl;
	}
};

int main()
{
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.initMembers(5000);
	buyer.BuyApples(seller, 2000);

	cout << "과일 판매자의 현황" << endl;
	seller.ShowalesResult();
	cout << "과일 구매자의 현황" << endl;
	buyer.ShowBuyResult();
	return 0;
}