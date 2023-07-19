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
    void WriteToFile(std::string filename, std::string text, bool overwrite = false, bool close = false);
    void CloseDataFiles();
};

#endif