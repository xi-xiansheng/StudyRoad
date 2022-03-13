#pragma once
#pragma once

enum COLOR
{
	BLACK,
	RED
};

template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;

	T _data;
	COLOR _color;

	RBTreeNode(const T& data)
		:_left(nullptr),
		_right(nullptr),
		_parent(nullptr),
		_data(data),
		_color(RED)
	{
	}
};

template<class T, class Ref, class Ptr>
struct RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef RBTreeIterator<T, Ref, Ptr> Self;
	Node* _node;
	RBTreeIterator(Node* node = nullptr)
		:_node(node)
	{
	
	}

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &_node->_data;
	}

	Self& operator--()
	{
		if (_node->_left == nullptr)
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && parent->_left == cur)
			{
				cur = parent;
				parent = parent->_parent;
			}
			_node = parent;
		}
		else
		{
			Node* left, right;
			left = right = _node->_left;
			while (right && right->_right)
			{
				right = right->_right;
			}
			_node = right;
		}
		return *this;
	}

	Self& operator++()
	{
		if (_node->_right == nullptr)
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && parent->_right == cur)
			{
				cur = parent;
				parent = parent->_parent;
			}
			_node = parent;
		}
		else
		{
			Node* left, *right;
			left = right = _node->_right;
			while (left && left->_left)
			{
				left = left->_left;
			}
			_node = left;
		}
		return *this;
	}

	bool operator!=(const Self& s) const
	{
		return _node != s._node;
	}

	bool operator==(const Self& s) const
	{
		return _node == s._node;
	}
};




template<class K, class T, class KeyOfT>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	RBTree()
		:_root(nullptr)
	{
	}
	typedef RBTreeIterator<T, T&, T*> iterator;
	typedef RBTreeIterator<T, const T&, const T*> const_iterator;

	pair<iterator, bool> Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_color = BLACK;
			return make_pair(_root,true);
		}

		Node* parent = nullptr;
		Node* cur = _root;
		KeyOfT kot;
		while (cur)
		{
			if (kot(cur->_data) > kot(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (kot(cur->_data) < kot(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return make_pair(iterator(cur), false);
			}
		}
		cur = new Node(data);
		cur->_parent = parent;
		if (kot(parent->_data) > kot(data))
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}

		Node* tmp = cur;
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
				return make_pair(iterator(tmp), false);
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
					return make_pair(iterator(tmp), true);
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
					return make_pair(iterator(tmp), true);
				}
				else if (parent == grandparent->_right && cur == parent->_right)
				{
					//左单旋
					RotateL(grandparent);
					parent->_color = BLACK;
					grandparent->_color = RED;
					return make_pair(iterator(tmp), true);
				}
				//情况三
				else if (parent == grandparent->_left && cur == parent->_right)
				{
					RotateL(parent);
					RotateR(grandparent);
					grandparent->_color = RED;
					cur->_color = BLACK;
					return make_pair(iterator(tmp), true);
				}
				else if (parent == grandparent->_right && cur == parent->_left)
				{
					RotateR(parent);
					RotateL(grandparent);
					grandparent->_color = RED;
					cur->_color = BLACK;
					return make_pair(iterator(tmp), true);
				}
				else
				{
					return make_pair(iterator(tmp),false);
				}
			}
		}
		return make_pair(iterator(tmp), true);
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	/*bool CheckBlackNum(Node* cur, int blackNum, int benchmark) {
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
	}*/

	iterator begin()
	{
		Node* left = _root;
		while (left && left->_left)
		{
			left = left->_left;
		}

		//return left;
		return iterator(left);
	}

	iterator end()
	{
		return iterator(nullptr);
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
		cout << root->_data.first << " ";
		_InOrder(root->_right);
	}

	Node* _root;
};
