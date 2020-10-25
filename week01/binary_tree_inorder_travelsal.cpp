//
// Created by lewang on 10/25/20.
//

#include <iostream>
#include <vector>
#include <stack>
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),right(right) {}
};

*/
//递归
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& res) {
        if (!root) {
            return;
        }
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
//
//    Runtime:4 ms, faster than 46.42% of C++ online submissions.
//    Memory Usage:8.7 MB, less than 7.75% of C++ online submissions.


    //---------------------------------------------
    //遍历
    //显式得维护一个栈
    vector<int> inorderTraversal2(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        while (root != nullptr || !stk.empty()) {
            while(root != nullptr) {
                stk.push(root);
                root = root -> left;
            }
            root = stk.top();
            stk.pop();
            res.push_back(root->val);
            root = root -> right;
        }
        return res;
    }
//    Success:
//    Runtime:0 ms, faster than 100.00% of C++ online submissions.
//    Memory Usage:8.6 MB, less than 8.33% of C++ online submissions.

//-------------------------------------------------------------------------
    //Morris中序遍历

    vector<int> inorderTraversal3(TreeNode* root) {
        vector<int> res;
        TreeNode *predecessor = nullptr;

        while (root  != nullptr) {
            if (root->left != nullptr) {
                predecessor = root->left;
                while(predecessor->right != nullptr && predecessor->right != root) {
                    predecessor = predecessor->right;
                }

                if(predecessor->right == nullptr) {
                    predecessor->right = root;
                    root = root->left;
                }else {
                    res.push_back(root->val);
                    predecessor->right = nullptr;
                    root = root->right;
                }
            } else {
              res.push_back(root->val);
              root = root->right;
            }

        }
        return res;
    }
//    Runtime:0 ms, faster than 100.00% of C++ online submissions.
//    Memory Usage:8.5 MB, less than 15.76% of C++ online submissions.

    vector<int> inorderTraversal4(TreeNode* root) {
        vector<int> result;
        stack<pair<TreeNode*, int> > stk;
        stk.push((make_pair(root, 0)));

        while(!stk.empty()) {
            auto [node, type] = stk.top();
            stk.pop();
            if(node == nullptr) continue;
            if(type == 0) {
                stk.push(make_pair(node->right, 0));
                stk.push(make_pair(node, 1));
                stk.push(make_pair(node->left, 0));
            }
            else result.emplace_back(node->val);
        }

        return result;

    }
    //Success:
    //Runtime:0 ms, faster than 100.00% of C++ online submissions.
    //Memory Usage:8.2 MB, less than 24.91% of C++ online submissions.

};
