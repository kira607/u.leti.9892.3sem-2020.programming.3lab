#ifndef COURSEWORK_TRUCK_H
#define COURSEWORK_TRUCK_H

#include <string>

struct Truck
{
    int id;
    float capacity;
    int transportation_distance;
    std::string brand;

    Truck *prev;
    Truck *next;

    Truck();
    Truck(const Truck &truck);
};

#endif //COURSEWORK_TRUCK_H
