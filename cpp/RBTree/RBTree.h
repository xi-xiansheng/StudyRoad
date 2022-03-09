#pragma once

enum COLOR
{
	BLACK,
	RED
};

template<class K, class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;

	pair<K, V> _kv;
	COLOR _color;

	RBTreeNode(const pair<K, V>& kv)
		:_left(nullptr),
		_right(nullptr),
		_parent(nullptr),
		_kv(kv),
		_color(RED)
	{

	}
};

template<class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	RBTree()
		:_root(nullptr)
	{
	}

	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_color = BLACK;
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;

		while (cur)
		{
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(kv);
		cur->_parent = parent;
		if (parent->_kv.first > kv.first)
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}

		while (parent && parent->_color == RED)
		{
			Node* grandparent = parent->_parent;
			Node* uncle = nullptr;
			if (grandparent && grandparent->_left == parent)
			{
				uncle = grandparent->_right;
			}
			else if (grandparent && grandparent->_right == parent)
			{
				uncle = grandparent->_left;
			}
			else
			{
				return false;
			}

			//情况一：cur为红，p为红，g为黑，u存在且为红
			if (grandparent->_color == BLACK && uncle && uncle->_color == RED)
			{
				grandparent->_color = RED;
				uncle->_color = BLACK;
				parent->_color = BLACK;
				cur = grandparent;
				parent = cur->_parent;
				if (grandparent == _root)
				{
					_root->_color = BLACK;
					return true;
				}
			}
			else if (grandparent->_color == BLACK && (uncle == nullptr || uncle->_color == BLACK))
			{
				//情况二: cur为红，p为红，g为黑，u不存在/u为黑
				if (parent == grandparent->_left && cur == parent->_left)
				{
					//右单旋
					RotateR(grandparent);
					parent->_color = BLACK;
					grandparent->_color = RED;
					return true;
				}
				else if (parent == grandparent->_right && cur == parent->_right)
				{
					//左单旋
					RotateL(grandparent);
					parent->_color = BLACK;
					grandparent->_color = RED;
					return true;
				}
				//情况三
				else if (parent == grandparent->_left && cur == parent->_right)
				{
					RotateL(parent);
					RotateR(grandparent);
					grandparent->_color = RED;
					cur->_color = BLACK;
					return true;
				}
				else if (parent == grandparent->_right && cur == parent->_left)
				{
					RotateR(parent);
					RotateL(grandparent);
					grandparent->_color = RED;
					cur->_color = BLACK;
					return true;
				}
				else
				{
					return false;
				}
			}
		}
		return true;
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	bool CheckBlackNum(Node* cur, int blackNum, int benchmark) {
		if (cur == nullptr) 
		{
			if (blackNum != benchmark) {
				cout << "违反规则四：黑色节点的数量不相等" << endl;
				return false;
			}
			return true;
		}

		if (cur->_color == BLACK)
			++blackNum;

		return CheckBlackNum(cur->_left, blackNum, benchmark)
			&& CheckBlackNum(cur->_right, blackNum, benchmark);
	}

	bool Check3(Node* root)
	{
		if (root == nullptr)
			return true;
		if (root->_color == RED)
		{
			if (root->_left && root->_left->_color == RED)
			{
				cout << "违反性质三：存在连续的红色节点" << endl;
				return false;
			}
				
			if (root->_right && root->_right->_color == RED)
			{
				cout << "违反性质三：存在连续的红色节点" << endl;
				return false;
			}
		}
		return Check3(root->_left) && Check3(root->_right);
	}

	void Chcke()
	{
		if (_root == nullptr)
			return;
		if (_root->_color == RED)
		{
			cout << "违反性质二：根节点是黑色的" << endl;
		}
		Check3(_root);
		int benchmark = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_color == BLACK)
			{
				++benchmark;
			}

			cur = cur->_left;
		}

		int blackNum = 0;
		CheckBlackNum(_root, blackNum, benchmark);
	}

private:
	//左单旋
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}

		Node* pnode = parent->_parent;

		subR->_left = parent;
		parent->_parent = subR;

		if (parent == _root)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (parent == pnode->_left)
				pnode->_left = subR;
			else
				pnode->_right = subR;
			subR->_parent = pnode;
		}
		
	}

	//右单旋
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}

		Node* pnode = parent->_parent;

		parent->_parent = subL;
		subL->_right = parent;

		if (pnode == nullptr)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (parent == pnode->_right)
				pnode->_right = subL;
			else
				pnode->_left = subL;
			subL->_parent = pnode;
		}
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_kv.first << " ";
		_InOrder(root->_right);
	}

	Node* _root;
};


void testBalance()
{

	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	//int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	const int n = 1000000;
	vector<int> a;
	a.reserve(n);
	srand(time(0));
	for (size_t i = 0; i < n; ++i)
	{
		a.push_back(rand());
	}

	RBTree<int, int> t1;
	for (auto e : a)
	{
		t1.Insert(make_pair(e, e));
	}
	//t1.InOrder();
	t1.Chcke();

}











