//
// Created by lewang on 11/6/20.
//
#include <iostream>
#include <bitset>
#include <vector>
#include <unordered_map>
//二叉树-->递归
//前序: |   根  | 左子树 | 右子树 |
//中序: | 左子树 |   根  | 右子树 |
//时间复杂度O(N) 二叉树的结点数
//空间复杂度O(N) 哈希表的长度

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        //异常输入检查
        int preLen = preorder.size();
        int inLen = inorder.size();
        if(preLen != inLen) {
            cerr << "[ERROR] Incorrect input"<<endl;
        }
        //用hashmap存储中序遍历中,数值和下标,优化
        unordered_map<int,int> m(inLen, 0);
        for (int i = 0; i < inLen; i++) {
            m[inorder[i]] = i;
        }

        return getTree(preorder,0,preLen - 1,m,0,inLen - 1);

    }
    //i,i1 是前序遍历的两个边界
    //i2,i3是中序遍历的两个边界

private:
    TreeNode* getTree(vector<int>& preorder,int preLeft,int preRight,unordered_map<int,int> m,int inLeft, int inRight) {
        //terminator 传去的区间里没有数了
        //即,左边界数值大于右边界数值
        if(preLeft > preRight || inLeft > inRight) {
            return null;//返回空结点
        }
        //找到前序遍历的第一个结点,即二叉树的根节点
        int rootVal = preorder[preLeft];
        TreeNode* root = new TreeNode(preorder[preorder_root]);
        //root -> val = rootVal;
        auto it = m.find(rootVal);
        int pIndex = it->second;

        root->left = getTree(preorder, preLeft +1, pIndex - inleft + preLeft,m,inLeft, pIndex - 1 );

        root->right = getTree(preorder,pIndex - inLeft + preLeft + 1, preRight, m pIndex + 1, inRight);

        return root;
    }

};

int main() {
    Solution test;
    vector<int> preorder {3,9,20,15,7};
    vector<int> inorder {9,3,15,20,7};

    TreeNode* res;
    res = test.buildTree(preorder,inorder);

    return 0;
}