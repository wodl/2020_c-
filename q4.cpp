#include <iostream>

int main()
{
	//while(int i=0)  =>  강제종료                 while(조건문)  =   (조건)이 true일때 반복
	while (1)
	{
		int i;
		std::cout << "판매 금액을 만원 단위로 입력(-1 to end): ";
		std::cin >> i;
		if (i == -1) break;
		else
			std::cout << "이번 달 급여: " << 50 + i * 0.12 << "만원" << std::endl;
	}
	std::cout << "프로그램을 종료합니다.";
	
	return 0;
}