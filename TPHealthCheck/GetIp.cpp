#using <mscorlib.dll>
#include <fstream>
#include <string>

// File in which IP address to check is written.
const std::string IP_FILE = "c:\\Report\\Setting\\RPC\\ip.txt";

// Handling results.
class GetIp
{
public:
	System::String^ GetIp::getIp()
	{
		System::String^ ret;
		// Read text file.
		std::ifstream ifs(IP_FILE);
		for (std::string line; getline(ifs, line);)
		{
			System::String^ str = gcnew System::String(line.c_str());
			ret += str + ";";
		}
		return ret;
	}
};