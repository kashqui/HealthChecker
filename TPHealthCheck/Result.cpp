#include <fstream>
#include <string>

// File in which result to be written.
const std::string OUTPUT_FILE = "c:\\ProductivityReport\\Setting\\RPC\\tp.txt";

// Handling results.
class Result
{
public:
	void Result::exportResult(std::string msg)
	{
		// Overwrite text file.
		std::ofstream ofs(OUTPUT_FILE);
		ofs << msg << std::endl;
	}
};