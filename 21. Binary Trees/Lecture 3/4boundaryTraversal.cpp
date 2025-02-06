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
Node* construct(int arr[],int n){
    queue<Node*>q;
    Node* root= new Node(arr[0]);
    q.push(root);
    int i=1;
    int j=2;
    while (q.size()>0 && i<n){
        Node* temp=q.front();
        q.pop();
        Node* l;
        Node* r;
        if(arr[i]!=INT_MIN) l=new Node(arr[i]);
        else l=NULL;
        if(j!=n && arr[j]!=INT_MIN) r=new Node(arr[j]);
        else r=NULL;

        temp->left=l;
        temp->right=r;
        
        if(l!=NULL) q.push(l);
        if(r!=NULL)q.push(r);

        i+=2;
        j+=2;
    }
    return root; 
}
int levels(Node*root){
    if(root==NULL) return 0;
    return 1+max(levels(root->left),levels(root->right));
}

void NthLevel(Node*root ,int curr, int level){
    if (root==NULL) return;
    if(curr==level)cout<<root->val<<" "; //work
    NthLevel(root->left,curr+1, level); //left
    NthLevel(root->right,curr+1,level); // right
}
void levelOrderTraversal(Node*root){
    int n=levels(root);
    for (int i = 0; i <= n; i++)
    {
        NthLevel(root,1,i);
        cout<<endl;
    }
    
}

void leftBoundary(Node*root){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL)return; //jab leaf node me reach ho toh return
    cout<<root->val<<" ";
    leftBoundary(root->left);
    if(root->left==NULL) leftBoundary(root->right);
    //jab left me null ho tbhi right me jaao
}
void rightBoundary(Node*root){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL)return; //jab leaf node me reach ho toh return
    rightBoundary(root->right);
    if(root->right==NULL) rightBoundary(root->left);
    cout<<root->val<<" ";
    //jab left me null ho tbhi right me jaao
}

void bottomBoundary(Node*root){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) //jab leaf node me reach ho toh print kr do
    cout<<root->val<<" ";
    bottomBoundary(root->left);
    bottomBoundary(root->right);
}

int main(){   
   //construct
int arr[]={1,2,3,4,5,INT_MIN,6,7 ,INT_MIN,INT_MIN,8,INT_MIN,9,10,INT_MIN,11,INT_MIN,12,INT_MIN,13, INT_MIN, 14,15,16,INT_MIN,17,INT_MIN,INT_MIN,18,INT_MIN,19,INT_MIN,INT_MIN,20,21,22,23,INT_MIN,24,25,26,27,INT_MIN,28,INT_MIN};
   int n=sizeof(arr)/sizeof(arr[0]);
   Node* root=construct(arr,n);

   levelOrderTraversal(root);
   cout<<endl<<endl<<endl;
    cout << root->val << " "; // Print the root node
    leftBoundary(root->left); // Print the left boundary excluding the leaf nodes
    bottomBoundary(root->left); // Print the leaf nodes from the left subtree
    bottomBoundary(root->right); // Print the leaf nodes from the right subtree
    rightBoundary(root->right); // Print the right boundary excluding the leaf nodes
    cout << endl;

    return 0;
}