#include"LinkedList.h"
#include<iostream>
using namespace std;


//1.构造函数，创建头节点，初始化空链表
LinkedList::LinkedList() {
	head = new ListNode;
	head->next = nullptr;
}
//2.析构函数，销毁链表，释放所有节点内存
LinkedList::~LinkedList() {
	ListNode* p = head;
	while (p != nullptr) {
		ListNode* temp = p->next;//存放下一个节点的地址
		delete p;
		p = temp;
	}
}
//3.判断链表是否为空
bool LinkedList::isEmpty() const {
	return head->next == nullptr;
}
//4.获得链表长度
size_t LinkedList::getLength() const {
	size_t len = 0;
	ListNode* p = head->next;
	while (p != nullptr) {
		++len;
		p = p->next;
	}
	return len;
}
//5.头插法，在链表头部插入新节点
void LinkedList::headInsert(int val) {
	ListNode* s = new ListNode;///创建一个val的新节点
	s->data = val;
	s->next = head->next;//新节点的指针域指向首元节点（头节点的指针域）
	head->next = s;//头节点指针域的指向新节点
}
//6.尾插法，在链表尾部插入新节点
void LinkedList::tailInsert(int val) {
	//获取尾节点
	ListNode* p = head;
	while (p->next != nullptr) {//p的指针域不为空
		p = p->next;
	}
	ListNode* s = new ListNode;
	s->data = val;
	s->next = nullptr;
	p->next = s;
}
//7.按位置插入：在整个链表的第pos个位置插入一个新节点（pos从1开始）
bool LinkedList::insert(int pos, int val) {
	if (pos < 1) return false;
	//找要插入的前一个位置（第pos-1的位置），用指针p指向这个位置，表示该指针
	ListNode* p = head;//指向头节点
	size_t i = 0;
	while (p != nullptr && i < pos - 1) {
		p = p->next;
		++i;
	}
	//本身p指向的是头节点，移动pos-1个单位之后到了pos-1的位置

	//防止越界插入，链表没有创建至少pos-1个节点（不包括头节点），插入到pos的位置不可能
	//只要有pos-1的位置（不管pos位置），就一定可以插入
	if (p == nullptr) return false;
	ListNode* s = new ListNode;
	s->data = val;
	s->next = p->next;
	p->next = s;
	return true;
}
//8.按位置删除：删除第pos位置的节点，用val的引用接收返回被删数据
bool LinkedList::remove(size_t pos, int& val) {
	if (pos < 1) return false;
	ListNode* p = head;
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
	ListNode* q = p->next;//q指向被删除位置
	val = q->data;
	p->next = q->next;
	delete q;
	return true;
}
//9.按位置查找节点
ListNode* LinkedList::getNodeByPos(int pos) {
	if (pos < 1) return nullptr;
	ListNode* p = head->next;//指向第一个节点的位置
	size_t i = 1;
	//移动pos-1次，指向pos的位置
	while (p != nullptr && i < pos) {
		p = p->next;
		++i;
	}
	return p;
}
//10.按值查找第一个匹配的节点
ListNode* LinkedList::searchByVal(int val) {
	ListNode* p = head->next;//指向首元节点
	while (p != nullptr && p->data != val) {
		p = p->next;
	}
	return p;
}
//11.遍历打印链表
void LinkedList::printList() {
	ListNode* p = head->next;
	while (p != nullptr) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << '\n';
}
//12.清空链表（保留头节点，删除所有数据节点）
void LinkedList::clear() {
	ListNode* p = head->next;
	while (p != nullptr) {
		auto temp = p->next;
		delete p;
		p = temp;
	}
	head->next = nullptr;
}
//13.反转单链表
void LinkedList::reverse() {
	if (head == nullptr || head->next == nullptr)
		return;
	//空表/只有头节点
	
	ListNode* pre = nullptr;	//遍历到的前一个节点，必须初始化为nullptr，遍历的第一轮，cur反过来指向pre的时候，反转的链表最后指向nullptr
	ListNode* cur = head->next;	//当前遍历到的节点，从第一个节点开始
	ListNode* nex = nullptr;	//存放下一个节点

	while (cur != nullptr) {	//从头节点到最后一个节点，每一个节点都不为空
		nex = cur->next;	//存放下一个节点的地址，防止中断
		cur->next = pre;	//核心步骤，当前遍历到的节点的指针域，中断之前的连接，改到前一个节点的地址
		pre = cur;	//遍历
		cur = nex;
	}

	head->next = pre;	//重新链接头节点
}
// 14.辅助函数：打印带虚拟头节点的链表
void printRawList(ListNode* head) {
	ListNode* p = head->next;
	while (p) { cout << p->data << " "; p = p->next; }
	cout << endl;
}

