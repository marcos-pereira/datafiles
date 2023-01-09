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