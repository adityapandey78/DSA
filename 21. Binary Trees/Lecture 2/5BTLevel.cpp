/*
/
 #include<vector>
class Solution {
public:
    int levels(TreeNode*root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }

    void NthLevel(TreeNode*root ,int curr, int level,vector<int>&v){
    if (root==NULL) return;
    if(curr==level){
        v.push_back(root->val);//root
        return;
    }
    NthLevel(root->left,curr+1, level,v);
    NthLevel(root->right,curr+1,level,v);
}
    void levelOrderTraversal(TreeNode*root, vector<vector<int>>&ans){
        int n=levels(root);
        for (int i = 1; i <= n; i++)
        {
            vector<int>v;
            NthLevel(root,1,i,v);
            ans.push_back(v);
        }
        
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        levelOrderTraversal(root,ans);
        return ans;
    }
};
 */