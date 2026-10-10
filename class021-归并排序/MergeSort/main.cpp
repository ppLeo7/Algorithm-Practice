#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>

using namespace std;

static const int MAXN = 100001;
int arr[MAXN];
int help[MAXN];
int n = 0;

void Merge(int l, int m, int r);

//递归版本
void mergeSort1(int l, int r) {
	if (l == r) return;		//边界情况
	int m = l + ((r - l) >> 1);
	mergeSort1(l, m);
	mergeSort1(m + 1, r);
	Merge(l, m, r);
}

//非递归版本
void mergeSort2() {
	//step就是每一次循环处理的每组数据的量
	int l = 0, m = 0, r = 0;
	int step = 1;
	for ( ; step < n; step <<= 1) {
		l = 0;
		while (l < n) {
			m = l + step - 1;
			if (m + 1 >= n) {
				break;
			}
			r = min(l + (step << 1) - 1, n - 1);
			Merge(l, m, r);
			l = r + 1;
		}
	}
}

//归并函数
//合并[l,m]和[m+1,r]两个区间，合并两个有序数组
void Merge(int l, int m, int r) {
	int i = l;		//新数组指针
	int a = l;		//左区间指针
	int b = m + 1;	//右区间指针
	while (a <= m && b <= r) {
		help[l++] = arr[a] < arr[b] ? arr[a++] : arr[b++];
	}
	//至少有一个区间到头了
	while (a <= m) {
		help[i++] = arr[a++];
	}
	while (b <= r) {
		help[i++] = arr[b++];
	}

	for (int i = l; i <= r; ++i) {
		arr[i] = help[i];
	}
}
int main() {

	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}

	//调用归并排序
	mergeSort2();

	for (int i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
	}

	return 0;
}