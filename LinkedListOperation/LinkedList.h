#pragma once
using namespace std;

struct ListNode
{
	int data;
	ListNode* next;
	ListNode(int val=0,ListNode* n=nullptr):data(val),next(n){}
};

class LinkedList {
private:
	ListNode* head = nullptr;

public:
	//1.构造函数，创建头节点，初始化空链表
	LinkedList();
	//2.析构函数，销毁链表，释放所有节点内存
	~LinkedList();
	//3.判断链表是否为空
	bool isEmpty()const;
	//4.获得链表长度
	size_t getLength()const;
	//5.头插法，在链表头部插入新节点
	void headInsert(int val);
	//6.尾插法，在链表尾部插入新节点
	void tailInsert(int val);
	//7.按位置插入：在整个链表的第pos个位置插入一个新节点（pos从1开始）
	bool insert(int pos, int val);
	//8.按位置删除：删除第pos位置的节点，用val的引用接收返回被删数据
	bool remove(size_t pos,int& val);
	//9.按位置查找节点
	ListNode* getNodeByPos(int pos);
	//10.按值查找第一个匹配的节点
	ListNode* searchByVal(int val);
	//11.遍历打印链表
	void printList();
	//12.清空链表（保留头节点，删除所有数据节点）
	void clear();
	//13.反转单链表
	void reverse();

};

// 14.辅助函数：打印带虚拟头节点的链表
void printRawList(ListNode* head);

ListNode* mergeTwoLists(ListNode* head1, ListNode* head2);
ListNode* addTwoNumbers(ListNode* head1, ListNode* head2);
ListNode* partition(ListNode* h, int x);