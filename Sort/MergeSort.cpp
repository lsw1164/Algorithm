#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//interface
bool AscendingOrder(int &n1, int &n2);
bool DescendingOrder(int &n1, int &n2);
void PushRandomNums(int * arr, int len);

template <typename T>
void MergeSort(T * arr, T * buf, int first, int last, bool(*compare)(T & t1, T & t2));

template <typename T>
void Merge(T * arr, T * buf, int first, int last, bool(*compare)(T & t1, T & t2));

template <typename T>
void PrintArr(T * arr, int first, int last);

//implement
bool AscendingOrder(int &n1, int &n2) {
	return n1 < n2;
}

bool DescendingOrder(int &n1, int &n2) {
	return n1 > n2;
}

template <typename T>
void MergeSort(T * arr, T * buf, int first, int last, bool(*compare)(T & t1, T & t2)) {
	int len = last - first + 1;
	if (len <= 1) return;

	int mid = (first + last) / 2;

	MergeSort(arr, buf, first, mid, compare);
	MergeSort(arr, buf, mid + 1, last, compare);
	Merge(arr, buf, first, last, compare);
}

template <typename T>
void Merge(T * arr, T * buf, int first, int last, bool(*compare)(T & t1, T & t2)) {
	int len = last - first + 1;
	int mid = (first + last) / 2;
	int left = first;
	int right = mid + 1;

	for (int i = first; i <= last; i++) {
		if (left > mid) buf[i] = arr[right++];
		else if (right > last) buf[i] = arr[left++];
		else {
			//custom compare	
			bool isPositive = compare(arr[left], arr[right]);
			buf[i] = isPositive ? arr[left++] : arr[right++];
		}
	}

	for (int i = first; i <= last; i++) {
		arr[i] = buf[i];
	}

//	printf("Len : %3d, (Idx : %3d to %3d ) Merge result : ", len, first, last);
//	PrintArr(arr, first, last);
}


template <typename T>
void PrintArr(T * arr, int first, int last) {
	for (int i = first; i <= last; i++) {
		cout << arr[i] << " ";
	}
	cout << '\n';
}

void PushRandomNums(int * arr, int len) {
	srand(time(NULL));
	for (int i = 0; i < len; i++) {
		arr[i] = rand() % 100;
	}
}

int main(void) {
	const int count = 20;
	int * arr = new int[count];
	int * buf = new int[count];
	PushRandomNums(arr, count);
	cout << "\n------------------------------------------\n";
	cout << "\n-----------before sorting-----------\n";
	cout << "\n------------------------------------------\n";
	PrintArr(arr, 0, count-1);
	cout << "\n------------------------------------------\n";
	MergeSort(arr, buf, 0, count-1, AscendingOrder);
	cout << "\n------------------------------------------\n";
	cout << "\n------after sorting with AscendingOrder------\n";
	cout << "\n------------------------------------------\n";
	PrintArr(arr, 0, count-1);
	cout << "\n------------------------------------------\n";
	MergeSort(arr, buf, 0, count-1, DescendingOrder);
	cout << "\n------------------------------------------\n";
	cout << "\n------after sorting with DescendingOrder------\n";
	cout << "\n------------------------------------------\n";
	PrintArr(arr, 0, count-1);
	cout << "\n------------------------------------------\n";

	return 0;
}
