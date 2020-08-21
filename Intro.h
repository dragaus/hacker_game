#pragma once
#include "User.h"
#include <iostream>

class Intro
{
public:
	User Introduction();
private:
	void CreateUser(std::string* Name, std::string* Password);
	void LogInUser(std::string* Name, std::string* Password);
};

