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
    void gotree(TreeNode *q,const int &targetSum,vector<int>&current,vector<vector<int>>&result){
        if(!q)return;
        current.push_back(q->val);
         if (!q->left && !q->right  && q->val == targetSum) {
            result.push_back(current);
        }
        gotree(q->left, targetSum - q->val, current, result);
        gotree(q->right, targetSum - q->val, current, result);
        current.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root)return {};
        vector<vector<int>>result;
        vector<int>current;
        gotree(root,targetSum,current,result);
        return result;
    }
};