#include<iostream>
using namespace std;

//swap
static void Swap(int arr[], int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

//选择排序
static void  selectionSort(int arr[], int n) {
	if (arr == nullptr || n < 2)
		return;
	for (int i = 0;i < n - 1;++i) {
		int minIndex = i;
		for (int j = i + 1;j < n;++j) {
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}
		Swap(arr, i, minIndex);
	}
	return;
}

//冒泡排序
static void bubbleSort(int arr[], int n) {
	if (arr == nullptr || n < 2)
		return;
	for (int end = n - 1;end > 0;--end) {
		for (int i = 0;i < end;++i) {
			if (arr[i] > arr[i + 1])
				Swap(arr, i, i + 1);
		}
	}
	return;
}

//插入排序
static void insertionSort(int arr[], int n) {
	if (arr == nullptr || n < 2)
		return;

	//j位置是当前遍历到的数的前一个位置（第i个数）
		//需要交换操作的条件（进入循环体的条件）
		//i（当前需要插入的数）不在0位置，即j>=0
		//并且arr[j]>arr[j+1]

	for (int i = 1;i < n;++i) {
		for (int j = i - 1;j >= 0 && arr[j] > arr[j + 1];--j) {
			Swap(arr, j, j + 1);
		}
	}
	return;
}
int main() {
	int arr[] = { 4,7,9,2,0,1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	//selectionSort(arr,n);
	//bubbleSort(arr,n);
	insertionSort(arr,n);
	for (int i = 0; i < n; ++i) {
		cout << arr[i];
		if (i != n - 1)
			cout << " ";
	}
	cout << '\n';
	return 0;
}