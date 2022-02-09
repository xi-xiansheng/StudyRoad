#pragma once

namespace MyList
{
	template<class T>
	struct __list_node
	{
		__list_node<T>* _prev;
		__list_node<T>* _next;
		T _data;

		__list_node(const T& val = T())
			:_prev(nullptr)
			,_next(nullptr)
			,_data(val)
		{

		}
	};

	//迭代器
	template<class T, class Ref, class Ptr>
	struct __list_iterator
	{
		

		typedef __list_iterator<T, Ref, Ptr> self;
		typedef __list_node<T> Node;
		
		Node* _node;

		__list_iterator(Node* node)
			:_node(node)
		{
			
		}



		Ref	operator*()
		{
			return _node->_data;
		}

		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		self operator++(int)
		{
			self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		self operator--(int)
		{
			self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}
		 
		
		Ptr operator->()
		{
			return &_node->_data;
		}

		bool operator!= (const self& it)const
		{
			return it._node != _node;
		}

		bool operator== (const self& it)const
		{
			return it._node == _node;
		}

		
	};


	template <class T>
	class list
	{
		typedef __list_node<T> Node;

	public:
		typedef  __list_iterator<T, T&, T*> iterator;
		typedef  __list_iterator<T, const T&, const T*> const_iterator;

		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}

		list()
		{
			//带头双向循环链表
			//_head = new Node(T());
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		void push_back(const T& val)
		{
			/*Node* tail = _head->_prev;
			Node* newnode = new Node(val);

			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;*/

			insert(end(), val);
		}

		void push_front(const T& val)
		{
			insert(begin(), val);
		}

		iterator insert(iterator pos, const T& val)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;

			Node* newnode = new Node(val);

			newnode->_next = cur;
			newnode->_prev = prev;
			prev->_next = newnode;
			cur->_prev = newnode;

			return iterator(newnode);
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;
			prev->_next = next;
			next->_prev = prev;
			delete cur;

			return iterator(next);
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		size_t size()
		{
			size_t sz = 0;
			iterator it = begin();
			
			while (it != end())
			{
				++sz;
				++it;
			}
			return sz;
		}

		bool empty() const
		{
			return begin() == end();
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		/*list<T>& operator=(const list<T>& lt)
		{
			if (&lt != this)
			{
				list<T> tmp(lt);
				std::swap(tmp._head, _head);
				return *this;
			}
		}*/

		//现代写法
		list<T>& operator=(list<T> lt)
		{
			std::swap(lt._head, _head);
			return *this;
		}


		list(const list<T>& lt)
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			for (const auto& e : lt)
			{
				push_back(e);
			}
		}

		template<class InputIterator>
		list(InputIterator first, InputIterator last)
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}

		//现代写法
		/*list(const list<T>& lt)
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _heda;
			
			list<T>tmp(lt.begin(), lt.end());
			std::swap(_head, tmp._head);
		}*/


		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

	private:
		Node* _head;
	};


	void test_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		cout << "sz:" << lt.size() << endl;
		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;


		lt.pop_back();
		lt.pop_front();

		list<int>::iterator it = lt.begin();

		cout << "sz:" << lt.size() << endl;
		while (it != lt.end())
		{
			//*it *= 2;
			cout << *it << " ";
			++it;
		}
		cout << endl;	
	}

	void test_list2()
	{
		list<int> lt1;
		lt1.push_back(1);
		lt1.push_back(2);
		lt1.push_back(3);
		lt1.push_back(4);
		for (auto e : lt1)
		{
			cout << e << " ";
		}
		cout << endl;

		list<int> lt2(lt1);
		for (auto e : lt2)
		{
			cout << e << " ";
		}
		cout << endl;

		list<int> lt3(lt1.begin(), lt1.end());
		string s("hello");
		list<int> lt4(s.begin(), s.end());

		for (auto e : lt3)
		{
			cout << e << " ";
		}
		cout << endl;

		for (auto e : lt4)
		{
			cout << e << " ";
		}
		cout << endl;

		lt1 = lt4;

		for (auto e : lt1)
		{
			cout << e << " ";
		}
		cout << endl;
	}

}



