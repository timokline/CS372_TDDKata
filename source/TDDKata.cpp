#include "TDDKata.h"

int TDDKata(std::string str)
{
	int count = 0;
	std::string delimiter1 = ",", delimiter2 = "\n";
	std::string temp = "";
	int num[3], arrpos = 0, total = 1;

	if (str == "") //An empty string returns zero
	{
		return 0;
	}
	
	for (int i = 0; i < str.length(); i++) //A single number returns the value
	{
		if (isdigit(str[i]) == 0)
		{
			count = 1;
		}
	}
	if (count == 0)
	{
		return std::stoi(str);
	}

	for(int i = 0; i < str.length(); i++)
	{
		if (str[i] == delimiter1[0] || str[i] == delimiter2[0])
		{
			num[arrpos] = std::stoi(temp);
			temp = "";
			arrpos++;
			if (str[i + 1] == delimiter2[1])
			{
				i++;
			}
		}
		else
		{
			temp += str[i];
		}
	}
	arrpos = 0;

	while (num[arrpos] != NULL)
	{
		total += num[arrpos];
		arrpos++;
	}
	
	

	return total;
}
