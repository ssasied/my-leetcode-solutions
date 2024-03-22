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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    vector<int>values;
    if(lists.empty())return nullptr;
    for(int i=0;i<lists.size();i++){
        while(lists[i]!=nullptr){
            values.push_back(lists[i]->val);
            lists[i]=lists[i]->next;
        }
    }
    if(values.empty())return nullptr;
    sort(values.begin(),values.end());
    ListNode*head=new ListNode(values[0]);
    ListNode*current=head;
    for(int i=1;i<values.size();i++){
        current->next=new ListNode(values[i]);
        current=current->next;
    }
    return head;

    }
};