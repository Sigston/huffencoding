#ifndef HUFFTREE_H
#define HUFFTREE_H
#include <map>
#include <vector>
#include "HuffNode.h"

class HuffTree {
public:
	// Con/Des
	HuffTree() = default;
	HuffTree(const std::map<char, unsigned>& letterCount);
	~HuffTree();
	// Creation methods
	bool createFromMap(const std::map<char, unsigned>& letterCount);
	bool createFromString(const std::string& binaryTree);
	std::string treeToFile();
	// Encoding methods
	char encodeChar(const char input);
	char decodeChar(const char input);
	// Get and set
	char getTerminator() { return m_treeTerminator; };
	bool isVoid() { return m_allNodes.empty(); };
private:
	// Private member functions
	bool verifyTree();
	void wipeTree();
private:
	// HuffTree stores a vector of all nodes created. This is used for quick deletion.
	// All member functions access m_nodes[0] and traverse the tree using node functions.
	std::vector<HuffNode> m_allNodes;
	char m_treeTerminator = '\0';
};

#endif
