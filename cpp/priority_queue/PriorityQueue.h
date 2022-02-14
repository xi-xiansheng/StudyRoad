#pragma once
#include <vector>
#include <list>

namespace my_priority_queue
{
	template <class T>
	class Less
	{
	public:
		bool operator()(const T& x, const T& y)
		{
			return x < y;
		}
	};

	template <class T>
	class Greater
	{
	public:
		bool operator()(const T& x, const T& y)
		{
			return x > y;
		}
	};


	template <class T, class Container = vector<T>,class Compare = less<typename Container::value_type> >
	class priority_queue
	{
	public:
		void AdjustDown(size_t parent)
		{
			Compare com;
			size_t child = 2 * parent + 1;
			
			while (child < _con.size())
			{
				if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))
				{
					child++;
				}
				if (com(_con[parent],_con[child]))
				{
					std::swap(_con[parent], _con[child]);
					parent = child;
					child = 2 * parent + 1;
				}
				else
				{
					break;
				}
			}		
		}

		void AdjustUp(size_t child)
		{
			Compare com;
			int parent = int((child - 1) / 2);
			while (child > 0)
			{
				if (com(_con[parent], _con[child]))
				{
					std::swap(_con[parent], _con[child]);	
					child = parent;
					parent = (parent - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}

		bool empty() const
		{
			return _con.empty();
		}

		const T& top() const
		{
			return _con[0];
		}

		void push(const T& val)
		{
			_con.push_back(val);			
			AdjustUp(_con.size() - 1);
		}

		void pop()
		{
			std::swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			AdjustDown(0);
		}

		const size_t size()const
		{
			return _con.size();
		}

		template <class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				_con.push_back(*first);
				first++;
			}
			//½¨¶Ñ
			for (int i = int((_con.size() - 1 - 1) / 2); i >= 0; --i)
			{
				AdjustDown(i);
			}
		}

	private:
		Container _con;

	};


	void test_priority_queue()
	{


		list<int> lt = { 3, 4, 5, 6, 2, 10 };
		//priority_queue<int, vector<int>, greater<int>> pq;
		priority_queue<int, vector<int>, greater<int>> pq(lt.begin(), lt.end());
		//priority_queue<int> pq(lt.begin(), lt.end());
		pq.push(1);
		pq.push(10);
		pq.push(11);
		pq.push(3);
		pq.push(5);
		pq.push(8);

		//cout << pq.top() << endl;
		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;
	}


}