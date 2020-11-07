//
// Created by lewang on 11/5/20.
//

#include <iostream>


 Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

//思路
//
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if( root == nullptr || root = p || root == q) return root;
    TreeNode left = lowestCommonAncestor(root->left,p,q);
    TreeNode right = lowestCommonAncestor(root->right, p ,q);
    if(left == nullptr) return right;
    if(right == nullptr) return left;
    return root;
    }
};

//时间复杂度O(N),
//空间复杂度O(N)