#include<iostream>
#include<iomanip>

using namespace std;

class Rectangle
{
private:
	double length;
	double width;
public:
	Rectangle(double l = 0.0, double w = 0.0)
		: length(l), width(w) {
	};
	void set(double l, double h) {
		length = l;
		width = h;
	}

	double getlength(double l) const
	{
		return l;
	}

	double getWidth(double h) const
	{
		return h;
	}

	double area() const
	{
		return length * width;
	}
};

class Cuboid 
{
private:
	double height;
	Rectangle base;
public:
	Cuboid(double h = 0.0, double l = 0.0, double w = 0.0)
		:height(h), base(l, w) {
	};

	void set(double l, double h, double w)
	{
		height = h;
		base.set(l, w);
	}

	double Tiji()
	{
		return base.area() * height;
	}

};

int main()
{
	double l, w, h;
	cin >> l >> w >> h;
	Cuboid cb;
	cb.set(l, h, w);
	cout << fixed << setprecision(2);
	cout << cb.Tiji() << endl;
	return 0;
}
