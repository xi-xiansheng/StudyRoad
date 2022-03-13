#pragma once
#include "RBTree.h"

template<class K>
class set
{

	struct SetKeyOfT
	{
		const K& operator()(const K& key)
		{
			return key;
		}
	};
public:
	typedef K key_type;
	typedef K key_value;

	typedef typename RBTree<K, K, SetKeyOfT>::iterator iterator;

	iterator begin()
	{
		return _t.begin();
	}

	iterator end()
	{
		return nullptr;
	}

	pair<iterator, bool> insert(const K& key)
	{
		return _t.Insert(key);
	}


private:
	RBTree <key_type, key_value, SetKeyOfT> _t;
};

void test_set()
{
	set<int> s;
	s.insert(1);
	s.insert(3);
	s.insert(7);
	s.insert(2);
	s.insert(12);
	s.insert(22);
	s.insert(2);
	s.insert(23);
	s.insert(-2);
	s.insert(-9);
	s.insert(30);

	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}