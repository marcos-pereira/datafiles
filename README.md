# Compiling and running
1. Clone the repository.
2. Change to the repository home folder:
```
cd ~/path_to_repo/datafiles
```
3. Create a build folder and change to it:
```
mkdir build
cd build
```
4. Run cmake:
```
cmake -G "Unix Makefiles" ../
```
5. Run the make command:
```
make
```
6. Run the compiled executable:
```
./main
```
The result should be the creation of file1.txt and file2.txt with some example text written to it.


# datafileprinter
The DataFilePrinter class is a C++ class that allow to create and open files and print data to them. 

## How to use the class DataFilePrinter
1. Include the library to your code:
```
#include "path_to_repo/include/DataFilePrinter.h"
```
2. Declare the object of the class:
```
DataFilePrinter datafile_printer;
```
3. Add the files you want to create and open:
```
std::string file1 = "file1.txt";
datafile_printer.AddDataFile(file1_name);

std::string file2 = "file2.txt";
datafile_printer.AddDataFile(file2_name);
...
```
4. Write text to the files:
```
std::string text1_to_file1 = "Hello world!";
text1_to_file1 += "\n";
datafile_printer.WriteToFile(file1_name, text1_to_file1);
...
```
5. After writing everything you need to the files, close them:
```
datafile_printer.CloseDataFiles();
```
Check the `main.cpp` under the `src` folder for a minimal example.

# datafilereader
The DataFileReader class is a C++ class that allow to open files and read data from them. 

## How to use the class DataFileReader
1. Include the library to your code:
```
#include "path_to_repo/include/DataFileReader.h"
```
2. Declare the object of the class:
```
DataFileReader datafile_reader;
```
3. Add the files you want to read from:
```
std::string file1 = "file1.txt";
datafile_reader.AddDataFile(file1_name);
...
```
4. Read file lines from file:
```
std::vector<std::string> file1_lines = datafile_reader.ReadFromFile(file1_name);
...
```
5. After reading everything you need from the files, close them:
```
datafile_reader.CloseDataFiles();
```
Check the `main.cpp` under the `src` folder for a minimal example.




