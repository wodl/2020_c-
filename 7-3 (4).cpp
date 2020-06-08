#include <iostream>
using namespace std;

class Rectangle
{
	int x, y;
public:
	Rectangle(int x,int y):x(x),y(y) { }
	void ShowAreaInfo()
	{
		cout << "¸éÀû: " << x * y << endl;
	}
};

class Square :public Rectangle
{
public:
	Square(int d) :Rectangle(d, d){}
};

int main()
{
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();
	return 0;
}