//分而治之
//求小数和
#include<iostream>
using namespace std;
static const int MAXN = 100001;

int arr[MAXN];
int help[MAXN];
int n = 0;		//数组元素个数

//合并函数
//merge
long long merge(int l, int m, int r) {
	long long ans = 0;
	//先求左跨右的小数和
	int i = l;		//左半部分的指针，[ l , m ]
	int j = m + 1;	//右半部分的指针，[ m+1 , r ]
	int sum = 0;	//左半部分的有序数字，在i位置之前的总和，用来保留数据
	for (; j <= r; ++j) {
		while (i <= m && arr[i] <= arr[j]) {
			sum += arr[i++];
		}
		ans += sum;
	}
	//再排序
	int a = l;		//左数组指针
	int b = m + 1;	//右数组指针
	int p = l;		//辅助数组指针
	while (a <= m && b <= r) {
		help[p++] = arr[a] < arr[b] ? arr[a++] : arr[b++];
	}
	while (a <= m) {
		help[p++] = arr[a++];
	}
	while (b <= r) {
		help[p++] = arr[b++];
	}
	for (int k = l; k <= r; ++k) {
		arr[k] = help[k];
	}
	return ans;
}

//功能函数
//解决问题
long long SmallSum(int l,int r) {
	if (l == r) return 0;
	int m = l + ((r - l) >> 1);
	return SmallSum(l, m) + SmallSum(m + 1, r) + merge(l, m, r);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	//归并分治
	long long sum = SmallSum(0, n);
	//输出结果
	cout << sum << endl;
	return 0;
}