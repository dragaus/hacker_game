#pragma once
#include <iostream>

class Writer
{
public:
	static void WriteInConsole(std::string Message);
	static void WriteInConsole(std::string Message, long time);
	static void WriteActionInConsole(std::string Action, std::string Result, int Dots, long DotTime);
	static void WriteActionInConsole(std::string Action, std::string Result, int Dots, long DotTime, long Time);
	static void WriteSimpleActionInConsole(std::string Action, int Dots, long DotTime);
	static void WriteSimpleActionInConsole(std::string Action, int Dots, long DotTime, long Time);
	static void WriteErrorInConsole(std::string Message, std::string ErrorNumber);
	static void WriteErrorInConsole(std::string Message, std::string ErrorNumber, long Time);
	static void DoubleLineBreak();
private:
	const static long WritingTime = 50;
};

