#include <iostream>

template <typename T>
int SumArray(T arr[], int len)
{
	T sum=0;
	for (int i = 0; i < len; i++)
		sum += arr[i];
	return sum;
}

int main()
{
	int arr1[] = { 10,20,30 };
	std::cout << SumArray(arr1, sizeof(arr1) / sizeof(int)) << std::endl;
	return 0;
}
