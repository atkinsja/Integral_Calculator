#include <iostream>
#include <iomanip>
using namespace std;

double left(double, double, double, int);
double right(double, double, double, int);
double midpoint(double, double, double, int);
double trapezoid(double, double, double, int);
double simpson(double, double, double, int);
double f(double);

int main()
{
	double x_l, x_r, width;
	int n;
	cout << "Enter the left and right end points of the interval: ";
	cin >> x_l >> x_r;
	cout << "Enter the number of subintervals: ";
	cin >> n;
	width = fabs(x_r - x_l) / n;
	cout << fixed << setprecision(5);
	cout << "The area under the curve using left endpoints is: " << left(x_l, x_r, width, n) << endl;
	cout << "The area under the curve using right endpoints is: " << right(x_l, x_r, width, n) << endl;
	cout << "The area under the curve using midpoints is: " << midpoint(x_l, x_r, width, n) << endl;
	cout << "The area under the curve using the trapezoidal rule is: " << trapezoid(x_l, x_r, width, n) << endl;
	cout << "The area under the curve using the simpson rule is: " << simpson(x_l, x_r, width, n) << endl;

	return 0;
}

double f(double x)
{
	return exp(x*x);
	//return 1 / x;
	//return pow(x, 2) + 2*(x);
	//return log(x);
}

double simpson(double x_left, double x_right, double w, int n)
{
	double area = f(x_left) + f(x_right);
	for (int i = 1; i < n; i++)
	{
		if (i % 2 == 0)
			area += 2 * f(x_left + i * w);
		else
			area += 4 * f(x_left + i * w);
	}
	area = area * (w / 3);

	return area;
}

double trapezoid(double x_left, double x_right, double w, int n)
{
	double area;
	area = f(x_left) + f(x_right);
	for (int i = 1; i < n; i++)
	{
		area += 2 * f(x_left + i * w);
	}
	area = area * (w / 2);
	return area;
}
double left(double x_left, double x_right, double w, int n)
{
	double x_val, area;
	x_val = x_left;
	area = 0;
	for (int i = 1; i <= n; i++)
	{
		area += f(x_val)*w;
		x_val += w;
	}
	return area;
}

double right(double x_left, double x_right, double w, int n)
{
	double x_val, area;
	x_val = x_left + w;
	area = 0;
	for (int i = 1; i <= n; i++)
	{
		area += f(x_val)*w;
		x_val += w;
	}
	return area;
}

double midpoint(double x_left, double x_right, double w, int n)
{
	double x_val, area;
	x_val = x_left + (w/2);
	area = 0;
	for (int i = 1; i <= n; i++)
	{
		area += f(x_val)*w;
		x_val += w;
	}
	return area;
}