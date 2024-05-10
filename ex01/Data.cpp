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

	void Data::set_lname(std::string lname){this->l_name = lname;}
	void Data::set_fname(std::string fname){this->f_name = fname;}
	void Data::set_nickname(std::string nickname){this->nickname = nickname;}
	void Data::set_number(std::string number){this->number = number;}
	void Data::set_darkest(std::string darkest){this->darkest_secret = darkest;}
	std::string Data::get_lname(){return this->l_name;}
	std::string Data::get_fname(){return this->f_name;}
	std::string Data::get_nickname(){return this->nickname;}
	std::string Data::get_number(){return this->number;}
	std::string Data::get_darkest(){return this->darkest_secret;}

void Data::make_data(Book &note)
{
	Data get;
	std::string temp;
	std::cout << "FIRST NAME : ";
	std::getline(std::cin, temp);
	if(!Data::is_ok(temp))
		throw "f_name";
	get.set_fname(temp);
	std::cout << "LAST NAME : ";
	std::getline(std::cin, temp);
	if(!Data::is_ok(temp))
		throw "l_name";
	get.set_lname(temp);
	std::cout << "NICKNAME : ";
	std::getline(std::cin, temp);
	if(!Data::is_ok(temp))
		throw "nickname";
	get.set_nickname(temp);
	std::cout << "NUMBER : ";
	std::getline(std::cin, temp);
	if(!Data::is_ok(temp))
		throw "number";
	get.set_number(temp);
	std::cout << "DARKEST_SECRET : ";
	std::getline(std::cin, temp);
	if(!Data::is_ok(temp))
		throw "darkest_secret";
	get.set_darkest(temp);
	note.ADD(get);

}

int Data::is_ok(std::string str)
{
	for(int i = 0; i < (int)str.size(); i++)
	{
		if(!isspace(str[i]))
			return 1;
	}
	return 0;
}