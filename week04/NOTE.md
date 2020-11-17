学习笔记
# 第九课
**深度优先搜索 广度优先搜索**

遍历搜索
在树(图)中寻找特定结点
前
中
后
序遍历

每个结点要访问且仅访问一次

 - 深度优先
 - 广度优先
 - 优先级优先(启发式搜索)
 
 ```python
def dfs(node):
    if node in visited:
        # already
        return
    visited.add(node)
    
    # process current node
    # ... # logic here
    dfs(node.left)
    dfs(node.right)

```

## dfs模板

递归写法 -- 由系统维护一个栈

```
map<int, int> visited;

void dfs(Node* root) {
    //temintor
    if(!root) return;
    if(visited.count(root->val)) {
        //already visited
        return;
    }
    
    visited[root->val] = 1
    
    //process current node here
    //...
    for(int i = 0; i < root->children.size(); ++i) {
        dfs(root->children[i]);
    }
    return;
}

```


非递归写法 -- 自己显式的维护一个栈
```
void dfs(Node* root) {
    map<int,int> visited;
    if(!root) return;
    
    stack<Node*> stackNode;
    stackNode.push(root);
    
    while(!stackNode.empty()) {
    Node* node = stackNode.top() ;
    stackNode.pop();
    if(visited.count(node->val)) continue;
    visited[node->val] = 1;
        
        for (int i = node->children.size() - 1; i>= 0; --i) {
            stackNode.push(node->children[i]);
        }
    }
return ;
}

```

## bfs模板
```
void bfs(Node* root) {
    map<int, int> visited;
    if(!root) return;
    
    queue<Node*> queueNode;
    queueNode.pop();
    while(!queueNode.emppty()) {
    
    Node* node = queueNode.top();
    queueNode.pop();
    
    if(visited.count(node->val)) continue;
    visited[node->val] = 1;
    
    for(int i = 0; i < node->children.size(); ++i) {
        queueNode.push(node->children[i]);
    }
    
 }
 
 return;
}
```

## Todo
## 实战题目

- &radic; [二叉树的层序遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/#/description)（字节跳动、亚马逊、微软在半年内面试中考过）
- &radic;[最小基因变化](https://leetcode-cn.com/problems/minimum-genetic-mutation/#/description)
- &radic;[括号生成](https://leetcode-cn.com/problems/generate-parentheses/#/description)（字节跳动、亚马逊、Facebook 在半年内面试中考过）
- &radic;[在每个树行中找最大值](https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/#/description)（微软、亚马逊、Facebook 在半年内面试中考过）

## 课后作业

- &radic;[单词接龙](https://leetcode-cn.com/problems/word-ladder/description/)（亚马逊在半年内面试常考）
- &radic;[单词接龙 II ](https://leetcode-cn.com/problems/word-ladder-ii/description/)（微软、亚马逊、Facebook 在半年内面试中考过）
- &radic;[岛屿数量](https://leetcode-cn.com/problems/number-of-islands/)（近半年内，亚马逊在面试中考查此题达到 350 次）
- [Todo][扫雷游戏](https://leetcode-cn.com/problems/minesweeper/description/)（亚马逊、Facebook 在半年内面试中考过）

# 第十课
*贪心算法*

贪心算法是一种在每一步选择中都采取在当前状态下最好或最优(即最有利)的选择,
从而希望导致结果是全局最好或最优的算法.

贪心算法与动态规划的不同在于他对每个子问题的结局方案都做出选择,*不能回退*.
动态规划则会保存以前运算的结果,并根据以前的运算结果,并根据以前的结果对当前进行选择,*有回退功能*.

贪心算法有时不能达到全局最优

 - 贪心: 当下做出局部最优判断
 - 回溯: 能够回退
 - 动态规划: 最优判断 + 回退

贪心法可以解决一些最优化问题.
如:求途中的最小生成树,求哈夫曼编码.
然而对于工程和生活中的问题,贪心法一般不能得到我们所需要的答案.

一旦一个问题可以通过叹息发来求解,那么贪心法一般是解决这个问题的最好办法.
由于贪心法的高效性以及其所求得的答案比较接近最优结果,贪心法也可以用作辅助计算法或者直接解
一些要求结果不特别精确的问题.


例: 换硬币,特殊情况,小额硬币可以整除大额硬币

## 适用贪心算法的场景
简答地说,问题能够分解成子问题来解决,子问题的最优解能够地推带最终问题的最优解.
这种子问题最优解称为最优子结构.

贪心算法与动态规划的不同在于它对每个子问题的解决方案都做出选择,不能回退.
动态规划规则则会保存以前的运算结果,并根据以前的结果对当前进行选择,有回退功能.

## 课后作业

- &radic; [柠檬水找零](https://leetcode-cn.com/problems/lemonade-change/description/)（亚马逊在半年内面试中考过）
- &radic; [买卖股票的最佳时机 II ](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/description/)（亚马逊、字节跳动、微软在半年内面试中考过）
- &radic; [分发饼干](https://leetcode-cn.com/problems/assign-cookies/description/)（亚马逊在半年内面试中考过）
- &radic; [模拟行走机器人](https://leetcode-cn.com/problems/walking-robot-simulation/description/)
- &radic; [跳跃游戏](https://leetcode-cn.com/problems/jump-game/) （亚马逊、华为、Facebook 在半年内面试中考过）
- &radic; [跳跃游戏 II ](https://leetcode-cn.com/problems/jump-game-ii/)（亚马逊、华为、字节跳动在半年内面试中考过）


# 二分查找
## 二分查找的前提
1. 目标函数单调性(单调递增或者单调递减) 有序的!!!!!!!
2. 存在上下界(bounded) 
3. 能够通过索引访问(index accessible)

```代码模板
left,right = 0, len(array) - 1

while left <= right: #此处要注意有没有等于号
    mid = (left + right) / 2
    if array[mid] == target
    #find the target!
        break or return result
    elif array[mid] < target:
        left = mid + 1
    else:
        right = mid -1  
```
五毒神掌,四步做题

1. 分析题目
2. 想所有解法,讨论分析出最优解
3. 写代码
4. 测试&debug


例:
1. 暴力:还原->升序 -> 二分  (O(n)但是也可以做到O(logn) 自己思考 *todo*)  
2. 二分查找  
   
   
## 参考链接

- [二分查找代码模板](https://shimo.im/docs/xvIIfeEzWYEUdBPD/)
- [Fast InvSqrt() 扩展阅读](https://www.beyond3d.com/content/articles/8/)

## 实战题目

- &radic; [x 的平方根](https://leetcode-cn.com/problems/sqrtx/)（字节跳动、微软、亚马逊在半年内面试中考过）
- &radic; [有效的完全平方数](https://leetcode-cn.com/problems/valid-perfect-square/)（亚马逊在半年内面试中考过）

## 课后作业

- &radic; [搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)（Facebook、字节跳动、亚马逊在半年内面试常考）
- &radic; [搜索二维矩阵](https://leetcode-cn.com/problems/search-a-2d-matrix/)（亚马逊、微软、Facebook 在半年内面试中考过）
- &radic; [寻找旋转排序数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)（亚马逊、微软、字节跳动在半年内面试中考过）
- 使用二分查找，寻找一个半有序数组 [4, 5, 6, 7, 0, 1, 2] 中间无序的地方
  说明：同学们可以将自己的思路、代码写在学习总结中




