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
//     ListNode* deleteDuplicates(ListNode* head) {
//         ListNode * a=head;
//         ListNode * b=head;
//         if(head==NULL || head->next==NULL) return head; //handling the case of only one linkedList
//         while(b!=NULL){
//             while( b!=NULL && b->val==a->val){
//                 b=b->next;
//             }
//             a->next=b;//yaani ki repeating nodes toot gye
//             a=b;//ab a B ke paas aa gya
//             if(b!=NULL) b=b->next;
//         }
//         return head;
//     }
// };