#include "Book.hpp"
#include "Data.hpp"
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>

int is_ok(std::string str)
{
	for(int i = 0; i < (int)str.size(); i++)
	{
		if(!isspace(str[i]))
			return 1;
	}
	return 0;
}
void to_upper(std::string &str)
{
	for(int i = 0; i<(int)str.size(); i++)
	{
		if(std::islower(str[i]))
			str[i] = str[i] - 'a' + 'A';
	}
}
void book_add(Book& note)
{
	std::string f_name;
	std::string l_name;
	std::string nickname;
	std::string number;
	std::string darkest_secret;

	std::cout << "FIRST NAME : ";
	std::getline(std::cin, f_name);
	if(!is_ok(f_name))
		throw "f_name";
	std::cout << "LAST NAME : ";
	std::getline(std::cin, l_name);
	if(!is_ok(l_name))
		throw "l_name";
	std::cout << "NICKNAME : ";
	std::getline(std::cin, nickname);
	if(!is_ok(nickname))
		throw "nickname";
	std::cout << "NUMBER : ";
	std::getline(std::cin, number);
	if(!is_ok(number))
		throw "number";
	std::cout << "DARKEST_SECRET : ";
	std::getline(std::cin, darkest_secret);
	if(!is_ok(darkest_secret))
		throw "darkest_secret";
	note.ADD(f_name,l_name,nickname,number,darkest_secret);
}

void book_search(Book& note)
{
	if (note.SEARCH() == 1)
		std::cout << "!INVAILID COMMAND!" << std::endl;
}
int main() {
	Book note = Book();
	std::string command;

	while(true)
	{
		std::cout << "PLEASE PUT COMMNAD" << '\n' << "ex)\nADD" <<'\n' <<"SEARCH" << '\n' << "EXIT" << std::endl <<std::endl;
		std::getline(std::cin, command);
		to_upper(command);
		if (std::cin.eof())
			return (0);
		if (command == "ADD"){
			try{
			book_add(note);
			}
			catch (const char* str){
				std::cout << "NOT VAILABLE !! " << str << " !!"<< std::endl << std::endl;
			}
		}
		else if(command == "SEARCH")
			book_search(note);
		else if (command== "EXIT")
			return (0);
	}

}