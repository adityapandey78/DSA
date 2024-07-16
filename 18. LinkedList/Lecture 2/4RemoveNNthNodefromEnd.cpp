// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//          int len=0;
//        ListNode*temp=head;
//         ListNode*slow=head;
//         ListNode*fast=head;
//         while(temp!=NULL){
//             len++;
//             temp=temp->next;
//         }
//        for(int i=1;i<=n+1;i++){
//         if(fast==NULL) //return NULL; //coz in case of len==2 the fast will start pointing to the NULL
//             return head->next;//ye jyada better hai isse y ehead ke next yani NULL ko ko hi return krega even in size==2
//             fast=fast->next;
//        }
//        //move slo an d fast at the same pace
//        while(fast!=NULL){
//         slow=slow->next;
//         fast=fast->next;
//        }
//        //now slow is exactly at the place you want to remove
//        slow->next= slow->next->next;
//         return head;
//     }
// };