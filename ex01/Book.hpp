#ifndef BOOK_HPP
#define BOOK_HPP
#include "Data.hpp"

class Book
{
private:
	Data a[8];
	int num;
public:
	Book();
	void ADD(std::string f_name, std::string l_name, std::string nickname, std::string number, std::string darkest_secret);
	int SEARCH();
	void show_number (std::string index);
	void print_number (int index);
	~Book();
};
# endif

//한줄받기 모두 //