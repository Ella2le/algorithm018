//
// Created by lewang on 11/1/20.
//
//N叉树的层序遍历 重点掌握广度优先搜索!!! && 深度优搜索
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val){
        val = _val;
    }
    Node(int _val, vector<Node*> _children){
        val = _val;
        children = _children;
    }
};

class Solution {
//recursion
private:
    vector<vector<int>> res;
    void traverseNode(Node node,int level) {
        if(res.size() <= level) {
            res.add(new vector<int>)
        }
        res[level].push_back(node.val);
        for(Node child: node.children){
            traverseNode(child,level+1);
        }
    }
public:
    vector<vector<int>> levelOrder(Node* root){
        if(root != nullptr) traverseNode(root,0);
        return res;
    }

//breath first search BFS 广度优先搜索
    vector<vector<int>> levelOrder1(Node* root) {
        vector<vector<int>> res;
        if(!root) {
            return  res;
        }

        quene<Node*> q{{root}};

        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            while(size--){
                auto cur = q.front();
                q.pop();
                level.push_back(cur->val);
                for(const auto& child : cur->children){
                    q.push(child);
                }
            }
            res.push_back(level);

        }

        return res;
    }

//Deepth First Search DFS 深度优先搜索
    vector<vector<int>> levelOrder2(Node* root) {
        vector<vector<int>> res;
        if(!root) {
            return res;
        }
        dfs(root,res,0);
        return res;
    }

private:
    void dfs(Node* root, vector<vector<int>>& res, int level) {
        if(!root) {
            return;
        }
        if(res.size() == level) {
            res.push_back(vector<int>());
        }
        res[level].push_back(root->val);
        for(const auto& child: root->children) {
            dfs(child,res,levle+1);
        }
    }

};

