#pragma once

template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	pair<K, V> _kv;

	int _BalanceFactor;

	AVLTreeNode(const pair<K, V>& kv)
		:_left(nullptr),
		_right(nullptr),
		_parent(nullptr),
		_kv(kv),
		_BalanceFactor(0)
	{
	}
};


template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:

	AVLTree()
		:_root(nullptr)
	{
	}

	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		Node* cur = _root;
		Node* parent = nullptr;

		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		if (parent->_kv.first > cur->_kv.first)
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		cur->_parent = parent;

		//判断平衡
		while (parent)
		{
			if (parent->_left == cur)
			{
				parent->_BalanceFactor--;
			}
			else
			{
				parent->_BalanceFactor++;
			}

			if (parent->_BalanceFactor == 0)
			{
				break;
			}
			else if (parent->_BalanceFactor == 1 || parent->_BalanceFactor == -1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_BalanceFactor == 2 || parent->_BalanceFactor == -2)
			{
				if (parent->_BalanceFactor == 2 && cur->_BalanceFactor == 1)
				{
					//右右——左单旋
					RotateL(parent);
				}
				else if (parent->_BalanceFactor == -2 && cur->_BalanceFactor == -1)
				{
					//左左——右单旋
					RotateR(parent);
				}
				else if (parent->_BalanceFactor == 2 && cur->_BalanceFactor == -1)
				{
					RotateRL(parent);
				}
				else if (parent->_BalanceFactor == -2 && cur->_BalanceFactor == 1)
				{
					RotateLR(parent);
				}
				else
				{
					assert(false);
				}
				break;
			}
			else
			{
				assert(false);
			}
		}
		return true;
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

		subR->_BalanceFactor = parent->_BalanceFactor = 0;
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

		subL->_BalanceFactor = parent->_BalanceFactor = 0;
	}

	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		int bf = subLR->_BalanceFactor;
		//右右——左单旋
		RotateL(parent->_left);
		//左左——右单旋
		RotateR(parent);

		if (bf == -1)
		{
			subLR->_BalanceFactor = 0;
			subL->_BalanceFactor = 0;
			parent->_BalanceFactor = 1;
		}
		else if (bf == 1)
		{
			subLR->_BalanceFactor = 0;
			subL->_BalanceFactor = -1;
			parent->_BalanceFactor = 0;
		}
		else if (bf == 0)
		{
			subLR->_BalanceFactor = 0;
			subL->_BalanceFactor = 0;
			parent->_BalanceFactor = 0;
		}
		else
		{
			assert(false);
		}
	}
	 
	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_BalanceFactor;
		//右右——左单旋
		RotateR(subR);
		//左左——右单旋
		RotateL(parent);

		if (bf == -1)
		{
			subR->_BalanceFactor = 1;
			parent->_BalanceFactor = 0;
			subRL->_BalanceFactor = 0;
		}
		else if(bf == 1)
		{
			subR->_BalanceFactor = 0;
			parent->_BalanceFactor = -1;
			subRL->_BalanceFactor = 0;
		}
		else if (bf == 0)
		{
			subR->_BalanceFactor = 0;
			parent->_BalanceFactor = 0;
			subRL->_BalanceFactor = 0;
		}
		else
		{
			assert(false);
		}	
	}


	int Height(Node* root)
	{
		if (root == nullptr)
			return 0;

		int leftHeight = Height(root->_left);
		int rightHeight = Height(root->_right);
		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}

	bool _IsBalance(Node* root)
	{
		if (root == nullptr)
			return true;

		int leftHeight = Height(root->_left);
		int rightHeight = Height(root->_right);
		if (rightHeight - leftHeight != root->_BalanceFactor)
		{
			cout << "平衡因子异常:" << root->_kv.first << endl;
		}

		return abs(rightHeight - leftHeight) < 2
			&& _IsBalance(root->_left)
			&& _IsBalance(root->_right);
	}

public:
	bool IsBalance()
	{
		return _IsBalance(_root);
	}



private:

	Node* _root;
};

void TestAVLTree2()
{
	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };

	AVLTree<int, int> t1;
	for (auto e : a)
	{
		t1.Insert(make_pair(e, e));
	}
	cout << t1.IsBalance() << endl;
}

/*
bool _IsBalanceTree(AVLTreeNode<int, int>* pRoot);

void TestAVLTree()
{
	AVLTree<int, int> t1;
	t1.Insert(make_pair(1, 1));
	t1.Insert(make_pair(2, 2));
	t1.Insert(make_pair(3, 3));
	t1.Insert(make_pair(4, 4));
	t1.Insert(make_pair(5, 5));
	t1.Insert(make_pair(6, 6));

	
	_IsBalanceTree(t1.test());


}


int TreeDepth(AVLTreeNode<int, int>* pRoot) {
	if (pRoot == nullptr)
		return 0;
	int left = TreeDepth(pRoot->_left);
	int right = TreeDepth(pRoot->_right);
	return left > right ? left + 1 : right + 1;
}

bool _IsBalanceTree(AVLTreeNode<int, int>* pRoot)
{
	// 空树也是AVL树
		if (nullptr == pRoot) return true;
	// 计算pRoot节点的平衡因子：即pRoot左右子树的高度差
	int leftHeight = TreeDepth(pRoot->_left);
	int rightHeight = TreeDepth(pRoot->_right);
	int diff = rightHeight - leftHeight;
	// 如果计算出的平衡因子与pRoot的平衡因子不相等，或者
	// pRoot平衡因子的绝对值超过1，则一定不是AVL树
	if (diff != pRoot->_BalanceFactor || (diff > 1 || diff < -1))
	{
		cout << pRoot->_kv.first << ": " << diff << " bf:" << pRoot->_BalanceFactor << endl;
		return false;
	}
	// pRoot的左和右如果都是AVL树，则该树一定是AVL树
	return _IsBalanceTree(pRoot->_left) && _IsBalanceTree(pRoot->_right);
}*/
