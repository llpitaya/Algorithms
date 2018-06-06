#include<iostream>
using namespace std;

class AllocOnlyOnHeap{
public:
	static AllocOnlyOnHeap* Create()
	{ 
		return new AllocOnlyOnHeap(); 
	}

	void Destroy()
	{
		delete this;
	}
private:
	int mData;
	~AllocOnlyOnHeap()
	{ 
		cout << "Release current object." << endl; 
	}
};

class AllocOnlyOnStack{
public:
	AllocOnlyOnStack(){ cout << "Default constructor." << endl; }
private:
	void* operator new(size_t n);
	void operator delete(void* ptr);
};

int main()
{
	AllocOnlyOnHeap* obj = AllocOnlyOnHeap::Create();
	obj->Destroy();

	AllocOnlyOnStack obj2;
	return 0;
}