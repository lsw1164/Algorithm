#include <iostream>
#include <time.h>

using namespace std;

void PushRandomNums(int * arr, int len) {
	srand(time(NULL));
	for (int i = 0; i < len; i++) {
		arr[i] = rand() % 100;
	}
}

void PrintArray(int * arr, int len) {
	for (int i = 0; i < len; i++) {
		printf("%3d ", arr[i]);
	} printf("\n");
}

void PrintArray(int * arr, int left, int right) {
	for (int i = left; i <= right; i++) {
		printf("%3d ", arr[i]);
	} printf("\n");
}

void Merge(int * arr, int left, int right) {
	int len = right - left + 1;
	int mid = (right + left) / 2;
	int * temp = new int[len];
	for (int i = 0, l = left, r = mid + 1; i < len; i++) {
		if (l > mid) temp[i] = arr[r++];
		else if (r > right) temp[i] = arr[l++];
		else {
			temp[i] = (arr[l] < arr[r]) ? arr[l++] : arr[r++];
		}
	}
	for (int i = 0, l = left; i < len; i++) {
		arr[l++] = temp[i];
	}
	free(temp);
	printf("Len : %3d, (Idx : %3d to %3d ) Merge result : ",len, left, right);
	PrintArray(arr, left, right);
}

void MergeSort(int * arr, int left, int right) {
	int len = right - left + 1;
	if (len <= 1) return;

	int mid = (left + right) / 2;

	MergeSort(arr, left, mid);
	MergeSort(arr, mid + 1, right);
	Merge(arr, left, right);
}

int main(void) {
	int len = 15;
	int * input = new int[len];
	PushRandomNums(input, len);
	puts("-----------------------------");
	puts("before sorting...");
	puts("-----------------------------");
	PrintArray(input, len);
	puts("-----------------------------");

	MergeSort(input, 0, len - 1);
	puts("-----------------------------");
	puts("afrer sorting...");
	puts("-----------------------------");
	PrintArray(input, len);
	puts("-----------------------------");

	return 0;
}