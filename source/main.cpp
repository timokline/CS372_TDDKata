
#include <iostream>
#include <string>


int main()
{
	std::string KataString;
	int KataNumber1, KataNumber2, KataNumber3;

	std::cout << "Enter a String: ";
 	std::cin >> KataString;
	std::cout << std::endl;

	// #1
	if (KataString == "")
	{
		return 0;
	}


	return -1; //safety net
}