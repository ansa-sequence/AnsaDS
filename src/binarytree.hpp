#pragma once

namespace ansa
{
	template <typename T>
	struct Bnode
	{
		explicit Bnode(T val) : mLeft(nullptr), mRight(nullptr), mVal(val)
		{
		}

		~Bnode()
		{
			delete mLeft;
			delete mRight;
		}

		Bnode* mLeft;
		Bnode* mRight;
		T      mVal;
	};

	template <typename T>
	struct BinaryTree
	{
		explicit BinaryTree(Bnode<T>* root) : mRoot(root)
		{
		}

		Bnode<T>* searchElement(T element)
		{
			auto node = mRoot;
			while (node != nullptr)
			{
				if (node->mVal == element)
				{
					return node;
				}
				if (element < node->mVal)
				{
					node = node->mLeft;
				}
				else
				{
					node = node->mRight;
				}
			}
			return nullptr;
		}

		Bnode<T>* getMinimum()
		{
			auto temp = mRoot;
			if (!temp) return nullptr;
			while (temp->mLeft)
			{
				temp = temp->mLeft;
			}
			return temp;
		}

		Bnode<T>* getMinimumBy(Bnode<T>* root)
		{
			if (!root) return nullptr;
			auto temp = root;
			while (root->mLeft)
			{
				temp = root->mLeft;
			}
			return temp;
		}

		Bnode<T>* maximum()
		{
			auto temp = mRoot;
			if (!temp) return nullptr;
			while (temp->mRight)
			{
				temp = temp->mRight;
			}
			return temp;
		}

		Bnode<T>* getMaximumByNode(Bnode<T>* root)
		{
			if (!root) return nullptr;
			auto temp = root;
			while (root->mRight)
			{
				temp = root->mRight;
			}
			return temp;
		}

		Bnode<T>* erase(Bnode<T>* node, const T& value)
		{
			if (node == nullptr)
			{
				return nullptr;
			}
			if (value < node->mVal)
			{
				node->mLeft = erase(node->mLeft, value);
			}
			else if (value > node->mVal)
			{
				node->mRight = erase(node->mRight, value);
			}
			else
			{
				if (node->mLeft == nullptr && node->mRight == nullptr)
				{
					delete node;
					node = nullptr;
				}
				else if (node->mLeft == nullptr)
				{
					Bnode<T>* temp = node;
					node           = node->mRight;
					temp->mRight   = nullptr;
					delete temp;
				}
				else if (node->mRight == nullptr)
				{
					Bnode<T>* temp = node;
					node           = node->mLeft;
					temp->mLeft    = nullptr;
					delete temp;
				}
				else
				{
					Bnode<T>* minNode = getMinimumBy(node->mRight);
					node->mVal        = minNode->mVal;
					node->mRight      = erase(node->mRight, minNode->mVal);
				}
			}
			return node;
		}

		void insert(const T& value)
		{
			mRoot = insertRecursive(mRoot, value);
		}

		Bnode<T>* getRoot() const { return mRoot; }

		~BinaryTree()
		{
			delete mRoot;
		}

	private:
		Bnode<T>* insertRecursive(Bnode<T>* node, const T& value)
		{
			if (node == nullptr)
			{
				node = new Bnode<T>(value);
			}
			else if (value < node->mVal)
			{
				node->mLeft = insertRecursive(node->mLeft, value);
			}
			else if (value > node->mVal)
			{
				node->mRight = insertRecursive(node->mRight, value);
			}
			return node;
		}

		Bnode<T>* mRoot;
	};
}
