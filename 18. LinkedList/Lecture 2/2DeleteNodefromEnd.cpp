//leetcode 19
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

//+++++++++++++++ Method 1 ++++++++++++++++++
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//          int len=0;
//         ListNode*temp=head;
//         while(temp!=NULL){
//             len++;
//             temp=temp->next;
//         }
//         if(n==len){ //in case jab pehla node hi delete krna ho
//             head=head->next;
//             return head;
//         }

//         //nth node from end =(len-n+1) from start
//         int m=len-n+1;
//         int idx=m-1;//jise delete krna - ahai usse ek node pehle jaan ahai
//         temp=head;//temp ko fir se head pe laaya
//         for(int i=1;i<=idx-1;i++){
//             temp=temp->next;
//         }
//         temp->next=temp->next->next;
//         return head;
//     }
// };


//++++++++++++++++++++ Method 2+++++++++++++++++++++++++++

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

// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//          int len=0;
//         ListNode*temp=head;
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