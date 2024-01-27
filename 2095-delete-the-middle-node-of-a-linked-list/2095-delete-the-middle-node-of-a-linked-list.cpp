/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return NULL;
        }
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* temp=head;
        int size=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            size++;
        }
        int mid=1.00*size/2;
        int count=0;
        temp=dummy;
        while(count<mid)
        {
            count++;
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return dummy->next;
        
    }
};