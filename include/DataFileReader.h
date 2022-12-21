#ifndef DATAFILEREADER_H_
#define DATAFILEREADER_H_

#include <iostream>
#include <vector>
// #include <boost/filesystem.hpp>
// #include <sstream>
#include <fstream>
#include <sstream>
#include <memory>
// #include <unordered_map>
#include <map>

class DataFileReader {
protected:
private:    
    // Map string to datafile ofstream
    std::map<std::string, std::fstream> datafiles_;    

public:
    DataFileReader();
    virtual ~DataFileReader();

    void AddDataFile(std::string filename);
    std::vector<std::string> ReadFromFile(std::string filename);
    std::vector<std::string> SplitString(std::string string_to_split);
    void CloseDataFiles();
};

#endif