#ifndef PROGRAM_H
#define PROGRAM_H
#include <string>

namespace Program {
	struct Options {
		std::string filePath;
		bool decode;
	};
	Options processArgs(char* args[]);
	std::string ReadFile(const char* fileName);
	void SaveFile(const std::string data, const std::string outputFile = "output.txt");
	void error();
}

#endif
