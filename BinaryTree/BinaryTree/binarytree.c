#include "binarytree.h"

BTNode* BinaryTreeCreate(BTDataType *a, int *pi)
{
	assert(a);
	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}
	else
	{
		BTNode *root = (BTNode *)malloc(sizeof(BTNode));
		root->_data = a[*pi];
		(*pi)++;
		root->_left = BinaryTreeCreate(a, pi);
		root->_right = BinaryTreeCreate(a, pi);
		return root;
	}
}
void BinaryTreeDestory(BTNode **root)
{
	assert(root);

}

//二叉树的节点总数
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
	}
}

//二叉树的叶子节点总数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->_left == NULL && root->_right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

//第k层结点数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

void BinaryTreePrevOrder(BTNode *root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		printf("%c ", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
}

void BinaryTreeInOrder(BTNode *root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		BinaryTreeInOrder(root->_left);
		printf("%c ", root->_data);
		BinaryTreeInOrder(root->_right);
	}
}

void BinaryTreePostOrder(BTNode *root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		printf("%c ", root->_data);
	}
}

BTNode *BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root->_data == x)
	{
		return root;
	}
	else
	{
		BTNode *cur = NULL;
		cur = BinaryTreeFind(root->_left, x);
		if (cur)
			return cur;
		cur = BinaryTreeFind(root->_right, x);
		return cur;
	}
}

//非递归遍历
//层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{

}

void BinaryTreeTest()
{
	BTDataType arr[100] = "ABD##E#H##CF##G##";
	int size = sizeof(arr) / sizeof(BTDataType);
	int i = 0;	
	BTNode *root = BinaryTreeCreate(arr, &i);
	/*BinaryTreePrevOrder(root);
	printf("\n");
	BinaryTreeInOrder(root);
	printf("\n");
	BinaryTreePostOrder(root);
	printf("\n");*/
	//printf("%d\n", BinaryTreeSize(root));
	//printf("%d\n", BinaryTreeLeafSize(root));
	//printf("%d\n", BinaryTreeLevelKSize(root, 3));
}