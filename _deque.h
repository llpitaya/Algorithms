#include"__deque_iterator.h"
#include"simple_alloc.h"
#include<memory>
#include<algorithm>
#pragma once
template<class BidirectionalIterator1, class BidirectionalIterator2>
BidirectionalIterator2 _copy_backward(BidirectionalIterator1 first,
	BidirectionalIterator1 last,
	BidirectionalIterator2 result)
{
	while (last != first) *(--result) = *(--last);
	return result;
}

template<class InputIterator, class OutputIterator>
OutputIterator _copy(InputIterator first, InputIterator last, OutputIterator result)
{
	while (first != last) {
		*result = *first;
		++result; ++first;
	}
	return result;
}


template<class T,class Alloc,size_t BufSiz = 0>
class _deque{
public:             // basic types
	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;

public:
	typedef __deque_iterator<T, T&, T*, BufSiz> iterator;

protected:
	typedef pointer* map_pointer;

protected:
	iterator start;
	iterator finish;

	map_pointer map;
	size_type map_size; //map内有多少指针

	typedef simple_alloc<value_type, Alloc> data_allocator;
	typedef simple_alloc<pointer, Alloc> map_allocator;
public:
	iterator begin()
	{
		return start;
	}

	iterator end()
	{
		return finish;
	}

	reference operator[](size_type n)
	{
		return start[difference_type(n)];
	}

	reference front()
	{
		return *start;
	}

	reference back()
	{
		iterator tmp = finish;
		--tmp;
		return *tmp;
	}

	size_type size() const
	{
		return finish - start;
	}

	size_type max_size() const
	{
		return size_type(-1);
	}

	bool empty() const
	{
		return finish == start;
	}

	_deque(int n, const value_type& value) :start(), finish(), map(0), map_size(0)
	{
		fill_initialize(n, value);
	}

	void fill_initialize(size_type n, const value_type& value)
	{
		creat_map_and_nodes(n);
		map_pointer cur;
		for (cur = start.node; cur < finish.node; ++cur)
		{
			std::uninitialized_fill(*cur, *cur + iterator::iterator::buffer_size(), value);
		}
		//因为最后一个节点可能存在备用空间，所以只对[first,cur)区间进行初始化
		std::uninitialized_fill(finish.first, finish.cur, value);
	}

	void creat_map_and_nodes(size_t num_elements)
	{
		// 需要节点数 = （元素个数/每个缓冲区可容纳的元素个数）+ 1
		size_type num_nodes = num_elements / iterator::buffer_size() + 1;

		// 计算一个map需要管理的节点数,最少为8个，最多为 ‘所需节点数’ + 2
		map_size = max(initial_map_size(), num_nodes + 2);
		
		map = map_allocator::allocate(map_size);

		// 令nstart和nfinish指向map所拥有之全部节点的最中央区段
		map_pointer nstart = map + (map_size - num_nodes) / 2;
		map_pointer nfinish = nstart + num_nodes - 1;
		
		map_pointer cur;
		for (cur = nstart; cur <= nfinish; cur++)
		{
			*cur = allocate_node();
		}
		start.set_node(nstart);
		finish.set_node(nfinish);
		start.cur = start.first;
		finish.cur = finish.first + num_elements % iterator::buffer_size();
		
	}
	pointer allocate_node()
	{
		return data_allocator::allocate(iterator::buffer_size());
	}

	size_type initial_map_size() const
	{
		return 8;
	}
	void push_back(const value_type& t)
	{
		if (finish.cur != finish.last - 1)
		{
			// 最后缓冲区尚有两个以上的元素备用空间
			*finish.cur = t; //????
			++finish.cur; 
		}
		else
		{
			push_back_aux(t);
		}
	}

	// 当最后一个缓冲区只剩下一个备用元素空间的时候会调用该函数
	void push_back_aux(const value_type& t)
	{
		value_type t_copy = t;
		reserve_map_at_back();
		*(finish.node  + 1) = allocate_node();
		*finish.cur = t_copy;
		finish.set_node(finish.node + 1);
		finish.cur = finish.first;
		
	}

