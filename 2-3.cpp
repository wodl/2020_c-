#include <iostream>

typedef struct __Point
{
	int xpos;
	int ypos;
} Point;

Point& pntAdder(const Point &p1, const Point &p2)
{
	Point * p = new Point;
	p->xpos = p1.xpos + p2.ypos;
	p->ypos = p1.ypos + p2.ypos;
	return *p;
}

int main()
{
	Point * p1 = new Point;
	Point * p2 = new Point;
	p1->xpos = 10;
	p1->ypos = 10;
	p2->xpos = 20;
	p2->ypos = 20;

	Point &pref=pntAdder(*p1, *p2);

	std::cout << pref.xpos << " " << pref.ypos;
	delete p1;
	delete p2;
	delete &pref;
	return 0;
}