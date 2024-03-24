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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next)return head;
       ListNode* start=new ListNode(0,head);
      
       while(head->next){
            ListNode* cr=head;
            while(head->next&&head->val==head->next->val){
                head=head->next;
            }
            cr->next=head->next;
            if(head->next)head=head->next;
        }
       
        return start->next;
    }
};