#include <iostream>
#include <string>

#include "../include/DataFilePrinter.h"
#include "../include/DataFileReader.h"

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

    DataFileReader datafile_reader;

    // Open datafile
    datafile_reader.AddDataFile(file1_name);

    // Read file lines
    std::vector<std::string> file1_lines = datafile_reader.ReadFromFile(file1_name);

    // Print file lines
    for (int line = 0; line < file1_lines.size(); line++)
    {
        std::cout << file1_lines[line] << "\n";
    }    
        
    // Close all datafiles opened
    datafile_reader.CloseDataFiles();

    // Splitted file lines
    std::vector<std::string> splitted_line;

    // Print splitted file lines
    for (int line = 0; line < file1_lines.size(); line++)
    {
        splitted_line = datafile_reader.SplitString(file1_lines[line]);
        for (int element = 0; element < splitted_line.size(); element++)
        {
            std::cout << splitted_line[element] << "\n";
        }
    }    
    
    return 0;
}