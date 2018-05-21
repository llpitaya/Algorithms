#include"_deque.h"
#include<iostream>
#include"__malloc_alloc_template.h"
using namespace std;

int main()
{
	//_deque < int, malloc_alloc, 8 > que(20,8);
	//que[0] = 10;
	//cout << que[0] << endl;
	unsigned int  m = ( 15- 127) << 23;
	cout << hex << m << endl;
	return 0;
}