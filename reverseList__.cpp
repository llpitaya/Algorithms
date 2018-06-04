#include<stdio.h>

struct  node
{
	int val;
	node *pnext;
	node(int x) :val(x), pnext(nullptr){}
};

void ReverseList()
{
	node * root = new node(1);
	node * node1 = new node(2);
	node * node2 = new node(3);
	node1->pnext = node2;
	root->pnext = node1;

	node * p = root;
	node * newH = nullptr;
	while (p != nullptr)
	{	
		node *temp = p->pnext;
		p->pnext = newH;
		newH = p;
		p = temp;
	}
	while (newH!= nullptr)
	{
		printf("%d", newH->val);
		newH = newH->pnext;
	}
	delete node2;
	delete node1;
	delete root;
}

int main()
{
	ReverseList();
	return 0;
}