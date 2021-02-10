#include <iostream>
#include "Huff.h"
#include "Program.h"

int main(int argc, char* argv[])
{
	Program::Options options;
	if(argc <= 2)
	{
		Program::error();
		return -1;
	}
	else if(argc >= 3)
	{
		options = Program::processArgs(argv);
		if(options.filePath.empty())
		{
			Program::error();
			return -1;
		}
	}

	// Now we have a valid input data for doing stuff with. We need to read the file and
	// save the contents to a string.
	std::string inputString(Program::ReadFile(options.filePath.c_str()));

	// Pass the opened string to the huff and save the resulting string to file.
	std::string outputString;
	Huff huff;
	if(options.decode)
		huff.decode(inputString, outputString);
	else
		huff.encode(inputString, outputString);
	Program::SaveFile(outputString);

	// Inform the user where the file has been written to.
	std::string operation = (options.decode) ? "decoded" : "encoded";
	std::cout << "Input has been " << operation << " to output.txt." << std::endl;

	return 0;
}	

