#include"Queue.h"
using namespace std;

//Queue1

//判断队列是否为空
bool Queue1::isEmpty()const {
	return queue.empty();
}

//入队操作，将num添加到队列尾部
void Queue1::offer(int num) {
	queue.push(num);
}

//出队操作，获取队列头部元素，并返回该值，最后移除该元素
int Queue1::poll() {
	int front = queue.front();
	queue.pop();
	return front;
}

//查看返回队列头部元素
int Queue1::peek()const {
	return queue.front();
}

//返回队列元素个数
int Queue1::size() const {
	return queue.size();
}

//Queue2

bool Queue2::isEmpty()const {
	return l == r;
}

void Queue2::offer(int num) {
	queue[r] = num;
	++r;
	//queue[r++]=num;
}

int Queue2::poll() {
	int front = queue[l];
	++l;
	return front;	//return queue[l++];
}

int  Queue2::head()const {
	return queue[l];
}

int Queue2::tail() {
	return queue[r - 1];
}

int Queue2::size() {
	return r - l;
}

//循环队列

//在队列尾加入元素
bool MyCircularQueue::enQueue(int v) {
	if (isFull()) {
		return false;
	}
	queue[r] = v;	//队列没有满，r指向的位置有空间
	r = (r + 1 + limit) % limit;	//移动指针
	++size;		//更新指针
	return true;
}

bool MyCircularQueue::deQueue() {
	if (isEmpty()) {
		return false;
	}
	l = (l + limit + 1) % limit;
	--size;
	return true;
}

int MyCircularQueue::Front()const {
	if (isEmpty()) {
		return -1;
	}
	return queue[l];
}

int MyCircularQueue::Rear()const {
	if (isEmpty()) {
		return -1;
	}
	int last = r == 0 ? limit - 1 : r - 1;
	return queue[last];
}

bool MyCircularQueue::isEmpty() const {
	return size == 0;
}

bool MyCircularQueue::isFull()const {
	return size == limit;
}

//MyQueue
void MyQueue::push(int x) {
	in.push(x);
	InToOut();
}

int MyQueue::pop() {
	InToOut();
	int val = out.top();
	out.pop();
	return val;
}

int MyQueue::peek() {
	InToOut();
	return out.top();
}

bool MyQueue::empty()const {
	return in.empty() && out.empty();
}