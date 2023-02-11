#include "gtest/gtest.h"
#include "../src/binarytree.hpp"

namespace binaryTreeTests
{
	TEST(BinaryTreeSearching, Searching)
	{
		// Act
		auto root            = new ansa_algo::Bnode(5);
		root->mLeft          = new ansa_algo::Bnode(3);
		root->mRight         = new ansa_algo::Bnode(7);
		root->mLeft->mLeft   = new ansa_algo::Bnode(2);
		root->mLeft->mRight  = new ansa_algo::Bnode(4);
		root->mRight->mLeft  = new ansa_algo::Bnode(6);
		root->mRight->mRight = new ansa_algo::Bnode(8);

		// Arrange
		const auto tree = new ansa_algo::BinaryTree<int>(root);

		const auto existElement = tree->searchElement(4);
		const auto nonExist     = tree->searchElement(9);
		const auto rootElement  = tree->searchElement(5);
		const auto minimal      = tree->searchElement(2);
		const auto maximal      = tree->searchElement(8);

		// Assert
		ASSERT_EQ(existElement->mVal, 4);
		ASSERT_EQ(nonExist, nullptr);
		ASSERT_EQ(rootElement->mVal, 5);
		ASSERT_EQ(minimal->mVal, 2);
		ASSERT_EQ(maximal->mVal, 8);
	}

	TEST(BinaryTreeSearching, Insertion)
	{
		// Act
		auto root           = new ansa_algo::Bnode(5);
		root->mLeft         = new ansa_algo::Bnode(3);
		root->mRight        = new ansa_algo::Bnode(7);
		root->mLeft->mLeft  = new ansa_algo::Bnode(2);
		root->mLeft->mRight = new ansa_algo::Bnode(4);
		root->mRight->mLeft = new ansa_algo::Bnode(6);

		// Arrange
		const auto tree = new ansa_algo::BinaryTree<int>(root);
		insert(tree->mRoot, 8);
		const auto maximal = tree->searchElement(8);
		// Assert
		ASSERT_EQ(maximal->mVal, 8);
	}

	TEST(BinaryTreeSearching, Deletion)
	{
		// Act
		auto root           = new ansa_algo::Bnode(5);
		root->mLeft         = new ansa_algo::Bnode(3);
		root->mRight        = new ansa_algo::Bnode(7);
		root->mLeft->mLeft  = new ansa_algo::Bnode(2);
		root->mLeft->mRight = new ansa_algo::Bnode(4);
		root->mRight->mLeft = new ansa_algo::Bnode(6);

		// Arrange
		const auto tree = new ansa_algo::BinaryTree<int>(root);
		erase(tree->mRoot, 6);
		const auto iter = tree->searchElement(6);
		// Assert
		ASSERT_EQ(iter, nullptr);
	}
}
