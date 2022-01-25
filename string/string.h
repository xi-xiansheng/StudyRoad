#pragma once
#include<assert.h>
#include<string.h>
#include<iostream>

using namespace std;

namespace my_string
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const_iterator begin()const
		{
			return _str;
		}

		const_iterator end()const
		{
			return _str + _size;
		}


		//构造函数
		/*string()
			:_size(0),
			_capacity(0),
			_str(new char[1])
		{
			*_str = '\0';
		}*/

		string(const char* str= "")
			:_size(strlen(str)),
			_capacity(_size)
		{
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		//析构函数
		~string()
		{
			delete[] _str;
			_str = nullptr;
		}

		//拷贝构造函数
		//深拷贝
		//传统写法
		/*string(const string& s)
		{
			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}*/

		//现代写法

		string(const string& s)
			:_str(nullptr)
		{
			//调用构造函数
			string tmp(s._str);
			//实行交换
			std::swap(_str, tmp._str);
			_size = s._size;
			_capacity = s._capacity;
		}

		//读写
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		//只读
		const char& operator[](size_t pos)const
		{
			assert(pos < _size);
			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}

		void resize(size_t n,char c = '\0')
		{
			if (n < _size)
			{
				_str[n] = '\0';
			}
			else
			{
				if (n > _capacity)
				{
					reserve(n);
				}
				for (size_t i = _size; i < n; i++)
				{
					_str[i] = c;
				}
				_str[n] = '\0';
			}
			_size = n;
		}

		
		size_t size()const
		{
			return _size;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		void clear()
		{
			for (size_t i = 0; i < _size; i++)
			{
				_str[i] = '\0';
			}
			_size = 0;
		}
		
		// 重载+=
		string& operator+=(const char* c )
		{
			/*size_t n = strlen(c);
			if ( n + _size > _capacity)
			{
				reserve(n + _size);
			}
			for (size_t i = 0; i < n; i++)
			{
				_str[i + _size] = c[i];
			}
			_size += n;
			_str[_size] = '\0';*/

			append(c);

			return *this;
		}

		string& operator+=(char c)
		{
			/*if (1 + _size > _capacity)
			{
				reserve(1 + _size);
			}
			_str[_size] = c;
			_size += 1;
			_str[_size] = '\0';*/

			push_back(c);

			return *this;
		}

		// 重载=
		string& operator=(const string s)
		{
			//调用拷贝构造函数
			string tmp(s);
			std::swap(_str, tmp._str);
			_size = tmp._size;
			_capacity = tmp._capacity;
			return *this;
		}

		string& operator=(const char* s)
		{
			//调用构造函数
			string tmp(s);
			std::swap(_str, tmp._str);
			_size = tmp._size;
			_capacity = tmp._capacity;
			return *this;
		}

		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				reserve(_capacity + 1);
			}
			_str[_size] = ch;
			_size += 1;
			_str[_size] = '\0';
		}

		void append(const char* str)
		{
			size_t n = strlen(str);
			if (n + _size > _capacity)
			{
				reserve(n + _size);
			}
			for (size_t i = 0; i < n; i++)
			{
				_str[_size + i] = *(str + i);
			}
			_size += n;
			_str[_size] = '\0';
		}

		//重载insert
		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				reserve(_capacity + 1);
			}
			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}
			_size += 1;
			_str[pos] = ch;
			
			return *this;
		}

		string& insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				reserve(_capacity + strlen(str));
			}
			size_t len = strlen(str);
			size_t end = _size + len;

			while (end >= pos + len)
			{
				_str[end] = _str[end - len];
				--end;
			}
			for (size_t i = 0; i < len; i++)
			{
				_str[pos + i] = str[i];
			}
			_size += len;
			return *this;
		}

		string& erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);
			if (len == npos || len + pos >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
			

			return *this;
		}
	

		const char* c_str()
		{
			return _str;
		}


	private:
		char* _str;
		size_t _size;
		size_t _capacity; // 不包含最后做标识的  '\0'

		static const size_t npos;
	};
	const size_t string::npos = -1;

	// 存在深拷贝对象，尽量少用
	string operator+(const string& s1, char ch)
	{
		string ret = s1;
		ret += ch;
		return ret;
	}

	string operator+(const string& s1, const char* str)
	{
		string ret = s1;
		ret += str;
		return ret;
	}

	istream& getline(istream& in, string& s)
	{
		s.clear();
		char ch;
		ch = in.get();
		while (ch != '\n')
		{
			s += ch;
			ch = in.get();
		}
		return in;
	}

	ostream& operator<<(ostream& out, const string& s)
	{
		for (int i = 0; i < s.size(); i++)
		{
			out << s[i];
		}
		return out;
	}

	istream& operator>>(istream& in, string& s)
	{
		s.clear();
		char ch;
		ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			s += ch;
			ch = in.get();
		}
		return in;
	}

	bool operator>(const string& s1, const string& s2)
	{
		size_t i1 = 0, i2 = 0;
		while (i1 < s1.size() && i2 < s2.size())
		{
			if (s1[i1] > s2[i2])
			{
				return true;
			}
			else if (s1[i1] < s2[i2])
			{
				return false;
			}
			else
			{
				++i1;
				++i2;
			}
		}
		if (i1 == s1.size())
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	bool operator==(const string& s1, const string& s2)
	{
		size_t i1 = 0, i2 = 0;
		while (i1 < s1.size() && i2 < s2.size())
		{
			if (s1[i1] != s2[i2])
			{
				return false;
			}
			else
			{
				++i1;
				++i2;
			}
		}

		if (i1 == s1.size() && i2 == s2.size())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	inline bool operator!=(const string& s1, const string& s2)
	{
		return !(s1 == s2);
	}

	inline bool operator>=(const string& s1, const string& s2)
	{
		return s1 > s2 || s1 == s2;
	}

	inline bool operator<(const string& s1, const string& s2)
	{
		return !(s1 >= s2);
	}

	inline bool operator<=(const string& s1, const string& s2)
	{
		return !(s1 > s2);
	}


	void test_string1()
	{
		string s1("hello");
		string s2(s1);
		cout << "s1:" << s1 << endl;
		s1 += " world";
		s1 += "!";
		cout << "s1:" << s1 << endl;
		
		//cin >> s2;
		s2 += '!';
		cout << "s2:" << s2 << endl;
		//getline(cin, s2);
		cout << "s2:" << s2 << endl;
		s2 = s1;
		cout << "s2:" << s2 << endl;
		s2 = "nice to meet you!";
		cout << "s2:" << s2 << endl;
	}
	void test_string2()
	{
		string s1("hello");
		string s2(s1);
		s1 += " world";

		cout << "s1:" << s1 << endl;
		s2 = s1;

		cout << "s2:" << s2 << endl;
		s1 += "!";
		s1 += "!";
		cout << "s1:" << s1 << endl;
		s2.append("my son");
		cout << "s2:" << s2 << endl;
		s1 += '?';
		cout << "s1:" << s1 << endl;
		s1 = "abcd";
		s1.insert(0, 'z');
		cout << "s1:" << s1 << endl;
		s1.insert(5, 'g');
		cout << "s1:" << s1 << endl;
		s1.insert(6, "xy");
		cout << "s1:" << s1 << endl;
		s1.erase(1, 4);
		cout << "s1:" << s1 << endl;
		s1 = "hello!";
		s2 = "hello!";
		cout << endl << endl << endl;
		if (s1 == s2)
			cout << "s1 == s2" << endl;
		s2 = "gello!";
		if (s1 == s2)
			cout << "s1 == s2" << endl;
		if (s1 <= s2)
			cout << "s1 <= s2" << endl;
		if (s1 >= s2)
			cout << "s1 >= s2" << endl;
		if (s1 > s2)
			cout << "s1 > s2" << endl;
	}

}