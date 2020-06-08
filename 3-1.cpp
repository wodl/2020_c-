#include <iostream>

struct Point
{
	int xpos;
	int ypos;
	void Movepos(int x, int y);
	void AddPoint(const Point &pos);
	void ShowPosition();
};

void Point::Movepos(int x, int y)
{
	xpos += x;
	ypos += y;
}
void Point::AddPoint(const Point &pos)
{
	xpos += pos.xpos;
	ypos += pos.ypos;
}
void Point::ShowPosition()
{
	std::cout << "[" << xpos << " ," << ypos << "]" << std::endl;
}

int main()
{
	Point pos1 = { 12,4 };
	Point pos2 = { 20,30 };

	pos1.Movepos(-7, 10);
	pos1.ShowPosition();

	pos1.AddPoint(pos2);
	pos1.ShowPosition();
	return 0;

}