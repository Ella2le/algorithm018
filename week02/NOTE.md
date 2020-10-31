学习笔记

# 哈希表

哈希表（Hash table，也叫散列表），是根据关键码值(Key value)而直接进行访问的数据结构。也就是说，它通过把关键码值映射到表中一个位置来访问记录，以加快查找的速度。这个映射函数叫做  ** 散列函数 **，存放记录的数组叫做散列表。

## 哈希碰撞 （Hask Collisions）
解决方法
	- 拉链法 （链地址法
	- 散列法 （开放地址法

|search|insertion|deletion|
|---------|---------|---------|
|O(1)|O(1)|O(1)|

在c++STL中，map 对应的数据结构是 **红黑树**。红黑树是一种近似于平衡的二叉查找树，里面的数据是有序的。在红黑树上做查找操作的时间复杂度为 O(logN)。而 unordered_map 对应 哈希表，哈希表的特点就是查找效率高，时间复杂度为常数级别 O(1)， 而额外空间复杂度则要高出许多。所以对于需要高效率查询的情况，使用 unordered_map 容器。而如果对内存大小比较敏感或者数据存储要求有序的话，则可以用 map 容器

map是键值对

set只有单个不重复元素

##Todo 学习
**unordered_map**
底层实现hashmap的get（） pop（）函数
**map**

**set**
hastset
concurrentset
skiplistset.....

## 实战练习

### 1. 有效的字母异位词

### 2. 字母异位词分组

### 3. 两数之和
三数之和
四数之和

# 树，二叉树&二叉搜索树
## 节点的定义
```c++
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL),right(NULL) {}
}
```
## 二叉树  
每个节点最多只有两个分支的树结构.  
通常分支分支被成为"左子树"和"右子树"  
二叉树是有序树, 二叉树的分支具有左右次序, 不能随意颠倒.  

### 相关术语  

1. 结点: 包含一个数据元素以及若干指向子数分支的信息  
2. 结点的度: 一个结点拥有子树的数目称为该结点的度  
3. 叶子结点: 也称终端节点, 没有子树的结点或者度为零的结点  
4. 分支结点: 也称为非终端结点,度不为零的结点为非终端结点  
5. 树的度: 树中所有结点的度的最大值  
6. 结点的层次: 从根节点开始,假设根节点为第一层,根节点的子节点为第二层以此类推,
   如果某一节点位于第L层,则其子节点位于L+1层  
7. 树的深度: 也称为树的高度,树中所有结点的层次的最大值称为树的深度  
8. 有序树: 如果树中各个子树的次序是有先后次序,则称为该树是有序树
9. 无序树: 如果树中各个子树的次序没有先后次序,则称该树为无序树
10. 森林: 由m(m>=0)棵互不相交的树构成一片森林,如果把一棵非空的树的根节点删除,
    则该树就变成一片森林,森林中的树由原来根节点的各棵子树构成

### 一些性质

1. 二叉树的第*i*层至多有2<sup>i-1</sup>(i <= 1)个结点
2. 深度为h的二叉树中至多含有2<sup>h</sup>-1个节点
3. 具有n个几点的完全二叉树深度为log<sub>2</sub><sup>x</sup>+1个结点

### 二叉树的遍历

- 深度遍历  
  - 前序遍历(pre-order): 根结点 -> 左子树 -> 右子树  
  - 中序遍历(in-order): 左子树 -> 跟结点 -> 右子树 
  - 后序遍历(post-order):  左子树 -> 右子树 -> 根结点
- 广度遍历: 按层次遍历(需要堆等数据结构的支撑)

多用递归实现
实例（c++）


## 二叉搜索树
二叉搜索树，也称二叉排序树，有序二叉树（ordered binary tree），排序二叉树（sorted binary tree), 是指一棵空树或者具有下列性质的二叉树：  
1.左子树上的**所有结点**的值均小于它的根结点的值；  
2.右子树上的**所有结点**的值均大于它的根结点的值；  
3.以此类推：左，右子树叶分别为二叉搜索树  

 中序遍历是升序遍历？？？  

|查询|插入|删除|
|------|------|------|
|O(logn)|O(logn)|O(logn)|

 删除，需要找新的结点替代被删除的结点，保持树的结构，右子树第一个大于需要替换掉的结点...  

## 实战训练
**Todo**
c++ 的前中后序遍历的实现

### 1.preorder

### 2. inorder

### 3. postorder



# 堆(Heap) &二叉堆（Binary Heap)  
堆： 可以迅速找到一堆数中的最大或者最小值的数据结构。
将根结点最大的堆叫做大顶堆或大根堆，根结点最小的堆叫做小顶堆或小根堆

