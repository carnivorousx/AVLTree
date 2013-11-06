#include "AVLTree.h"

AvlNode::AvlNode()
{
	key = -1;
	leftchild = NULL;
	rightchild = NULL;
	bf = 0;
	height = 1;
}

AvlNode::AvlNode(int k)
{
	key = k;
	leftchild = NULL;
	rightchild = NULL;
	bf = 0;
	height = 1;
}

AvlNode::~AvlNode()
{
	delete leftchild;
	delete rightchild;
}

//void AvlNode::updateBalanceFactor()
//{
//	int rightHeight = 0;
//	int leftHeight = 0;
//	if (leftchild != NULL)
//		leftHeight = leftchild->getHeight();
//	if (rightchild != NULL)
//		rightHeight = rightchild->getHeight();
//	bf = leftHeight - rightHeight;
//}

void AvlNode::updateRelativeBalanceFactor()
{
	int rightHeight = 0;
	int leftHeight = 0;
	if (leftchild != NULL)
		leftHeight = leftchild->height;
	if (rightchild != NULL)
		rightHeight = rightchild->height;
	bf = leftHeight - rightHeight;
}
//int AvlNode::getHeight()
//{
//	if (leftchild == NULL && rightchild == NULL)
//		return 1;
//	else if (leftchild == NULL && rightchild != NULL)
//		return rightchild->getHeight() + 1;
//	else if (leftchild != NULL && rightchild == NULL)
//		return leftchild->getHeight() + 1;
//	else
//	{
//		if (leftchild->getHeight() > rightchild->getHeight())
//			return leftchild->getHeight() + 1;
//		else
//			return rightchild->getHeight() + 1;
//	}
//}
int AvlNode::getRelativeHeight()
{
	int leftH = 0, rightH = 0;
	if (leftchild != NULL)
		leftH = leftchild->height;
	if (rightchild != NULL)
		rightH = rightchild->height;
	if (leftH > rightH)
		return leftH + 1;
	else
		return rightH + 1;
}

void AvlNode::updateRelativeHeight()
{
	int leftH = 0, rightH = 0;
	if (leftchild)
		leftH = leftchild->height;
	if (rightchild)
		rightH = rightchild->height;
	if (leftH > rightH)
		height = leftH + 1;
	else
		height = rightH + 1;
}

AvlTree::AvlTree()
{
	root = NULL;
	size = 0;
}

AvlTree::~AvlTree()
{
	// to do
}

