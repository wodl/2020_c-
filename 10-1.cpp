#include <iostream>
using namespace std;

class Point
{
	int xpos, ypos;
public:
	Point(int x=0,int y=0) : xpos(x),ypos(y) {}
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	Point& operator+=(const Point &ref)
	{
		xpos += ref.xpos;
		ypos += ref.ypos;
		return *this;
	}
	Point& operator-=(const Point &ref)
	{
		xpos -= ref.xpos;
		ypos -= ref.ypos;
		return *this;
	}
	friend Point operator+(const Point &, const Point &);
	friend Point operator-(const Point &, const Point &);
	friend bool operator==(const Point &, const Point &);
	friend bool operator!=(const Point &, const Point &);
};

Point operator+(const Point &pos1, const Point &pos2)	//��������� ȣ�� 
{
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos;
}

Point operator-(const Point &pos1, const Point &pos2)	//��������� ȣ�� 
{
	Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
	return pos;
}

bool operator==(const Point &pos1, const Point &pos2)
{
	if (pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos)
		return true;
	return false;
}

bool operator!=(const Point &pos1, const Point &pos2)
{
	return !(pos1 == pos2);
}
int main()
{
	Point pos1(20, 30);
	Point pos2(10, 20);
	Point pos3 = pos2;
	(pos1 - pos2).ShowPosition();	//10,10
	(pos2 += pos1).ShowPosition();	//30,50=pos2

	if (pos2 == pos3)
		cout << "equal" << endl;	//not equal
	else
		cout << "not equal" << endl;

	(pos2 -= pos3).ShowPosition();	//20,30

	if (pos2 != pos1)
		cout << "not equal" << endl;
	else
		cout << "equal" << endl;	//equl

	return 0;
}