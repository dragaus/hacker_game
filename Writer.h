#pragma once
#include <iostream>

class Writer
{
public:
	static void WriteInConsole(std::string Message);
	static void WriteInConsole(std::string Message, long time);
	static void DoubleLineBreak();
};

