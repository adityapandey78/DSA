#include<iostream>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std;
class Node{
    public:
    int val;
    Node*left;
    Node* right;
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
// int levels(Node*root){
//     if(root==NULL) return 0;
//     return 1+max(levels(root->left),levels(root->right));
// }

// void NthLevel(Node*root ,int curr, int level){
//    if(root==NULL) return; //base case
//    if(curr==level){
//     cout<<root->val<<" ";
//     return;} //work
//    NthLevel(root->left,curr+1,level); //left
//    NthLevel(root->right,curr+1,level);//right
// }
void levelOrderTraversal(Node*root){
   queue<Node*>q;
   q.push(root);
    while(q.size()>0){
       Node* temp=q.front();
       q.pop();
       cout<<temp->val<<" ";
       if(temp->left!=NULL) q.push(temp->left); 
       if(temp->right!=NULL) q.push(temp->right); 
    }

    
}
int main(){   
    Node* a=new Node(1);
    Node* b=new Node(2);
    Node* c=new Node(3);
    Node* d=new Node(4);
    Node* e=new Node(5);
    Node* f=new Node(6);
    Node* g=new Node(7);

    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;

    //NthLevel(a,1,2);
    cout<<endl;
    levelOrderTraversal(a);
   
    return 0;
}