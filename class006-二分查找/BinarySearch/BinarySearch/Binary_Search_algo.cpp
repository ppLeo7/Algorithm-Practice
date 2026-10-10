#include"Binary_Search_algo.h"
using namespace std;
//二分查找

//有序数组值存在性
bool findnumber(const vector<int>& arr, int key) {
	int n = arr.size();
	if (n < 1) return false;
	int l = 0, r = n - 1, m = 0;
	while (l <= r) {
		m = l + ((r - l) >> 1);
		if (arr[m] == key) {
			return true;
		}
		else if (arr[m] < key) {
			l = m + 1u;
		}
		else {
			r = m - 1u;
		}
	}
	return false;
}

bool right_FindNumber(const std::vector<int>& arr, int key) {
	int n = arr.size();
	for (int i = 0;i < n;++i) {
		if (arr[i] == key) {
			return true;
		}
	}
	return false;
}

//有序数组>=num的最左位置
int findLeft(const vector<int>& arr, int num) {
	int n = arr.size();
	int l = 0, r = n - 1, m = 0;
	int ans = -1;//记录查找的最左位置
	while (l <= r) {
		m = l + ((r - l) >> 1);
		if (arr[m] >= num) {
			ans = m;
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
	return ans;
}

//有序数组<=num的最右位置
int findRight(const vector<int>& arr, int num) {
	int n = arr.size();
	int l = 0, r = n - 1, m = 0;
	int ans = -1;
	while (l <= r) {
		m = l + ((r - l) >> 1);
		if (arr[m] <= num) {
			ans = m;
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
	return ans;
}

//有序数组峰值存在性
//任何两个相邻的值的不相等
//返回峰值元素的索引
//返回一个即可
bool findPeakElement(const vector<int>& arr) {
	int n = arr.size();
	if (n == 1)
		return 0;
	if (arr[0] > arr[1]) {
		return 0;
	}
	if (arr[n - 2] < arr[n - 1]) {
		return n - 1;
	}
	int l = 1, r = n - 2, m = 0;
	int ans = -1;
	while (l <= r) {
		m = l + ((r - l) >> 1);
		if (arr[m - 1] > arr[m]) {
			r = m - 1;
		}
		else if (arr[m] < arr[m + 1]) {
			l = m + 1;
		}
		else {
			ans = m;
			break;
		}
	}
	return ans;
}