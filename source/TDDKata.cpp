#include "TDDKata.h"

int TDDKata(std::string str)
{
	std::string temp = "";
	std::vector<int> num;
	std::string delimiter{};
	int digit = 0;
	int count = 0;
	int total = 0;
	
	//Kata 1: An empty string returns zero
	if (str == "")
		return 0;
	
	int index = 0;
	if (str[0] == '/' && str[1] == '/')
	{
		//count++;
		index = 3;
		if (str[index - 1] == '[')
		{
			while (str[index] != ']')
			{
				delimiter += str[index];
				++index;
				++count;
			}
			++index;
		}
		else
			delimiter = str[2];
	}
	size_t found = str.find(delimiter);
	//Kata 2-5: addings numbers that are comma or newline delimited
	for (index; index < str.length(); ++index)
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
		//   //[$&%]657$&%9
		/*
		
		
		
		*/
		else if (str[index] == ',' || str[index] == '\n' || (found = str.find(delimiter, found + 1)) == index)
		{
			num.push_back(std::stoi(temp));
			temp = "";
			digit = 0;
			if(count > 1)
				index += (count-1);
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
