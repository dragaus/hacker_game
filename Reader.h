#pragma once
#include "Writer.h"
#include <iostream>
#ifdef _WIN32
	#include <string>
	#include <windows.h>
#else
	#include <termios.h>
	#include <unistd.h>
	#include <stdio.h>
#endif


class Reader
{
public:
	static void SimpleInput(std::string Message ,std::string* Input);
	static void PasswordInput(std::string Message, std::string* Input);
	static void PasswordInput(std::string Message, std::string* Input, bool ShowAsterisk);
private:
#ifdef _WIN32
#else
	static int Getch();
#endif
};

