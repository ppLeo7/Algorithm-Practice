#pragma once
#include<stack>
#include<queue>
#include<vector>

using namespace std;

//
struct Stack1
{
	stack<int> stack;

	bool isEmpty()const;

	void push(int num);

	int pop();

	int peek();

	int size()const;
};

//
class Stack2 {
private:
	vector<int> stack;
	size_t size;
public:
	Stack2(int n):stack(n),size(0){}

	bool isEmpty();

	void push(int num);

	int pop();

	int peek()const;

	int getSize()const;
};

//（1）用STL中的queue实现MyStack
class MyStack {
private:
	queue<int> q;
public:
	MyStack(){ }

	//每次新的元素入队以后，将之前的size个元素都再依次，出队，入队，使其元素倒序
	//加入元素的时间复杂度O(n)
	void push(int x);

	int pop();

	int top();

	bool empty();
};

//（2）最小栈
//寻找栈内最小值
//空间换时间
//两个栈，data存所有数据，min存当前平行位的栈的最小值
//栈使用STL的stack
//栈使用STL的vector动态数组
//栈使用数组

class MinStack1 {
private:
	stack<int> data;
	stack<int> min;
public:
	MinStack1(){}

	void push(int val) {
		data.push(val);
		if (min.empty() || val <= min.top()) {
			min.push(val);
		}
		else {
			min.push(min.top());
		}
	}

	void pop() {
		data.pop();
		min.pop();
	}

	int top() {
		return data.top();
	}

	int getMin() {
		return min.top();
	}
};


class MinStack2 {
private:
	std::vector<int> data;
	std::vector<int> min;

public:
	MinStack2() {}

	void push(int val) {
		data.push_back(val);
		if (min.empty() || val <= min.back()) {
			min.push_back(val);
		}
		else {
			min.push_back(min.back());
		}
	}

	void pop() {
		data.pop_back();
		min.pop_back();
	}

	int top() {
		return data.back();
	}

	int getMin() {
		return min.back();
	}
};

class MyStack3 {
private:
	static const int MAXN = 15000;
	int data[MAXN];
	int minArr[MAXN];
	int size;
public:
	MyStack3(){ }

	void push(int val) {
		data[size] = val;
		if (size == 0 || val <= minArr[size - 1]) {
			minArr[size] = val;
			++size;
		}
		else {
			minArr[size] = minArr[size - 1];
			++size;
		}
	}

	void pop() {
		--size;
	}

	int top() {
		return data[size - 1];
	}

	int getMin() {
		return minArr[size - 1];
	}
};