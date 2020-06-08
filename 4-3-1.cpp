#include <iostream>
using namespace std;

class Point
{
	int xpos, ypos;
public:
	Point(int x, int y) :xpos(x), ypos(y) {}
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
	Circle(int x, int y, int r) : center(x, y), radius(r) {} 
	/*Circle(int x, int y) : center(x,y)
	{				
		radius=r;		
	}
	*/
	void ShowCircleInfo() const
	{
		cout << "radius: " << radius << endl;
		center.ShowPointInfo();
	}
};

class Ring
{
	Circle InnerCircle, OutterCircle;
public:
	Ring(int x1, int y1, int r1, int x2, int y2, int r2) : InnerCircle(x1,y1,r1),OutterCircle(x2,y2,r2){}
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
	Ring ring(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}