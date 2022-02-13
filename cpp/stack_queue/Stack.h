#pragma once
#include <list>
namespace my_stack
{
	template<class T, class Container = std::deque<T> >
	class stack
	{
	public:
		bool empty() const
		{
			return _con.empty();
		}

		size_t size() const
		{
			return _con.size();
		}

		const T& top() const
		{
			return _con.back();
		}

		void push(const T& val)
		{
			_con.push_back(val);
		}

		void pop()
		{
			_con.pop_back();
		}


	private:
		Container _con;
	};

	void test_stack()
	{
		//stack<int, std::vector<int>> st;
		//stack<int, std::list<int>> st;
		stack<int> st;
		st.push(1);
		st.push(2);
		st.push(3);
		st.push(4);

		while (!st.empty())
		{
			cout << st.top() << " ";
			st.pop();
		}
		cout << endl;
	}

}