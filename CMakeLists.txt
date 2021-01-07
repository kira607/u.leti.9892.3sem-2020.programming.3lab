cmake_minimum_required(VERSION 3.15)
project(Lab3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")

set(CSV fast-cpp-csv-parser/csv.h)

set(TRUCK
        src/truck.cpp
        src/truck.h
        src/truck_list.cpp
        src/truck_list.h
        src/truck_db.cpp
        src/truck_db.h
)

set(CMD 
        src/cmd.cpp 
        src/cmd.h
)

set(INPUT 
        src/input.cpp
        src/input.h
)

set(SOURCE_FILES src/main.cpp ${TRUCK} ${CMD} ${CSV} ${INPUT})

add_executable(Lab3 ${SOURCE_FILES})
