#include <iostream>
#include <stdlib.h>
#include <time.h>

#define NULL 0
#define LEN 8 
using namespace std;

typedef struct DATA {
	int originIdx;
	int val;
	bool visit;
	DATA(): originIdx(NULL), val(NULL), visit(false){}
	DATA(int _idx, int _val) : originIdx(_idx), val(_val), visit(false) {}
}Data;

Data * CreateDataList() {
	Data * list = new Data[LEN];
	for (int i = 0; i < LEN; i++) {
		list[i] = Data(i, rand() % 5000);
	}
	return list;
}

void PrintInfo(Data * list) {
	for (int i = 0; i < LEN; i++) {
		printf("Data[%3d] --> originIdx : %3d, val : %5d\n", i, list[i].originIdx, list[i].val);
	}
}

void InitVisit(Data * list, int len) {
	for (int i = 0; i < len; i++) {
		list[i].visit = false;
	}
}

void Merge(Data * list, int from, int to) {
	int len = to - from + 1;
	int mid = (from + to) / 2;
	Data * sortedList = new Data[len];
	int left = from, right = mid + 1;
	for (int i = 0; i < len; i++) {
		if (left > mid) sortedList[i] = list[right++];
		else if (right > to) sortedList[i] = list[left++];
		else if (list[left].val < list[right].val) sortedList[i] = list[left++];
		else sortedList[i] = list[right++];
	}
	for (int i = 0, left = from; i < len; i++, left++) {
		list[left] = sortedList[i];
	}
	delete[] sortedList;
}

void MergeSort(Data * list, int from, int to) {
	if (from >= to) return;
	int mid = (from + to) / 2;
	MergeSort(list, from, mid);
	MergeSort(list, mid+1, to);
	Merge(list, from, to);
}

int binarySearch(Data * list, int minkey, int maxkey, int from, int to) {

	if (from > to) return -1;
	int mid = (from + to) / 2;

	if (minkey <= list[mid].val && list[mid].val <= maxkey) {

		//this key was already searched
		if (list[mid].visit) {

			//find except for current key
			int searchL = binarySearch(list, minkey, maxkey, from, mid - 1);
			if (searchL != -1) return searchL;

			int searchR = binarySearch(list, minkey, maxkey, mid + 1, to);
			if (searchR != -1) return searchR;

			return -1;
		}
		list[mid].visit = true;
		return list[mid].originIdx;

	} else if (maxkey < list[mid].val) {
		return binarySearch(list, minkey, maxkey, from, mid - 1);
	} else {
		return binarySearch(list, minkey, maxkey, mid + 1, to);
	}
}

int main(void) {
	srand(time(NULL));
	Data * list = CreateDataList();
	InitVisit(list, LEN);

	puts("-------------origin--------------");
	PrintInfo(list);
	puts("----------------------------------");
	MergeSort(list, 0, LEN - 1);
	puts("-------------sorting--------------");
	PrintInfo(list);

	puts("----------------------------------");
	puts("-------------searching--------------");

	int minkey = 0;
	int maxkey = 1000;

	printf("range : [%d ~ %d]\n", minkey, maxkey);
	while (true) {
		int originIdx = binarySearch(list, minkey, maxkey, 0, LEN - 1);
		if (originIdx != -1) printf("originIdx : %d\n", originIdx);
		else  break;
	}
	puts("----------------------------------");

	return 0;
}