void AvlTree::LLrotation(AvlNode* &node)
{
	AvlNode* par = NULL;
	int whichChild = -1;
	if (node != root)
	{
		par = node->parent;
		if (par->leftchild == node)
			whichChild = LEFT;
		else
			whichChild = RIGHT;
	}
	AvlNode* node2 = node->leftchild;
	AvlNode* node1 = node2->leftchild;
	//AvlNode* nd = NULL;
	AvlNode* nc = NULL;
	//if (node->rightchild != NULL)
	//	nd = node->rightchild;
	if (node2->rightchild != NULL)
		nc = node2->rightchild;
	if (node == root)
	{
		root = node2;
		node2->parent = NULL;
	}
	else
	{
		if (whichChild == LEFT)
			par->leftchild = node2;
		else
			par->rightchild = node2;
		node2->parent = par;
	}
	node2->rightchild = node;
	node2->leftchild = node1;
	node1->parent = node2;
	node->parent = node2;
	node->leftchild = NULL;
	if (nc != NULL)
	{
		node->leftchild = nc;
		nc->parent = node;
	}
	node->updateRelativeHeight();
	node2->updateRelativeHeight();
}
void AvlTree::LRrotation(AvlNode* &node)
{
	AvlNode* par = NULL;
	int whichChild = -1;
	if (node != root)
	{
		par = node->parent;
		if (par->leftchild == node)
			whichChild = LEFT;
		else
			whichChild = RIGHT;
	}
	AvlNode* node1 = node->leftchild;
	AvlNode* node2 = node1->rightchild;
	AvlNode* nc = NULL;
	AvlNode* nd = NULL;
	if (node2->leftchild != NULL)
		nc = node2->leftchild;
	if (node2->rightchild != NULL)
		nd = node2->rightchild;

	if (node == root)
	{
		root = node2;
		node2->parent = NULL;
	}
	else
	{
		if (whichChild == LEFT)
			par->leftchild = node2;
		else
			par->rightchild = node2;
		node2->parent = par;
	}

	node2->leftchild = node1;
	node1->parent = node2;
	node2->rightchild = node;
	node->parent = node2;
	node->leftchild = NULL;
	node1->rightchild = NULL;
	if (nc != NULL)
	{
		node1->rightchild = nc;
		nc->parent = node1;
	}

	if (nd != NULL)
	{
		node->leftchild = nd;
		nd->parent = node;
	}
	node1->updateRelativeHeight();
	node->updateRelativeHeight();
	node2->updateRelativeHeight();
}
void AvlTree::RRrotation(AvlNode* &node)
{
	AvlNode* par = NULL;
	int whichChild = -1;
	if (node != root)
	{
		par = node->parent;
		if (par->leftchild == node)
			whichChild = LEFT;
		else
			whichChild = RIGHT;
	}
	AvlNode* node2 = node->rightchild;
	AvlNode* node3 = node2->rightchild;
	AvlNode* nb = NULL;
	if (node2->leftchild != NULL)
		nb = node2->leftchild;

	if (node == root)
	{
		root = node2;
		node2->parent = NULL;
	}
	else
	{
		if (whichChild == LEFT)
			par->leftchild = node2;
		else
			par->rightchild = node2;
		node2->parent = par;
	}

	node2->leftchild = node;
	node2->rightchild = node3;
	node->parent = node2;
	node3->parent = node2;
	node->rightchild = NULL;
	if (nb != NULL)
	{
		node->rightchild = nb;
		nb->parent = node;
	}
	node->updateRelativeHeight();
	node2->updateRelativeHeight();
}
void AvlTree::RLrotation(AvlNode* &node)
{
	AvlNode* par = NULL;
	int whichChild = -1;
	if (node != root)
	{
		par = node->parent;
		if (par->leftchild == node)
			whichChild = LEFT;
		else
			whichChild = RIGHT;
	}

	AvlNode* node3 = node->rightchild;
	AvlNode* node2 = node3->leftchild;

	AvlNode* nc = NULL;
	AvlNode* nd = NULL;
	if (node2->leftchild != NULL)
		nc = node2->leftchild;
	if (node2->rightchild != NULL)
		nd = node2->rightchild;

	if (node == root)
	{
		root = node2;
		node2->parent = NULL;
	}
	else
	{
		if (whichChild == LEFT)
			par->leftchild = node2;
		else
			par->rightchild = node2;
		node2->parent = par;
	}

	node2->leftchild = node;
	node2->rightchild = node3;
	node->parent = node2;
	node3->parent = node2;
	node->rightchild = NULL;
	node3->leftchild = NULL;
	if (nc != NULL)
	{
		node->rightchild = nc;
		nc->parent = node;
	}
	if (nd != NULL)
	{
		node3->leftchild = nd;
		nd->parent = node3;
	}
	node->updateRelativeHeight();
	node3->updateRelativeHeight();
	node2->updateRelativeHeight();
}

void AvlTree::insert(int k)
{
	if (root == NULL)
	{
		root = new AvlNode();
		root->key = k;
	}
	else
	{
		AvlNode* node = new AvlNode(k);
		AvlNode* curr = root;
		while ((curr->leftchild != NULL && k <= curr->key) ||
			(curr->rightchild != NULL && k > curr->key))

		{
			if (k <= curr->key)
				curr = curr->leftchild;
			else
				curr = curr->rightchild;
		}
		if (k < curr->key)
		{
			curr->leftchild = node;
			node->parent = curr;
		}
		else
		{
			curr->rightchild = node;
			node->parent = curr;
		}
		int rotationType = NOROTATION;
		updateTreeStructure(node, rotationType);
	}

}

AvlNode* AvlTree::deleteNode(AvlNode* &node)
{
	AvlNode* ret;
	if (node == root)
	{
		if (node->rightchild == NULL && node->leftchild == NULL)
		{
			root = new AvlNode();
			return NULL;
		}
		if ((node->rightchild == NULL && node->leftchild != NULL)
			|| (node->rightchild != NULL && node->leftchild == NULL))
		{
			if (node->rightchild)
			{
				root = node->rightchild;
				root->parent = NULL;

			}
			else
			{
				root = node->leftchild;
				root->parent = NULL;
			}
			return root;
		}
		else
		{
			AvlNode* curr = node->leftchild;
			while (curr->rightchild != NULL)
				curr = curr->rightchild;
			node->key = curr->key;
			ret = curr->parent;
			deleteNode(curr);
			return ret;
		}
	}
	else
	{

		if (node->rightchild == NULL && node->leftchild == NULL)
		{
			ret = node->parent;
			if (node->parent->leftchild == node)
				node->parent->leftchild = NULL;
			else
				node->parent->rightchild = NULL;
			node->parent = NULL;

		}
		else if ((node->rightchild == NULL && node->leftchild != NULL)
			|| (node->rightchild != NULL && node->leftchild == NULL))
		{
			ret = node->parent;
			if (node->rightchild != NULL)
			{
				node->key = node->rightchild->key;
				node->rightchild->parent = NULL;
				node->rightchild = NULL;
			}
			else{
				node->key = node->leftchild->key;
				node->leftchild->parent = NULL;
				node->leftchild = NULL;
			}
		}
		else
		{
			AvlNode* curr = node->leftchild;
			while (curr->rightchild != NULL)
				curr = curr->rightchild;
			node->key = curr->key;
			ret = curr->parent;
			deleteNode(curr);
		}
		return ret;
	}
}

