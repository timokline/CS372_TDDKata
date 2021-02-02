#include "TDDKata.h"

int TDDKata(std::string str)
{
	std::string temp = "";
	std::vector<int> num;
	char delimiter{};
	int digit = 0;
	int total = 0;
	
	//Kata 1: An empty string returns zero
	if (str == "")
		return 0;
	
	int index = 0;
	if (str[0] == '/' && str[1] == '/')
	{
		delimiter = str[2];
		index = 3;
	}

	//Kata 2-5: addings numbers that are comma or newline delimited
	for (index; index < str.length(); index++)
	{	
		try
		{
			if (str[index] == '-')
				throw str[index];
		}
		catch (char str[])
		{
			std::cout << "[ERROR] Negative number entered." << std::endl;
		}

		if (isdigit(str[index]))
		{
			digit++;
			temp += str[index];
		}
		else if (str[index] == ',' || str[index] == '\n' || str[index] == delimiter)
		{
			num.push_back(std::stoi(temp));
			temp = "";
			digit = 0;
		}
		
		if (digit == 4)
		{
			temp = "0";
		}
	}
	num.push_back(std::stoi(temp));

	for (auto& n : num)
		total += n;

	return total;
}
