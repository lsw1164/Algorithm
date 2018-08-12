#pragma once
#include "Data.h"
#define null 0

class Node {
public:
	Data data;
	Node * pNode;
	Node * nNode;
	Node(): nNode(null), pNode(null) {}
	Node(Data _data) : data(_data), nNode(null), pNode(null) {}
	~Node(){}
};

