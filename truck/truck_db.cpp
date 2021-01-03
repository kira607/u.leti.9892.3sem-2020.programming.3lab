#include "truck_db.h"

void TruckDataBase::PrintAll() const
{
    std::cout << std::left
              << std::setw(4)  << "id "
              << std::setw(14) << "brand "
              << std::setw(10)  << "capacity "
              << std::setw(5)  << "transportation_distance\n";
    for(int i = 0; i < list.size; ++i)
    {
        Print(i);
    }
}

void TruckDataBase::Print(int index, bool print_header) const
{
    list._check_index(index);
    auto p = list.Get(index);
    if(print_header)
    {
        std::cout << std::left
                  << std::setw(4) << "id "
                  << std::setw(14) << "brand "
                  << std::setw(10) << "capacity "
                  << std::setw(5) << "transportation_distance\n";
    }
    std::cout << std::left
              << std::setw(3)  << p-> id << " "
              << std::setw(13) << p->brand << " "
              << std::setw(9)  << p->capacity << " "
              << std::setw(5)  << p->transportation_distance << "\n";
}

void TruckDataBase::Edit(int index)
{
    list._check_index(index);
    Truck *target_element = list.Get(index);
    while(true)
    {
        std::cout << "------------------------\n";
        Print(index);
        std::cout << "------------------------\n";
        std::cout << "Choose filed:\n";
        std::cout << "1 brand" << "\n";
        std::cout << "2 capacity" << "\n";
        std::cout << "3 distance" << "\n";
        std::cout << "0 Finish edit" << "\n";

        int option;
        Input(option, "CMD: ");

        switch (option)
        {
            case 1:
                Input(target_element->brand, "New value: ");
                break;
            case 2:
                Input(target_element->capacity, "New value: ");
                break;
            case 3:
                Input(target_element->transportation_distance, "New value: ");
                break;
            case 0:
                return;
            default: std::cout << "\nIncorrect input\n\n";
        }
    }
}

void TruckDataBase::Add()
{
    Truck new_element;
    new_element.id = list.size > 0 ? list.Get(list.size-1)->id + 1 : 0;
    Input(new_element.brand, "brand: ");
    Input(new_element.capacity, "capacity: ");
    Input(new_element.transportation_distance, "transportation distance: ");
    list.Add(new_element);
}

void TruckDataBase::Delete(int index)
{
    list.Delete(index);
    for(int i = index; i < list.size; ++i)
    {
        list.Get(i)->id = i;
    }
}

void TruckDataBase::Exit()
{
    list.Free();
}

void TruckDataBase::Load(const std::string& db_path)
{
    Truck truck{};

    io::CSVReader<4> in(db_path);
    in.read_header(io::ignore_extra_column, "id", "brand", "capacity", "transportation_distance");
    while(in.read_row(truck.id, truck.brand, truck.capacity, truck.transportation_distance))
    {
        list.Add(truck);
    }
}

void TruckDataBase::Save(const std::string& db_path) const
{
    std::ofstream fout(db_path, std::ios_base::trunc);
    fout << "id,brand,capacity,transportation_distance\n";

    Truck *p = list.head;
    while(p)
    {
        fout << p->id << ","
             << p->brand << ","
             << p->capacity << ","
             << p->transportation_distance;
        fout << "\n";
        p = p->next;
    }
}


