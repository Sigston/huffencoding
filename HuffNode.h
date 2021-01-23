#ifndef HUFFNODE_H
#define HUFFNODE_H

struct HuffNode {
	unsigned weight;
	char value;
	std::tuple<HuffNode*, HuffNode*> links;
};

#endif
