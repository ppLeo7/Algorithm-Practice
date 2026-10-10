#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<random>
using namespace std;

static const int MAXN = 5000005;
static int arr[MAXN] = { 0 };

static random_device rd;
static mt19937 gen(rd());

void Swap(int m, int n) {
    int temp = arr[m];
    arr[m] = arr[n];
    arr[n] = temp;
}

int first = 0, last = 0;
void partation(int l, int r, int x) {
    first = l;
    last = r;
    int i = l;
    while (i <= last) {
        if (arr[i] < x) {
            Swap(i, first);
            ++i;
            ++first;
        }
        else if (arr[i] > x) {
            Swap(i, last);
            --last;
        }
        else {
            ++i;
        }
    }
}

int func(int l, int r, int k) {
    int ans = 0;    //返回值
    int begin = l, end = r;
    while (begin <= end) {
        uniform_int_distribution<int> dist(begin, end);
        int pos = dist(gen);
        int x = arr[pos];
        partation(begin, end, x);
        if (k < first) {
            end = first - 1;
        }
        else if (k > last) {
            begin = last + 1;
        }
        else {
            ans = arr[k];
            break;
        }
    }
    return ans;
}

int main() {
    int n = 0, k = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    printf("%d", func(0, n - 1, k));
    return 0;
}