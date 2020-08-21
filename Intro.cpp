#include "Intro.h"
#include "User.h"
#include "Writer.h"

User Intro::Introduction()
{
    std::string Name;
    std::string Password;

    Writer::WriteInConsole("Initializing SeHaSy");
    Writer::WriteInConsole("...\n", 300);
    Writer::WriteInConsole("Initialized.");
    Writer::DoubleLineBreak();

    Writer::WriteInConsole("Establishing a secure connection");
    Writer::WriteInConsole(".....\n", 500);
    Writer::WriteInConsole("Secure connection establish");
    Writer::DoubleLineBreak();

    Writer::WriteInConsole("Welcome to the Secret Hacking System!");
    Writer::DoubleLineBreak();

    Writer::WriteInConsole("Do You have a user? (Y/N)\n");
    std::string Answer;
    std::cin >> Answer;
    std::cout << std::endl;

    if (tolower(Answer[0]) == 'y') 
    {
        LogInUser(&Name, &Password);
    }
    else
    {
        CreateUser(&Name, &Password);
    }

    Writer::WriteInConsole("Connecting");
    Writer::WriteInConsole(".....\n", 500);
    Writer::WriteInConsole("Connected");

    Writer::DoubleLineBreak();
    Writer::WriteInConsole("Welcome back " + Name + "\n");
    return User(Name, Password);
}

void Intro::CreateUser(std::string* Name, std::string* Password)
{
    Writer::WriteInConsole("Executing user creation");
    Writer::WriteInConsole("...", 100);
    Writer::WriteInConsole("Introduce your username:\n");
    std::string input;
    std::cin >> input;
    *Name = input;
    std::cout << std::endl;
    std::string passInput = "a";
    std::string repeat = "b";
    while (passInput != repeat)
    {
        while (passInput.length() < 8)
        {
            Writer::WriteInConsole("Please enter a new password:\n");
            std::cin >> passInput;
            std::cout << std::endl;
            if (passInput.length() < 8)
            {
                Writer::WriteInConsole("Password should be eight or more characters long\n");
            }
        }

        Writer::WriteInConsole("Please repeat your password:\n");
        std::cin >> repeat;
        std::cout << std::endl;
        if (passInput != repeat)
        {
            Writer::WriteInConsole("The passwords doesn´t match\n");
            passInput = "";
        }
    }

    *Password = passInput;
    std::cout << std::endl;
}

void Intro::LogInUser(std::string* Name, std::string* Password)
{
    Writer::WriteInConsole("Introduce your username:\n");
    std::string input;
    std::cin >> input;
    *Name = input;
    std::cout << std::endl;
    Writer::WriteInConsole("Please enter your password:\n");
    std::cin >> input;
    *Password = input;
    std::cout << std::endl;
}
