#include <iostream>
using namespace std;

class Calculator
{
	int add, min, mul, div;
public:
	void Init()
	{
		add = 0; min = 0; mul = 0; div = 0;
	}
	double Add(double x,double y)
	{
		add++;
		return x + y;
	}
	double Min(double x, double y)
	{
		min++;
		return x - y;
	}
	double Mul(double x, double y)
	{
		mul++;
		return x * y;
	}
	double Div(double x,double y)
	{
		div++;
		return x / y;
	}
	void ShowOpCount()
	{
		cout << "µ¡¼À: " << add << " »¬¼À: " << min << " °ö¼À: " << mul << " ³ª´°¼À: " << div << endl;
	}
};

int main()
{
	Calculator cal;
	cal.Init();
	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
	cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
	cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
	cal.ShowOpCount();
	return 0;
}