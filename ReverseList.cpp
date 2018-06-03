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
	if (H == NULL || H->next == NULL)       //����Ϊ��ֱ�ӷ��أ���H->nextΪ���ǵݹ��
		return H;
	Node* newHead = In_reverseList(H->next); //һֱѭ������β 
	H->next->next = H;                       //��ת�����ָ��
	H->next = NULL;                          //�ǵø�ֵNULL����ֹ�������
	return newHead;                          //������ͷ��Զָ�����ԭ�������β
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