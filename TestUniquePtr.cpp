#include<iostream>
#include<memory>
using namespace std;
struct TreeNode{
	shared_ptr<TreeNode> left;
	shared_ptr<TreeNode> right;
	int val;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){}
};

typedef shared_ptr<TreeNode> PNODE;

PNODE PrintTree(PNODE root, PNODE newNode)
{
	if (root->left == nullptr)
	{
		root->left = newNode;
	}
	else if(root->right == nullptr)
	{
		root->right = newNode;
	}
	else{
		PrintTree((PNODE(root->left)),(newNode));
	}
	return root;
}

int main()
{
	PNODE root(new TreeNode(0));
	for (size_t i = 1; i <= 3; i++)
	{
		PNODE temp(new TreeNode(i));
		root = PrintTree(root, temp);
	}

	return 0;
}