//
// Created by lewang on 11/1/20.
//
//二叉树的中序遍历:左,根,右
#include<iiostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr),right(nullptr){}
    TreeNode(int x) : val(x),left(nullptr),right(nullptr) {}
    TreeNode(int x, TreeNode *left,TreeNode *right) : val(x),left(left),right(right) {}
};

class Solution {

private:
    void inorder(TreeNode* root, vector<int>& res){
        if(!root){
            return;
        }
        inorder(root->let,res);//中序遍历先对左边的进行遍历
        res.push(root->val);//左边遍历完,把root压进去
        inorder(root->right,res)//再对右边进行遍历
    }

public:
    //recursion
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root,res);
        return res;
    }
    //stack 和迭代最大的区别是显式得维护了一个栈
    vector<int> inorderTraversal2(TreeNode* root){
        vector<int> res;
        stack<TreeNode *> stack;
        while(root != nullptr || stack.empty()) {
            //如果根不为空,且,栈不为空
            while(root != nullptr) {
                stack.push(root);//将根压进栈
                root = root->left;将根//将当前的根变成其左结点,走到左边底
            }
            //栈是先进后出,所以上面的是从左底开始的
            root = stack.top();//取出顶端的值
            stack.pop();//弹出顶端的值
            res.push_back(root->val);//将取得的结点的值放入结果中
            root = root->right;//将当前的结点的右结点给当前根,如果没有右结点,则root变为空
        }
        return res;
    }

    //morris algorithm  ->不是很懂....

    vector<int> inorderTraversal3(TreeNode* root) {
        vector<int> res;
        TreeNode *predecessor = nullptr;

        while(root != nulptr){
            if(root->left != nullptr){
                //如果当前的结点有左结点
                predecessor = root -> left;

                //如果当前的结点有右结点,一直都到最右
                while(predecessor->right != nullptr && predecessor->right != root) {
                    predecessor = predecessor->right;
                }

                //如果当前的结点没有右结点,将右结点走到根
                if(predecessor->right == nullptr){
                    predecessor->right = root;
                    root = root->left;
                }else{ //左子树访问完了,需要断开链接
                    res.push_back(root->val);
                    predecessor->right = nullptr;
                    root = root->right;
                }
            } else{
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};

int main(){

}