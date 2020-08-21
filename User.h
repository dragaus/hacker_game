#pragma once
#include <iostream>

class User
{
public:
	User( std::string UserNa, std::string Pass);
	std::string UserName;
	std::string Password;
};