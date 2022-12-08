#include <iostream>
#include <string>

#include "../include/DataFilePrinter.h"

int main(int argc, char **argv)
{
    DataFilePrinter datafile_printer;

    std::string file1_name = "file1.txt";

    // Create and open datafile
    datafile_printer.AddDataFile(file1_name);

    std::string text1_to_file1 = "Hello world!";
    text1_to_file1 += "\n";

    // Write string to datafile
    datafile_printer.WriteToFile(file1_name, text1_to_file1);

    std::string text2_to_file1 = "This is my first datafile!";
    text2_to_file1 += "\n";

    // Write string to datafile
    datafile_printer.WriteToFile(file1_name, text2_to_file1);

    std::string file2_name = "file2.txt";

    // Create and open datafile
    datafile_printer.AddDataFile(file2_name);

    std::string text1_to_file2 = "This is my second datafile!";
    text1_to_file2 += "\n";

    // Write string to datafile
    datafile_printer.WriteToFile(file2_name, text1_to_file2);

    // Close all datafiles opened
    datafile_printer.CloseDataFiles();

    return 0;
}