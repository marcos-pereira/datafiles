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

add_library(CsvFilePrinter
    src/CsvFilePrinter.cpp
)

target_link_libraries(CsvFilePrinter 
)

add_executable(main src/main.cpp)
target_link_libraries(main   
  -lDataFilePrinter  
  -lDataFileReader
  -lCsvFilePrinter
)

install(TARGETS DataFilePrinter 
  # https://stackoverflow.com/questions/21592361/cmake-install-is-not-installing-libraries-on-windows    
	RUNTIME DESTINATION "bin"
  LIBRARY DESTINATION "lib"
	ARCHIVE DESTINATION "lib"
  PUBLIC_HEADER DESTINATION "include/DataFilePrinter"
  PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
)

install(TARGETS DataFileReader 
  # https://stackoverflow.com/questions/21592361/cmake-install-is-not-installing-libraries-on-windows    
	RUNTIME DESTINATION "bin"
  LIBRARY DESTINATION "lib"
	ARCHIVE DESTINATION "lib"
  PUBLIC_HEADER DESTINATION "include/DataFileReader"
  PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
)

install(TARGETS CsvFilePrinter 
  # https://stackoverflow.com/questions/21592361/cmake-install-is-not-installing-libraries-on-windows    
	RUNTIME DESTINATION "bin"
  LIBRARY DESTINATION "lib"
	ARCHIVE DESTINATION "lib"
  PUBLIC_HEADER DESTINATION "include/DataFileReader"
  PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
)

install(FILES
    include/DataFilePrinter.h    
    DESTINATION "include/DataFilePrinter")

install(FILES
    include/DataFileReader.h    
    DESTINATION "include/DataFileReader")

install(FILES
    include/CsvFilePrinter.h    
    DESTINATION "include/CsvFilePrinter")

INSTALL(FILES
    src/DataFilePrinter.cpp    
    DESTINATION "src/DataFilePrinter")

INSTALL(FILES
    src/DataFileReader.cpp    
    DESTINATION "src/DataFileReader")

INSTALL(FILES
    src/CsvFilePrinter.cpp    
    DESTINATION "src/CsvFilePrinter")