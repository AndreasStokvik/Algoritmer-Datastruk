// Factorials.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    double n = 0;
    double result = 1;

    std::cin >> n;
	n = (int)n;
		while (n > 1)
		{
			result *= n;
			n--;
		}
		std::cout << result << std::endl;
	return main();
}
