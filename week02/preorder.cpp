//
// Created by lewang on 11/1/20.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Node {
public:
    int val;
    vector<Node* > children;

    Node() {}

    Node(int _val) {
        val = _val;
    }
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution{
public:
    //recursion
    vector<int> res;
    vector<int> preorder(Node* root) {
        //判断root是否为空,如果为空返回
        if(!root) return res;
        //将根节点的值压入结果
        res.push_back(root->val);
        //next = root->children
        for(auto i : root->childen){
            //遍历root的孩子结点,递归调用preorder
            res = preorder(i);
        }
        return res;
    }
    //iteration
    vector<int> preorder2(Node* root) {
        vector<int> res;
        if(!root) return res;

        stack<Node*> stack;
        stack.push(root);
        while(!stack.empty()) {
            Node* temp = stack.top();
            stack.pop();
            res.push_back(temp->val);
            for (int i = tmp->children.size()-1; i >= 0; --i) {
                //栈是后进先出,所以是从孩子结点中的最后一个开始循环
                stack.push(temp->children[i]);
            }
        }
        return res;
    }



};

int main(){

    return 0;
}