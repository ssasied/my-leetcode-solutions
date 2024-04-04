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
    bool checkifsame(TreeNode* p,TreeNode* q){
        if(p->val!=q->val)return false;
        if(p->left==nullptr||q->left==nullptr){
            if(p->left!=q->left)return false;
        }  
        if(p->right==nullptr||q->right==nullptr){
            if(p->right!=q->right)return false;
        }
        if(p->left){
            if(q->left){
                if(!checkifsame(p->left,q->left)){
                    return false;
                }
            }
        }
        if(p->right){
            if(q->right){
                if(!checkifsame(p->right,q->right)){
                    return false;
                }
            }
        }
        return true;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p&&!q)return true;
        if(!p&&q)return false;        
        if(!q&&p)return false;
        return (checkifsame(p,q));
    }
};