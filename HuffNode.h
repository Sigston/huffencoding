#ifndef HUFFNODE_H
#define HUFFNODE_H

struct HuffNode {
	char value;
	unsigned weight;
	std::tuple<HuffNode*, HuffNode*> links;
};

#endif
