//
// Created by Kirill on 02.01.2021.
//

#ifndef LAB3_CMD_H
#define LAB3_CMD_H

#include <iostream>
#include <sstream>
#include <cstring>

#include "input.h"

enum Command
{
    Add,
    Load,
    Save,
    Print,
    PrintAll,
    Help,
    Exit,
    Skip,
    NONE,
};

struct CMD
{
    Command command = Command::NONE;
    std::string command_str{};

    CMD *Get();
    Command Parse();
};

#endif //LAB3_CMD_H
