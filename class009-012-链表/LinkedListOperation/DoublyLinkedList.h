#pragma once
using namespace std;

struct DoubleListNode
{
	int val;
	DoubleListNode* last;
	DoubleListNode* next;
	DoubleListNode(int v=0,DoubleListNode* l=nullptr,DoubleListNode* n=nullptr)
		:val(v),last(l),next(n){}
};

class DoublyLinkedList {
private:
	DoubleListNode* head;
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	size_t getSize()const;
	bool isEmpty()const;
	void append(int v);
	void pushFront(int v);
	void printForward();
	void printBackward();
	void reverse();
};
