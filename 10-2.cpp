#include <iostream>
using namespace std;

class Point
{
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x),ypos(y) {}
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	friend Point& operator-(Point &);
	friend Point& operator~(Point &);
};

Point& operator~(Point &ref)
{
	int temp = ref.xpos;
	ref.xpos = ref.ypos;
	ref.ypos = temp;
	return ref;
}
Point& operator-(Point &ref)
{
	ref.xpos *= (-1);
	ref.ypos *= (-1);
	return ref;
}

int main()
{
	Point pos1(1, 2);
	Point pos2 = -pos1;
	pos2.ShowPosition();
	(~pos2).ShowPosition();
	return 0;
}