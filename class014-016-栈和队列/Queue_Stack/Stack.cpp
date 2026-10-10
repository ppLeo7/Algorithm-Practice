#include"Stack.h"

using namespace std;

//Stack1

bool Stack1::isEmpty()const {
	return stack.empty();
}

void Stack1::push(int num) {
	stack.push(num);
}

int Stack1::pop() {
	int top = stack.top();
	stack.pop();
	return top;
}

int Stack1::peek() {
	return stack.top();
}

int Stack1::size()const {
	return stack.size();
}

//Stack2

bool Stack2::isEmpty() {
	return size == 0;
}

void Stack2::push(int num) {
	stack[size++] = num;
}

int Stack2::pop() {
	return stack[--size];
}

int Stack2::peek()const {
	return stack[size - 1];
}

int Stack2::getSize()const {
	return size;
}

//MyStack

void MyStack::push(int x) {
	int n = q.size();
	q.push(x);
	for (int i = 0; i < n; ++i) {
		q.push(q.front());
		q.pop();
	}
}

int MyStack::pop() {
	int val = q.front();
	q.pop();
	return val;
}

int MyStack::top() {
	return q.front();
}

bool MyStack::empty() {
	return q.empty();
}