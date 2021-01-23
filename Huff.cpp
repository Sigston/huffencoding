#include <string>
#include <cctype>
#include <map>
#include <iostream>
#include "Huff.h"

// From a string of text, produces a binary string with tree and encoded data.
void Huff::encode(const std::string& input, std::string& output)
{
	// Count the occurence of letters in the text.
	std::map<char, unsigned> letterCount;
	for(const auto &c : input)
	{
		auto it = letterCount.find(c);
		if(it == letterCount.end())
			letterCount[c] = 1;
		else
			letterCount[c]++;
	}
	// Construct the tree in memory.
	m_tree.createFromMap(letterCount);

	// Translate the input stream into encoded binary in a buffer.
	std::string buffer;
	for(const auto &c : input)
	{
		buffer.append(1, m_tree.encodeChar(c));
	}
	// Write the tree and buffer to the output string.	
	std::string treeData(m_tree.treeToFile());
	output = std::string(treeData + buffer);
}

// From a valid string of tree and encoded data, produces a decoded string.
bool Huff::decode(const std::string& input, std::string& output)
{
	// Check whether we can create a HuffTree from the input string.
	size_t loc = input.find(m_tree.getTerminator());
	if(loc == std::string::npos)
		return false;
	if(!m_tree.createFromString(input.substr(0, loc)))
		return false;
	std::string buffer;
	for(const auto &c : input.substr(loc + 1))
	{
		buffer.append(1, m_tree.decodeChar(c));
	}
	output = buffer;
	return true;
}
