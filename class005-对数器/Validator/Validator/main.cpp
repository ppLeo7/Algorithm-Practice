#include<iostream>
#include<vector>
#include<random>
using namespace std;
//生成给定范围随机整数(int)
int randint(int l, int r) {
	static random_device rd;
	static mt19937 gen(rd());	//后续反复使用同一个发生器，状态持续迭代
	uniform_int_distribution<int> dist(l, r);	//每次传入的l,r不一样，开销也小
	return dist(gen);
}
//生成随机数组，长度为n，范围为[1,v]
vector<int> randomArray(int n, int v) {
	vector<int> arr(n);	//n初始化表示数组长度
	for (auto& num : arr) {
		//使用每个元素的引用，用于改变元素的值
		num = randint(1, v);
	}
	return arr;
}
//拷贝数组，深拷贝
vector<int> copyArray(const vector<int>& arr) {
	//传入只读引用，值返回（调用拷贝构造函数）
	return arr;
}
//比较两个数组是否相同
bool sameArray(const vector<int>& arr1, const vector<int>& arr2) {
	if (arr1.size() != arr2.size())
		return false;
	for (int i = 0;i < arr1.size();++i) {
		if (arr1[i] != arr2[i])
			return false;
	}
	return true;    
}
//交换两个数
static void Swap(vector<int>& arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
//选择排序
static void selectionSort(vector<int>& arr) {
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
static void bubbleSort(vector<int>& arr) {
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
static void insertionSort(vector<int>& arr) {
	int n = arr.size();
	if (n < 2)
		return;
	for (int i = 1;i < n;++i) {
		for (int j = i - 1;j >= 0 && arr[j] > arr[j + 1];--j) {
			Swap(arr, j, j + 1);
		}
	}
}
//打印数组信息
void printArray(const vector<int>& arr) {
	int n = arr.size();
	for (int i = 0;i < n;++i) {
		cout << arr[i] << " ";
	}
	cout << '\n';
}
int main() {
	const int N = 20;	//最大数组长度
	const int V = 200;	//元素取值范围
	const int testTimes = 50;	//测试次数
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
	return 0;
}