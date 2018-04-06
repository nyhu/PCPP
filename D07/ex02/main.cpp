#include "Array.hpp"

int			main( void )
{
	Array<int> int_array(12);

	int_array[8] = 34;

	for (size_t i = 0; i < 12; i++)
		std::cout << i << ":\t" << int_array[i] << std::endl;
	try
	{
		int_array[13];
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << ": Array too small" << std::endl;
	}
    Array<char> char_array(12);

	char_array[8] = 120;

	for (size_t i = 0; i < 12; i++)
		std::cout << i << ":\t" << char_array[i] << std::endl;
	try
	{
		char_array[13];
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << ": Array too small" << std::endl;
	}

    Array<char> copy = char_array;
	for (size_t i = 0; i < 12; i++)
		std::cout << i << ":\t" << copy[i] << std::endl;

	return (0);
}