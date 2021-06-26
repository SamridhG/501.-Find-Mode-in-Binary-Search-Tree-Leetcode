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
    map<int,int>mp;
    vector<int>A;
    void inorder(TreeNode *root)
    {
        if(root!=NULL)
        {
            inorder(root->left);
            mp[root->val]++;
            A.push_back(root->val);
            inorder(root->right);
        }
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>result;
        inorder(root);
        if(A.size()==mp.size())
        {
            return A;
        }
        else
        {
            int i=0;
            for(auto s:mp)
            {
                if(s.second>i)
                {
                    i=s.second;
                }
            }
            for(auto s:mp)
            {
                if(s.second==i)
                {
                    result.push_back(s.first);
                }
            }
        }
        return result;
    }
};
