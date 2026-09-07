#pragma once

//声明类结构、模板定义以及所有成员函数的实现
//由于 C++ 模板的特性，编译器在实例化模板时需要看到完整的函数定义

#include<iostream>
using namespace std;

//单链表节点
template<typename T>
struct ListNode
{
	T data;
	ListNode* next;
	//重载的构造函数，包含默认构造函数
	ListNode(const T& val = T(), ListNode* n = nullptr) :data(val), next(n) {}
	//默认实参，初始化列表
};
//单链表
//包含头指针->头节点（没有实际数据，只保存第一个数据节点位置）
//首元节点：第一个真正存储有效数据的节点
template<typename T>
class LinkedList {
private:
	ListNode<T>* head = nullptr;//头节点指针
public:
	//1.构造函数，创建头节点，初始化空链表
	LinkedList() {
		head = new ListNode<T>;
		head->next = nullptr;
	}
	//2.析构函数，销毁链表，释放所有节点内存
	~LinkedList() {
		ListNode<T>* p = head;
		while (p != nullptr) {
			ListNode<T>* temp = p->next;//存放下一个节点的地址
			delete p;
			p = temp;
		}
	}
	//3.判断链表是否为空
	bool isEmpty() {
		return head->next == nullptr;
	}
	//4.获得链表长度
	size_t getLength() {
		size_t len = 0;
		ListNode<T>* p = head->next;
		while (p != nullptr) {
			++len;
			p = p->next;
		}
		return len;
	}
	//5.头插法，在链表头部插入新节点
	void headInsert(const T& val) {
		ListNode<T>* s = new ListNode<T>;///创建一个val的新节点
		s->data = val;
		s->next = head->next;//新节点的指针域指向首元节点（头节点的指针域）
		head->next = s;//头节点指针域的指向新节点
	}
	//6.尾插法，在链表尾部插入新节点
	void tailInsert(const T& val) {
		//获取尾节点
		ListNode<T>* p = head;
		while (p->next != nullptr) {//p的指针域不为空
			p = p->next;
		}
		ListNode<T>* s = new ListNode<T>;
		s->data = val;
		s->next = nullptr;
		p->next = s;
	}
	//7.按位置插入：在整个链表的第pos个位置插入一个新节点（pos从1开始）
	bool insert(int pos, const T& val) {
		if (pos < 1) return false;
		//找要插入的前一个位置（第pos-1的位置），用指针p指向这个位置，表示该指针
		ListNode<T>* p = head;//指向头节点
		size_t i = 0;
		while (p != nullptr && i < pos - 1) {
			p = p->next;
			++i;
		}
		//本身p指向的是头节点，移动pos-1个单位之后到了pos-1的位置

		//防止越界插入，链表没有创建至少pos-1个节点（不包括头节点），插入到pos的位置不可能
		//只要有pos-1的位置（不管pos位置），就一定可以插入
		if (p == nullptr) return false;
		ListNode<T>* s = new ListNode<T>;
		s->data = val;
		s->next = p->next;
		p->next = s;
		return true;
	}
	//8.按位置删除：删除第pos位置的节点，用val的引用接收返回被删数据
	bool remove(size_t pos, T& val) {
		if (pos < 1) return false;
		ListNode<T>* p = head;
		size_t i = 0;
		//p至远指向最后一个节点（p->next==nullptr）
		//p指向删除位置的前一个位置
		//“走流程”
		while (p->next != nullptr && i < pos - 1) {
			p = p->next;
			++i;
		}
		//“做判断”
		if (p->next == nullptr) return false;//防止越位删除
		ListNode<T>* q = p->next;//q指向被删除位置
		val = q->data;
		p->next = q->next;
		delete q;
		return true;
	}
	//9.按位置查找节点
	ListNode<T>* getNodeByPos(int pos) {
		if (pos < 1) return nullptr;
		ListNode<T>* p = head->next;//指向第一个节点的位置
		size_t i = 1;
		//移动pos-1次，指向pos的位置
		while (p != nullptr && i < pos) {
			p = p->next;
			++i;
		}
		return p;
	}
	//10.按值查找第一个匹配的节点
	ListNode<T>* searchByVal(const T& val) {
		ListNode<T>* p = head->next;//指向首元节点
		while (p != nullptr && p->data != val) {
			p = p->next;
		}
		return p;
	}
	//11.遍历打印链表
	void printList() {
		ListNode<T>* p = head->next;
		while (p != nullptr) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << '\n';
	}
	//12.清空链表（保留头节点，删除所有数据节点）
	void clear() {
		ListNode<T>* p = head->next;
		while (p != nullptr) {
			auto temp = p->next;
			delete p;
			p = temp;
		}
		head->next = nullptr;
	}
};