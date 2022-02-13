#pragma once
#include <deque>
#include <list>
namespace my_queue
{
	template<class T, class Container = std::deque<T> >
	class queue
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

		const T& front() const
		{
			return _con.front();
		}

		const T& back() const
		{
			return _con.back();
		}

		void push(const T& val)
		{
			_con.push_back(val);
		}

		void pop()
		{
			_con.pop_front();
		}

	private:
		Container _con;
	};

	void test_queue()
	{
		//queue<int, std::vector<int>> st; // vector头删效率低，不能头删，所以不能适配
		queue<int, std::list<int>> st;
		//queue<int> st;
		st.push(1);
		st.push(2);
		st.push(3);
		st.push(4);

		while (!st.empty())
		{
			cout << st.front() << " ";
			st.pop();
		}
		cout << endl;
	}


}