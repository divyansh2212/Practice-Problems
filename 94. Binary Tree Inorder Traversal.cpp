// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long

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
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return {};

        stack<TreeNode *> st;
        vector<int> ans;

        TreeNode *curr = root;

        while (1)
        {
            if (curr)
            {
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                if (st.empty())
                    break;
                curr = st.top();
                ans.push_back(curr->val);
                curr = curr->right;
                st.pop();
            }
        }
        return ans;
    }
};