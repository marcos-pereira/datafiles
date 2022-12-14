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

#include "../include/DataFilePrinter.h"

/**
 * @brief Class constructor
 * 
*/
DataFilePrinter::DataFilePrinter()
{
}

/**
 * @brief Class destructor
 * 
*/
DataFilePrinter::~DataFilePrinter()
{    
}

/**
 * @brief Add datafile to be created. Datafiles are .txt. 
 * Every datafile added is created.
 * 
 * @param filename Name of the file to be created.
*/
void DataFilePrinter::AddDataFile(std::string filename)
{   
    datafiles_.emplace(filename, std::ofstream(filename));   
}

/**
 * @brief Write text to datafile.
 * 
 * @param filename Name of the file where the text will be written.
 * @param text Text to be written to file.
*/
void DataFilePrinter::WriteToFile(std::string filename, std::string text)
{
    datafiles_[filename] << text;
}

/**
 * @brief Close all the datafiles.
*/
void DataFilePrinter::CloseDataFiles()
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



