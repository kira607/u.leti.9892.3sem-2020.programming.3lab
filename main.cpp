#include <iostream>
#include <sstream>

#include "truck/lib_truck.h"
#include "cmd.h"

bool YN(const std::string &message = "");
void RunCommand(TruckDataBase &db, CMD &cmd);

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
        RunCommand(db, cmd);
    }

    db.Exit();
    return 0;
}

bool YN(const std::string &message)
{
    std::string choice;
    Input(choice, message + " (y/n): ");
    return choice == "y";
}

void RunCommand(TruckDataBase &db, CMD &cmd)
{
    switch(cmd.command)
    {
        case Command::Add:
            db.Add();
            break;
        case Command::Load:
        {
            if(db.list.size > 0)
            {
                if(!YN("Loading file will rewrite current list. Continue loading?"))
                    break;
            }
            db.Exit();
            try
            {
                std::string file;
                Input(file, "Path to file: ");
                db.Load(file);
            }
            catch (const std::exception &e)
            {
                std::cout << "Error loading: " << e.what() << ". Loading aborted.\n";
            }
        }
            break;
        case Command::Save:
        {
            std::string file;
            Input(file, "Path to file: ");
            if(std::filesystem::is_directory(file))
            {
                std::cout << "'" << file << "' is a directory.\n";
                break;
            }
            if(!std::filesystem::exists(file))
            {
                db.Save(file);
                break;
            }
            std::cout << "File '" << file << "' exists already\n";
            if(!YN("Rewrite it?"))
            {
                std::cout << "Saving aborted\n";
                break;
            }
            std::cout << "Saving...\n";
            db.Save(file);
            std::cout << "Saved\n";
        }
            break;
        case Command::Print:
        {
            if (db.list.size == 0)
            {
                std::cout << "Nothing to print. Try 'add'.\n";
                break;
            }
            int index;
            Input(index, "Index: ");
            try
            {
                db.Print(index, true);
            }
            catch (const std::exception &e)
            {
                std::cout << e.what() << "\n";
            }
        }
            break;
        case Command::PrintAll:
            if (db.list.size == 0)
            {
                std::cout << "Nothing to print. Try 'add'.\n";
                break;
            }
            db.PrintAll();
            break;
        case Command::Help:
        {
            std::cout << "\nCommands:\n";
            std::cout << "  add - add new item in list\n";
            std::cout << "  load - load list from file\n";
            std::cout << "  save - save list in file\n";
            std::cout << "  print - print item by index\n";
            std::cout << "  printall - print all items\n";
            std::cout << "  help - see this help\n";
            std::cout << "  exit - exit program\n\n";
        }
            break;
        case Command::Exit:
        case Command::Skip:
            break;
        case Command::NONE:
            std::cout << "Unknown command '" << cmd.command_str << "'. Try 'help'\n";
            break;
    }
}