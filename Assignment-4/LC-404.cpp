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
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL) return 0;
        cout<<root->val<<" ";
        int sum=0;
        if(root->left!=NULL && root->left->left==NULL && root->left->right==NULL)
        {
            sum += root->left->val;
        }
        if(root->left!=NULL) sum += sumOfLeftLeaves(root->left);
        if(root->right!=NULL) sum += sumOfLeftLeaves(root->right);
        return sum;
    }
};
