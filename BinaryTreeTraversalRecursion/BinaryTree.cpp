#include"BinaryTree.h"

using namespace std;

//二叉树的三种遍历，递归版本
//（1）先序遍历，中左右
void preOrder(TreeNode* head) {
	if (head == nullptr) {
		return;
	}
	cout << head->val << " ";
	preOrder(head->left);
	preOrder(head->right);
}
//（2）中序遍历，左中右
void inOrder(TreeNode* head) {
	if (head == nullptr) {
		return;
	}
	inOrder(head->left);
	cout << head->val << " ";
	inOrder(head->right);
}
//（3）后序遍历，左右中
void posOrder(TreeNode* head) {
	if (head == nullptr) {
		return;
	}
	posOrder(head->left);
	posOrder(head->right);
	cout << head->val << " ";
}

void deleteTree(TreeNode* root) {
	if (root == nullptr) {
		return;
	}
	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
}


//二叉树递归函数递归遍历过程演示
void f(TreeNode* head) {
	if (head == nullptr) {
		return;
	}
	cout << head->val << " ";
	// 位置1：刚进入节点
	f(head->left);
	cout << head->val << " ";
	// 位置2：左子树返回后
	f(head->right);
	cout << head->val << " ";
	// 位置3：右子树返回后
}


//二叉树的三种遍历，非递归版本
//（1）先序遍历，中左右
void preorderTraversal(TreeNode* head) {
	if (head != nullptr) {		//二叉树至少有一个节点
		stack<TreeNode*> st;	//栈
		st.push(head);		//将根压入栈
		while (!st.empty()) {
			head = st.top();
			cout << head->val << " ";
			st.pop();
			//将栈首元素弹出，并打印
			if (head->right) st.push(head->right);
			if (head->left) st.push(head->left);
			//将head的右儿子和左儿子依次压入栈（依旧处理了“中”，对于这个子树，在之后的处理中，
			//先弹出左儿子，并处理，再弹出右儿子，并处理，满足“中左右”）

			//在循环中，对于这个子树，左子树的节点会不断的压入弹出进行处理
			//在左子树的节点没有处理完之前，右子树不会被处理
			//所有的子树的遵循这个原则

			//弹出左儿子处理完之后，又会把它的儿子压入栈
		}
	}
}
//（2）中序遍历，左中右
void inorderTraversal(TreeNode* head) {
	stack<TreeNode*> st;
	//栈不为空，遍历指针不为空
	while (!st.empty() || head) {
		if (head != nullptr) {
			//指针不为空
			st.push(head);		//将当前节点压入栈
			head = head->left;	//继续往左走
		}
		else {
			//此时head==nullptr
			//走到最左端
			head = st.top();	//栈顶元素，最左端未访问元素（左儿子为nullptr）
			cout << head->val << " ";
			st.pop();		//弹出
			head = head->right;	//转向右子树
			//右子树继续向左遍历到尽头
		}
	}

	//对于一个子树，会走到它的左子树，一直到处理完左子树
	//处理完的时候，head==nullptr，即指向一个叶子的儿子(nullptr)
	//此时“左”已处理完
	//弹出“中”节点，并且处理打印
	//然后接着处理右子树，“右”
	//在左子树（在栈里面）没有处理完之前，“中”节点不会弹出处理
	//处理到“中”之后，才去遍历右子树，处理“右”

}
//（3）后序遍历，左右中

//双栈法
//先序遍历->中左右，将其左右调换顺序->中右左
//->反过来就是->左右中
//方法：使用一个栈来存打印信息，再依次弹出
void postorderTraversalTwoStacks(TreeNode* head) {
	if (head) {
		stack<TreeNode*> st, temp;
		st.push(head);
		while (!st.empty()) {
			//二叉树的各个节点都是堆内存
			//这里的栈元素以及head都是结点指针，stack的成员函数都是对于指针而言，对指针指向的内容没有关系
			head = st.top();
			st.pop();
			temp.push(head);
			if (head->left) st.push(head->left);
			if (head->right) st.push(head->right);
		}
		while (!temp.empty()) {
			cout << temp.top()->val << " ";
			temp.pop();
		}
	}
}


//单栈法


void postorderTraversalOneStack(TreeNode* h) {
	if (h != nullptr) {
		stack<TreeNode*> st;
		st.push(h);
		TreeNode* lastPrinted = nullptr;   // 记录上一次访问并弹出的节点
		while (!st.empty()) {
			TreeNode* cur = st.top();      // 只查看栈顶，不弹出
			// 情况1：左子树存在且尚未处理
			if (cur->left != nullptr && lastPrinted != cur->left && lastPrinted != cur->right) {
				st.push(cur->left);
			}
			// 情况2：右子树存在且尚未处理
			else if (cur->right != nullptr && lastPrinted != cur->right) {
				st.push(cur->right);
			}
			// 情况3：左右子树均已处理或无子树，访问当前节点
			else {
				ans.push_back(cur->val);
				lastPrinted = cur;
				st.pop();                // 弹出当前节点
			}
		}
	}
}