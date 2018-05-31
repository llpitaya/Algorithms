#include<iostream>
using namespace std;
struct TreeNode{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){}
};

TreeNode* MirrorBinaryTree(TreeNode* root)
{
	
	if (root == nullptr)
	{
		return root;
	}
	TreeNode * temp = root->left;
	root->left = root->right;
	root->right = temp;
	MirrorBinaryTree(root->left);
	MirrorBinaryTree(root->right);
	return root;
}

int main()
{
	TreeNode * root = new TreeNode(0);
	TreeNode * node1 = new TreeNode(1);
	TreeNode * node2 = new TreeNode(2);
	TreeNode * node3 = new TreeNode(3);

	node2->right = node3;
	root->left = node1;
	root->right = node2;
	root = MirrorBinaryTree(root);
	return 0;
}