void AvlTree::remove(int k)
{
	AvlNode* curr = search(k);
	curr = deleteNode(curr);
	while (curr->height != curr->getRelativeHeight())
	{

		curr->updateRelativeHeight();
		curr->updateRelativeBalanceFactor();
		if (curr->bf >= 2)
		{
			if (curr->leftchild->bf == 1)
			{
				LLrotation(curr);
			}
			else if (curr->leftchild->bf == -1)
			{
				LRrotation(curr);
			}
		}
		else if (curr->bf == -2)
		{
			if (curr->rightchild->bf == 1){
				RLrotation(curr);
			}
			else if (curr->rightchild->bf == -1){
				RRrotation(curr);
			}
		}
		curr = curr->parent;

	}
}
int AvlTree::kthMin(int k)
{
	return getRank(k);
}
int AvlTree::getRank(int k)
{
	int m = k;
	AvlNode* tmp = root;
	while (1)
	{
		if (tmp->getLeftSubEleNum() == m)
			return tmp->key;
		else if (tmp->getLeftSubEleNum() > m)
		{
			tmp = tmp->leftchild;
		}
		else
		{
			m -= (tmp->getLeftSubEleNum() + 1);
			tmp = tmp->rightchild;

		}
	}
}
int AvlNode::getLeftSubEleNum()
{
	if (leftchild == NULL)
		return 0;
	else
		return 1 + leftchild->getSubTreeEleNum();
}
int AvlNode::getSubTreeEleNum()
{
	int ret;
	if (leftchild == NULL && rightchild == NULL)
		ret = 0;
	else if (leftchild == NULL)
		ret = 1 + rightchild->getSubTreeEleNum();
	else if (rightchild == NULL)
		ret = 1 + leftchild->getSubTreeEleNum();
	else
		ret = 2 + leftchild->getSubTreeEleNum() + rightchild->getSubTreeEleNum();
	return ret;
}


AvlNode* & AvlTree::updateTreeStructure(AvlNode* &node, int & rotateType)
{
	AvlNode* curr = node->parent;
	int flag = 0;
	while (1)
	{
		if (curr->getRelativeHeight() == curr->height)
		{
			return curr;
		}
		else
		{
			curr->height = curr->getRelativeHeight();
			curr->updateRelativeBalanceFactor();
			if (curr->bf >= 2)
			{
				if (curr->leftchild->bf == 1)
				{
					LLrotation(curr);
					rotateType = LLROTATION;
				}
				else if (curr->leftchild->bf == -1)
				{
					rotateType = LRROTATION;
					LRrotation(curr);
				}
				return curr;
			}
			else if (curr->bf == -2)
			{
				if (curr->rightchild->bf == 1){
					rotateType = RLROTATION;
					RLrotation(curr);
				}
				else if (curr->rightchild->bf == -1){
					rotateType = RRROTATION;
					RRrotation(curr);
				}
				return curr;
			}

		}
		if (curr == root)
			return curr;
		else
			curr = curr->parent;
	}

}

AvlNode* AvlTree::search(int k)
{
	AvlNode* curr = root;
	while (curr->key != k)
	{
		if (k < curr->key)
			curr = curr->leftchild;
		else
			curr = curr->rightchild;
	}
	return curr;
}

#define _TEST_AVLTREE_
#ifdef _TEST_AVLTREE_
#include <stdlib.h>
#include <iostream>

int main()
{
	AvlTree* at = new AvlTree();
	for (int i = 0; i < 8; i++){
		int a = rand() % 1000;
		at->insert(a);
		std::cout << a << ", ";
	}
	system("pause");
	return 0;
}
#endif









