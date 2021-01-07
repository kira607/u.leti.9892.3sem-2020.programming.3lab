cmake_minimum_required(VERSION 3.15)
project(Lab3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")

set(CSV fast-cpp-csv-parser/csv.h)

set(TRUCK
        truck.cpp
        truck.h
        truck_list.cpp
        truck_list.h
        truck_db.cpp
        truck_db.h
)

set(SOURCE_FILES main.cpp ${TRUCK} cmd.cpp cmd.h ${CSV} input.cpp input.h)

add_executable(Lab3 ${SOURCE_FILES})
