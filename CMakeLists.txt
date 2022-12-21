cmake_minimum_required(VERSION 3.8)
project(datafileprinter)

add_library(DataFilePrinter
    src/DataFilePrinter.cpp
)

target_link_libraries(DataFilePrinter
)

add_library(DataFileReader
    src/DataFileReader.cpp
)

target_link_libraries(DataFileReader
)

add_executable(main src/main.cpp)
target_link_libraries(main   
  DataFilePrinter  
  DataFileReader
)