常见的堆有二叉堆，斐波那契堆 （不同的具体实现，[参考wiki](https://en.wikipedia.org/wiki/Heap_(data_structure))

|Operation|	find-max|delete-max|insert|increase-key|meld|
|-----|-----|-----|-----|-----|-----|-----|
|Binary|Θ(1)|Θ(log n)|O(log n)|O(log n)|Θ(n)|
|Leftist|Θ(1)|Θ(log n)|Θ(log n)|O(log n)|Θ(log n)|
|Binomial|Θ(1)|Θ(log n)|Θ(1)|Θ(log n)|O(log n)[c]|
|Fibonacci|Θ(1)|O(log n)|Θ(1)|Θ(1)[b]|Θ(1)|
|Pairing|Θ(1)|O(log n)|Θ(1)|o(log n)|Θ(1)|
|Brodal|Θ(1)|O(log n)|Θ(1)|Θ(1)|Θ(1)|
|Rank-pairing|Θ(1)|O(log n)|Θ(1)|Θ(1)[b]|Θ(1)|
|Strict Fibonacci|Θ(1)|O(log n)|Θ(1)|Θ(1)|Θ(1)|
|2-3 heap|O(log n)|O(log n)|O(log n)|Θ(1)| ?|

insert ：先插入左/右的末尾，然后根据堆的定义将其向上浮动

delete： 删除堆顶，把堆尾元素放入堆顶，和更大的子儿子进行换位。

**Note** 二叉堆是堆的一种常见且简单的实现，但并不是最优的实现。（在实际工程中可以直接调用priority_quene)

可以看一下c++中heap的源码实现



## 实战训练

### 面试题40. 最小的K个数

1. 排序，取前k个数， nlogn

2. 堆，nlogk
3. 快排 quick-sort

堆的实现

heap 小顶堆

### 滑动窗口的最小值

1. 双端队列
2. heap （priority——query）

### 前k个高频元素

1. hash map+大顶堆



# 图

## 图的属性和分类

现在算法面试中用的比价少

有点有边

- Graph(V,E)

- V - vertex ： 点

  1. 度（入度和出度） 连了多少个边
  2. 点与点之间：连通与否

  

- E - edge :边  
	1. 有向和无向（单行线）
	2. 权重（边长）



DFS代码 （Depth-First-Search) 深度优先搜索

 递归写法 

```
visited = set（） //和树中最大的区别
```

BFS (Breadth-First-Search) 宽度优先搜索

  

  ## 图的高级算法 （有兴趣自学）



## 参考链接

- 连通图个数：[ https://leetcode-cn.com/problems/number-of-islands/](https://leetcode-cn.com/problems/number-of-islands/)
- 拓扑排序（Topological Sorting）：[ https://zhuanlan.zhihu.com/p/34871092](https://zhuanlan.zhihu.com/p/34871092)
- 最短路径（Shortest Path）：Dijkstra https://www.bilibili.com/video/av25829980?from=search&seid=13391343514095937158
- 最小生成树（Minimum Spanning Tree）：[ https://www.bilibili.com/video/av84820276?from=search&seid=17476598104352152051](https://www.bilibili.com/video/av84820276?from=search&seid=17476598104352152051)



# 本周作业

### 简单：

- 写一个关于 HashMap 的小总结。
  说明：对于不熟悉 Java 语言的同学，此项作业可选做。
- [有效的字母异位词](https://leetcode-cn.com/problems/valid-anagram/description/)（亚马逊、Facebook、谷歌在半年内面试中考过）
- [两数之和](https://leetcode-cn.com/problems/two-sum/description/)（近半年内，亚马逊考查此题达到 216 次、字节跳动 147 次、谷歌 104 次，Facebook、苹果、微软、腾讯也在近半年内面试常考）
- [N 叉树的前序遍历](https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/description/)（亚马逊在半年内面试中考过）
- HeapSort ：自学 https://www.geeksforgeeks.org/heap-sort/

### 中等：

- [字母异位词分组](https://leetcode-cn.com/problems/group-anagrams/)（亚马逊在半年内面试中常考）
- [二叉树的中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)（亚马逊、字节跳动、微软在半年内面试中考过）
- [二叉树的前序遍历](https://leetcode-cn.com/problems/binary-tree-preorder-traversal/)（字节跳动、谷歌、腾讯在半年内面试中考过）
- [N 叉树的层序遍历](https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/)（亚马逊在半年内面试中考过）
- [丑数](https://leetcode-cn.com/problems/chou-shu-lcof/)（字节跳动在半年内面试中考过）
- [前 K 个高频元素](https://leetcode-cn.com/problems/top-k-frequent-elements/)（亚马逊在半年内面试中常考）

## 下周预习

### 预习题目：

- [爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/)
- [括号生成](https://leetcode-cn.com/problems/generate-parentheses/)
- [Pow(x, n)](https://leetcode-cn.com/problems/powx-n/)
- [子集](https://leetcode-cn.com/problems/subsets/)
- [N 皇后](https://leetcode-cn.com/problems/n-queens/)