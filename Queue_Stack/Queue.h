#pragma once
#include<queue>
#include<stack>
#include<vector>

using namespace std;

//基于STL的队列
struct Queue1
{
	queue<int> queue;
	
	//判断队列是否为空
	bool isEmpty()const;
	//入队操作，将num添加到队列尾部
	void offer(int num);
	//出队操作，获取队列头部元素，并返回该值，最后移除该元素
	int poll();
	//查看返回队列头部元素
	int peek()const;
	//返回队列元素个数
	int size() const;
};

//基于数组的轻量队列（总操作次数上限n）
class Queue2
{
private:
	vector<int> queue;
	size_t l = 0;	//队列首部索引
	size_t r = 0;	//队列尾部索引
					//范围[ l , r )
public:
	Queue2(int n=0):queue(n),l(0),r(0){ }

	bool isEmpty()const;

	void offer(int num);

	int poll();

	int  head()const;
	
	int tail();

	int size();
};

//循环队列
//使用size来使头指针和尾指针解耦
class MyCircularQueue {
private:
	vector<int> queue;
	int l;	//队首指针
	int r;	//队尾指针
	int size;	//当前队列元素个数
	int limit;	//队列容量

public:
	MyCircularQueue(int k) :queue(k), l(0), r(0), size(0), limit(k) {

	}

	//在队列尾加入元素
	bool enQueue(int v);

	bool deQueue();

	int Front()const;

	int Rear()const;

	bool isEmpty() const;

	bool isFull()const;
};

//（1）用STL中的stack实现MyQueue
//用两个栈一起实现，in，out，一进一出
//将in倒入out的条件
//（1）out里面没有元素
//（2）每次要把in里面所有元素都倒入

class MyQueue {
private:
	stack<int> in;
	stack<int> out;

	//私有成员函数，类内实现细节
	void InToOut() {
		if (out.empty()) {
			while (!in.empty()) {
				out.push(in.top());
				in.pop();
			}
		}
	}
public:
	MyQueue(){ }

	void push(int x);

	int pop();

	int peek();

	bool empty()const;
};

//循环双端队列
//用内置数组实现
//l和r指针表示队列头部和队列尾部的元素
//size和limit实现双指针解耦
class MyCircularDeque {
private:
	int* deque;		//动态数组
	int l, r;		//双端队列头尾指针
	int size;		//当前队列元素个数
	int limit;		//队列数组最大容量

public:
	MyCircularDeque(int k):limit(k),l(0),r(0),size(0){
		deque = new int[k];
	}

	~MyCircularDeque() {
		delete[] deque;
	}

	//队首插入元素
	//满了->false
	//空的->直接插入l位置
	//l==0	l=limit-1插入
	//l!=0	--l，插入
	//!!!!!!size同时更改
	bool insertFront(int v) {
		if (isFull()) {
			return false;
		}

		if (isEmpty()) {
			l = r = 0;
			deque[0] = v;
		}
		else {
			l = l == 0 ? (l = limit - 1) : (l - 1);
			deque[l] = v;
		}

		++size;
		return true;
	}

	//队尾插入元素
	//满了->false
	//空的->直接插入r位置
	//r==limit-1 r=0插入
	//r!=limit-1 ++r 插入
	bool insertLast(int v) {
		if (isFull()) {
			return false;
		}
		if (isEmpty()) {
			l = r = 0;
			deque[0] = v;
		}
		else {
			r = r == limit - 1 ? (0) : (r + 1);
			deque[r] = v;
		}

		++size;
		return true;
	}

	//从队首删除元素
	//是否为空判断
	//删除不需要有什么实际的操作，关键是改变l，后续再在队首位置加入元素会对其进行覆盖
	//l=limit-1	->l=0
	//l!=limit-1	->++l
	bool deleteFront() {
		if (isEmpty()) {
			return false;
		}
		l = (l == limit - 1) ? (0) : (l + 1);
		--size;
		return true;
	}

	//r==0	->r=limit-1
	//r!=0	->--r
	bool deleteLast() {
		if (isEmpty()) {
			return false;
		}
		r = (r == 0) ? (limit - 1) : (r - 1);
		--size;
		return true;
	}

	/** 获取队首元素，若队列为空返回 -1 */
	int getFront() {
		if (isEmpty()) return -1;
		return deque[l];
	}

	/** 获取队尾元素，若队列为空返回 -1 */
	int getRear() {
		if (isEmpty()) return -1;
		return deque[r];
	}



	bool isEmpty()const {
		return size == 0;
	}

	bool isFull()const {
		return size == limit;
	}

};