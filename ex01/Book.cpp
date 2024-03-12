#include "Book.hpp"
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <cstdio>
void Book::ADD(std::string f_name, std::string l_name, std::string nickname, std::string number, std::string darkest_secret)
{
	int index = this->num % 8;
	a[index] = Data(f_name,l_name,nickname,number,darkest_secret);
	this->num++;
}

void print_data(std::string str)
{
	std::cout << "|";
	if (str.size() > 10)
	{
		std::cout << std::setw(9) << str.substr(0,9) << ".";
	}
	else
		std::cout << std::setw(10) << str.substr(0,10);
}

void print_index()
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

void Book::print_number (int index)
{
	std::cout << std::endl;
	std::cout << "CONTACT DETAIL" << std::endl;
	std::cout << "index :" << index << std::endl;
	std::cout << "FRIST NAME :" << a[index].GET_DATA(0) << std::endl;
	std::cout << "LAST NAME :" << a[index].GET_DATA(1) << std::endl;
	std::cout << "NICKNAME :" << a[index].GET_DATA(2) << std::endl;
	std::cout << "NUMBER :" << a[index].GET_DATA(3) << std::endl;
	std::cout << "DARKEST_SECRET :" << a[index].GET_DATA(4) << std::endl <<std::endl;
}
void Book::show_number (std::string index){
	std::cout << std::endl;
	char *ptr;
	const char *str = index.c_str();
	int num; num = strtol(str, &ptr, 10);
	if (ptr != 0 || 0 > num || this->num % 8 - 1 < num)
		std::cout << "!!>> " << index << " << NOT VAILID!!\n" << std::endl; /// 수정
	else
		Book::print_number(num);
}
int Book::SEARCH()
{
	std::cout << std::endl;
	if (num == 0)
	{
		std::cout << "NO DATA\n" << std::endl;
		return 0;
	}
	std::cout << "---------------------------------------------" << '\n' ;
	print_index();
	int p_num;
	if (num > 8)
		p_num = 8;
	else 
		p_num = num;
	for(int i = 0; i<p_num; i++)
	{
		char num[20];
		sprintf(num, "%d" ,i);
		std::string s_num = num;
		print_data(s_num);
		print_data(a[i].GET_DATA(0));
		print_data(a[i].GET_DATA(1));
		print_data(a[i].GET_DATA(2));
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
}
Book::~Book() {
}

