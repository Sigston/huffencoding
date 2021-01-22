#include <fstream>
#include <iostream>
#include <streambuf>
#include <cstring>
#include "Huff.h"

struct Options {
	std::string filePath;
	bool decode;
};

Options processArgs(char* args[]);
void error();

int main(int argc, char* argv[])
{
	Options options;
	if(argc <= 2)
	{
		error();	
		return -1;
	}
	else if(argc >= 3)
	{
		options = processArgs(argv);
		if(options.filePath.empty())
		{
			error();
			return -1;
		}
	}

	// Now we have a valid input data for doing stuff with. We need to read the file and
	// save the contents to a string.
	std::ifstream fstr(options.filePath.c_str());
	std::string inputString((std::istreambuf_iterator<char>(fstr)),
			std::istreambuf_iterator<char>());
	fstr.close();

	// Pass the opened string to the huff and save the resulting string to file.
	std::string outputString;
	Huff huff;
	if(options.decode)
		huff.decode(inputString, outputString);
	else
		huff.encode(inputString, outputString);
	std::ofstream ostr("output.txt");
	ostr << outputString;
	ostr.close();
	
	// Inform the user where the file has been written to.
	std::string operation = (options.decode) ? "decoded" : "encoded";
	std::cout << "Input has been " << operation << " to output.txt." << std::endl;

	return 0;
}	

// Taking in three or more command line args (the first being the name of the program),
// checks if encode or decode is used and if valid filepath. Returns an Options struct.
Options processArgs(char* args[])
{
	Options options = { "", false };
	// Check if valid arg[1]
	if(!(strcmp(args[1], "encode") == 0 || strcmp(args[1], "decode") == 0))
	       return options;	
	// Check if valid arg[2]
	std::ifstream fstr(args[2]);
	if(!fstr.good())
		return options;
	options.filePath = args[2];
	if(args[1] == "decode")
		options.decode = true;
	else
		options.decode = false;
	return options;
}

void error()
{
	std::cout << "Enter encode or decode followed by a valid filepath." << std::endl;
}
