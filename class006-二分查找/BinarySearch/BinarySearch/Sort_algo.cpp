#include"Sort_algo.h"
using namespace std;
//排序算法

//交换两个数
void Swap(vector<int>& arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
//选择排序
void selectionSort(std::vector<int>& arr) {
	int n = arr.size();
	if (n < 2)
		return;
	for (int i = 0;i < n - 1;++i) {
		int minIndex = i;
		for (int j = i + 1;j < n;++j) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		Swap(arr, i, minIndex);
	}
}
//冒泡排序
void bubbleSort(vector<int>& arr) {
	int n = arr.size();
	if (n < 2)
		return;
	for (int end = n - 1;end > 0;--end) {
		for (int j = 0;j < end;++j) {
			if (arr[j] > arr[j + 1]) {
				Swap(arr, j, j + 1);
			}
		}
	}
}
//插入排序
void insertionSort(vector<int>& arr) {
	int n = arr.size();
	if (n < 2)
		return;
	for (int i = 1;i < n;++i) {
		for (int j = i - 1;j >= 0 && arr[j] > arr[j + 1];--j) {
			Swap(arr, j, j + 1);
		}
	}
}