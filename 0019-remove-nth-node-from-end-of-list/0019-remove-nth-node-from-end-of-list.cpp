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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        int N=count-n;
        if(N==0){
            ListNode*node=head;
            head=head->next;
            delete(node);
        }
        else{
        ListNode*temp1=head;
        for(int i=1;i<N;i++){
            temp1=temp1->next;
        }
        ListNode*node=temp1->next;
        temp1->next=temp1->next->next;
        delete(node);
        }
        return head;
    }
};