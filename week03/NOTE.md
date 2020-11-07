学习笔记

## 第七课
树的面试题,很多都是用递归来解决的.

二叉树的遍历(前中后)

python 的递归模板

```python
def recursion(level,param1,param2,...):
    #recursion terminator
    #一定要有防止死循环
    if level > max_level: 
        process_result
        return
        
    #process logic in current level
    process(level,data...)
    
    #drill down
    self.rcursion(level+1,p1,...)
    
    #reverse the current level status if needed
    #比如一些全局变量啥的,

```
java 模板
```java
public void recur(int level, int param) {
//terminator 
    if(level > max_level) {
    //process result
    return;
    }
    
    //process current logic
    process(level,param));
    
    //drill down
    recur(level:level+1,newParam);
    
    //restore current status

```

注意
- 不要进行人肉递归,就是不要自己老是手写来推
- 找到最近最简洁方法,将其拆解成为可重复解决的问题
(重复子问题)
- 数学归纳法

习题
1.爬楼梯 f(n) = f(n-1) + f(n-2)
2.括号生成 


## 第八课
分治,回溯
有点像递归,可以套用之前的模板
但是针对具体的问题,drill down 可以灵活的处理

回溯是一种利用深度优先搜索的有方向的搜索搜索,也可算一种稍微聪明一点的搜索方法.

实战
子集
生成括号
N皇后


## 本周作业

### 中等：

- &radic;  [二叉树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/)（Facebook 在半年内面试常考）
- &radic; [从前序与中序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)（字节跳动、亚马逊、微软在半年内面试中考过）
- &radic; [组合](https://leetcode-cn.com/problems/combinations/)（微软、亚马逊、谷歌在半年内面试中考过）
- &radic; [全排列](https://leetcode-cn.com/problems/permutations/)（字节跳动在半年内面试常考）
- &radic; [全排列 II ](https://leetcode-cn.com/problems/permutations-ii/)（亚马逊、字节跳动、Facebook 在半年内面试中考过）

## 下周预习

### 预习题目：

- [二叉树的层次遍历](http://leetcode-cn.com/problems/binary-tree-level-order-traversal/#/description)
- [分发饼干](http://leetcode-cn.com/problems/assign-cookies/description/)
- &radic; [买卖股票的最佳时机 II](http://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/description/)
- [跳跃游戏](http://leetcode-cn.com/problems/jump-game/)
- &radic; [x 的平方根](http://leetcode-cn.com/problems/sqrtx/)
- &radic; [有效的完全平方数](http://leetcode-cn.com/problems/valid-perfect-square/)

