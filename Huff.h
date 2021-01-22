#ifndef HUFF_H
#define HUFF_H
#include <string>
#include "HuffTree.h"

class Huff {
public:
	// Takes a string of text and encodes that text into output.
	void encode(const std::string& input, std::string& output);
	// Takes a properly formatted input string and outputs a decoded version. Returns
	// false if the input string is not properly formatted.
	bool decode(const std::string& input, std::string& output);
private:
	// Private helper functions.
private:
	// Private members
	HuffTree m_tree;
};

#endif
