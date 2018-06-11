#include<iostream>
using namespace std;

struct TreeNode{
	TreeNode * left;
	TreeNode * right;
	int val;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){}
};

int maxVal = -1;
int CalDepthOfTree(TreeNode * root, int depth)
{
	if (root == nullptr)
	{
		maxVal = (maxVal > depth ? maxVal : depth);
		return maxVal;
	}
	else
	{
		++depth;	
	}
	CalDepthOfTree(root->left, depth);
	CalDepthOfTree(root->right, depth);
}

int main()
{
	TreeNode * root = new TreeNode(0);
	TreeNode * p1 = new TreeNode(1);
	TreeNode * p2 = new TreeNode(2);
	TreeNode * p3 = new TreeNode(3);
	TreeNode * p4 = new TreeNode(4);
	p1->right = p2;
	p1->left = p4;
	root->left = p1;
	root->right = p3;
	int depth = 0;
	CalDepthOfTree(root, depth);
	cout << maxVal << endl;
	delete p4;
	delete p3;
	delete p2;
	delete p1;
	delete root;
	return 0;
}