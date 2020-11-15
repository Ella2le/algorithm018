//
// Created by lewang on 11/10/20.
//

//参考模板
#include <iostream>
#include <vector>
#include <queue>
#include <map>
struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
        };

class Solution {
public:
    // stack<vector<int>> temp;

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> que;
        //把当前结点放到队列中
        que.push(root);
        //只要队列不为空就一直循环
        while(que.size()!=0) {
            int size = que.size();
            //为了满足输出要求,每层一个list
            vector<int> level;
            //size是当前队列中有的结点数,也即需要到同一个list的一层的所有结点
            while(size--) {
                //从队列中取最上面的,
                TreeNode* cur = que.front();
                que.pop();
                //只要取出来的cur不为空,才进行下去
                if(!cur) {
                    continue;
                }
                //把当前结点的存的值放到当前层的list中
                level.push_back(cur->val);
                //把这个结点对应的左,右结点放到队列后
                que.push(cur->left);
                que.push(cur->right);
            }
            //一层循环完后把当前的list放进最后返回的容器中
            if(level.size()!=0){
                res.push_back(level);
            }
        }
        return res;
    }
    //参照模板写一个 ---> 不能生搬硬套模板
    vector<vector<int> levelOrder2(TreeNode* root) {
        vector<vector<int>> res;
        map<int,int> visited;

        queue<TreeNode*> que;
        que.push(root);

        //只要队列不为空就一直循环
        while(!que.empty()){
            vector<int> ans;
            TreeNode* node = que.top();
            que.pop();
            //如果这个结点访问过了就跳过
            if(visited.count(node->val)) continue;
            //如果没有,就把其对应位置设成1,标记成访问过了
            visited[node->val] = 1;
            //为了满足输入现将一层的放在一个结果
            ans.push_back(node->val);

            for(int i = 0; )

        }


        return res;

    }
};