#include <iostream>
#include "Data.h"
#define null 0
using namespace std;

class Node {
public:
	Data * data;
	Node * pNode;
	Node * nNode;
	Node() : data(null), nNode(null), pNode(null) {}
	Node(Data * _data) : data(_data), nNode(null), pNode(null) {}
	~Node() {}
};