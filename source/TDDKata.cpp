#include "TDDKata.h"

int TDDKata(std::string str)
{
	std::string temp = "";
	std::vector<int> num;
	std::vector<std::string> delim{ ",", "\n" };
	int total = 0;
	int start = 0;

	//Kata 1: An empty string returns zero
	if (str == "")
		return 0;

	//Finding delimiters
	for (int i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]))
		{
			break;
		}
		if (str[0] == '/' && str[1] == '/')
		{
			if (str[2] == '[') //Multi-Character
			{
				for (int j = i + 3; j < str.length(); j++)
				{
					if (str[j] == ']')
					{
						delim.push_back(temp);
						start += temp.length() + 4;
						i += temp.length() + 3;
						temp = "";
						j = str.length();
					}
					else
						temp.push_back(str[j]);
				}
			}
			else //Single-Character
			{
				temp.push_back(str[2]);
				delim.push_back(temp);
				start += 3;
				temp = "";
				break;
			}
			
		}

	}
	
	//Extracting numbers with delimeters
	for (int i = start; i < str.length(); i++)
	{
		if (isdigit(str[i])) //If the character is a digit
			temp += str[i];

		else if (str[i] == '-' && isdigit(str[i + 1])) //Negative number tester
			throw str[i];

		for (auto& n : delim) //Checking for delimeters
		{
			if (str[i] == n[0])
			{
				for (int j = 0; j < n.length(); j++)
				{
					if (n[j] != str[i + j])
					{
						total++;
					}
				}
				if (total == 0)
				{
					num.push_back(std::stoi(temp));
					temp = "";
				}
				else
					total = 0;
			}

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
