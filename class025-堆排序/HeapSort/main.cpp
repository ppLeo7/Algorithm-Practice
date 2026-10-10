//堆结构
//完全二叉树和数组前缀范围对应，单独的变量size控制
//下标从0开始
//i的父亲节点：(i-1)/2	向下取整
//左孩子：i*2+1
//右孩子：i*2+2
//大根堆，小根堆
//堆的调整：heapInsert（向上调整），heapify（向下调整）
//heapInsert和heapify单次调用的时间复杂度都是O(logn)，树高

//堆排序
//A：从顶到底建堆，时间复杂度O(n*logn),log1+log2+...+logn->O(n*logn)
//采用增倍分析法，同规模（小）确定上限，同规模（大）确定下限
//B：从底到顶建堆，时间复杂度O(n)
//C：建好堆之后的调整阶段，从最大值到最小值归位，时间复杂度O(n*logn)
//所有建堆的方式空间复杂度都是O(1)

#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
using namespace std;

static const int MAXN = 100005;
static int arr[MAXN];
static int n = 0;

void Swap(int m, int n) {
	int temp = arr[m];
	arr[m] = arr[n];
	arr[n] = temp;
}

//i位置向上调整
void heapInsert(int i) {
	//i==0这种情况也包含，因为此时i==(i-1)/2
	while (arr[i] > arr[(i - 1) / 2]) {
		Swap(i, (i - 1) / 2);
		i = (i - 1) / 2;
	}
}

//i位置向下调整，当前大小为size
void heapify(int i,int size) {
	int l = i * 2 + 1;	//左儿子
	//左儿子存在的前提下
	while (l < size) {
		int best = i * 2 + 2 < size && arr[l + 1] > arr[l] ? l + 1 : l;
		//最大的儿子
		if (arr[best] <= arr[i]) {
			break;
		}
		Swap(i, best);
		i = best;
		l = i * 2 + 1;
	}
}

//从顶向下建立大根堆
void heapSort1() {
	//建立大根堆
	for (int i = 0; i < n; ++i) {
		heapInsert(i);
	}
	//排序
	int last = n-1;
	while (last > 0) {
		Swap(0, last);
		--last;
		heapify(0, last + 1);
	}
}

//从底向上建立大根堆
void heapSort2() {
	//建立大根堆
	for (int i = n - 1; i >= 0; --i) {
		heapify(i, n);	//从最后一个元素开始，元素数量始终是n
	}
	//排序
	int last = n - 1;
	while (last > 0) {
		Swap(0, last);
		--last;
		heapify(0, last + 1);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}

	heapSort1();

	for (int i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
	}
	return 0;
}