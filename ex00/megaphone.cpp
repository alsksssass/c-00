#include <iostream>
#include <string>

void to_upper(std::string &str)
{
	for(int i = 0; i<(int)str.size(); i++)
	{
		if(std::islower(str[i]))
			str[i] = str[i] - 'a' + 'A';
	}
	str += " ";	
}

int main(int argc , char** argv) {
	std::string str = *argv;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" ;
	else if (argc >= 2)
	{
		for (int i = 1; i < argc; i++)
		{
			std::string str = argv[i];
			to_upper(str);
			std::cout << str;
		}
	}
	std::cout << std::endl;
	
	return 0;
}