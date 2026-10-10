#include"DoublyLinkedList.h"
#include<iostream>
using namespace std;

//构造函数
DoublyLinkedList::DoublyLinkedList() {
	head = new DoubleListNode(0);	//创建头节点
}

//析构函数
DoublyLinkedList::~DoublyLinkedList() {
	DoubleListNode* cur = head;
	DoubleListNode* nex = nullptr;
	while (cur != nullptr) {
		nex = cur->next;
		delete cur;
		cur = nex;
	}
}

//获取长度
size_t DoublyLinkedList::getSize()const {
	size_t len = 0;
	DoubleListNode* cur = head;
	while (cur->next) {
		++len;
		cur = cur->next;
	}
	return len;
}

//判空
bool DoublyLinkedList::isEmpty()const {
	return head->next == nullptr;
}

//尾部追加
void DoublyLinkedList::append(int v) {
	//遍历找到尾节点
	DoubleListNode* cur = head;
	DoubleListNode* nex = head->next;
	while (nex != nullptr) {
		cur = cur->next;
		nex = nex->next;
	}
	//创建新节点
	DoubleListNode* temp = new DoubleListNode(v);
	temp->next = nullptr;
	cur->next = temp;
	temp->last = cur;

}

//头部追加
void DoublyLinkedList::pushFront(int v) {
	DoubleListNode* p = new DoubleListNode(v);
	p->next = head->next;
	if (head->next)
		head->next->last = p;	//判断是否为空表

	head->next = p;
	p->last = head;
}

//正向打印
void DoublyLinkedList::printForward() {
	DoubleListNode* cur = head->next;
	while (cur) {
		cout << cur->val;
		if (cur->next)
			cout << "<->";
		cur = cur->next;
	}
	cout << '\n';
}

//反向打印
void DoublyLinkedList::printBackward() {
	//（1）先走到尾节点
	DoubleListNode* p = head->next;
	while (p->next) {
		p = p->next;
	}
	while (p != head) {	//指向同一片区域
		cout << p->val;
		if (p->last != head) {
			cout << "<->";
		}
		p = p->last;
	}
	cout << '\n';
}

//反转双链表
void DoublyLinkedList::reverse() {
	if (head == nullptr || head->next == nullptr)
		return;
	DoubleListNode* pre = nullptr;
	DoubleListNode* cur = head->next;
	DoubleListNode* nex = nullptr;
	while (cur) {
		nex = cur->next;
		cur->next = pre;
		cur->last = nex;
		pre = cur;
		cur = nex;
	}
	head->next = pre;
	if (pre)
		pre->last = head;
	//需要判断pre是否为空
}