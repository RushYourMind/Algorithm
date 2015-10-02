#include "stdafx.h"
#include <stack>

class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};

class Solution {
public:
	/**
	* @param root: a TreeNode, the root of the binary tree
	* @return: nothing
	*/
	void invertBinaryTree_recursive(TreeNode *root) {
		// write your code here
		if (root->right == NULL && root->left == NULL)
			return;
		TreeNode *temp = root->left;
		root->left = root->right;
		root->right = temp;
		if (root->right != NULL)
			invertBinaryTree(root->right);
		if (root->left != NULL)
			invertBinaryTree(root->left);
	}

	void invertBinaryTree_iteration(TreeNode *root) {
		if (root == NULL)
			return;
		stack<TreeNode*> s;
		s.push(root);
		while (!s.empty()) {
			TreeNode *t = s.top();
			s.pop();
			TreeNode *temp = t->left;
			t->left = t->right;
			t->right = temp;
			if (t->left != NULL)
				s.push(t->left);
			if (t->right != NULL)
				s.push(t->right);
		}
	}
};
