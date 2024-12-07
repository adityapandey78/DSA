#include<iostream>
#include<algorithm>
#include<climits>
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
void displayTree(Node*root){
    if (root==NULL) return;
    cout<<root->val<<" ";
    displayTree(root->left); //left recursion
    displayTree(root->right); //right recursion
    
}

int size(Node*root){
    if(root==NULL) return 0;
     return 1+size(root->left) +size(root->right);
}
int levels(Node*root){
    if(root==NULL) return 0;
     return 1+ max(levels(root->left),levels(root->right));
}

int sum(Node* root){
    if(root==NULL) return 0;
    int ans =root->val +sum(root->left)+ sum(root->right);
    //Sum = root.val + sum of left subtree + sum of right subtree
    return ans;
}
int max2(Node* root){
    if(root==NULL) return INT_MIN;
    int maxl= max2(root->left);
    int maxr= max2(root->right);
    int max3= max(maxl,maxr);
    return max(root->val,max3);
}
int main(){
    Node* a=new Node(1);
    Node* b=new Node(2);
    Node* c=new Node(3);
    Node* d=new Node(4);
    Node* e=new Node(75);
    Node* f=new Node(6);
    Node* g=new Node(7);

    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    displayTree(a);
    cout<<endl<<sum(a); //finding sum
    cout<<endl<<size(a); //finding size
    cout<<endl<<max2(a);
    cout<<endl<<levels(a);

return 0;
}