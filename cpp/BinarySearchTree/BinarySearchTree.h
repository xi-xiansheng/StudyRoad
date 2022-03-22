#pragma once
namespace KEY
{
	template<class K>
	struct BinarySearchTreeNode
	{
		BinarySearchTreeNode * _left;
		BinarySearchTreeNode * _right;
		K _key;

		BinarySearchTreeNode(const K& key)
			:_left(nullptr),
			_right(nullptr),
			_key(key)
		{	
		}
	};

	template<class K>
	class BSTree
	{
		typedef BinarySearchTreeNode<K> Node;

	public:
		BSTree()
			:_root(nullptr)
		{
		}
	
		BSTree(const BSTree& bst)
		{
			_root = _Copy(bst._root);
		}

		BSTree<K>& operator=(BSTree<K> t)
		{
			std::swap(_root, t._root);
			//std::swap(_root, bst._root);
			return *this;
		}

		~BSTree()
		{
			_Destroy(_root);
		}


		bool insert(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;
			
			if (parent == cur)
			{
				_root = new Node(key);
				return true;
			}
			while (cur)
			{
				parent = cur;
				if (key > cur->_key)
					cur = cur->_right;
				else if (key < cur->_key)
					cur = cur->_left;
				else
					return false;
			}
			if (parent->_key < key)
				parent->_right = new Node(key);
			else
				parent->_left = new Node(key);
			return true;
		}

		Node* find(const K& key)
		{
			//Node* parent = nullptr;
			Node* cur = _root;

			while (cur)
			{
				if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else
				{
					//if(parent->_left==cur)
					return cur;
				}
			}
			return cur;
		}

		bool Erase(const K& key)
		{
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur)
			{		
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					if (cur->_left == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{
							if (parent->_left == cur)
							{
								parent->_left = cur->_right;
							}
							else
							{
								parent->_right = cur->_right;
							}
						}	
						delete cur;
					}
					else if (cur->_right == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_left;
						}
						else
						{
							if (parent->_left == cur)
							{
								parent->_left = cur->_left;
							}
							else
							{
								parent->_right = cur->_left;
							}
						}
						delete cur;
					}
					else
					{
						Node* minRightParent = cur;
						Node* minRight = cur->_right;
						while (minRight->_left)
						{
							minRightParent = minRight;
							minRight = minRight->_left;
						}
						cur->_key = minRight->_key;
						if (minRightParent->_right == minRight)
							minRightParent->_right = minRight->_right;
						else
							minRightParent->_left = minRight->_right;
						delete minRight;
					}
					return true;
				}	
			}
			return false;	
		}

		//µÝ¹é°æ±¾

		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}

		bool InsertR(const K& key)
		{
			return _insertR(_root, key);
		}

		Node* _FindR(const K& key)
		{
			return _FindR(_root, key);
		}

		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}


	private:

		void _InOrder(Node* root)
		{
			if (root == nullptr)
				return;
			_InOrder(root->_left);
			cout << root->_key << " ";
			_InOrder(root->_right);
		}

		//µÝ¹é²åÈë
		bool _insertR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				root = new Node(key);
				return true;
			}

			if (root->_key > key)
				return _insertR(root->_left, key);
			else if (root->_key < key)
				return _insertR(root->_right, key);
			else 
				return false;
		}

		//µÝ¹é²éÕÒ
		Node* _FindR(Node* root, const K& key)
		{
			if (root == nullptr)
				return nullptr;
			if (root->_key < key)
				return _FindR(root->_right, key);
			else if (root->_key > key)
				return _FindR(root->_left, key);
			else
				return root;
		}

		//µÝ¹éÉ¾³ý
		bool _EraseR(Node*& root,const K& key)
		{
			if (root == nullptr)
				return false;
			if (root->_key < key)
			{
				return _EraseR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _EraseR(root->_left, key);
			}
			else
			{
				Node* del = root->_right;
				if (root->_left == nullptr)
				{
					root = root->_right;
					return true;
				}
				else if (root->_right == nullptr)
				{
					root = root->_left;
					return true;
				}
				else
				{
					while (del->_left)
					{
						del = del->_left;
					}
					root->_key = del->_key;
					return _EraseR(root->_right, root->_key);
				}
				delete del;
				return true;
			}
		}

		Node* _Copy(Node* root)
		{
			if (root == nullptr)
				return nullptr;
			Node* newRoot = new Node(root->_key);

			newRoot->_left = _Copy(root->_left);
			newRoot->_right = _Copy(root->_right);
			return newRoot;
		}

		void _Destroy(Node* root)
		{
			if (root == nullptr)
				return;
			_Destroy(root->_left);
			_Destroy(root->_right);
			delete root;
		}

	private:
		Node* _root;
	};
}

