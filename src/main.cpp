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

#include <iostream>
#include <string>

#include <DataFilePrinter/DataFilePrinter.h>
#include <DataFileReader/DataFileReader.h>
#include <CsvFilePrinter/CsvFilePrinter.h>

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
    datafile_reader.AddDataFile(file2_name);

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
    
    // CSV File
    CsvFilePrinter csv_file_printer;
    bool append_to_csv_file = true;

    std::string file3_csv_name = "file3.csv";
    
    // Create and open datafile
    csv_file_printer.AddDataFile(file3_csv_name);

    std::string text1_to_file3 = "My special variable 1,My special variable 2,My special variable 3,My special variable 4";    
    text1_to_file3 += "\n";

    // Write string to datafile
    csv_file_printer.WriteToFile(file3_csv_name, text1_to_file3, append_to_csv_file);

    std::string text2_to_file3 = "3.142,2.718,my value,my other value";    
    text2_to_file3 += "\n";

    // Write string to datafile
    csv_file_printer.WriteToFile(file3_csv_name, text2_to_file3, append_to_csv_file);

    // Close all datafiles opened
    csv_file_printer.CloseDataFiles();

    DataFileReader datafile_reader2;

    // Open datafile
    datafile_reader2.AddDataFile(file3_csv_name);

    // Read file lines
    std::vector<std::string> file3_lines = datafile_reader2.ReadFromCsvFile(file3_csv_name);

    // Print file lines
    for (int line = 0; line < file3_lines.size(); line++)
    {
        std::cout << file3_lines[line] << "\n";
    }        

    // Close all datafiles opened
    datafile_reader2.CloseDataFiles();

    return 0;
}