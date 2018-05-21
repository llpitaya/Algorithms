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
	size_type map_size; //map���ж���ָ��

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
		//��Ϊ���һ���ڵ���ܴ��ڱ��ÿռ䣬����ֻ��[first,cur)������г�ʼ��
		std::uninitialized_fill(finish.first, finish.cur, value);
	}

	void creat_map_and_nodes(size_t num_elements)
	{
		// ��Ҫ�ڵ��� = ��Ԫ�ظ���/ÿ�������������ɵ�Ԫ�ظ�����+ 1
		size_type num_nodes = num_elements / iterator::buffer_size() + 1;

		// ����һ��map��Ҫ����Ľڵ���,����Ϊ8�������Ϊ ������ڵ����� + 2
		map_size = max(initial_map_size(), num_nodes + 2);
		
		map = map_allocator::allocate(map_size);

		// ��nstart��nfinishָ��map��ӵ��֮ȫ���ڵ������������
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
			// ��󻺳��������������ϵ�Ԫ�ر��ÿռ�
			*finish.cur = t; //????
			++finish.cur; 
		}
		else
		{
			push_back_aux(t);
		}
	}

	// �����һ��������ֻʣ��һ������Ԫ�ؿռ��ʱ�����øú���
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
		//Ĭ������£���finish֮���node�ĸ���С��2��ʱ����Ҫ��������
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
			//����һ��ռ䣬����mapʹ��
			map_pointer new_map = map_allocator::allocate(new_map_size);
			new_nstart = new_map + (new_map_size - new_num_nodes) / 2 + (add_at_front ? nodes_to_add : 0);
			//��ԭmap���ݿ�������
			_copy(start.node, finish.node + 1, new_nstart);
			//�ͷ�ԭmap
			map_allocator::deallocate(map, map_size);
			//�趨��map����ʼ��ַ���С
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

	// ����һ��������û���κα���Ԫ��ʱ�ű�����
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
			//��󻺳���û���κ�Ԫ��
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
		//ͷβ��������л�����
		for (map_pointer node = start.node + 1; node < finish.node;++node)
		{
			//�ͷŻ������ڴ�
			data_allocator::deallocate(*node, iterator::buffer_size());
		}
		if (start.node != finish.node)
		{
			//ֻ�ͷ�β��������ͷ����������
			data_allocator::deallocator(finish.first, iterator::buffer_size());
		}
		else
		{
			//ֻ��һ���������������ͷţ����ǽ��䱣��
			finish = start;
		}

	}

	//iterator erase(iterator pos)
	//{

	//}

	////���[first,last)�����ڵ�����Ԫ��
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