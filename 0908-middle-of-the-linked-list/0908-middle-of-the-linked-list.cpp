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
        int cnt=0;
        ListNode*temp=head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        int n;
        n=cnt/2;
      ListNode*tem=head;
      for(int i=1;i<=n;i++){
        tem=tem->next;
      }
      return tem;

    }
};