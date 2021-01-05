#ifndef LAB3_CMD_H
#define LAB3_CMD_H

#include <iostream>
#include <sstream>
#include <cstring>
#include <filesystem>

#include "input.h"
#include "truck/lib_truck.h"

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
    static bool YN(const std::string &message);
    void Run(TruckDataBase &db);
};

#endif //LAB3_CMD_H
