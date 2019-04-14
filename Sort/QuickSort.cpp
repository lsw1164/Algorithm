#include <iostream>
#include <stdlib.h>
#include <time.h>
#define null 0 
#define MAX 10
using namespace std;

bool AscendingOrder(int &n1, int &n2);
bool DescendingOrder(int &n1, int &n2);
void PushRandomNums(int * arr, int len);

template <typename T>
void Swap(T & t1, T & t2);

template <typename T>
void PrintArr(T * arr, int first, int last);

template <typename T>
void QuickSort(T * arr, int first, int last, bool(*compare)(T & t1, T & t2));

template<typename T>
int Partition(T * arr, int first, int last, bool(*compare)(T & t1, T & t2));

bool AscendingOrder(int &n1, int &n2) {
	return n1 <= n2;
}

bool DescendingOrder(int &n1, int &n2) {
	return n1 > n2;
}

template <typename T>
void Swap(T & t1, T & t2) {
	T temp = t1;
	t1 = t2;
	t2 = temp;
}

void PushRandomNums(int * arr, int len) {
	srand(time(null));
	for (int i = 0; i < len; i++) {
		arr[i] = rand() % 100;
	}
}

template <typename T>
void PrintArr(T * arr, int first, int last) {
	for (int i = first; i <= last; i++) {
		cout << arr[i] << " ";
	}
	cout << '\n';
}

template <typename T>
void QuickSort(T * arr, int first, int last, bool(*compare)(T & t1, T & t2)) {
	if (first >= last) return;
	int partIdx = Partition(arr, first, last, compare);
	QuickSort(arr, first, partIdx - 1, compare);
	QuickSort(arr, partIdx + 1, last, compare);
}

template<typename T>
int Partition(T * arr, int first, int last, bool(*compare)(T & t1, T & t2)) {
	int mid = (first + last) / 2;
	Swap(arr[mid], arr[last]);
	T pivot = arr[last];
	int rose = first;
	for (int i = first; i < last; i++) {
		if (compare(arr[i], pivot)) {
			Swap(arr[rose], arr[i]);
			rose++;
		}
	}
	Swap(arr[rose], arr[last]);	
//	printf("(pivot : %3d, Idx : %3d to %3d ) Quick result : ",pivot, first, last);
//	PrintArr(arr, 0, MAX-1);
	return rose;
}

int main(void) {
	int * arr = new int[MAX];
	PushRandomNums(arr, MAX);
	cout << "\n------------------------------------------\n";
	cout << "\n-----------before sorting-----------\n";
	cout << "\n------------------------------------------\n";
	PrintArr(arr, 0, MAX - 1);
	cout << "\n------------------------------------------\n";
	QuickSort(arr, 0, MAX - 1, AscendingOrder);
	cout << "\n------------------------------------------\n";
	cout << "\n------after sorting with AscendingOrder------\n";
	cout << "\n------------------------------------------\n";
	PrintArr(arr, 0, MAX - 1);
	cout << "\n------------------------------------------\n";
	QuickSort(arr, 0, MAX - 1, DescendingOrder);
	cout << "\n------------------------------------------\n";
	cout << "\n------after sorting with DescendingOrder------\n";
	cout << "\n------------------------------------------\n";
	PrintArr(arr, 0, MAX - 1);
	cout << "\n------------------------------------------\n";

	return 0;
}