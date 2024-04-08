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
    
    bool gotree(TreeNode *q,int num,const int &targetsum){
        int newnum=num+q->val;
        if(!q->right&&!q->left){
            if(newnum==targetsum)return true;
        }
        if((q->left&&gotree(q->left,newnum,targetsum))||(q->right&&gotree(q->right,newnum,targetsum)))return true;    
        return false;    
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)return false;
        return gotree(root,0,targetSum);
         

    }
};