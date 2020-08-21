#include "Writer.h"
#include <chrono>
#include <thread>

void Writer::WriteInConsole(std::string Message)
{
	WriteInConsole(Message, WritingTime);
}

void Writer::WriteInConsole(std::string Message, long time)
{
	int Index = 0;
	while (Index < Message.length())
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(time));
		std::cout << Message[Index];
		Index++;
	}
}

void Writer::WriteActionInConsole(std::string Action, std::string Result, int Dots, long DotTime)
{
	WriteActionInConsole(Action, Result, Dots, DotTime, WritingTime);
}

void Writer::WriteActionInConsole(std::string Action, std::string Result, int Dots, long DotTime, long Time)
{
	WriteSimpleActionInConsole(Action, Dots, DotTime);
	WriteInConsole(Result, Time);
	DoubleLineBreak();
}

void Writer::WriteSimpleActionInConsole(std::string Action, int Dots, long DotTime)
{
	WriteSimpleActionInConsole(Action, Dots, DotTime, WritingTime);
}

void Writer::WriteSimpleActionInConsole(std::string Action, int Dots, long DotTime, long Time)
{
	int Index = 0;
	WriteInConsole(Action, Time);
	while (Index < Dots)
	{
		WriteInConsole(".", DotTime);
		Index++;
	}
	WriteInConsole("\n", Time);
}

void Writer::WriteErrorInConsole(std::string Message, std::string ErrorNumber)
{
	WriteErrorInConsole(Message, ErrorNumber, WritingTime);
}

void Writer::WriteErrorInConsole(std::string Message, std::string ErrorNumber, long Time)
{
	std::string FinalMessage = "\033[1;31mError: " + ErrorNumber + "!\n" + Message + "\033[0m\n";
	WriteInConsole(FinalMessage, Time);
}

void Writer::DoubleLineBreak()
{
	std::cout << std::endl << std::endl;
}
