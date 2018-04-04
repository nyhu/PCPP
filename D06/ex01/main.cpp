#include <iostream>
#include <ctime>
#include <stdlib.h>

struct Data
{
	std::string s1;
	int n;
	std::string s2;
};

std::string randStr(void)
{
	std::string s(8, ' ');
	static const char alphabet[] = "0123456789aeiouybcdfghjklmnpqrstvwxz";

	for (int i = 0; i < 8; i++)
		s[i] = alphabet[rand() % (sizeof(alphabet) - 1)];

	return s;
}

void *serialize(void)
{
	Data *data = new Data();

	data->s1 = randStr();
	data->n = rand();
	data->s2 = randStr();

	std::cout << "origin->s1: " << data->s1 << std::endl;
	std::cout << "origin->n : " << data->n << std::endl;
	std::cout << "origin->s2: " << data->s2 << std::endl;

	return data;
}

int main(void)
{
	srand(std::time(NULL));

	void *raw = serialize();

	Data *data = reinterpret_cast<Data *>(raw);

	std::cout << "result->s1: " << data->s1 << std::endl;
	std::cout << "result->n : " << data->n << std::endl;
	std::cout << "result->s2: " << data->s2 << std::endl;

	delete data;

	return (0);
}
