#include "Writer.h"
#include <chrono>
#include <thread>

void Writer::WriteInConsole(std::string Message)
{
	WriteInConsole(Message, 50);
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

void Writer::DoubleLineBreak()
{
	std::cout << std::endl << std::endl;
}
