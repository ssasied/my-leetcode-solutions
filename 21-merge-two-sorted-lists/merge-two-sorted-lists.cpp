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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr){
            if(list2==nullptr)return nullptr;
            return list2;
        }
        if(list2==nullptr)return list1;
        ListNode*head;
        if(list1->val<list2->val){
            head=new ListNode(list1->val);
            if(list1->next)list1=list1->next;
            else {head->next=list2;
            return head;}
        }
        else {
            head=new ListNode(list2->val);
            if(list2->next)list2=list2->next;
            else{ head->next=list1;
            return head;  } 
        }
        bool l1end,l2end;
        ListNode*current=head;
        while(list1->val!=1001||list2->val!=1001){
            int val=min(list1->val,list2->val);
            if(val==list1->val){
                if(list1->next==nullptr){list1->val=1001;}
                else list1=list1->next;}
            else {
                if(list2->next==nullptr){list2->val=1001;}
                else list2=list2->next;}          
            current->next=new ListNode(val);
            current=current->next;
        }
        return head;
        }
        

        
    
};