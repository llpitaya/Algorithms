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
#include<iostream>
using namespace std;
const int N = 8;
const int K = 4;

/*
���ö��ֵķ�����ȡTOP k���⡣
���Ȳ��� max �� min��Ȼ������ mid = (max + min) / 2
���㷨��ʵ����Ѱ������K��������С��һ����


*/

int find(int * a, int x) //��ѯ�����ڻ��ߵ���x��Ԫ�ظ���    
{
	int sum = 0;

	for (int i = 0; i < N; i++)
	{
		if (a[i] >= x)
			sum++;
	}
	return sum;
}


int getK(int * a, int max, int min) //����max min֮��ֻ�����һ�����߶����ͬ������    
{
	while (max - min > 1)             //max - min��ֵӦ�ñ�֤��������С��Ԫ��֮��ҪС    
	{
		int mid = (max + min) / 2;
		int num = find(a, mid);    //���ر�mid������ָ���    
		if (num >= K)                 //����k����Ŀ��Ҫ��minֵ��    
			min = mid;
		else
			max = mid;
	}
	cout << "end" << endl;
	return min;
}

int main()
{
	int a[N] = { 54, 2, 5, 11, 554, 65, 33, 2 };
	int x = getK(a, 554, 2);
	cout << x << endl;
	int yy = (5 / 2);
	
	return 0;
}

