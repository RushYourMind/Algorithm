#include "stdafx.h"

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
	 * @param root: The root of binary tree.
	 * @return: Preorder in vector which contains node values.
	 */
	 vector<int> preorderTraversal(TreeNode *root) {
		 stack<TreeNode*> s;
		 vector<int> results;
		 //s.push(root);
		 while (root != NULL || !s.empty())
		 {
			 while (root != NULL)
			 {
				 results.push_back(root->val);
				 s.push(root);
				 root = root->left;
			 }

			 if (!s.empty())
			 {
				 root = s.top();
				 s.pop();
				 root = root->right;
			 }
		 }
		 return results;
	 }

	 //recursive
	 vector<int> preorderTraversal_r(TreeNode *root) {
		 vector<int> results;
		 if (root == NULL)
			 return results;
		 helper_pre(results, root);
		 return results;
	 }

	 void helper_pre(vector<int> &results, TreeNode *root)
	 {
		 if (root == NULL)
			 return;
		 results.push_back(root->val);
		 helper_pre(results, root->left);
		 helper_pre(results, root->right);
	 }




	 vector<int> inorderTraversal(TreeNode *root) {
		 vector<int> results;
		 TreeNode *p = root;
		 stack<TreeNode*> s;
		 while (p != NULL || !s.empty())
		 {
			 while (p != NULL)
			 {
				 s.push(p);
				 p = p->left;
			 }

			 if (!s.empty())
			 {
				 p = s.top();
				 s.pop();
				 results.push_back(p->val);
				 p = p->right;
			 }
		 }
		 return results;
	 }

	 vector<int> inorderTraversal_r(TreeNode *root) {
		 vector<int> results;
		 if (root == NULL)
			 return results;
		 helper_in(results, root);
		 return results;
	 }

	 void helper_in(vector<int> &results, TreeNode *root)
	 {
		 if (root == NULL)
			 return;
		 helper_in(results, root->left);
		 results.push_back(root->val);
		 helper_in(results, root->right);
	 }




	 vector<int> postorderTraversal(TreeNode *root) {
		 TreeNode* pre;
		 stack<TreeNode*> s;
		 vector<int> results;
		 if (root == NULL)
			 return results;
		 s.push(root);
		 while (!s.empty())
		 {
			 TreeNode *p = s.top();
			 if ((p->left == NULL && p->right == NULL) || (p->left == pre || p->right == pre))
			 {
				 s.pop();
				 results.push_back(p->val);
				 pre = p;
			 }
			 else
			 {
				 if (p->right != NULL)
					 s.push(p->right);
				 if (p->left != NULL)
					 s.push(p->left);
			 }
		 }
		 return results;
	 }
	 vector<int> postorderTraversal_r(TreeNode *root) {
		 vector<int> results;
		 if (root == NULL)
			 return results;
		 helper_post(results, root);
		 return results;
	 }

	 void helper_post(vector<int> &results, TreeNode *root)
	 {
		 if (root == NULL)
			 return;
		 helper_post(results, root->left);
		 helper_post(results, root->right);
		 results.push_back(root->val);
	 }
 };