#include <iostream>

double recur(double n);

double result = 1;
double lastResult = 0;
double nextResult;

int main()
{

	double input = 0;
	std::cin >> input;
	if (!std::cin)
	{
		std::cout << "no work" << std::endl;
	} else
	{
		recur(input);
	}
}

double recur(double n)
{
	nextResult = result + lastResult;
	std::cout << nextResult << std::endl;
	lastResult = result;
	result = nextResult;

	if (n > 1)
	{
		recur(n - 1);
	}
	return result;
}