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
        if(head==NULL) return NULL;
      ListNode* dummyNode=head;
      int count=0;
      while(dummyNode!=NULL){
        count++;
        dummyNode=dummyNode->next;
      }
        int del=count-n;
         if(del == 0) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        ListNode* temp=head;
        for(int i=1;i<del;i++){
          temp=temp->next;
        }
        ListNode* delNode=temp->next;
        temp->next=temp->next->next;
        delete(delNode);
        return head;
    }
};