#include "Intro.h"
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

    std::string Answer;
    Reader::SimpleInput("Do You have a user? (Y/N)", &Answer);

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
    Reader::SimpleInput("\nIntroduce a new username:", Name);

    std::string PassInput = "a";
    std::string Repeat = "b";
    while (PassInput != Repeat)
    {
        while (PassInput.length() < 8)
        {
            Reader::SimpleInput("Please enter a new password:", &PassInput);
            if (PassInput.length() < 8)
            {
                Writer::WriteErrorInConsole("Password should be eight or more characters long", "001");
            }
        }

        Reader::SimpleInput("Please repeat ypur password:", &Repeat);
        if (PassInput != Repeat)
        {
            Writer::WriteErrorInConsole("The passwords doesn't match", "002");
            PassInput = "";
        }
    }

    Writer::WriteActionInConsole("Creating", "Created!", 4, 200);

    *Password = PassInput;
    Loging();
    Writer::WriteInConsole("Welcome " + *Name + "!\n");
}

void Intro::LogInUser(std::string* Name, std::string* Password)
{
    Reader::SimpleInput("Introduce your Username:", Name);
    Reader::SimpleInput("Please enter your password:", Password);

    Loging();

    Writer::WriteInConsole("Welcome back " + *Name + "!\n");
}

void Intro::Loging()
{
    Writer::WriteActionInConsole("Loging", "Logged", 5, 500);
}
