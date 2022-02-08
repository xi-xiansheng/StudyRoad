#pragma once

namespace my_vector
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		const_iterator begin()const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		iterator begin()
		{
			return _start;
		}

		iterator end() 
		{
			return _finish;
		}

		void swap(vector<T>& v)
		{
			std::swap(v._start, _start);
			std::swap(v._finish, _finish);
			std::swap(v._endofstorage, _endofstorage);
		}


		//构造函数
		vector()
			:_start(nullptr),
			_finish(nullptr),
			_endofstorage(nullptr)
		{

		}

		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		//拷贝构造函数
		//传统写法
		/*vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(v.capacity());
			for (const auto& e : v)
			{
				push_back(e);
			}
		}*/

		//现代写法
		vector(const vector<T>& v)
			:_start(nullptr),
			_finish(nullptr),
			_endofstorage(nullptr)
		{
			//调用构造函数
			vector<T> tmp(v.begin(), v.end());
			swap(tmp);		
		}

		//重载=
		//传统写法
		/*vector<T>& operator=(const vector<T>& v)
		{
			if (this != &v)
			{
				delete[]_start;
				_start = _finish = _endofstorage = nullptr;
				reserve(v.capacity);
				for (const auto& e : v)
				{
					push_back(e);
				}
			}
			return *this;
		}*/

		//现代写法
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}

		size_t capacity() const
		{
			return _endofstorage - _start;
		}

		size_t size() const
		{
			return _finish - _start;
		}

		//重载[]
		T& operator[] (size_t n)
		{
			assert(n < size());
			return _start[n];
		}

		const T& operator[] (size_t n) const
		{
			assert(n < size());
			return _start[n];
		}

		//只开空间
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				if (_start)
				{
					//memcpy(tmp, _start, sz * sizeof(T));   //深浅拷贝问题
					for (size_t i = 0; i < sz; i++)
					{
						//若为string，则调用string的 =
						tmp[i] = _start[i];
					}
					delete[]_start;
				}
				_start = tmp;
				_finish = _start + sz;
				_endofstorage = _start + n;
			}
		}

		//开空间+初始化
		void resize(size_t n,const T& val = T())
		{
			if (n <= size())
			{
				_finish = _start + n;
			}
			else 
			{
				if (n > capacity())
				{
					reserve(n);
				}
				while (_finish != end())
				{
					*_finish = val;
					_finish++;
				}
			}
		}

		void push_back(const T& val)
		{
			/*if (_finish == _endofstorage)
			{
				size_t newcapacity = capacity() == 0 ? 4 : 2 * capacity();
				reserve(newcapacity);
			}
			*_finish = val;
			_finish++;*/

			insert(end(), val);
		}

		//重载insert
		iterator insert(iterator pos, const T& val)
		{
			assert(pos >= _start && pos <= _finish);
			if (_finish == _endofstorage)
			{
				size_t len = pos - _start;
				size_t newcapacity = capacity() == 0 ? 4 : 2 * capacity();
				reserve(newcapacity);
				pos = _start + len;
			}
			iterator it = end();
			while (it != pos)
			{
				*it = *(it - 1);
				it--;
			}
			*pos = val;
			_finish++;

			return pos;
		}

		void insert(iterator pos, size_t n, const T& val)
		{
			assert(pos >= _start && pos <= _finish);
			if (_finish  + n >= _endofstorage)
			{
				size_t len = pos - _start;
				size_t newcapacity = capacity() == 0 ? 4 : capacity() + n;
				reserve(newcapacity);
				pos = _start + len;
			}
			iterator it = end() + n;
			while (it != pos + n - 1)
			{
				*it = *(it - n);
				it--;
			}
			for (size_t i = 0; i < n; i++)
			{
				*(pos + i) = val;
			}		
			_finish += n;
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finish);

			iterator it = pos;
			while (it != _finish)
			{
				*it = *(it + 1);
				it++;
			}
			--_finish;
			return pos;
		}

		void pop_back()
		{
			erase(--end());
		}


		//析构函数
		~vector()
		{
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}



	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};


	void test1()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<int> v2(v1);
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;
		v2.push_back(5);
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;
		v2 = v1;
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;

	}

	void test2()
	{
		vector<string> v1;
		v1.reserve(4);
		v1.push_back("1111");
		v1.push_back("2222");
		v1.push_back("3333");
		v1.push_back("4444");
		v1.push_back("5555");
		for (auto e : v1)
		{
			cout << e << endl;
		}
		vector<string>v2(v1);
		for (auto e : v2)
		{
			cout << e << endl;
		}
		v2.insert(v2.begin(), 5, "0000");
		cout << endl << endl;
		for (auto e : v2)
		{
			cout << e << endl;
		}
		printf("%p\n", v1.begin());
		printf("%p\n", v2.begin());
		printf("%p\n", v1.end());
		printf("%p\n", v2.end());

	}


	void test_vector()
	{

		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);

		cout << "V1: ";
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		v1.erase(v1.end() - 1);
		cout << "V1: ";
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		cout << "V2: ";
		vector<int> v2(v1);
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;

		string s("abcde");
		vector<int> v3(v1.begin(), v1.end());
		vector<int> v4(s.begin(), s.end());

		v1 = v4;
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
	}



}

