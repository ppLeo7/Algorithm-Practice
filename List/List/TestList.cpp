#include"TestList.h"
#include"LinkedList.h"
//...
#include<iostream>
#include<string>
using namespace std;
void TestLinkedListBasics(void) {
	cout << "===== int 类型链表测试 =====" << endl;
	LinkedList<int> intList;

	intList.tailInsert(10);
	intList.tailInsert(20);
	intList.tailInsert(30);
	cout << "尾插法建表：";
	intList.printList();

	intList.headInsert(5);
	cout << "头插5后：";
	intList.printList();

	intList.insert(3, 15);
	cout << "第3位插入15：";
	intList.printList();

	int delVal;
	intList.remove(2, delVal);
	cout << "删除第2位，被删值：" << delVal << endl;
	cout << "删除后：";
	intList.printList();

	cout << "链表长度：" << intList.getLength() << endl << endl;

	// ========== 测试 string 类型链表 ==========
	cout << "===== string 类型链表测试 =====" << endl;
	LinkedList<string> strList;

	strList.tailInsert("apple");
	strList.tailInsert("banana");
	strList.tailInsert("cherry");
	cout << "尾插法建表：";
	strList.printList();

	strList.headInsert("orange");
	cout << "头插orange后：";
	strList.printList();

	if (strList.searchByVal("banana")) {
		cout << "找到值为 banana 的节点" << endl;
	}
}