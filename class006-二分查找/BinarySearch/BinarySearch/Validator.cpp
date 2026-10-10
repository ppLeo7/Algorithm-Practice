#include"Validator.h"
#include<iostream>
using namespace std;

//对数器 Validator

//生成给定范围随机整数(int)
int randint(int l, int r) {
	static random_device rd;
	static mt19937 gen(rd());
	static uniform_int_distribution<int> dist(l, r);
	return dist(gen);
}
//生成随机数组，长度为n，范围为[1,v]
vector<int> randomArray(int n, int v) {
	vector<int> arr(n);	//n初始化表示数组长度
	for (auto& num : arr) {
		num = randint(1, v);
	}
	return arr;
}
//拷贝数组，深拷贝
vector<int> copyArray(vector<int>& arr) {
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

//打印数组信息
void printArray(const vector<int>& arr) {
	int n = arr.size();
	for (int i = 0;i < n;++i) {
		cout << arr[i] << " ";
	}
	cout << '\n';
}