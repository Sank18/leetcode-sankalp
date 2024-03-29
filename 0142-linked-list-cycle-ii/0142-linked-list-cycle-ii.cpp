/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
        {
            return NULL;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        bool flag=false;
        while(slow!=NULL && fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast)
            {
                cout<<"cycle yes"<<endl;
                break;
            }
            
        }
        if(slow!=fast)
        {
            return NULL;
        }
        
            slow=head;
        ListNode* temp=head;
            while(slow!=fast)
            {
                slow=slow->next;
                fast=fast->next;
                if(slow==fast)
                {
                    
                    break;
                }
            }
                
        
        return slow;
        
    }
};