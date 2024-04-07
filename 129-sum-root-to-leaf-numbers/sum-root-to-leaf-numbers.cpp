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
    void gotree(TreeNode *q,int num,int& sum){
        int newnum=num*10+q->val;
        if(!q->right&&!q->left){
            sum+=newnum;
            return;
        }
        if(q->left)gotree(q->left,newnum,sum);
        if(q->right)gotree(q->right,newnum,sum);
        return;
    } 
    int sumNumbers(TreeNode* root) {
        int sum=0;
        gotree(root,0,sum);
        return sum; 
    }
};