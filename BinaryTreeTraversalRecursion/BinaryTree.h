#pragma once
#include<iostream>
#include<stack>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int v):val(v),left(nullptr),right(nullptr){ }
};

//二叉树的三种遍历，递归版本
//（1）先序遍历，中左右
void preOrder(TreeNode* head);
//（2）中序遍历，左中右
void inOrder(TreeNode* head);
//（3）后序遍历，左右中
void posOrder(TreeNode* head);


//递归释放内存
void deleteTree(TreeNode* root);

//二叉树递归函数递归遍历过程演示
void f(TreeNode* head);

//二叉树的三种遍历，非递归版本
//（1）先序遍历，中左右
void preorderTraversal(TreeNode* head);
//（2）中序遍历，左中右
void inorderTraversal(TreeNode* head);
//（3）后序遍历，左右中
void postorderTraversalTwoStacks(TreeNode* head);
void postorderTraversalTOneStacks(TreeNode* head);