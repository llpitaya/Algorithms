#include<iostream>
#include<cassert>
#include<memory>
#include<queue>
using namespace std;

struct TreeNode{
	shared_ptr< TreeNode>  left;
	shared_ptr< TreeNode>  right;
	int val;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){}
};


typedef  TreeNode NODE;
typedef  shared_ptr<TreeNode> PNODE;

PNODE ConstructTree(PNODE root,PNODE newNode)
{
	assert(root != nullptr);
	if (root->left == nullptr)
	{
		root->left = newNode;	
	}
	else if (root->right == nullptr)
	{
		root->right = newNode;
	}
	else
	{
		ConstructTree(root->left, (newNode));
	}
	return root;
}


void PrintFromTopToBottom(PNODE root)
{
	if (root == nullptr)
	{
		return;
	}
	queue<PNODE> que[2];
	que[0].push(root);
	int flag = 0;
	while (!que[flag].empty())
	{
		while (!que[flag].empty())
		{
			cout << que[flag].front()->val << " ";
			if (que[flag].front()->left != __nullptr)
			{
				que[(flag + 1) % 2].push(que[flag].front()->left);
			}
			if (que[flag].front()->right != __nullptr)
			{
				que[(flag + 1) % 2].push(que[flag].front()->right);
			}
			que[flag].pop();
		}
		flag = (flag + 1)%2;
	}
}
int main()
{
	PNODE root(new NODE(0));
	int num = 0;
	for (size_t i = 1; i < 3; i++)
	{
		PNODE temp(new NODE(i));
		root = ConstructTree((root), (temp));
	}
	root->right->right = PNODE(new NODE(3));
	PrintFromTopToBottom(root);
	
	return 0;
}