#include"LinkedList.h"
#include"DoublyLinkedList.h"
#include <iostream>
#include <cassert> // 用于断言测试

using namespace std;

int main() {
    cout << "===== 1. 测试基础链表操作 =====" << endl;
    LinkedList list;

    // 测试 isEmpty 和 getLength
    cout << "初始链表是否为空: " << (list.isEmpty() ? "是" : "否") << endl;
    cout << "初始链表长度: " << list.getLength() << endl;

    // 测试尾插法
    cout << "\n--- 尾插法插入 1, 2, 3 ---" << endl;
    list.tailInsert(1);
    list.tailInsert(2);
    list.tailInsert(3);
    list.printList(); // 预期输出: 1 2 3
    cout << "当前长度: " << list.getLength() << endl;

    // 测试头插法
    cout << "\n--- 头插法插入 0 ---" << endl;
    list.headInsert(0);
    list.printList(); // 预期输出: 0 1 2 3

    // 测试按位置插入
    cout << "\n--- 在第2个位置插入 99 ---" << endl;
    bool insertRes = list.insert(2, 99);
    cout << "插入结果: " << (insertRes ? "成功" : "失败") << endl;
    list.printList(); // 预期输出: 0 99 1 2 3

    // 测试按位置查找
    cout << "\n--- 查找第3个位置的节点 ---" << endl;
    ListNode* node = list.getNodeByPos(3);
    if (node) cout << "第3个节点的值: " << node->data << endl; // 预期输出: 1

    // 测试按值查找
    cout << "\n--- 查找值为 2 的节点 ---" << endl;
    ListNode* foundNode = list.searchByVal(2);
    if (foundNode) cout << "找到值为 2 的节点，其值为: " << foundNode->data << endl;

    // 测试按位置删除
    cout << "\n--- 删除第2个位置的节点 ---" << endl;
    int deletedVal = -1;
    bool removeRes = list.remove(2, deletedVal);
    cout << "删除结果: " << (removeRes ? "成功" : "失败") << ", 被删除的值: " << deletedVal << endl;
    list.printList(); // 预期输出: 0 1 2 3

    // 测试反转链表
    cout << "\n--- 反转链表 ---" << endl;
    list.reverse();
    list.printList(); // 预期输出: 3 2 1 0

    // 测试清空链表
    cout << "\n--- 清空链表 ---" << endl;
    list.clear();
    cout << "清空后是否为空: " << (list.isEmpty() ? "是" : "否") << endl;
    list.printList(); // 预期输出: (空行)

    cout << "\n===== 2. 测试合并两个有序链表 =====" << endl;
    // 创建两个有序链表 (带虚拟头节点)
    LinkedList l1, l2;
    l1.tailInsert(1); l1.tailInsert(3); l1.tailInsert(5);
    l2.tailInsert(2); l2.tailInsert(4); l2.tailInsert(6);

    cout << "链表1: "; l1.printList();
    cout << "链表2: "; l2.printList();

    // 注意：mergeTwoLists 接收的是带虚拟头节点的指针
    // 这里我们获取内部头指针进行合并 (假设LinkedList有获取head的方法，或者直接操作)
    // 为了测试，我们手动构建简单的带虚拟头节点的链表
    ListNode* h1 = new ListNode(0); // 虚拟头
    h1->next = new ListNode(1); h1->next->next = new ListNode(3); h1->next->next->next = new ListNode(5);

    ListNode* h2 = new ListNode(0); // 虚拟头
    h2->next = new ListNode(2); h2->next->next = new ListNode(4); h2->next->next->next = new ListNode(6);

    ListNode* mergedHead = mergeTwoLists(h1, h2);
    cout << "合并后的链表: ";
    ListNode* p = mergedHead->next; // 从首元节点开始打印
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    // 清理合并后的链表内存 (简单演示，实际应封装)
    p = mergedHead;
    while (p) { ListNode* t = p; p = p->next; delete t; }

    cout << "\n===== 3. 测试两数相加 =====" << endl;
    // 数字 342 (逆序存储: 2->4->3) + 465 (逆序存储: 5->6->4) = 807 (逆序存储: 7->0->8)
    ListNode* num1 = new ListNode(0); // 虚拟头
    num1->next = new ListNode(2); num1->next->next = new ListNode(4); num1->next->next->next = new ListNode(3);

    ListNode* num2 = new ListNode(0); // 虚拟头
    num2->next = new ListNode(5); num2->next->next = new ListNode(6); num2->next->next->next = new ListNode(4);

    ListNode* sumHead = addTwoNumbers(num1, num2);
    cout << "相加结果 (逆序): ";
    p = sumHead->next;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl; // 预期输出: 7 0 8
    // 清理内存
    p = sumHead;
    while (p) { ListNode* t = p; p = p->next; delete t; }
    p = num1; while (p) { ListNode* t = p; p = p->next; delete t; }
    p = num2; while (p) { ListNode* t = p; p = p->next; delete t; }

    cout << "\n===== 4. 测试划分链表 =====" << endl;
    // 链表: 1->4->3->2->5->2, x = 3
    ListNode* partList = new ListNode(0); // 虚拟头
    partList->next = new ListNode(1);
    partList->next->next = new ListNode(4);
    partList->next->next->next = new ListNode(3);
    partList->next->next->next->next = new ListNode(2);
    partList->next->next->next->next->next = new ListNode(5);
    partList->next->next->next->next->next->next = new ListNode(2);

    cout << "原链表: ";
    p = partList->next;
    while (p) { cout << p->data << " "; p = p->next; }
    cout << endl;

    ListNode* partitionedHead = partition(partList, 3);
    cout << "划分后 (x=3): ";
    p = partitionedHead->next;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl; // 预期输出: 1 2 2 4 3 5 (小于3的在前，大于等于3的在后)

    // 清理划分后的链表内存
    p = partitionedHead;
    while (p) { ListNode* t = p; p = p->next; delete t; }

    cout << "\n===== 所有测试完成 =====" << endl << endl;


    cout << "===== 双链表测试 =====" << endl;
    DoublyLinkedList dll;
    dll.append(1);
    dll.append(2);
    dll.append(3);
    cout << "尾插法建表：" << '\n';

    std::cout << "正向: "; dll.printForward();   // 1 <-> 2 <-> 3
    std::cout << "反向: "; dll.printBackward();  // 3 <-> 2 <-> 1

    dll.reverse();
    std::cout << "反转后正向: "; dll.printForward(); // 3 <-> 2 <-> 1

    return 0;
}
