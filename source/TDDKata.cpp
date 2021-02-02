#include "TDDKata.h"

int TDDKata(std::string str)
{
	std::string temp = "";
	std::vector<int> num;
	int total = 0;

	//Kata 1: An empty string returns zero
	if (str == "") 
	{
		return 0;
	}
		
	//Kata 2-5 adding numbers that are comma or new line delimited
	for (int i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]))
		{
			temp += str[i];
		}
		else if (str[i] == ',' || str[i] == '\n')
		{
			num.push_back(std::stoi(temp));
			temp = "";
		}
	}
	num.push_back(std::stoi(temp));

	for (auto i : num)
	{
		total += i;
	}

	return total;
}
