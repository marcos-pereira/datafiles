#ifndef DATAFILEPRINTER_H_
#define DATAFILEPRINTER_H_

#include <iostream>
#include <vector>
// #include <boost/filesystem.hpp>
// #include <sstream>
#include <fstream>
#include <memory>
// #include <unordered_map>
#include <map>

class DataFilePrinter {
protected:
private:    
    // Map string to datafile ofstream
    std::map<std::string, std::ofstream> datafiles_;    

public:
    DataFilePrinter();
    virtual ~DataFilePrinter();

    void AddDataFile(std::string filename);
    void WriteToFile(std::string filename, std::string text);
    void CloseDataFiles();
};

#endif