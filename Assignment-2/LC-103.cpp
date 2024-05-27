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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        deque<TreeNode*> dq;
        dq.push_back(root);
        int direction = 0;
        while(!dq.empty())
        {
            direction++;
            int l = dq.size();
            vector<int> v;
            TreeNode* temp;
            for(int i=0;i<l;i++)
            {
                if(direction%2)
                {
                    temp = dq.front();
                    dq.pop_front();
                    if(temp) v.push_back(temp->val);
                    if(temp->left) dq.push_back(temp->left);
                    if(temp->right) dq.push_back(temp->right);
                }
                else
                {
                    temp = dq.back();
                    dq.pop_back();
                    if(temp) v.push_back(temp->val);
                    if(temp->right) dq.push_front(temp->right);
                    if(temp->left) dq.push_front(temp->left);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};
