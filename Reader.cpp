#include "Reader.h"

void Reader::SimpleInput(std::string Message, std::string* Input)
{
	Writer::WriteInConsole(Message + "\n");
	std::cin >> *Input;
	std::cout << std::endl;
}

void Reader::PasswordInput(std::string Message, std::string* Input)
{
    PasswordInput(Message, Input, true);
}

void Reader::PasswordInput(std::string Message, std::string* Input, bool ShowAsterisk)
{
    Writer::WriteInConsole(Message + "\n");

    std::string password;
    unsigned char ch = 0;

#ifdef _WIN32

    const char BACKSPACE = 8;
    const char RETURN = 13;

    DWORD con_mode;
    DWORD dwRead;

    HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);

    GetConsoleMode(hIn, &con_mode);
    SetConsoleMode(hIn, con_mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));

    while (ReadConsoleA(hIn, &ch, 1, &dwRead, NULL) && ch != RETURN)
    {
        if (ch == BACKSPACE)
        {
            if (password.length() != 0)
            {
                if (ShowAsterisk) 
                {
                    std::cout << "\b \b";
                }
                password.resize(password.length() - 1);
            }
        }
        else
        {
            password += ch;
            if (ShowAsterisk)
            {
                std::cout << '*';
            }
        }
    }
    std::cout << std::endl;

#else

    const char BACKSPACE = 127;
    const char RETURN = 10;

    std::string password;
    unsigned char ch = 0;

    while ((ch = getch()) != RETURN)
    {
        if (ch == BACKSPACE)
        {
            if (password.length() != 0)
            {
                if (ShowAsterisk)
                {
                    std::cout << "\b \b";
                }
                password.resize(password.length() - 1);
            }
        }
        else
        {
            password += ch;
            if (ShowAsterisk)
            {
                std::cout << '*';
            }
        }
    }
    std::cout << std::endl;

#endif

    *Input = password;
}

#ifdef _WIN32
#else
    int Reader::Getch()
    {
        int ch;
        struct termios t_old, t_new;

        srd::tcgetattr(STDIN_FILENO, &t_old);
        t_new = t_old;
        t_new.c_lflag &= ~(ICANON | ECHO);
        std::tcsetattr(STDIN_FILENO, TCSANOW, &t_new);

        ch = getchar();

        std::tcsetattr(STDIN_FILENO, TCSANOW, &t_old);
        return ch;
    }
#endif
