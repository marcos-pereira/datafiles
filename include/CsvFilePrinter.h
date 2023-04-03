#ifndef CSVFILEPRINTER_H_
#define CSVFILEPRINTER_H_

#include <iostream>
#include <vector>
// #include <boost/filesystem.hpp>
// #include <sstream>
#include <fstream>
#include <memory>
// #include <unordered_map>
#include <map>

class CsvFilePrinter
{
private:
    // Map string to file pointer fstream
    std::map<std::string, std::fstream> datafiles_;    

public:
    CsvFilePrinter();
    virtual ~CsvFilePrinter();

    void AddDataFile(std::string filename);
    void WriteToFile(std::string filename, std::string text);
    void CloseDataFiles();
};

#endif