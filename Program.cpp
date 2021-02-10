#include <cstring>
#include <fstream>
#include <iostream>
#include <streambuf>
#include "Program.h"

// Taking in three or more command line args (the first being the name of the program),
// checks if encode or decode is used and if valid filepath. Returns an Options struct.
Program::Options Program::processArgs(char* args[])
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
	if(strcmp(args[1], "decode") == 0)
		options.decode = true;
	else
		options.decode = false;
	return options;
}

std::string Program::ReadFile(const char* fileName)
{
	std::ifstream fstr(fileName);
	std::string result((std::istreambuf_iterator<char>(fstr)), std::istreambuf_iterator<char>());
	fstr.close();
	return result;
}

void Program::SaveFile(const std::string data, const std::string outputFile)
{
	std::ofstream ostr(outputFile.c_str());
	ostr << data;
	ostr.close();
}
void Program::error()
{
	std::cout << "Enter encode or decode followed by a valid filepath." << std::endl;
}
