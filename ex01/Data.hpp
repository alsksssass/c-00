#ifndef DATA_HPP
#define DATA_HPP
#include <iostream>

class Book;

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
	~Data();
	void set_lname(std::string lname);
	void set_fname(std::string fname);
	void set_nickname(std::string nickname);
	void set_number(std::string number);
	void set_darkest(std::string darkest);
	std::string get_lname();
	std::string get_fname();
	std::string get_nickname();
	std::string get_number();
	std::string get_darkest();
	static void make_data(Book &note);
	static int is_ok(std::string str);
};
#include "Book.hpp"
#endif 