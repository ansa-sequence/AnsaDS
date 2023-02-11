#pragma once

namespace ansa_algo
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
			while (temp->left)
			{
				temp = temp->left;
			}
			return temp;
		}

		Bnode<T>* getMinimumBy(Bnode<T>* root)
		{
			if (!root) return nullptr;
			auto temp = root;
			while (root->left)
			{
				temp = root->left;
			}
			return temp;
		}

		Bnode<T>* maximum()
		{
			auto temp = mRoot;
			if (!temp) return nullptr;
			while (temp->right)
			{
				temp = temp->right;
			}
			return temp;
		}

		Bnode<T>* successor(Bnode<T>* root)
		{
			auto node = root;
			if (node->right)
			{
				return getMinimumBy(node->right);
			}
		}

		~BinaryTree()
		{
			delete mRoot;
		}

		Bnode<T>* mRoot;
	};

	template <typename T>
	Bnode<T>* insert(Bnode<T>* root, T val)
	{
		if (root == nullptr)
		{
			return new Bnode(val);
		}
		if (val < root->mVal)
		{
			root->mLeft = insert(root->mLeft, val);
		}
		else
		{
			root->mRight = insert(root->mRight, val);
		}
		return root;
	}

	template <typename T>
	Bnode<T>* erase(Bnode<T>* root, T val)
	{
		if (root == nullptr)
		{
			return root;
		}

		const auto tree = new BinaryTree<T>(root);
		auto       node = tree->searchElement(val);

		while (root)
		{
		}
	}
}
