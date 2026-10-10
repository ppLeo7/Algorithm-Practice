#include"BinaryTree.h"
#include<iostream>

using namespace std;

int main() {
	//构建二叉树
	TreeNode* head = new TreeNode(1);
	head->left = new TreeNode(2);
	head->right = new TreeNode(3);
	head->left->left = new TreeNode(4);
	head->left->right = new TreeNode(5);
	head->right->left = new TreeNode(6);
	head->right->right = new TreeNode(7);

	cout << endl << "先序遍历递归版: " << endl;
	preOrder(head);

	cout << endl << "中序遍历递归版: " << endl;
	inOrder(head);
	
	cout << endl << "后序遍历递归版: " << endl;
	posOrder(head);

	cout <<'\n' << '\n' << "前序遍历: " << '\n';
	preorderTraversal(head);

	cout << '\n' << "中序遍历: " << '\n';
	inorderTraversal(head);

	cout <<'\n'<< "后序遍历(双栈): "<<'\n';
	postorderTraversalTwoStacks(head);

	cout << '\n' << "后序遍历(单栈): "<<'\n';
	postorderTraversalOneStack(head);

	cout <<'\n' << "=======================" << "\n";

	//测试递归遍历过程
	f(head);

	deleteTree(head);

	return 0;
}