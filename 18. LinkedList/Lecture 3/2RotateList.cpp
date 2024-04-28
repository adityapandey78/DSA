//leetcode 61
/**
 
 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
      //finding the length of the list
      if(head==NULL||head->next==NULL) return head; //if the size of LL is Zero on One
        int n=0;
        ListNode *temp=head;
        ListNode *tail=head;
        while(temp!=NULL){
            if(temp->next==NULL) tail=temp;//taking the tail tio  the tailk of the LL
            temp=temp->next;
            n++;//getting the lengh of the linekdlist
        }
        
        k=k%n;//for teh caseif k>n

        if(k==0)return head;//in case of no rotation return headd
        temp=head;// temp ko fir se head pe laao
        for(int i=1;i<n-k;i++){
            //n-k coz n-k ko peeche shift krna hai
            temp=temp->next;
        }
        //ab jidhr kaatna hai udhr temp pahuch gya
        tail->next=head;//tail ke next pe mene head appoint kr diya and ab ek loop bn gya
        head=temp->next;//ab new head bn gya
        temp->next=NULL;// and temp ka next new tail bn gya ll ka
        return head;

    }
};
*/