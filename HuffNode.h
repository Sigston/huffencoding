#ifndef HUFFNODE_H
#define HUFFNODE_H
#include <string>

struct HuffNode {
	std::string value;
	unsigned weight;
	std::pair<HuffNode*, HuffNode*> links;
};

#endif
