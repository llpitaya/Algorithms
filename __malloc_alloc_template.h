#include<cstdlib>
#pragma once
template<int inst>
class __malloc_allc_template{
public:
	static void * allocate(size_t n)
	{
		void * result = malloc(n);
		return result;
	}

	static void deallocate(void *p, size_t /* n */) 
	{
		free(p);
	}

	static void * reallocate(void *p, size_t /* old_sz */, size_t new_sz)
	{
		void * result = realloc(p, new_sz);
		return result;
	}
};

typedef __malloc_allc_template<0> malloc_alloc;