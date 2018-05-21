#include<iostream>
using namespace std;
struct Node{
	Node * pNext;
	int val;
	Node(int x) :pNext(nullptr), val(x){}
};

void ReversePrint(const Node* p)
{
	if (p!=nullptr)
	{
		ReversePrint(p->pNext);
		cout << p->val << " ";
	}
}

int main(int argc, char argv[])
{
	Node * p1 = new Node(1);
	Node * p2 = new Node(2);
	Node * p3 = new Node(3);
	p1->pNext = p2;
	p2->pNext = p3;
	ReversePrint(p1);
	delete p3;
	delete p2;
	delete p1;
	return 0;
}