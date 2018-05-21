
struct _input_iterator_tag{};
struct _output_iterator_tag{};
struct _forward_iterator_tag : public _input_iterator_tag{};
struct _bidirectional_iterator_tag : public _forward_iterator_tag{};
struct _random_access_iterator_tag : public _bidirectional_iterator_tag{};

template<class T, class Ref, class Ptr,size_t BufSize>
struct __deque_iterator{
	typedef __deque_iterator<T, T&, T*, BufSize> iterator;
	typedef __deque_iterator<T, const T&, const T*, BufSize> const_iterator;
	

	static size_t buffer_size(){
		return __deque_buf_size(BufSize, sizeof(T));
	}

	typedef _random_access_iterator_tag iterator_tag;
	typedef T value_type;
	typedef Ptr pointer;
	typedef Ref reference;
	typedef size_t size_type;
	typedef int difference_type;
	typedef T** map_pointer;

	typedef __deque_iterator self;

	T* cur;
	T* first;
	T* last;
	map_pointer node;

	// 计算缓存区大小
	// 如果sz(sizeof(element))小于512，则传回512/sz
	// 如果sz不小于512，则返回1
	static size_t __deque_buf_size(size_t n, size_t sz)
	{
		return n != 0 ? n : (sz < 512 ? size_t(512 / sz) : size_t(1));
	}

	void set_node(map_pointer new_node)
	{
		node = new_node;
		first = *new_node;
		last = first + difference_type(buffer_size());
	}

	reference operator*() const {
		return *cur;
	}

	pointer operator->() const
	{
		return &(operator*());
	}

	difference_type operator-(const self& x) const
	{
		return (x.last - x.cur) + (cur - first) + difference_type(buffer_size()) * (node - x.node + 1);
	}

	// 后置++
	self& operator++()
	{
		++cur;
		if (cur == last)
		{
			set_node(this->node + 1);
			cur = first;
		}
		return *this;
	}
	//前置++
	self operator++(int)
	{
		self temp = *this;
		++*this;
		return temp;
	}

	self& operator--()
	{
		if (cur == first)
		{
			set_node(node - 1);
			cur = last;
		}
		--cur;
		return *this;
	}

	self operator--(int)
	{
		self temp = *this;
		--*this;
		return temp;
	}

	// key function
	self& operator+=(difference_type n)
	{
		difference_type offset = n + (cur - first);
		if (offset >= 0 && offset < difference_type(buffer_size()))
		{
			//目标位置在同一缓冲区
			cur += n;
		}
		else
		{
			//目标位置不在同一缓冲区
			difference_type node_offset = offset > 0 ?
				offset / difference_type(buffer_size()) : -difference_type((-offset - 1) / buffer_size()) - 1;
			set_node(node + node_offset);
			cur = first + (offset - node_offset * difference_type(buffer_size()));
		}
		return *this;
	}

	self operator+(difference_type n) const
	{
		self temp = *this;
		return temp += n;
	}

	self& operator-=(difference_type n)
	{
		return *this += (-n);
	}

	self operator-(difference_type n)
	{
		self temp = *this;
		return temp -= n;
	}

	reference operator[](difference_type n) const
	{
		return *(*this + n);
	}

	bool operator==(const self& x) const{
		return cur == x.cur;
	}
	
	bool operator!=(const self& x) const
	{
		return !(*this == x);
	}

	bool operator<(const self& x) const
	{
		return (node == x.node) ? (cur < x.cur) : (node < x.node);
	}
};