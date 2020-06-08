#include <iostream>
using namespace std;

class Point
{
	int xpos, ypos;
public:
	void Init(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	void ShowPointInfo() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

class Circle
{
	Point center;
	int radius;
public:
	void Init(int x, int y, int r)
	{
		center.Init(x, y);
		radius = r;
	}
	void ShowCircleInfo() const
	{
		cout << "radius: "<<radius << endl;
		center.ShowPointInfo();
	}
};

class Ring
{
	Circle InnerCircle, OutterCircle;
public:
	void Init(int x1, int y1, int r1, int x2, int y2, int r2)	//inX,inY,inR	outX,outY,outR
	{
		InnerCircle.Init(x1, y1, r1);
		OutterCircle.Init(x2, y2, r2);
	}
	void ShowRingInfo()
	{
		cout << "Inner CIrcle Info..." << endl;
		InnerCircle.ShowCircleInfo();
		cout << "Outter Circle Info..." << endl;
		OutterCircle.ShowCircleInfo();
	}
};


int main()
{
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}