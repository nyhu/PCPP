#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

int main(int ac, char **av)
{
	double d;
	int i;

	if (ac < 2)
	{
		std::cout << "usage: ./Scalar [number]" << std::endl;
		return (0);
	}
	while (*++av)
	{
		std::string str(*av);

		try
		{
			d = std::stod(str);
			i = static_cast<int>(d);
		}
		catch (std::exception &e)
		{
			std::cerr << "Invalid Input: " << e.what() << std::endl;
			return (-1);
		}

		if (i < 0 || i > 127)
			std::cout << "char: impossible" << std::endl;
		else if (isprint(static_cast<int>(d)))
			std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;

		if (!str.compare("nan") || !str.compare("NaN") || str.find("inf") != std::string::npos)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(d) << std::endl;

		std::cout << "float: " << static_cast<float>(d);
		if (static_cast<double>(static_cast<int>(d)) == d)
			std::cout << ".0";
		std::cout << "f" << std::endl;

		std::cout << "double: " << d;
		if (static_cast<double>(static_cast<int>(d)) == d)
			std::cout << ".0";
		std::cout << std::endl;
	}
	return (0);
}
