#include "Intro.h"
#include "User.h"
#include "Writer.h"
#include <regex>

User Intro::Introduction()
{
    std::string Name;
    std::string Password;
    
    Writer::WriteActionInConsole("Initializing SeHasy", "Initialized", 3, 300);
    Writer::WriteActionInConsole("Looking for a secure connection", "Secure Connection Found!", 5, 500);
    Writer::WriteActionInConsole("Conecting", "Sucess!\nSecure connection establish", 7, 200);

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

    return User(Name, Password);
}

void Intro::CreateUser(std::string* Name, std::string* Password)
{
    Writer::WriteSimpleActionInConsole("Executing user creation", 3, 150);
    Writer::WriteInConsole("\nIntroduce a new username:\n");
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
                Writer::WriteErrorInConsole("Password should be eight or more characters long", "001");
            }
        }

        Writer::WriteInConsole("Please repeat your password:\n");
        std::cin >> repeat;
        std::cout << std::endl;
        if (passInput != repeat)
        {
            Writer::WriteErrorInConsole("The passwords doesn't match", "002");
            passInput = "";
        }
    }

    Writer::WriteActionInConsole("Creating", "Created!", 4, 200);

    *Password = passInput;
    Loging();
    Writer::WriteInConsole("Welcome " + *Name + "!\n");
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

    Loging();

    Writer::WriteInConsole("Welcome back " + *Name + "!\n");
}

void Intro::Loging()
{
    Writer::WriteActionInConsole("Loging", "Logged", 5, 500);
}
