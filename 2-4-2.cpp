#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	int iCount;
	srand(time(NULL)); 
	for (iCount = 0; iCount < 5; iCount++)
		cout << "Random number" << rand() % 100 << endl;
	return 0;


}