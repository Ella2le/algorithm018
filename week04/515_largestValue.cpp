//
// Created by lewang on 11/13/20.
//

#include <iostream>
#include <vector>
#include<map>
#include <queue>
#include <limits.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {};

};
//思路
//BFS
//----------------自己写的,有错误----------------------------
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        res.push_back(root->val);
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        int levelmax;
        BFS(root,res,levelmax);



    }
private:
    void BFS(TreeNode* root,vector<int> &res,int &levelmax) {
        //map<int, int> visited;
        if(!root) return;
        int temp;
        levelmax = INT_MIN;
        temp = root->val;
        if(temp > levelmax){
            levelmax = temp;
        }

        queue<TreeNode*> queueNode;
        queueNode.push(root);

        while(!queueNode.empty()) {
            TreeNode* node = queueNode.front();
            queueNode.pop();
            BFS(node,res,levelmax);

            res.push_back(levelmax);
            TreeNode* left = node->left;
            if(left == nullptr) return;
            queueNode.push(left);

            TreeNode* right = node->right;
            if(right == nullptr) return;
            queueNode.push(right);
            //if(visited.count(node->val)) continue;
            //visited[root->val] = 1;
        }
    }
//---------------------参考题解 BFS -------------------
public:
    vector<int> largestValues2(TreeNode* root){
        vector<int> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int len = (int)q.size();
            int res = INT_MIN;
            q.pop();
            while(len--) {
                auto x = q.front();
                q.pop();
                res = max(res,x->val);
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
            ans.push_back(res);
        }
        return ans;

    }
 //******************************************************8
//Compile Error:
//Line 29: Char 34: runtime error: member access within misaligned address 0xbebebebebebebebe for type 'TreeNode', which requires 8 byte alignment (solution.cpp)
//0xbebebebebebebebe: note: pointer points here
//<memory cannot be printed>
//SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:38:34
//Your input:[1,3,2,5,3,null,9]
//------------------------end---------------------------

//---------------------参考2--DFS---------------------------
private:
    vector<int> ans;
    void preorder(TreeNode* root, int height) {
        if(!root) return;
        if(ans.size() < height) {
            ans.push_back(root->val);
        }else {
            ans[height - 1] = max(ans[height - 1], root->val);
        }
        preorder(root->left, height + 1);
        preorder(root->right, height +1);
    }
public:
    vector<int> largestValue3(TreeNode* root) {
        preorder(root, 1);
        return ans;
    }
//----------------end---------------------------
/*
* Success:
* Runtime:24 ms, faster than 49.02% of C++ online submissions.
* Memory Usage:22 MB, less than 40.89% of C++ online submissions.
*/
//-----------------参考3-BFS-----------------------
public:
    vector<int> BDF(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        queue<int> level;

        q.push(root);
        level.push(0);
        vector<int> mac;

        int m = -1;
        while(!q.empty()) {
            TreeNode*r = q.front();
            q.pop();
            int l = level.front();
            level.pop();
            if(r->right) {
                q.push(r->left);
                level.push(l+1);
            }
            if(r->right){
                q.push(r->right);
                level.push(l+1);
            }
            if(l > m) {
                m=1;
                mac.push_back(r->val);
            }else {
                mac[l] = max(mac[l],r->val);
            }
        }
        return mac;
    }
};




int main(){
    TreeNode* root;
    Solution test;
    vector<int> res;
    res = test.largestValues(root);
    return 0;
}