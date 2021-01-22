#include <string>
#include <cctype>
#include <map>
#include "Huff.h"
#include <iostream>

void Huff::encode(const std::string& input, std::string& output)
{
	// Count the occurence of letters in the text.
	std::map<char, int> letterCount;
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
		buffer.append(m_tree.encodeChar(c));
	}
	// Write the tree and buffer to the output string.	
	std::string treeData(m_tree.toFile());
	output = std::string(treeData + buffer);
}

bool Huff::decode(const std::string& input, std::string& output)
{
	std::string treeData = 
	if(treeData.empty())
		return false;

	output = input;
	return true;
}

