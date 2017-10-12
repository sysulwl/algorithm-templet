/*--------------快慢指针法找链表环入口----------------------*/ 
class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		ListNode *slow = pHead;
		ListNode *fast = pHead;
		do{
		if(fast == NULL || fast->next==NULL)
		return NULL;
		fast = fast->next->next;
		slow = slow->next;	
		}while(slow != fast);
		slow = pHead;
		while(slow != fast){
			slow = slow->next;
			fast = fast->next;
		}
		return slow;???
	}
};
