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
    TreeNode *lastRight(TreeNode *root)
    {
        if (root->right == NULL)
            return root;
        return lastRight(root->right);
    }

    TreeNode *helper(TreeNode *root)
    {
        if (root->left == NULL)
            return root->right;
        if (root->right == NULL)
            return root->left;

        TreeNode *rightChild = root->right;
        TreeNode *lastRightOfLeft = lastRight(root->left);

        lastRightOfLeft->right = rightChild;

        return root->left;
    }

public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == NULL)
            return root;

        if (root->val == key)
            return helper(root);

        TreeNode *dummy = root;
        while (root)
        {
            if (root->val > key)
            {
                if (root->left != NULL && root->left->val == key)
                    root->left = helper(root->left);
                else
                    root = root->left;
            }
            else
            {
                if (root->right != NULL && root->right->val == key)
                    root->right = helper(root->right);
                else
                    root = root->right;
            }
        }
        return dummy;
    }
};