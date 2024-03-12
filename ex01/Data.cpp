#include "Data.hpp"

Data::Data(){
}
Data::~Data(){
}
Data::Data(std::string f_name, std::string l_name, std::string nickname, std::string number, std::string darkest_secret)
{
	this->f_name = f_name;
	this->l_name = l_name;
	this->nickname = nickname;
	this->number = number;
	this->darkest_secret = darkest_secret;
}
std::string Data::GET_DATA(int num)
{
	switch(num)
	{
	case 0 :
		return f_name;
	case 1 :
		return l_name;
	case 2 :
		return nickname;
	case 3 :
		return number;
	case 4 :
		return darkest_secret;
	}
	return 0;
}