#pragma once
#include "RBTree.h"

template<class K, class V>
class map
{
public:
	typedef K key_type;
	typedef pair<K, V> key_value;

	struct MapKeyOfT
	{
		const K& operator()(const pair<K, V>& kv)
		{
			return kv.first;
		}
	};

	typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::iterator iterator;

	iterator begin()
	{
		return _t.begin();
	}

	iterator end()
	{
		return nullptr;
	}

	pair<iterator, bool> insert(const pair<const K, V>& kv)
	{
		return _t.Insert(kv);
	}

	V& operator[](const K& key)
	{
		pair<iterator, bool> ret = _t.Insert(make_pair(key, V()));
		return ret.first->second;
	}

private:
	RBTree<K, pair<const K, V>, MapKeyOfT> _t;
};

void test_map()
{
	map<string, string> dict;
	dict.insert(make_pair("sort", ""));
	dict.insert(make_pair("string", ""));
	dict.insert(make_pair("debug", ""));
	dict.insert(make_pair("set", ""));
	dict["make"];
	dict["debug"] = "调试";
	dict["insert"] = "插入";

	map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;
}
