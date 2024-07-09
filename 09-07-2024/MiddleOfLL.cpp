class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head==NULL || head->next==NULL )return head;

        ListNode* first = head;
        ListNode* second = head;
        
        while(second!=NULL&&second->next!=NULL)
        {
            first=first->next;
            second=second->next->next;
        }
        return first;
    }
};
