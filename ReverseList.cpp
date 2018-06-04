#include<iostream>
using namespace std;
struct Node
{
	int val;
	Node * next;
	Node(int x) :val(x), next(nullptr){}
};

Node * tail = new Node(-1);
Node * _tail = tail;
Node* ReverseList(Node * root)
{
	if (root->next == nullptr){
		tail = root;
		_tail = tail;
		return root;
	}
	else
	{
		ReverseList(root->next);
	}
}

Node* In_reverseList(Node* H)
{
	if (H == NULL || H->next == NULL)       //链表为空直接返回，而H->next为空是递归基
		return H;
	Node* newHead = In_reverseList(H->next); //一直循环到链尾 
	H->next->next = H;                       //翻转链表的指向
	H->next = NULL;                          //记得赋值NULL，防止链表错乱
	return newHead;                          //新链表头永远指向的是原链表的链尾
}

int main()
{
	Node * root = new Node(0);
	Node * node1 = new Node(1);
	Node * node2 = new Node(2);
	root->next = node1;
	node1->next = node2;
	root = In_reverseList(root);
	delete node2;
	delete node1;
	delete root;
	return 0;
}