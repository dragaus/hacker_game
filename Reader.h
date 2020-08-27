#pragma once
#include "Writer.h"
#include <iostream>

class Reader
{
public:
	static void SimpleInput(std::string Message ,std::string* Input);
	static void PasswordInput(std::string Message, std::string* Input);
};

