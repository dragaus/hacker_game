#include "Reader.h"

void Reader::SimpleInput(std::string Message, std::string* Input)
{
	Writer::WriteInConsole(Message + "\n");
	std::cin >> *Input;
	std::cout << std::endl;
}

void Reader::PasswordInput(std::string Message, std::string* Input)
{
	Writer::WriteInConsole(Message + "\n");

}
