
#include "__malloc_alloc_template.h"
#include "simple_alloc.h"
#include<iostream>
using namespace std;
namespace cc{
	int a;
};

template < class T >
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



template<class I, class T>
typename iterator_traits_<I>::diffence_type
_count(I first, I last, const T& value)
{
	typename iterator_traits_<I>::diffence_type n = 0;
	for (; first != last; ++first )
	{
		if (*first == value)
		{
			++n;
		}		
	}
	return n;
}

int main()
{
	//int a[] = { 1, 3, 2, 1, 4 };
	//cout << _count(a, a + 5,1) << endl;
	typedef simple_alloc<int, malloc_alloc> data_allocater;
	int * p = data_allocater::allocate(3);
	p[0] = 0;
	p[1] = 1;
	p[2] = 2;
	data_allocater::deallocate(p);
	return 0;
}