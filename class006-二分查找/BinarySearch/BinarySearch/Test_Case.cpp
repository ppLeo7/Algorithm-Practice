#include"Test_Case.h"
#include"Sort_algo.h"
#include"Binary_Search_algo.h"
#include"Validator.h"
#include<iostream>
#include<vector>
using namespace std;

void Test_Sort(int N, int V, int testTimes) {
	cout << "测试开始！" << '\n';
	for (int i = 0;i < testTimes;++i) {
		int n = randint(1, N);
		vector<int> arr = randomArray(n, V);
		vector<int> arr1 = copyArray(arr);
		vector<int> arr2 = copyArray(arr);
		vector<int> arr3 = copyArray(arr);
		selectionSort(arr1);
		insertionSort(arr2);
		bubbleSort(arr3);
		if (!sameArray(arr1, arr2) || !sameArray(arr2, arr3)) {
			cout << "出错了！" << '\n';
			cout << "selectionSort:"; printArray(arr1);
			cout << "insertionSort:"; printArray(arr2);
			cout << "bubbleSort   :"; printArray(arr3);
		}
	}
	cout << "测试结束！" << '\n';
}
void Test_FindNumber(int N, int V, int testTimes) {
	cout << "测试开始！" << '\n';
	for (int i = 0;i < testTimes;++i) {
		int n = randint(1, N);
		vector<int> arr = randomArray(n, V);
		insertionSort(arr);
		vector<int> arr1 = copyArray(arr);
		vector<int> arr2 = copyArray(arr);
		int num = randint(1, V);
		if (right_FindNumber(arr1, num) != findnumber(arr2, num)) {
			cout << "出错了" << '\n';
		}
	}
	cout << "测试结束！" << '\n';

}
void Test_FindLeft(int N, int V, int testTimes) {

}
void Test_FindRight(int N, int V, int testTimes) {

}
void Test_FindPeakElement(int N, int V, int testTimes) {

}