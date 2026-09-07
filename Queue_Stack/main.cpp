#include"Queue.h"
#include"Stack.h"
#include<iostream>

using namespace std;

int main() {

    // 测试 Queue1
    Queue1 q1;
    q1.offer(1);
    q1.offer(2);
    std::cout << "Queue1 peek: " << q1.peek() << std::endl;      // 1
    std::cout << "Queue1 poll: " << q1.poll() << std::endl;      // 1
    std::cout << "Queue1 size: " << q1.size() << std::endl;      // 1

    // 测试 Queue2（最多加入 5 次）
    Queue2 q2(5);
    q2.offer(10);
    q2.offer(20);
    std::cout << "Queue2 head: " << q2.head() << std::endl;      // 10
    std::cout << "Queue2 tail: " << q2.tail() << std::endl;      // 20
    std::cout << "Queue2 poll: " << q2.poll() << std::endl;      // 10
    std::cout << "Queue2 size: " << q2.size() << std::endl;      // 1

    // 测试 Stack1
    Stack1 s1;
    s1.push(100);
    s1.push(200);
    std::cout << "Stack1 peek: " << s1.peek() << std::endl;      // 200
    std::cout << "Stack1 pop: " << s1.pop() << std::endl;        // 200
    std::cout << "Stack1 size: " << s1.size() << std::endl;      // 1

    // 测试 Stack2（同时最多 3 个元素）
    Stack2 s2(3);
    s2.push(5);
    s2.push(6);
    s2.push(7);
    std::cout << "Stack2 peek: " << s2.peek() << std::endl;      // 7
    std::cout << "Stack2 pop: " << s2.pop() << std::endl;        // 7
    std::cout << "Stack2 size: " << s2.getSize() << std::endl;   // 2

    // 测试循环队列
    MyCircularQueue cq(3);
    std::cout << "enQueue(1): " << cq.enQueue(1) << std::endl;   // true
    std::cout << "enQueue(2): " << cq.enQueue(2) << std::endl;   // true
    std::cout << "enQueue(3): " << cq.enQueue(3) << std::endl;   // true
    std::cout << "enQueue(4): " << cq.enQueue(4) << std::endl;   // false (full)
    std::cout << "Rear: " << cq.Rear() << std::endl;             // 3
    std::cout << "deQueue: " << cq.deQueue() << std::endl;       // true
    std::cout << "Front: " << cq.Front() << std::endl;           // 2
    std::cout << "isEmpty: " << cq.isEmpty() << std::endl;       // false

	return 0;
}