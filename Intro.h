#pragma once
#include "User.h"
#include "Intro.h"
#include "Writer.h"
#include "Reader.h"
#include <iostream>

class Intro
{
public:
	User Introduction();
private:
	void CreateUser(std::string* Name, std::string* Password);
	void LogInUser(std::string* Name, std::string* Password);
	void Loging();
};

