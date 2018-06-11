#include<iostream>
using namespace std;

struct TreeNode{
	TreeNode * left;
	TreeNode * right;
	int val;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){}
};

bool IsAVLTree = true;
int TreeDepth(TreeNode * root)
{
	if (root == nullptr)
	{
		return 0;
	}
	int left = TreeDepth(root->left);
	int right = TreeDepth(root->right);
	if (left-right > 1 || left-right<-1)
	{
		IsAVLTree = false && IsAVLTree;

	}
	return left > right ? left + 1 : right + 1;
}
int main()
{
	TreeNode * root = new TreeNode(0);
	TreeNode * p1 = new TreeNode(1);
	TreeNode * p2 = new TreeNode(2);
	TreeNode * p3 = new TreeNode(3);
	TreeNode * p4 = new TreeNode(4);
	p2->right = p4;
	p1->right = p2;
	//p1->left = p4;
	root->left = p1;
	root->right = p3;
	int depth = 0;
	TreeDepth(root);
	cout << IsAVLTree << endl;
	delete p4;
	delete p3;
	delete p2;
	delete p1;
	delete root;
	return 0;
}
