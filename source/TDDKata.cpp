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
		if (isdigit(str[i])) //Stoping search for delimiters if a digit is found
		{
			break;
		}
		if (str[0] == '/' && str[1] == '/') // Searching for "//" to signify new delimiter
		{
			if (str[2] == '[') //Multi-Character
			{
				for (int j = i + 3; j < str.length(); j++)//Searching for the end of the delimiter
				{
					if (str[j] == ']') //Detects end of delimiter
					{
						delim.push_back(temp); //Adds delimiter to the vector of the delimiters
						start += temp.length() + 4; //Moves start
						i += temp.length() + 3;
						temp = "";
						j = str.length();
					}
					else
						temp.push_back(str[j]); //Adds characters to the delimiter
				}
			}
			else //Single-Character
			{
				temp.push_back(str[2]); //Adding the delimiter to the string
				delim.push_back(temp);
				start += 3; //Pushing the start value back to account for single character delimiters without brakets
				temp = "";
				break; //Exiting the for loop cause no brackets only means 1 delimiter
			}
			
		}

	}
	
	//Extracting numbers with delimiters
	for (int i = start; i < str.length(); i++)
	{
		if (isdigit(str[i])) //If the character is a digit
			temp += str[i];

		else if (str[i] == '-' && isdigit(str[i + 1])) //Negative number tester
			throw str[i];

		for (auto& n : delim) //Checking for delimeters
		{
			if (str[i] == n[0]) //Comparing the start of the delimiter
			{
				for (int j = 0; j < n.length(); j++) //Cycling through the delimiter and comparing to the string
				{
					if (n[j] != str[i + j]) //If a part of the delimiter does not match
						total++;
				}
				if (total == 0) //If the delimiter matches the string
				{
					num.push_back(std::stoi(temp));
					temp = "";
				}
				else //Reseting total 
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