//（1）合并两个有序链表
//返回新链表的头指针（入口）
ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
	//空链表判断
	if (!head1 || !head2) {
		return head1 ? head1 : head2;
	}
	if (head1->next == nullptr || head2->next == nullptr)
		return head1->next == nullptr ? head2 : head1;

	ListNode* head = (head1->next->data) <= (head2->next->data) ? head1 : head2;
	ListNode* cur1 = head->next->next;	//当前新头指针那一列，第二个数据节点
	ListNode* cur2 = head == head1 ? head2->next : head1->next;	//另一列第一个数据节点
	ListNode* pre = head->next;

	while (cur1 != nullptr && cur2 != nullptr) {
		if (cur1->data <= cur2->data) {
			pre->next = cur1;
			cur1 = cur1->next;
		}
		else {
			pre->next = cur2;
			cur2 = cur2->next;
		}
		pre = pre->next;	//移动
	}
	pre->next = cur1 == nullptr ? cur2 : cur1;
	//剩余的一段有序链表直接在pre后面

	return head;
}

//（2）两个逆序数字链表，两个数字相加
//返回一个新的链表（不复用原来的链表）
ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
	ListNode* ans = new ListNode;	//结果链表的头指针,创建一个头节点
	ListNode* cur = ans;	//结果链表当前尾节点，遍历指针
	int carry = 0;	//进位值

	ListNode* h1 = head1->next;	//第一个数字链表的首元节点
	ListNode* h2 = head2->next;	//第二个数字链表的首元节点

	//循环条件是head和1head2不为空
	while (h1 != nullptr || h2 != nullptr) {
		//（1）计算当前总和
		//h1或者h2为0，则值为0
		int sum = carry;	//sum初始化为上一轮的进位
		//加和，遍历下一个
		if (h1 != nullptr) {
			sum += h1->data;
			h1 = h1->next;
		}
		if (h2 != nullptr) {
			sum += h2->data;
			h2 = h2->next;
		}
		int val = sum % 10;	//当前位的值
		carry = sum / 10;	//进位值

		//结果链表创建节点存储当前位的值
		//往后遍历
		cur->next = new ListNode(val);
		cur = cur->next;
	}
	//循环结束可能依旧存在进位值
	if (carry == 1) {
		cur->next = new ListNode(1);
	}

	return ans;
}

//（3）划分链表
//链表包括头节点
ListNode* partition(ListNode* h, int x) {
	//定义<x的链表的头和尾
	ListNode* leftHead = new ListNode;
	ListNode* leftTail = leftHead;
	//定义>=x的链表的头和尾
	ListNode* rightHead = new ListNode;
	ListNode* rightTail = rightHead;

	ListNode* cur = h->next;	//当前节点，遍历
	ListNode* nex = nullptr;	//暂存下一个节点

	while (cur != nullptr) {
		nex = cur->next;	//（1）保存下一个节点
		cur->next = nullptr;	//（2）将当前节点从原链表摘下来，将其指针域改空，该节点断开后加到其他链表后，指针域为nullptr与尾指针自洽

		//（3）如果值<x，加到left链表
		if (cur->data < x) {
			leftTail->next = cur;	//将该节点加到left链表之后
			leftTail = cur;		//left链表尾指针后移一个单位
		}
		else {
			rightTail->next = cur;
			rightTail = cur;
		}
		cur = nex;	//当前原链表遍历指针后移一个单位
	}

	//处理左半部分为空情况
	ListNode* res;
	if (leftHead->next == nullptr) {
		// 左边无节点，直接使用right虚拟头作为结果
		res = rightHead;
		delete leftHead;
	}
	else {
		// 左右拼接
		leftTail->next = rightHead->next;
		res = leftHead;
		delete rightHead;
	}
	return res;	//单出口写法
	/*
		//一样的写法
	if (leftHead->next == nullptr) {
		delete leftHead;
		return rightHead;
	}
	leftTail->next = rightHead->next;
	delete rightHead;
	return leftHead;
	*/
}