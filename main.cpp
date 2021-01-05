#include <iostream>

#include "cmd.h"

int main()
{
    TruckDataBase db{};
    const std::string prompt = "LR3$>";
    Command command = Command::NONE;
    CMD cmd;

    while(command != Command::Exit)
    {
        std::cout << prompt;
        cmd.Get();
        command = cmd.command;
        cmd.Run(db);
    }

    db.Exit();
    return 0;
}