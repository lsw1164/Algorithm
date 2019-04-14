#include <iostream>
#define null 0
using namespace std;

template <typename T>
class Node {
	public:
		Node<T> * next;
		Node<T> * prev;
		T data;
		Node<T>() : next(null), prev(null) {}
		Node<T>(T _data) : next(null), prev(null), data(_data) {}
		~Node<T>() {}	
};

template <typename T>
class LinkedList {
	public:
		Node<T> * dummy;
		Node<T> * tail;
		int count;
		LinkedList<T>() {
			dummy = tail = new Node<T>();
			count = 0;
		}
		~LinkedList<T>(){
			Clear();
		}

		bool IsEmpty() {
			return count == 0;
		}

		void PushByNode(Node<T> * curNode, T _data) {
			Node<T> * nextNode = curNode->next;
			Node<T> * newNode = new Node<T>(_data);

			curNode->next = newNode;
			newNode->prev = curNode;

			newNode->next = nextNode;
			if(curNode != tail) {
				nextNode->prev = newNode;
			} else {
				tail = newNode;
			}
			count++;
		}

		void PushBack(T _data) {
			PushByNode(tail, _data);
		}

		void PushFront(T _data) {
			PushByNode(dummy, _data);
		}

		Node<T> * DeleteByNode(Node<T> * curNode) {

			if(IsEmpty()) {
				return null;
			}

			Node<T> * beforeNode = curNode->prev;
			Node<T> * nextNode = curNode->next;

			beforeNode->next = nextNode;
			if(curNode != tail) {
				nextNode->prev = beforeNode;
			} else {
				tail = beforeNode;
			}
			delete curNode;
			count--;
			return nextNode;
		}

		T PopFront() {
			T data = dummy->next->data;
			DeleteByNode(dummy->next);
			return data;
		}

		T PopBack() {
			T data = tail->data;
			DeleteByNode(tail);
			return data;
		}

		void Clear() {
			Node<T> * curNode = dummy->next;
			while(curNode != null) {
				curNode = DeleteByNode(curNode);
			}
		}

		void Print() {
			cout << "\n-------------------------------\n";
			Node<T> * curNode = dummy->next;
			while(curNode != null) {
				cout << curNode->data << " ";
				curNode = curNode->next;
			}
			cout << ", count : " << count;
			cout << "\n-------------------------------\n";
		}
};

int main(void) {
	LinkedList<int> list;
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushBack(8);
	list.Print();
	list.PopBack();
	list.PopBack();
	list.PopBack();
	list.Print();
	list.PushFront(11);
	list.PushFront(22);
	list.PushFront(33);
	list.Print();
	list.PopFront();
	list.PopFront();
	list.Print();
}
