#ifndef COURSEWORK_TRUCK_DB_H
#define COURSEWORK_TRUCK_DB_H

#define CSV_IO_NO_THREAD

#include <iomanip>
#include <fstream>

#include "fast-cpp-csv-parser/csv.h"
#include "truck_list.h"
#include "input.h"

struct TruckDataBase
{
    TruckList list{};

    TruckDataBase() = default;
    void PrintAll() const;
    void Print(int index, bool print_header = false) const;
    void Add();
    void Exit();
    void Load(const std::string& db_path);
    void Save(const std::string& db_path) const;
};

#endif //COURSEWORK_TRUCK_DB_H
