#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

#include "common.h"

typedef char BTDataType;
typedef struct BTNode
{
	BTDataType _data;
	struct BTNode *_left;
	struct BTNode *_right;
}BTNode;

BTNode* BinaryTreeCreate(BTDataType *a, int *pi);
void BinaryTreeDestory(BTNode **root);
void BinaryTreePrevOrder(BTNode *root);
void BinaryTreeInOrder(BTNode *root);
void BinaryTreePostOrder(BTNode *root);
int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);
int BinaryTreeLevelKSize(BTNode* root, int k);
BTNode *BinaryTreeFind(BTNode* root, BTDataType x);
void BinaryTreeLevelOrder(BTNode* root);

void BinaryTreeTest();
#endif //__BINARYTREE_H__