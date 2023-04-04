#include "../include/CsvFilePrinter.h"

/**
 * @brief Constructor.
 * 
 */
CsvFilePrinter::CsvFilePrinter(/* args */)
{
}

/**
 * @brief Destroy the Csv File Printer:: Csv File Printer object
 * 
 */
CsvFilePrinter::~CsvFilePrinter()
{
}

/**
 * @brief Add datafile to be created. Datafiles are .csv. 
 * Every datafile added is created.
 * 
 * @param filename 
 */
void CsvFilePrinter::AddDataFile(std::string filename)
{   
    datafiles_.emplace(filename, std::fstream(filename));   
}

/**
 * @brief Write text to datafile.
 * 
 * @param filename Name of the file where the text will be written.
 * @param text Text to be written to file.
 * @param append If desired to append to file set it to true.
*/
void CsvFilePrinter::WriteToFile(std::string filename, std::string text, bool append)
{
    if (append)
    {
        datafiles_[filename].open(filename, std::ios::out | std::ios::app);
    }
    else
    {
        datafiles_[filename].open(filename, std::ios::out);
    }

    if(!datafiles_[filename].is_open())
    {
        std::cerr << "\n\nDatafile " << filename <<  " did not open correctly!\n" << "\n";
        throw std::exception();
    }

    datafiles_[filename] << text;

    datafiles_[filename].close();
}

/**
 * @brief Close all the datafiles.
*/
void CsvFilePrinter::CloseDataFiles()
{
    for( const auto& datafile : datafiles_ )
    {
        datafiles_[datafile.first].close();
        if(datafiles_[datafile.first].is_open())
        {
            std::cerr << "\n\nDatafile " << datafile.first <<  " did not close correctly!\n" << "\n";
            throw std::exception();
        }
    }
}
