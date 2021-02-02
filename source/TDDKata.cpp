#include "TDDKata.h"

int TDDKata(std::string str)
{
	std::string delimiter1 = ",", delimiter2 = "\n";
	std::string temp = "";
	int num[3], arrpos = 0, total = 1;
	if (str == "")
	{
		return 0;
	}
	
	for(int loopt = 0; loopt < str.length(); loopt++)
	{
		if (str[loopt] == delimiter1[0] || (str[loopt] == delimiter2[0] && str[loopt+1] == delimiter2[1]))
		{
			num[arrpos] = std::stoi(temp);
			temp = "";
			arrpos++;
			if (str[loopt + 1] == delimiter2[1])
			{
				loopt++;
			}
		}
		else
		{
			temp += str[loopt];
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
