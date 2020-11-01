//
// Created by lewang on 11/1/20.
//
//二叉树的前序遍历,根,左,右
//和二叉树的中序遍历基本类似,注意往res.push_back的顺序
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x),left(left),right(right){}
};

class Solution{
private:
    void preorder(TreeNode* root, vector<int>& res){
        if(root == nullptr){
            return;
        }
        res.push_back(root->val);//左边遍历完,把root压进去
        preorder(root->let,res);//中序遍历先对左边的进行遍历
        preorder(root->right,res)//再对右边进行遍历
    }
public:
    //recursion
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root,res);
        return res;
    }
    //stack-iteration
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == nullptr){
            return res;
        }
        stack(TreeNode* ) stack;
        TreeNode* node = root;
        while(node != nullptr || !stack.empty()) {
            while (node != nullptr){
                res.push_back(node->val);
                stack.push(node);
                node = node->left;
            }
            node = stack.top();
            stack.pop();
            node = root->right;
        }
        return res;
    }
};

int main(){


    return 0;

}
