//
// Created by lewang on 11/8/20.
//
//dfs
//深度优先遍历用递归
class Solution {
public:
    // stack<vector<int>> temp;
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return res;
        getNext(root,0);
        return res;

    }

    void getNext(TreeNode* root,int level){
        //vector<int> temp;
        if(res.size() <= level) {
            res.push_back(vector<int>());
        }

        res[level].push_back(root->val);

        if(root->left != nullptr){
            getNext(root->left,level+1);
        }
        if(root->right != nullptr){
            getNext(root->right, level+1);
        }
    }


};
//DFS
//广度优先遍历用队列
class Solution {
public:
    // stack<vector<int>> temp;
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        while(que.size()!=0) {
            int size = que.size();
            vector<int> level;
            while(size--) {
                TreeNode* cur = que.front();
                que.pop();
                if(!cur) {
                    continue;
                }
                level.push_back(cur->val);
                que.push(cur->left);
                que.push(cur->right);
            }
            if(level.size()!=0){
                res.push_back(level);
            }
        }
        return res;
    }
};