#include"Test_Case.h"
#include<iostream>
using namespace std;

int main() {
	const int N = 20;	//最大数组长度
	const int V = 200;	//元素取值范围
	const int testTimes = 50;	//测试次数
	Test_FindNumber(N, V, testTimes);
	return 0;
}