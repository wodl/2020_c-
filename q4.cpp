#include <iostream>

int main()
{
	//while(int i=0)  =>  ��������                 while(���ǹ�)  =   (����)�� true�϶� �ݺ�
	while (1)
	{
		int i;
		std::cout << "�Ǹ� �ݾ��� ���� ������ �Է�(-1 to end): ";
		std::cin >> i;
		if (i == -1) break;
		else
			std::cout << "�̹� �� �޿�: " << 50 + i * 0.12 << "����" << std::endl;
	}
	std::cout << "���α׷��� �����մϴ�.";
	
	return 0;
}