//namespace KEY_VALUE
//{
//	template<class K, class V>
//	struct BinarySearchTreeNode
//	{
//		BinarySearchTreeNode* _left;
//		BinarySearchTreeNode* _right;
//		K _key;
//		V _value;
//		BinarySearchTreeNode(const K& key, const V& value)
//			:_left(nullptr),
//			_right(nullptr),
//			_key(key),
//			_value(value)
//		{
//		}
//	};
//
//	template<class K, class V>
//	class BSTree
//	{
//		typedef BinarySearchTreeNode<K> Node;
//
//	public:
//		BSTree()
//			:_root(nullptr)
//		{
//		}
//
//		BSTree(const BSTree& bst)
//		{
//			_root = _Copy(bst._root);
//		}
//
//		BSTree<K>& operator=(BSTree<K> t)
//		{
//			std::swap(_root, t._root);
//			//std::swap(_root, bst._root);
//			return *this;
//		}
//
//		~BSTree()
//		{
//			_Destroy(_root);
//		}
//
//
//		bool insert(const K& key)
//		{
//			Node* parent = nullptr;
//			Node* cur = _root;
//
//			if (parent == cur)
//			{
//				_root = new Node(key);
//				return true;
//			}
//			while (cur)
//			{
//				parent = cur;
//				if (key > cur->_key)
//					cur = cur->_right;
//				else if (key < cur->_key)
//					cur = cur->_left;
//				else
//					return false;
//			}
//			if (parent->_key < key)
//				parent->_right = new Node(key);
//			else
//				parent->_left = new Node(key);
//			return true;
//		}
//
//		Node* find(const K& key)
//		{
//			//Node* parent = nullptr;
//			Node* cur = _root;
//
//			while (cur)
//			{
//				if (cur->_key < key)
//				{
//					cur = cur->_right;
//				}
//				else if (cur->_key > key)
//				{
//					cur = cur->_left;
//				}
//				else
//				{
//					//if(parent->_left==cur)
//					return cur;
//				}
//			}
//			return cur;
//		}
//
//		bool Erase(const K& key)
//		{
//			Node* cur = _root;
//			Node* parent = nullptr;
//			while (cur)
//			{
//				if (cur->_key < key)
//				{
//					parent = cur;
//					cur = cur->_right;
//				}
//				else if (cur->_key > key)
//				{
//					parent = cur;
//					cur = cur->_left;
//				}
//				else
//				{
//					if (cur->_left == nullptr)
//					{
//						if (cur == _root)
//						{
//							_root = cur->_right;
//						}
//						else
//						{
//							if (parent->_left == cur)
//							{
//								parent->_left = cur->_right;
//							}
//							else
//							{
//								parent->_right = cur->_right;
//							}
//						}
//						delete cur;
//					}
//					else if (cur->_right == nullptr)
//					{
//						if (cur == _root)
//						{
//							_root = cur->_left;
//						}
//						else
//						{
//							if (parent->_left == cur)
//							{
//								parent->_left = cur->_left;
//							}
//							else
//							{
//								parent->_right = cur->_left;
//							}
//						}
//						delete cur;
//					}
//					else
//					{
//						Node* minRightParent = cur;
//						Node* minRight = cur->_right;
//						while (minRight->_left)
//						{
//							minRightParent = minRight;
//							minRight = minRight->_left;
//						}
//						cur->_key = minRight->_key;
//						if (minRightParent->_right == minRight)
//							minRightParent->_right = minRight->_right;
//						else
//							minRightParent->_left = minRight->_right;
//						delete minRight;
//					}
//					return true;
//				}
//			}
//			return false;
//		}
//
//		//µÝ¹é°æ±¾
//
//		bool EraseR(const K& key)
//		{
//			return _EraseR(_root, key);
//		}
//
//		bool InsertR(const K& key)
//		{
//			return _insertR(_root, key);
//		}
//
//		Node* _FindR(const K& key)
//		{
//			return _FindR(_root, key);
//		}
//
//		void InOrder()
//		{
//			_InOrder(_root);
//			cout << endl;
//		}
//
//
//	private:
//
//		void _InOrder(Node* root)
//		{
//			if (root == nullptr)
//				return;
//			_InOrder(root->_left);
//			cout << root->_key << " ";
//			_InOrder(root->_right);
//		}
//
//		//µÝ¹é²åÈë
//		bool _insertR(Node*& root, const K& key)
//		{
//			if (root == nullptr)
//			{
//				root = new Node(key);
//				return true;
//			}
//
//			if (root->_key > key)
//				return _insertR(root->_left, key);
//			else if (root->_key < key)
//				return _insertR(root->_right, key);
//			else
//				return false;
//		}
//
//		//µÝ¹é²éÕÒ
//		Node* _FindR(Node* root, const K& key)
//		{
//			if (root == nullptr)
//				return nullptr;
//			if (root->_key < key)
//				return _FindR(root->_right, key);
//			else if (root->_key > key)
//				return _FindR(root->_left, key);
//			else
//				return root;
//		}
//
//		//µÝ¹éÉ¾³ý
//		bool _EraseR(Node*& root, const K& key)
//		{
//			if (root == nullptr)
//				return false;
//			if (root->_key < key)
//			{
//				return _EraseR(root->_right, key);
//			}
//			else if (root->_key > key)
//			{
//				return _EraseR(root->_left, key);
//			}
//			else
//			{
//				Node* del = root->_right;
//				if (root->_left == nullptr)
//				{
//					root = root->_right;
//					return true;
//				}
//				else if (root->_right == nullptr)
//				{
//					root = root->_left;
//					return true;
//				}
//				else
//				{
//					while (del->_left)
//					{
//						del = del->_left;
//					}
//					root->_key = del->_key;
//					return _EraseR(root->_right, root->_key);
//				}
//				delete del;
//				return true;
//			}
//		}
//
//		Node* _Copy(Node* root)
//		{
//			if (root == nullptr)
//				return nullptr;
//			Node* newRoot = new Node(root->_key);
//
//			newRoot->_left = _Copy(root->_left);
//			newRoot->_right = _Copy(root->_right);
//			return newRoot;
//		}
//
//		void _Destroy(Node* root)
//		{
//			if (root == nullptr)
//				return;
//			_Destroy(root->_left);
//			_Destroy(root->_right);
//			delete root;
//		}
//
//	private:
//		Node* _root;
//	};
//}




void BSTree_test()
{
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	KEY::BSTree<int> t;
	for (auto e : a)
	{
		//t.Insert(e);
		t.InsertR(e);
	}
	cout << endl << "t:" << endl;
	t.InOrder();

	KEY::BSTree<int> copy = t;
	cout << endl << "copy:" << endl;
	copy.InOrder();

	t.Erase(7);
	t.InOrder();

	t.Erase(5);
	t.InOrder();

	for (auto e : a)
	{
		t.Erase(e);
		//t.EraseR(e);
		t.InOrder();
	}
}
