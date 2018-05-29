//#include"_deque.h"
//#include<iostream>
//#include"__malloc_alloc_template.h"
//using namespace std;
//
//int main()
//{
//	//_deque < int, malloc_alloc, 8 > que(20,8);
//	//que[0] = 10;
//	//cout << que[0] << endl;
//	int x = -1;
//	cout << hex << (x>>2) << endl;
//	unsigned char dst = 128;
//	unsigned char src = 179;
//	cout << ((dst)&(~src)) << endl;
//	return 0;
//}

#include <stdio.h>
int Add(int x, int y)
{
	int z = 0;
	z = x + y;
	return z;
}
int main()
{
	int a = 10;
	int b = 20;
	int ret = Add(a, b);
	printf("ret = %d\n", ret);
	return 0;
}