#include <iostream>

int main()
{
	double n = 0;
	double result = 1;
	double s1 = 0;
	double s2 = 1;

	std::cin >> n;
	n = (double)n;
	while (n > 1)
	{
		std::cout << result << std::endl;
		s2 = s1;
		s1 = result;
		result = s1+s2;
		n--;
	}
	std::cout << result << std::endl;
	return main();
}
