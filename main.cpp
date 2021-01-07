#include "cmd.h"

int main()
{
    TruckDataBase db{};
    Command command;
    Cmd cmd;

    do
    {
        command = cmd.Get();
        cmd.Run(db);
    } while(command != Command::Exit);

    db.Exit();
    return 0;
}