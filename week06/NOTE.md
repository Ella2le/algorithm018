学习笔记  
**这周没有做好时间管理!!!作业后面补全!!**

递归  
分支  
模板要熟记
面试的时候如果又很难的问题那么一定可以拆分成小的子问题  

# 动态规划 Dynamic Programming

关键点  
- 动态规划和递归或者分治没有根本上的区别(关键看有无最优的子结构)  
- 共性: 找到重复子问题
- 差异性: 最优子结构\中途可图淘汰次优解

# 实战
1. 斐波那契数列
递归 - O(2^n)  
可以加一个memory 数组,记忆中间状态, 变成O(n)  
循环 自底向上 o(n)  

2. 62.count the path 不同路径  
    a. 最优子结构 opt[n] = best_of(opt[n-1],p[t[n-2],...]  
    b. 储存中间状态 opt[i]  
    c. 递推公式: 
    opt[i][j] = opt[i+1][j] + opt[i][j+1] (且判断a[i][j]是否有障碍物)
    
    

3. 1143.最长公共子序列

动态规划小结
1. 打破自己的思维习惯,形成机器思维
2. 理解复杂逻辑的关键
3. 也是职业进阶的要点要领

mit动态规划


70 爬楼梯  
1. 每次可以上1 2 3 阶
2. 还是1,2,3,但相邻两步不能相同
 

三角形最小路径法 minimumTotal
1. brute-force 递归 n层 left or right
2. DP 
    a. 重复性(分治)
    b. 定义状态数组
    c. dp状态方程
    
   
和最大子数组
   
乘积最大子数组

零钱兑换
  - 暴力递归
  - BFS
  - dp
  
  
  
  
  ## 本周作业
  
  ### 中等
  
  - [最小路径和](https://leetcode-cn.com/problems/minimum-path-sum/)（亚马逊、高盛集团、谷歌在半年内面试中考过）
  - [解码方法](https://leetcode-cn.com/problems/decode-ways)（亚马逊、Facebook、字节跳动在半年内面试中考过）
  - [最大正方形](https://leetcode-cn.com/problems/maximal-square/)（华为、谷歌、字节跳动在半年内面试中考过）
  - [任务调度器](https://leetcode-cn.com/problems/task-scheduler/)（Facebook 在半年内面试中常考）
  - [回文子串](https://leetcode-cn.com/problems/palindromic-substrings/)（Facebook、苹果、字节跳动在半年内面试中考过）
  
  ### 困难
  
  - [最长有效括号](https://leetcode-cn.com/problems/longest-valid-parentheses/)（字节跳动、亚马逊、微软在半年内面试中考过）
  - [编辑距离](https://leetcode-cn.com/problems/edit-distance/)（字节跳动、亚马逊、谷歌在半年内面试中考过）
  - [矩形区域不超过 K 的最大数值和](https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k/)（谷歌在半年内面试中考过）
  - [青蛙过河](https://leetcode-cn.com/problems/frog-jump/)（亚马逊、苹果、字节跳动在半年内面试中考过）
  - [分割数组的最大值](https://leetcode-cn.com/problems/split-array-largest-sum)（谷歌、亚马逊、Facebook 在半年内面试中考过）
  - [学生出勤记录 II ](https://leetcode-cn.com/problems/student-attendance-record-ii/)（谷歌在半年内面试中考过）
  - [最小覆盖子串](https://leetcode-cn.com/problems/minimum-window-substring/)（Facebook 在半年内面试中常考）
  - [戳气球](https://leetcode-cn.com/problems/burst-balloons/)（亚马逊在半年内面试中考过）
  
  ## 下周预习
  
  ### 预习题目：
  
  - [实现 Trie (前缀树)](https://leetcode-cn.com/problems/implement-trie-prefix-tree/#/description)
  - [单词搜索 II](https://leetcode-cn.com/problems/word-search-ii/)
  - [岛屿数量](https://leetcode-cn.com/problems/number-of-islands/)
  - [有效的数独](https://leetcode-cn.com/problems/valid-sudoku/description/)
  - [N 皇后](https://leetcode-cn.com/problems/n-queens/)
  - [单词接龙](https://leetcode-cn.com/problems/word-ladder/)
  - [二进制矩阵中的最短路径](https://leetcode-cn.com/problems/shortest-path-in-binary-matrix/)





     
    








