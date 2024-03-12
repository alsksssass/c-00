#ifndef DATA_HPP
#define DATA_HPP
#include <iostream>
class Data
{
private:
	std::string f_name;
	std::string l_name;
	std::string nickname;
	std::string number;
	std::string darkest_secret;

public:
	Data();
	Data(std::string f_name, std::string l_name, std::string nickname, std::string number, std::string darkest_secret);
	std::string GET_DATA(int num);
	~Data();
};
#endif 