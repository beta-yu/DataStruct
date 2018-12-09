#include <stdio.h>

struct ListNode 
{
	int val;
	struct ListNode *next;
};

struct ListNode *middleNode(struct ListNode *head)
{
	struct ListNode *slow = head;
	struct ListNode *fast = head;
	while (fast && fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
struct ListNode *listReverse(struct ListNode *head)
{
	struct ListNode *newhead = NULL;
	struct ListNode *cur = head;
	while (cur)
	{
		struct ListNode *next = cur->next;
		cur->next = newhead;
		newhead = cur;
		cur = next;
	}
	return newhead;
}
int isPalindrome(struct ListNode* head) {
	if (head == NULL)
	{
		return 1;
	}
	struct ListNode *midNode = middleNode(head);
	struct ListNode *halfListReverse = listReverse(midNode->next);
	struct ListNode *cur1 = head;
	struct ListNode *cur2 = halfListReverse;
	while (cur2)
	{
		if (cur1->val != cur2->val)
		{
			return 0;
		}
		else
		{
			cur1 = cur2->next;
			cur2 = cur2->next;
		}
	}
	return 1;
}

int main()
{
	struct ListNode *head = NULL;

	return 0;
}