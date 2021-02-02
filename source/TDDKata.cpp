#include "TDDKata.h"

int TDDKata(std::string str)
{
	std::string temp = "";
	std::vector<int> num;
	int total = 0;
	
	//Kata 1: An empty string returns zero
	if (str == "")
		return 0;
	
	//Kata 2-6: addings numbers that are comma or newline delimited
	for (int i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i])) //If the character is a digit
			temp += str[i];
		else if (str[i] == ',' || str[i] == '\n') //If the character is a comma or a new line
		{
			num.push_back(std::stoi(temp));
			temp = "";
		}
		else if (str[i] == '-' && isdigit(str[i + 1])) //Negative number tester
		{
			try
			{
				throw -1;
			}
			catch (int e)
			{
				return e;
			}
		}
	}
	num.push_back(std::stoi(temp));

	for (auto& n : num) //Adding all the numbers up
		total += n;

	return total;
}
