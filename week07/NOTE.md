学习笔记
# 字典树 Trie  
按层次打印二叉树 bfs 

1. 字典树的数据结构   
字典树,即trie树

# 并查集

# 高级搜索  
初级搜索
1.朴素搜索
2.优化方式: 不重复(fibonacci),剪枝(生成括号)
3.搜索方向:
DFS
BFS
双向搜索
启发式搜索
动态规划
coin change
Alpha zero

回溯法
回溯法采用试错的思想,他尝试分布的去解决一个问题.在分布解决问题的过程中,当它通过尝试发现现有的分布答案不能
得到有效的正确的解答的时候,它将取消上一步甚至上几步的计算,再通过其他的可能的分布解答再次尝试寻找问题的答案

回溯法通常用最简单的递归方法来实现,在反复重复上述的步骤后可能出现两种情况:
1. 找到一个可能存在的正确的答案
2. 在尝试了所有可能的分布方法后宣告该问题没有答案
在最坏的情况下,回溯法会导致一次复杂度为指数时间的计算
## 剪枝
爬楼梯

括号生成
### 参考链接

- [DFS 代码模板](https://shimo.im/docs/UdY2UUKtliYXmk8t)
- [BFS 代码模板](https://shimo.im/docs/ZBghMEZWix0Lc2jQ)
- [AlphaZero Explained](https://nikcheerla.github.io/deeplearningschool/2018/01/01/AlphaZero-Explained/)
- [棋类复杂度](https://en.wikipedia.org/wiki/Game_complexity)

### 实战题目

- [爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/)（阿里巴巴、腾讯、字节跳动在半年内面试常考）
- [括号生成](https://leetcode-cn.com/problems/generate-parentheses/)（亚马逊、Facebook、字节跳动在半年内面试中考过）
- [N 皇后](https://leetcode-cn.com/problems/n-queens/)（亚马逊、苹果、字节跳动在半年内面试中考过）
- [有效的数独](https://leetcode-cn.com/problems/valid-sudoku/description/)（亚马逊、苹果、微软在半年内面试中考过）
- [解数独](https://leetcode-cn.com/problems/sudoku-solver/#/description)（亚马逊、华为、微软在半年内面试中考过）

## 双向BFS
单词接龙
1. BFS  
2. DFS  
3. 双向BFS

433.最小基因变换
### 实战题目

- [单词接龙](https://leetcode-cn.com/problems/word-ladder/)（亚马逊、Facebook、谷歌在半年内面试中考过）
- [最小基因变化](https://leetcode-cn.com/problems/minimum-genetic-mutation/)（谷歌、Twitter、腾讯在半年内面试中考过）

### 课后作业

- 总结双向 BFS 代码模版，请同学们提交在学习总结中。

## 启发式搜索( Heuristic Search A*)
基于BFS代码

模板:

**估价函数/优先级函数**： h(n),它用来评价那些结点最优希望是我们要找的结点,
h(n)会返回一个非负实数,也可以认为是从结点的目标结点路径的估计成本

启发式函数是一种告知搜索方向的方法.它提供了一种明智的方法来猜测哪个邻居结点会
导向一个目标

1091.二进制矩阵中的最短路径  
1.dp  
2.BFS  
3.A*  


773.滑动谜题  
slidingPuzzle  
1.BFS
2.A*
### 参考链接

- [A* 代码模板](https://shimo.im/docs/8CzMlrcvbWwFXA8r)
- [相似度测量方法](https://dataaspirant.com/2015/04/11/five-most-popular-similarity-measures-implementation-in-python/)
- [二进制矩阵中的最短路径的 A* 解法](https://leetcode.com/problems/shortest-path-in-binary-matrix/discuss/313347/A*-search-in-Python)
- [8 puzzles 解法比较](https://zxi.mytechroad.com/blog/searching/8-puzzles-bidirectional-astar-vs-bidirectional-bfs/)

### 实战题目

- [二进制矩阵中的最短路径](https://leetcode-cn.com/problems/shortest-path-in-binary-matrix/)（亚马逊、字节跳动、Facebook 在半年内面试中考过）
- [滑动谜题](https://leetcode-cn.com/problems/sliding-puzzle/)（微软、谷歌、Facebook 在半年内面试中考过）
- [解数独](https://leetcode-cn.com/problems/sudoku-solver/)（微软、华为、亚马逊在半年内面试中考过）


# 高级树,AVL树和红黑树
树

二叉树

二叉树遍历
代码模板

二叉搜索树,有序

保证性能的关键  
1.保证二维维度 -> 左右子树结点平衡  
2.balanced  
3.wiki/self-balancing_binary_search_tree 平衡二叉树

## AVL树
1.发明者: G.M.Adelson-Velsky 和 Evgenii Landis
2.Balance Factor(平衡因子)
是它的左子树的高度减去它的右子树的高度(有时相反)  
balance factor = {-1, 0, 1}
3.通过旋转操作来进行平衡(四种)
    右右子树 -> 左旋
    左左子树 -> 右旋
    左右子树 -> 左右旋
    右左子树 -> 右左旋
    
*注意有左右子树的的旋转,有需要换父节点
 不要求代码实现
不足: 结点需要储存额外信息,且调整次数频繁

## 红黑树(近似平衡二叉树)
红黑树是一种近似平衡的二叉搜索数(binary search tree), 它能够确保任何一个结点的左右子树
的高度差小于两倍.具体来说,红黑树是满足如下条件的二叉搜索树:
- 每个结点要么是红色,要么是黑色  
- 根节点是黑色  
- 每个叶结点(NIL结点,空结点),是黑色  
- 不能有相邻的两个红色结点  
- 从任一结点到其每个叶子的所有路径都包含相同数目的黑色结点-> 高度差小于两倍

对比红黑树和AVL
- AVL trees provide faster lookups than Red Black Trees because they are more strictly' balanced
- Red Black Trees provide faster insertion and removal operations than AVL trees as fewer rotations are
done due to relatively relaxed balancing
- AVL trees store balance factors or heights with each node thus requires storage for
an integer per node whereas Red Black Tree requires only 1 bit of information per
node.
- RedBlack Trees are used in most of the language libraries
like map, multimap, multisetin c++ whereas AVL trees are used in databases 
where faster retrievals are required.  

    

    
 
## 本周作业

### 简单

- [爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/)（阿里巴巴、腾讯、字节跳动在半年内面试常考）

### 中等

- [实现 Trie (前缀树) ](https://leetcode-cn.com/problems/implement-trie-prefix-tree/#/description)（亚马逊、微软、谷歌在半年内面试中考过）
- [朋友圈](https://leetcode-cn.com/problems/friend-circles)（亚马逊、Facebook、字节跳动在半年内面试中考过）
- [岛屿数量](https://leetcode-cn.com/problems/number-of-islands/)（近半年内，亚马逊在面试中考查此题达到 361 次）
- [被围绕的区域](https://leetcode-cn.com/problems/surrounded-regions/)（亚马逊、eBay、谷歌在半年内面试中考过）
- [有效的数独](https://leetcode-cn.com/problems/valid-sudoku/description/)（亚马逊、苹果、微软在半年内面试中考过）
- [括号生成](https://leetcode-cn.com/problems/generate-parentheses/)（亚马逊、Facebook、字节跳动在半年内面试中考过）
- [单词接龙](https://leetcode-cn.com/problems/word-ladder/)（亚马逊、Facebook、谷歌在半年内面试中考过）
- [最小基因变化](https://leetcode-cn.com/problems/minimum-genetic-mutation/)（谷歌、Twitter、腾讯在半年内面试中考过）

### 困难

- [单词搜索 II ](https://leetcode-cn.com/problems/word-search-ii/)（亚马逊、微软、苹果在半年内面试中考过）
- [N 皇后](https://leetcode-cn.com/problems/n-queens/)（亚马逊、苹果、字节跳动在半年内面试中考过）
- [解数独](https://leetcode-cn.com/problems/sudoku-solver/#/description)（亚马逊、华为、微软在半年内面试中考过）

## 下周预习题目

- [LRU 缓存机制](https://leetcode-cn.com/problems/lru-cache/#/)
- [有效的字母异位词](https://leetcode-cn.com/problems/valid-anagram/)

      










