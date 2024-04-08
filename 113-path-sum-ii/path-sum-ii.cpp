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
    vector<vector<int>> gotree(TreeNode *q,int num,const int &targetsum,vector<int>current,vector<vector<int>>&result){
        int newnum=num+q->val;
        current.push_back(q->val);
        if(!q->right&&!q->left){
            if(newnum==targetsum)result.push_back(current);
        }
        if(q->left)gotree(q->left,newnum,targetsum,current,result);
        if(q->right)gotree(q->right,newnum,targetsum,current,result);
        return result;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root)return {};
        vector<vector<int>>result;
        return gotree(root,0,targetSum,{},result);
    }
};