	void reserve_map_at_back(size_type nodes_to_add = 1)
	{
		//默认情况下，当finish之后的node的个数小于2个时，需要重新整治
		if (nodes_to_add + 1 > map_size - (finish.node - map))
		{
			reallocate_map(nodes_to_add, false);
		}
	}

	void reserve_map_at_front(size_type nodes_to_add = 1)
	{
		if (nodes_to_add > start.node - map)
		{
			reallocate_map(nodes_to_add, true);
		}
	}

	void reallocate_map(size_type nodes_to_add, bool add_at_front)
	{
		size_type old_num_nodes = finish.node - start.node + 1;
		size_type new_num_nodes = old_num_nodes + nodes_to_add;

		map_pointer new_nstart;
		if (map_size > 2 * new_num_nodes)
		{
			new_nstart = map + (map_size - new_num_nodes) / 2 + (add_at_front ? nodes_to_add : 0);
			if (new_nstart < start.node)
			{
				_copy(start.node, finish.node + 1, new_nstart);
			}
			else
			{
				_copy_backward(start.node, finish.node + 1, new_nstart + old_num_nodes);
			}
		}
		else
		{
			size_type new_map_size = map_size + max(map_size, nodes_to_add) + 2;
			//配置一块空间，给新map使用
			map_pointer new_map = map_allocator::allocate(new_map_size);
			new_nstart = new_map + (new_map_size - new_num_nodes) / 2 + (add_at_front ? nodes_to_add : 0);
			//把原map内容拷贝过来
			_copy(start.node, finish.node + 1, new_nstart);
			//释放原map
			map_allocator::deallocate(map, map_size);
			//设定新map的起始地址与大小
			map = new_map;
			map_size = new_map_size;
		}
	}

	void push_front(const value_type& t)
	{
		if (start.cur != start.first)
		{
			--start.cur;
			*start.cur = t;
		}
		else
			push_front_aux(t);
	}

	// 当第一个缓冲区没有任何备用元素时才被调用
	void push_front_aux(const value_type& t)
	{
		value_type t_copy = t;
		reserve_map_at_front();
		start.set_node(start.node - 1);
		start.cur = start.last - 1;
		*start.cur = t_copy;

	}

	void pop_back()
	{
		if (finish.cur != finish.first)
		{
			--finish.cur;
			std::_Destroy(finish.cur);
		}
		else
		{
			//最后缓冲区没有任何元素
			pop_back_aux();
		}
	}

	void pop_back_aux()
	{
		deallocate_node(finish.first);
		finish.set_node(finish.node - 1);
		finish.cur = finish.last - 1;
		std::_Destroy(finish.cur);
	}

	void deallocate_node(pointer p)
	{
		data_allocator::deallocate(p);
	}

	void pop_front()
	{
		if (start.cur != start.last - 1)
		{
			std::_destroy(start.cur);
			++start.cur;
		}
		else
			pop_front_aux();
	}

	void pop_front_aux()
	{
		std::_Destroy(start.cur);
		deallocate_node(start.first);
		start.set_node(start.node + 1);
		start.cur = start.first;
	}

	void clear()
	{
		//头尾以外的所有缓冲区
		for (map_pointer node = start.node + 1; node < finish.node;++node)
		{
			//释放缓冲区内存
			data_allocator::deallocate(*node, iterator::buffer_size());
		}
		if (start.node != finish.node)
		{
			//只释放尾缓冲区，头缓冲区保留
			data_allocator::deallocator(finish.first, iterator::buffer_size());
		}
		else
		{
			//只有一个缓冲区，并不释放，而是将其保留
			finish = start;
		}

	}

	//iterator erase(iterator pos)
	//{

	//}

	////清楚[first,last)区间内的所有元素
	//iterator erase(iterator first, iterator last)
	//{

	//}

	//iterator insert(iterator position, const value_type & x)
	//{

	//}

	//iterator insert_aux(iterator position, const value_type &x)
	//{

	//}
};