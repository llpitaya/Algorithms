#include<iostream>
#include<memory>
#include<vector>
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
	else if (root->right == nullptr)
	{
		root->right = newNode;
	}
	else{
		PrintTree((PNODE(root->left)), (newNode));
	}
	return root;
}

void FindPath(PNODE root, int expectedSum, int curSum, vector<int> & vecData)
{
	if (root==nullptr)
	{
		exit(0);
	}

	if (curSum == expectedSum && root->left==nullptr && root->right == nullptr)
	{
		auto PrintFun = [](const vector<int>& vec){for (auto i : vec) cout << i << " "; cout << endl; };
		PrintFun(vecData); 
		exit(0);
	}
	if (root->left!=nullptr && (root->left)->val + curSum <= expectedSum)
	{
		vecData.push_back(root->left->val);
		FindPath(root->left,expectedSum ,curSum + root->left->val, vecData);
		vecData.pop_back();
	}
	if (root->right!=nullptr && (root->right)->val + curSum <= expectedSum)
	{
		vecData.push_back(root->right->val);
		FindPath(root->right, expectedSum, curSum + root->right->val, vecData);
		vecData.pop_back();
	}
}

int main()
{
	PNODE root(new TreeNode(0));
	for (size_t i = 1; i <= 5; i++)
	{
		PNODE temp(new TreeNode(i));
		root = PrintTree(root, temp);
	}
	vector<int> vec;
	int curSum = 0;
	int expectedSum = 3;
	if (root!=nullptr)
	{
		vec.push_back(root->val);
		curSum += root->val;

	}
	FindPath(root, expectedSum, curSum, vec);
	return 0;
}