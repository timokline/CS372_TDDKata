#include "TDDKata.h"

int TDDKata(std::string str)
{
	std::string temp = "";
	std::vector<int> num;
	int digit = 0;
	int total = 0;
	
	//Kata 1: An empty string returns zero
	if (str == "")
		return 0;
	
	//Kata 2-5: addings numbers that are comma or newline delimited
	for (int i = 0; i < str.length(); i++)
	{
		try
		{
			if (str[i] == '-')
				throw str[i];
		}
		catch (char str[])
		{
			std::cout << "[ERROR] Negative number entered." << std::endl;
		}

		if (isdigit(str[i]))
		{
			digit++;
			temp += str[i];
		}
		else if (str[i] == ',' || str[i] == '\n')
		{
			num.push_back(std::stoi(temp));
			temp = "";
		}
		else if (digit == 4)
		{
			temp = "";
			i++;
		}
	}
	num.push_back(std::stoi(temp));

	for (auto& n : num)
		total += n;

	return total;
}
