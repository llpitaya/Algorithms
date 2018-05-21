#include<iostream>
using namespace std;

template<class T>
struct iterator_traits_
{
	typedef typename T::iterator_category  iterator_category;
	typedef typename T::value_type value_type;
	typedef typename T::difference_type difference_type;
	typedef typename T::pointer pointer;
	typedef typename T::reference reference;
};

struct _input_iterator_tag{};
struct _output_iterator_tag{};
struct _forward_iterator_tag : public _input_iterator_tag{};
struct _bidirectional_iterator_tag : public _forward_iterator_tag{};
struct _random_access_iterator_tag : public _bidirectional_iterator_tag{};

// 针对原生指针而设计的偏特化版本
template<class T>
struct iterator_traits_ <T*>
{
	typedef ptrdiff_t diffence_type;
	typedef T& reference;
	typedef _random_access_iterator_tag iterator_category;
};


//针对原生的pointer-to-const而设计的偏特化版本
template <class T>
struct iterator_traits_ < const T* >
{
	typedef ptrdiff_t diffence_type;
	typedef const T& reference;
	typedef _random_access_iterator_tag iterator_category;
};

template<class InputIterator, class OutputIterator>
inline OutputIterator unique_copy(InputIterator first,
	InputIterator last,
	OutputIterator result)
{
	if (first == last )
	{
		return result;
	}
	return _unique_copy(first, last, result);
}

template<class InputIterator, class ForwardIterator>
ForwardIterator _unique_copy(InputIterator first, InputIterator last, ForwardIterator result)
{
	*result = *first;
	++first;
	while (first != last)
	{
		if (*result != *first)
		{
			++result;
			*result = *first;		
			++first;
		}
		else
			++first;
	}
	return ++result;
}

int main()
{
	int a[] = { 1, 1, 2, 3, 3,4 };
	int *b = new int[6];
	int * last = unique_copy(a, a + sizeof(a) / sizeof(int), b);
	while (b!=last)
	{
		cout << *(b++) << " ";
	}
	delete[] b;
	return 0;
}