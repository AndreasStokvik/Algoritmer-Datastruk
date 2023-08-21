// Factorials.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
int recur(double n);

double result;

int main()
{
    double n = 0;

    std::cin >> n;
	n = (double)n;

	result = n;

	recur(n);
	std::cout << result << std::endl;
	return main();
}

int recur(double n)
{
	if (n <= 1)
	{
		return result > 0 ? result : 1;
	}
	result *= (n - 1);
	recur(n - 1);
}