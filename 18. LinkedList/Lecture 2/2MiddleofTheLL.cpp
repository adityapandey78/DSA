//leetcode 876
/*
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        //calculating the Length of the LL
        int len=0;
        ListNode* temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        //isse mid me pahuch jayenge
        int midIdx=len/2;
        ListNode* mid = head;
        for(int i=1;i<=midIdx;i++){
            mid=mid->next;
        }
        return mid;
    }
};
*/

//method 2

/*

//second solution

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        //calculating the Length of the LL
        int len=0;
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL &&fast->next!=NULL ){

            slow=slow->next; //slow ek node se jump krta hai
            fast=fast->next->next; //fast do node ko jump krta hai

        }
        return slow;
    }
};

*/