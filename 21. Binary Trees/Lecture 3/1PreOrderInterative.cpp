//Write the code for the pre order traversal of a binary tree iteratively
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//  #include<stack>
// class Solution {
// public:

    
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int>ans;
//         stack<TreeNode*> st;
//         if(root==NULL) return ans;
//         st.push(root);
//         while(st.size()>0){
//             TreeNode* temp= st.top();
//             st.pop();
//             ans.push_back(temp->val);
//             if(temp->right!=NULL) st.push(temp->right);
//             if(temp->left!=NULL) st.push(temp->left);
//         }
//         return ans;
       
//     }
// };