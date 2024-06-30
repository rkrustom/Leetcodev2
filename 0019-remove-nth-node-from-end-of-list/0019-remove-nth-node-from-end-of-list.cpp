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
        // agar linkedlist me koi element hi na ho
        if(head==NULL) return NULL;
        //counting the length of the linkedlist
        int count=0;
        ListNode*temp=head;
        while(temp!=NULL){
         count++;
         temp=temp->next;
        }
         //if count equall to length delete head
         if(count==n) {
            ListNode *newhead= head->next;
            delete(head);
            return newhead;
         }
        // position of node that we have to delete
        int res=count-n;
        temp=head;
        
        while(temp!=NULL){
            res--;
            if(res==0)
            break;
            temp=temp->next;
        }
        //code for deletion
        ListNode *deletenode=temp->next;
        temp->next=temp->next->next;
        delete(deletenode);
        return head;
    }
};