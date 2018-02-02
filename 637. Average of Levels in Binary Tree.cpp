637. Average of Levels in Binary Tree
DescriptionHintsSubmissionsDiscussSolution
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.

/**
 * Definition for a binary tree node.
 * struct TreeNode {//
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        dfs(root, 0);    
        vector<double> res;
        for(int i = 0; i <= ma ;i++) res.push_back(1.0*sum[i]/cnt[i]);
        return res;
    }
private: 
    int ma = 0;
    long long sum[1000], cnt[1000];
    void dfs(TreeNode* root, int lev) {
        if(root == NULL) return;
        sum[lev] += root->val;
        ma = max(ma,lev);
        cnt[lev]++;
        dfs(root->left, lev + 1);
        dfs(root->right, lev + 1);
    }
};
