#ifndef BOOK_HPP
#define BOOK_HPP

#include "Data.hpp"


class Book
{
private:
	Data a[8];
	int index;
	int num;
	void print_number (int index);
	void print_index();
	void show_number (std::string index);
	void print_data(std::string str);
public:
	Book();
	void ADD(Data &d);
	int SEARCH();
	~Book();
};
# endif

//한줄받기 모두 //