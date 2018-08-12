#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(void) {

	LinkedList list;
	list.PushFront(Data(0, 20000000));
	list.PushFront(Data(1, 20010000));
	list.PushFront(Data(2, 20020000));
	list.PushFront(Data(3, 20030000));
	list.PushBack(Data(4, 20040000));
	list.PushBack(Data(5, 20050000));
	list.PushBack(Data(6, 20060000));
	list.PushBack(Data(7, 20070000));

	printf("count : %d\n", list.Count);
	list.PrintAllData();

	puts("----------------------------");
	list.PopBack();
	list.PopBack();
	list.PopFront();

	printf("count : %d\n", list.Count);
	list.PrintAllData();


	return 0;
}