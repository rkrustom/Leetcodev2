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
    ListNode* middleNode(ListNode* head) {
    //    ListNode *slow=head;
    //    ListNode *fast=head;
    //    while(fast!=NULL && fast->next!=NULL){
    //     slow=slow->next;
    //     fast=fast->next->next;
    //    }
    //    return slow;

    ListNode*temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    int n=count/2;
    for(int i=1;i<=n;i++){
        head=head->next;
    }
     return head;

    }
};