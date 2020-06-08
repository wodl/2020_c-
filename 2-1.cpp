#include <iostream>

void plusOne(int &ref)
{
	ref++;
}

void SwapRef(int &ref)
{
	ref *= (-1);
}

int main()
{
	int n = 20;
	plusOne(n);
	SwapRef(n);
	std::cout << n;
	return 0;
}