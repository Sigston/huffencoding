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
		wipeTree();
}

HuffTree::~HuffTree()
{
	wipeTree();
}

// Creation methods
//

bool HuffTree::createFromMap(const std::map<char, unsigned>& letterCount)
{
	// 1. Populate the member vector with nodes with no links.
	for(const auto& [value, weight] : letterCount)
		m_allNodes.push_back( { std::string(1, value), weight, { nullptr, nullptr } } );
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
		for(auto ptr : ptrVec)
			std::cout << "Value: " << ptr->value << " Weight: " << ptr->weight << std::endl;
		std::cout << "ptrVec[0]->value: " << ptrVec[0]->value << " ptrVec[1]->value: " << ptrVec[1]->value <<
		       " m_allNodes.back().value: " << m_allNodes.back().value << std::endl;
		m_allNodes.push_back( { ptrVec[0]->value + ptrVec[1]->value, 
				ptrVec[0]->weight + ptrVec[1]->weight, { ptrVec[0], ptrVec[1] } } );
		std::cout << "ptrVec[0]->value: " << ptrVec[0]->value << " ptrVec[1]->value: " << ptrVec[1]->value <<
		       " m_allNodes.back().value: " << m_allNodes.back().value << std::endl;
		ptrVec.erase(ptrVec.begin(), ptrVec.begin() + 2);
		std::cout << "ptrVec[0]->value: " << ptrVec[0]->value << " ptrVec[1]->value: " << ptrVec[1]->value <<
		       " m_allNodes.back().value: " << m_allNodes.back().value << std::endl;
		if((ptrVec.empty())|| (m_allNodes.back().weight > ptrVec.back()->weight))
		{
			ptrVec.push_back(&m_allNodes.back());
		std::cout << "ptrVec[0]->value: " << ptrVec[0]->value << " ptrVec[1]->value: " << ptrVec[1]->value <<
		       " m_allNodes.back().value: " << m_allNodes.back().value << std::endl;
		}
		else
		{
			for(auto it = ptrVec.begin(); it != ptrVec.end(); it++)
			{
				if((*it)->weight >= m_allNodes.back().weight)
				{
					ptrVec.insert(it, &m_allNodes.back());
		std::cout << "ptrVec[0]->value: " << ptrVec[0]->value << " ptrVec[1]->value: " << ptrVec[1]->value <<
		       " m_allNodes.back().value: " << m_allNodes.back().value << std::endl;
					break;
				}
			}
		std::cout << "ptrVec[0]->value: " << ptrVec[0]->value << " ptrVec[1]->value: " << ptrVec[1]->value <<
		       " m_allNodes.back().value: " << m_allNodes.back().value << std::endl;
		}
		std::cout << "ptrVec[0]->value: " << ptrVec[0]->value << " ptrVec[1]->value: " << ptrVec[1]->value <<
		       " m_allNodes.back().value: " << m_allNodes.back().value << std::endl;
		std::cout << " ======================= " << std::endl;
	}
	return true;
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
