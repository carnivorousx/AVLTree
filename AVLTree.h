///////////////////////////////////////////////////////////////////////////
//      AVLTREE CPP IMPLEMENTATION                                       //
//      Author: Yiming Xiao                                              //
//      Version: 1.0                                                     //
//      Date: 11/06/2013                                                 //
///////////////////////////////////////////////////////////////////////////
/*
Maintain Log

*/
#pragma once
//#include <stdlib.h>

#define LEFT 0
#define RIGHT 1
#define LLROTATION 1
#define LRROTATION 2
#define RRROTATION 3
#define RLROTATION 4
#define NOROTATION 0
#ifndef _STDLIB_H_INCLUDED_
#define NULL 0
#endif

class AvlNode 
{
public:
	AvlNode();
	AvlNode(int k);
	~AvlNode();
	void updateRelativeBalanceFactor();
	int getRelativeHeight();
	void updateRelativeHeight();	
	int getLeftSubEleNum();
	int getSubTreeEleNum();
	//void updateBalanceFactor();
	//int getHeight();

private:
	int key;
	AvlNode* leftchild;
	AvlNode* rightchild;
	AvlNode* parent;
	int bf;                                    //balance factor
	int height;
	friend class AvlTree;
};

class AvlTree 
{
public:
	AvlTree();
	~AvlTree();
	void insert(int k);
	void LLrotation(AvlNode* &node);
	void LRrotation(AvlNode* &node);
	void RRrotation(AvlNode* &node);
	void RLrotation(AvlNode* &node);
	AvlNode* &updateTreeStructure(AvlNode* &node, int& rotateType);
	void remove(int k);
	int kthMin(int k);
	AvlNode* search(int k);
	AvlNode* deleteNode(AvlNode* &node);
	int getRank(int k);
private:
	AvlNode* root;
	int size;
};