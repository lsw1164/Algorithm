#include <iostream>
#define NULL 0

using namespace std;

typedef struct DATA {
	int var;
	struct DATA() : var(NULL) {}
	struct DATA(int _var) : var(_var) {}
	struct DATA(struct DATA & _data) {
		this->var = _data.var;
	}
	bool operator == (const struct DATA & other) {
		return this->var == other.var;
	}
}Data;

class Node {
public :
	string key;
	Node * next;
	Node * prev;
	Data data;
	Node() : key(""), next(NULL), prev(NULL) {}
	Node(Data & _data) :key(""), next(NULL), prev(NULL), data(_data) {}
	Node(Data & _data, string _key) :key(_key), next(NULL), prev(NULL), data(_data) {}
};

class LinkedList {
private :
public :
	Node * head; // dummy
	Node * tail;
	int count;
	LinkedList() : count(0) {
		head = tail = new Node();
	}
	~LinkedList() {
		Clear();
		delete head;
	}
	bool IsEmpty() { return count == 0; }
	void PushBack(Data & data, string key = "") {
		Node * newNode = new Node(data, key);

		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;

		count++;
	}

	Node * DeleteNode(Node * delNode) {
		if (!IsEmpty()) {
			puts("Empty !");
			return NULL;
		}
		Node * prevNode = delNode->prev;
		Node * nextNode = delNode->next;

		prevNode->next = nextNode;

		if (delNode != tail) { //if the node wil be deleted is tail, nextNode is null...
			nextNode->prev = prevNode;
		}
		count--;
		//return next of delNode 
		return nextNode;
	}

	void Clear() {
		Node * cur = head->next;
		while (cur != NULL) {
			cur = DeleteNode(cur);
		}
	}
};

class HashTable {
private :
	LinkedList ** table;
public :
	int tableSize;
	int count;
	HashTable(int _tableSize) : tableSize(_tableSize), count(0) {
		table = new LinkedList * [tableSize];
		for (int i = 0; i < tableSize; i++) {
			table[i] = NULL;
		}
	}
	~HashTable() {
		for (int i = 0; i < tableSize; i++) {
			delete table[i];
		}
		delete[] table;
	}

	int HashFunction(string key) {
		int hashcode = 0;
		for (char ch : key) {
			hashcode += (int)ch;
		}
		return hashcode;
	}

	int convertToIdx(string key) {
		return HashFunction(key) & tableSize;
	}

	void Put(string key, Data & value) {
		int idx = convertToIdx(key);
		LinkedList* & list = table[idx];
		if (list == NULL) {
			list = new LinkedList();
		}
		list->PushBack(value, key);
		this->count++;
	}

	Node * Search(string key, Data & value) {
		int idx = convertToIdx(key);
		LinkedList* & list = table[idx];
		if (list == NULL || list->IsEmpty()) {
			puts("there is no data");
			return NULL;
		}
		Node * cur = list->head->next;
		while (cur != NULL) {
			if (cur->data == value) {
				puts("success searching!");
				return cur;
			}
		}
		puts("fail : there is no data you tried to search...");
		return NULL;
	}

	bool Remove(string key, Data & value) {
		int idx = convertToIdx(key);
		LinkedList * list = table[idx];
		if (list == NULL || list->IsEmpty()) {
			puts("there is no data");
			return false;
		}
		Node * cur = list->head->next;
		while (cur != NULL) {
			if (cur->data == value) {
				list->DeleteNode(cur);
				puts("success Delete!");
				count--;
				return true;
			}
		}
		puts("fail : there is no data you tried to delete...");
		return false;
	}
};

int main(void) {
	HashTable * ht = new HashTable(100);

	puts("----------put Test----------");
	ht->Put("hi", Data(1));
	ht->Put("hello", Data(2));
	ht->Put("world", Data(3));

	puts("----------Search Test----------");
	Node * searchedNode = ht->Search("hi", Data(1));
	printf("data : %d\n", searchedNode->data.var);
	searchedNode = ht->Search("hello", Data(2));
	printf("data : %d\n", searchedNode->data.var);
	searchedNode = ht->Search("world", Data(3));
	printf("data : %d\n", searchedNode->data.var);

	puts("----------Delete Test----------");
	printf("before deleting... count : %d\n\n", ht->count);
	ht->Remove("hi", Data(1));
	ht->Remove("hello", Data(2));
	ht->Remove("world", Data(3));

	printf("after deleting... count : %d\n\n", ht->count);

	return 0;
}
