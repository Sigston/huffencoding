#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "HuffTree.h"
#include "HuffNode.h"

// Constructors
//

HuffTree::HuffTree(const std::map<char, unsigned>& letterCount)
{
	if(!createFromMap(letterCount))
	{
		wipeTree();
	}
}

HuffTree::~HuffTree()
{
	wipeTree();
}

// Creation methods
//

bool HuffTree::createFromMap(const std::map<char, unsigned>& letterCount)
{
	// 1. Populate the member vector with nodes.
	for(const auto& [value, weight] : letterCount)
	{
		m_allNodes.push_back( { value, weight, { nullptr, nullptr } } );
	}
	// 2. Copy this structure into a temp vec of ptrs. We will use this for workings out.
	std::vector<HuffNode*> ptrVec;
	for(auto& node : m_allNodes)
		ptrVec.push_back(&node);
	// 3. Sort the vec of ptrs by reverse weight.
	std::sort(std::begin(ptrVec), std::end(ptrVec), 
			[](HuffNode* i, HuffNode* j) { return i->weight < j->weight; }); 
	// 4. Take the first two items from the vec of ptrs and create a new node equal to their combined weight.
	// 	This node is inserted properly into the member vector and at the right place in the 
	// 	vec of ptrs. The two items used are removed from the vec of ptrs.
	while(ptrVec.size() > 1)
	{
		ptrVec
	}
	// 5. Keep doing (4) until there is only one node left. This is the start node and must be placed at
	//
	//	the beginning of the member vector.
	// 6. Verify the HuffTree. 
	if(verifyTree())
		return true;
	else
		return false;
}

bool HuffTree::createFromString(const std::string& binaryTree)
{
	return true;
}

std::string HuffTree::treeToFile()
{
	return std::string();
}

// Encoding methods
//

char HuffTree::encodeChar(const char input)
{
	return 'a';
}

char HuffTree::decodeChar(const char input)
{
	return 'a';
}

// Private member funcs
//

// Verifies if the HuffTree contains a sensible data structure.
bool HuffTree::verifyTree()
{
	// m_allNodes is either empty or has the starting node.
	if(isVoid())
		return false;
	// Run through the nodes from the starting node and verify the nodes
	//accessed = the size of the member vector.
	return true;
}

// Destroys any data structure in the HuffTree.
void HuffTree::wipeTree()
{
	m_allNodes.clear();
}
