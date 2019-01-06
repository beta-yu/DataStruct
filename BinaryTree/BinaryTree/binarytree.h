#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

#include "common.h"
#include "Queue.h"


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
int BinaryTreeComplete(BTNode *root);

void BinaryTreeTest();
#endif //__BINARYTREE_H__