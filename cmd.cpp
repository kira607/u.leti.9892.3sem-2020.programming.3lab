//
// Created by Kirill on 02.01.2021.
//

#include "cmd.h"

CMD *CMD::Get()
{
    std::cin >> std::noskipws >> command_str;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    Parse();
    return this;
}

Command CMD::Parse()
{
    command = Command::NONE;
    if(command_str == "add") command = Command::Add;
    if(command_str == "load") command = Command::Load;
    if(command_str == "save") command = Command::Save;
    if(command_str == "print") command = Command::Print;
    if(command_str == "printall") command = Command::PrintAll;
    if(command_str == "help") command = Command::Help;
    if(command_str == "exit") command = Command::Exit;
    if(command_str.empty()) command = Command::Skip;
    return command;
}