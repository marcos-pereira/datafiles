/*   This code is distributed WITHOUT ANY WARRANTY, without the implied
*   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*   See the GNU Lesser General Public License for more details.
*   
*   The license is distributed along with this repository or you can check
*   <http://www.gnu.org/licenses/> for more details.
*
* Contributors: 
* marcos-pereira (https://github.com/marcos-pereira)
*/

#include "../include/DataFileReader.h"

/**
 * @brief Class constructor
 * 
*/
DataFileReader::DataFileReader()
{
}

/**
 * @brief Class destructor
 * 
*/
DataFileReader::~DataFileReader()
{    
}

/**
 * @brief Add datafile to be read. Datafiles are .txt. 
 * 
 * @param filename Name of the file to be created.
*/
void DataFileReader::AddDataFile(std::string filename)
{   
    datafiles_.emplace(filename, std::fstream(filename));   
}

/**
 * @brief Read text from datafile.
 * 
 * @param filename Name of the file where the text will be written.
 * @param text Text to be written to file.
*/
std::vector<std::string> DataFileReader::ReadFromFile(std::string filename)
{    
    std::vector<std::string> file_lines;

    if (datafiles_[filename].is_open())
    {
        std::string file_line;  
        while(getline(datafiles_[filename], file_line))
        {
            file_lines.push_back(file_line);           
        }        
    }
    else
    {
        std::cerr << "File: " << filename << "\n";
        throw std::runtime_error("File not opened correctly.");
    }
    
    return file_lines;
}

/**
 * @brief Split string that contains strings separated by spaces.
 * 
 * @param string_to_split is the string to be splitted.
*/
std::vector<std::string> DataFileReader::SplitString(std::string string_to_split)
{
    std::stringstream string_streamer(string_to_split);
    
    std::vector<std::string> substrings;
    std::string substring;

    while(string_streamer >> substring)
    {
        substrings.push_back(substring);
    }

    return substrings;
}

/**
 * @brief Close all the datafiles.
*/
void DataFileReader::CloseDataFiles()
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





