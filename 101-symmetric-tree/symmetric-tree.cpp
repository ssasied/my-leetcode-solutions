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
    bool isSymmetric(TreeNode* root) {
        TreeNode *left, *right;
        if (!root)return true;

        deque<TreeNode*> q, p;
        q.push_back(root->left);
        p.push_back(root->right);
        while(!q.empty()&&!p.empty()){
            left = q.front();            
            right = p.front();
            q.pop_front();
            p.pop_front();
            if(!left&&!right)continue;
            else if(!left||!right) return false;
            else if(left->val != right->val)return false;
            q.push_back(left->left);
            q.push_back(left->right);
            p.push_back(right->right);
            p.push_back(right->left);
        }
        return true;
    }
};