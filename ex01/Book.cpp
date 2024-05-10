#include "Book.hpp"
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <cstdio>
void Book::ADD(Data &d)
{
	if(this->index >= 8)
		this->index = 0;
	a[this->index] = d;
	if(this->num < 8)
		this->num++;
	this->index++;
}

void Book::print_data(std::string str)
{
	std::cout << "|";
	if (str.size() > 10)
	{
		std::cout << std::setw(9) << str.substr(0,9) << ".";
	}
	else
		std::cout << std::setw(10) << str.substr(0,10);
}

void Book::print_index()
{
	print_data("INDEX");
	print_data("FIRSTNAME");
	print_data("LAST NAME");
	print_data("NICKNAME");
	std::cout << "|" << '\n';
}
int is_num (std::string str)
{
	for(int i =0; i< (int)str.size(); i++)
	{
		if (!isdigit(str[i]))
			return 0;
	}
	return 1;
}

void Book::print_number (int _index)
{
	std::cout << std::endl;
	std::cout << "CONTACT DETAIL" << std::endl;
	std::cout << "index :" << _index << std::endl;
	std::cout << "FRIST NAME :" << a[_index].get_fname() << std::endl;
	std::cout << "LAST NAME :" << a[_index].get_lname() << std::endl;
	std::cout << "NICKNAME :" << a[_index].get_nickname() << std::endl;
	std::cout << "NUMBER :" << a[_index].get_number() << std::endl;
	std::cout << "DARKEST_SECRET :" << a[_index].get_darkest() << std::endl <<std::endl;
}
void Book::show_number (std::string _index){
	std::cout << std::endl;
	char *ptr;
	const char *str = _index.c_str();
	int num; num = strtol(str, &ptr, 10);
	if (0 == this->num || this->num <= num)
		std::cout << "!!>> " << _index << " << NOT VAILID!!\n" << std::endl;
	else
		Book::print_number(num);
}
int Book::SEARCH()
{
	std::cout << std::endl;
	if (this->num == 0)
	{
		std::cout << "NO DATA\n" << std::endl;
		return 0;
	}
	std::cout << "---------------------------------------------" << '\n' ;
	Book::print_index();
	for(int i = 0; i < this->num; i++)
	{
		char _index[2] = {0}; _index[0] = i + '0';
		std::string s_index = _index;
		print_data(s_index);
		print_data(a[i].get_fname());
		print_data(a[i].get_lname());
		print_data(a[i].get_nickname());
		std::cout << "|" << '\n';
	}
	std::cout << "---------------------------------------------" << '\n' ;
	std::cout << "INSERT INDEX NUMBER : ";
	std::string str ;
	std::getline(std::cin,str);
	if(is_num(str))
		Book::show_number(str);
	else
		return 1;
	return 0;
}


Book::Book() {
	num = 0;
	index = 0;
}
Book::~Book() {
}

