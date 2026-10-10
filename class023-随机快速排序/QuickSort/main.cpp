#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<random>
#include<algorithm>

using namespace std;
//静态数组，减少空间开销
static const int MAXN = 100001;
int arr[MAXN];
int n = 0;
//随机设备，只有一个，减少每次向系统请求熵值的开销
static random_device rd;
//函数调用运算符重载
//随机数引擎，只有一个，程序运行期间公用，避免出现，相同随机数的情况
static mt19937 gen(rd());

void Swap(int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}
static int first = 0, last = 0;		//三色国旗的左右指针
//荷兰国旗
void partition(int l, int r, int x) {
	first = l;		//<x的越界位置
	last = r;		//>x的越界位置
	int i = l;		//整个遍历l到r的范围
	while (i <= last) {
		if (arr[i] < x) {
			Swap(i, first);
			++i;
			++first;
		}
		else if (arr[i] > x) {
			Swap(i, last);
			//不移动i
			--last;
		}
		else {
			++i;
		}
	}
}
//first 是「小于区的右边界 + 1」（等于区的左端），last 是「大于区的左边界 - 1」（等于区的右端）。它们界定了数组中所有等于 x 的元素所在的连续区间 [first, last]。
//随机排序的X存在性，导致first和last对应的位置一定是X

//随机快排
void QuickSort(int l, int r) {
	if (l >= r)
		return;
	//随机的常数时间比较大
	//只有这一下随机，将时间复杂度收敛到O(n * logn)
	uniform_int_distribution<int> dist(l, r);
	int pos = dist(gen);	//用随机数引擎初始化（不是函数调用运算符）
	int x = arr[pos];		//位置和对应的数字X不一样
	partition(l, r, x);
	//此时partition函数已经修改了first和last
	//防止递归的过程中覆盖数据
	int left = first;
	int right = last;
	QuickSort(l, left - 1);
	QuickSort(right + 1, r);
}

int main() {
	//保证效率
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	QuickSort(0, n - 1);

	for (int i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
}
	return 0;
}