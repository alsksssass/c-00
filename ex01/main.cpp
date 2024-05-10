#include "Book.hpp"
#include "Data.hpp"
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>


void book_search(Book& note)
{
	if (note.SEARCH() == 1)
		std::cout << "!INVAILID COMMAND!" << std::endl;
}
int main() {
	Book note;
	std::string command;

	while(true)
	{
		std::cout << "PLEASE PUT COMMNAD" << '\n' << "ex)\nADD" <<'\n' <<"SEARCH" << '\n' << "EXIT" << std::endl <<std::endl;
		std::getline(std::cin, command);
		if (std::cin.eof())
			return (0);
		if (!command.compare("ADD")){
			try{
				Data::make_data(note);
			}
			catch (const char* str){
				std::cout << "NOT VAILABLE !! " << str << " !!"<< std::endl << std::endl;
			}
		}
		else if(!command.compare("SEARCH"))
			book_search(note);
		else if (!command.compare("EXIT"))
			return (0);
	}

}