#pragma once
#include "Node.h"
#include <iostream>

class LinkedList {
public:
	Node * head;					//head is pointer which point to dummy node
	Node * tail;
	int Count;

	LinkedList() : Count(0) {
		head = tail = new Node();	//create dummy node
	}

	~LinkedList() {
		Clear();
		delete head;
	}

	bool IsEmpty() {
		return Count == 0;
	}

	void PushBackByNode(Node * curNode, Data newData) {
		Node * newNode = new Node(newData);
		Node * nextNode = curNode->nNode;

		curNode->nNode = newNode;
		newNode->pNode = curNode;

		newNode->nNode = nextNode;
		if(nextNode != null) nextNode->pNode = newNode;

		if (curNode == tail) tail = newNode;

		Count++;
	}

	void PushBack(Data newData) {
		PushBackByNode(tail, newData);
	}

	void PushFront(Data newData) {
		PushBackByNode(head, newData);
	}

	Node * DeleteByNode(Node * curNode) {
		if (IsEmpty()) {
			printf("list is empty");
			return null;
		}

		Node * prevNode = curNode->pNode;
		Node * nextNode = curNode->nNode;

		prevNode->nNode = nextNode;
		if(nextNode != null) nextNode->pNode = prevNode;

		if (curNode == tail) tail = prevNode;

		delete curNode;
		Count--;

		return nextNode;
	}

	void PopFront() {
		DeleteByNode(head->nNode);
	}

	void PopBack() {
		DeleteByNode(tail);
	}

	void Clear() {
		if (IsEmpty()) return;
		Node * ptr = head->nNode;
		while (ptr != null) {
			ptr = DeleteByNode(ptr);
		}
	}

	void PrintAllData() {
		Node * ptr = head->nNode;
		while (ptr != null) {
			printf("id : %5d, date : %9d\n", ptr->data.id, ptr->data.date);
			ptr = ptr->nNode;
		}
	}
};

