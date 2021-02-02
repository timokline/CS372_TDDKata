#include "TDDKata.h"

int TDDKata(std::string str)
{
	std::string temp = "";
	std::vector<int> num;
	std::vector<char> delim;
	int total = 0;
	int start = 0;
	
	//Kata 1: An empty string returns zero
	if (str == "")
		return 0;
	
	if (str[0] == '/' && str[1] == '/')
	{
		delim.push_back(str[2]);
		start = 3;
	}

	//Kata 2-6: addings numbers that are comma or newline delimited
	for (int i = start; i < str.length(); i++)
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
		else if (delim.size() > 0 && str[i] == delim.back())
		{
			num.push_back(std::stoi(temp));
			temp = "";
		}

		if (num.size() > 0 && num.back() > 1000) //Ignoring numbers greater than 1000
		{
			num.pop_back();
		}
	}

	num.push_back(std::stoi(temp));
	if (num.size() > 0 && num.back() > 1000) //Ignoring numbers greater than 1000
	{
		num.pop_back();
	}

	for (auto& n : num) //Adding all the numbers up
		total += n;

	return total;
}
