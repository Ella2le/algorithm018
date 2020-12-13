学习笔记


# 位运算
十进制转二进制

位运算:  
- 与  &
- 或  |
- 非  ~
- 异或 ^
- 左移 <<
- 右移 >>


异或的一些操作  
x ^ 0 =x  
x ^ 1s = ~x //注意 1s = ~0  
x ^ (~x) = 1s  
x ^ x = 0  
c = a ^ b => a ^ c = b, b ^ c = a //异或操作来 交换两个数    
a ^b ^ c = a ^ (b ^ c) = (a ^ b) ^c //满足结合律   

指定位置的位运算:  
1.将x最右边的n位清零:x&(~0<<n)  
2.获取x的第n位值(0或者1): (x>>n)&1   
3.获取x的第n位值的幂值: x&(1<<n)  
4.仅将第n位设为1: x|(1<<n)  
5.仅将第n为设为0: x & (~(1<<n))  
6.将x最高位到第n位(含)清零:x & ((1 << n) - 1)  

实战位运算要点  
- 判断奇偶  
x % 2 == 1 --> (x & 1) == 1
x % 2 == 0 --> (x & 1) == 0
- 除以二  
x>>1 --> x/2  
mid = (left + right) / 2 --> mid = (left + right) >> 1  
- 清零最低位的1  
x = x & (x-1) 

- 得到最低位的1  
x & -x

- x & ~x = 0
x & -x

位运算实战例题
## 实战题目 / 课后作业

- [位 1 的个数](https://leetcode-cn.com/problems/number-of-1-bits/)（Facebook、苹果在半年内面试中考过）
- [2 的幂](https://leetcode-cn.com/problems/power-of-two/)（谷歌、亚马逊、苹果在半年内面试中考过）
- [颠倒二进制位](https://leetcode-cn.com/problems/reverse-bits/)（苹果在半年内面试中考过）
- [N 皇后](https://leetcode-cn.com/problems/n-queens/description/)（字节跳动、亚马逊、百度在半年内面试中考过）
- [N 皇后 II ](https://leetcode-cn.com/problems/n-queens-ii/description/)（亚马逊在半年内面试中考过）
- [比特位计数](https://leetcode-cn.com/problems/counting-bits/description/)（字节跳动、Facebook、MathWorks 在半年内面试中考过）


# 布隆过滤器
Bloom filter  
和hash map 对比

hashTable + 拉链存储重复元素,没有误差,一一对应  
大,存储所有目标,以及目标对应的所有值  
只需要查询表中有还是没有这个目标--> bloom filter  
**布隆过滤器**  
一个很长的**二进制向量**和一系列随机映射函数.布隆过滤器可以用于检索一个元素是否在一个集合中  
优点是空间效率和查询时间都**远远**超过一般的算法  
缺点是有一定的误识别率和删除困难

布隆过滤器只是试试放在外面当一个很快的判断来使用,节省后序访问数据库的时间,

案例  
1. 比特币网络  
2. 分布式系统(Map_reduce) -- Hadoop ,search engine
3. Redis 缓存
4. 垃圾邮箱\评论等的过滤.



## 参考链接

- [布隆过滤器的原理和实现](https://www.cnblogs.com/cpselvis/p/6265825.html)
- [使用布隆过滤器解决缓存击穿、垃圾邮件识别、集合判重](https://blog.csdn.net/tianyaleixiaowu/article/details/74721877)
- [布隆过滤器 Python 代码示例](https://shimo.im/docs/UITYMj1eK88JCJTH)
- [布隆过滤器 Python 实现示例](https://www.geeksforgeeks.org/bloom-filters-introduction-and-python-implementation/)
- [高性能布隆过滤器 Python 实现示例](https://github.com/jhgg/pybloof)
- [布隆过滤器 Java 实现示例 1](https://github.com/lovasoa/bloomfilter/blob/master/src/main/java/BloomFilter.java)
- [布隆过滤器 Java 实现示例 2](https://github.com/Baqend/Orestes-Bloomfilter)



# LRUCache
Cache 缓存  
1. 记忆  
2. 钱包- 储物柜
3. 代码模块

CPU socket

- 两个要素: 大小\ 替换策略(决定哪些放在更优先的cache, 因为我们能存(人能记)的东西优先)
- Hash Table + Double LinkedList  
- O(1) 查询,修改,更新  

LRU - Least Recently Used
LFU - Least Frequently Used


## 参考链接

- [Understanding the Meltdown exploit](https://www.sqlpassion.at/archive/2018/01/06/understanding-the-meltdown-exploit-in-my-own-simple-words/)
- [替换算法总揽](https://en.wikipedia.org/wiki/Cache_replacement_policies)
- [LRU Cache Python 代码示例](https://shimo.im/docs/CoyPAyXooGcDuLQo)

## 实战题目 / 课后作业

- [LRU 缓存机制](https://leetcode-cn.com/problems/lru-cache/#/)（亚马逊、字节跳动、Facebook、微软在半年内面试中常考）


# 排序算法 - 初级排序和高级排序  
1. 比较类排序:  
    通过比较来决定元素间的相对次序,由于其时间复杂度不能突破O(nlogn),
    因此也被称为非线性时间比较类排序
2. 非比较类排序:  
    不通过比较来决定元素间的相对次序,他可以突破基于比较排序时的时间下界,
    以线性时间运行,因此也被称为线性时间非比较类排序
   
## 初级排序
1. 选择排序(Selection Sort)  
    每次找最小值,然后放到待排序数组的起始位置  
2. 插入排序(Insertion Sort)  
    从前到后逐步构建有序序列;对于未排序数据,在已经排序序列中从后向前  
    扫描,找到相应位置并插入  
3. 冒泡排序(Bubble Sort)  
    嵌套循环,每次查看相邻的元素如果逆序,则交换
    
## 高级排序 (O(N*logN)) 
1. 快速排序(Quick Sort)  
    数组取标杆pivot,将小元素放在pivot的左边,大元素放右侧,然后一次对右边和右边的子数组继续快排;
    以达到整个序列有序  
**注意** 正常情况下数组的prepend操作的时间复杂度是O(n),但是可以进行特殊优化到
        O(1).采用的方式申请稍大一些的内存空间,然后在数组最开始预留一部分空间,然后prepend
        操作则是把头下标前移一个位置即可 (主定理证明时间复杂度(O(N*logN)))
2. 归并排序(Merge Sort) -- 分治  
    1.把长度为n的输入序列分成两个长度为n/2的子序列;
    2.对这两个序列分别采用归并排序;
    3.将两个排序好的子序列合并成一个最终的排序序列
     
    归并和快排具有相似性, 但步骤顺序相反
    归并: 先排序左右子数组,然后合并两个有序子数组
    快排:先调配出左右子数组,然后对于左右子数组进行排序

3. 堆排序 (Heap Sort) -- 堆插入O(logN),取最大/小值O(1)
    1.数组元素一次建立小顶堆
    2.依次取堆顶元素,并删除  
  
## 特殊排序
1. 计数排序(Counting Sort)  
    计数排序奥球输入的数据必须是有确定范围的整数.
    将输入的数据值转化为键存储在额外开辟的数组空间中,然后依次把计数大于1的
    填充回原数组   
2. 桶排序(Bucket Sort)
    桶排序假设输入数据服从均匀分布,将数据分到
    有限数量的桶,每个桶分别排序,(有可能再其使用别的排序
    算法或是以递归的方式继续使用桶排序进行排序).  
3.  基数排序(Radix Sort)
    基数排序按照地位优先排序,然后手机;再按照高位排序,然后再收集;依次类推,
    直到最高位.有时候有些属性是有优先级顺序的,先按照优先级排序,再按照
    高优先级排序.   
    



## 参考链接

- [十大经典排序算法](https://www.cnblogs.com/onepixel/p/7674659.html)
- [快速排序代码示例](https://shimo.im/docs/TX9bDbSC7C0CR5XO)
- [归并排序代码示例](https://shimo.im/docs/sDXxjjiKf3gLVVAU)
- [堆排序代码示例](https://shimo.im/docs/M2xfacKvwzAykhz6)


# 特殊排序&实战

## 参考链接

- [十大经典排序算法](https://www.cnblogs.com/onepixel/p/7674659.html)
- [9 种经典排序算法可视化动画](https://www.bilibili.com/video/av25136272)
- [6 分钟看完 15 种排序算法动画展示](https://www.bilibili.com/video/av63851336)

## 实战题目 / 课后作业

- [数组的相对排序](https://leetcode-cn.com/problems/relative-sort-array/)（谷歌在半年内面试中考过）
- [有效的字母异位词](https://leetcode-cn.com/problems/valid-anagram/)（Facebook、亚马逊、谷歌在半年内面试中考过）
- [力扣排行榜](https://leetcode-cn.com/problems/design-a-leaderboard/)（此题选做；Bloomberg 在半年内面试中考过）
- [合并区间](https://leetcode-cn.com/problems/merge-intervals/)（Facebook、字节跳动、亚马逊在半年内面试中常考）
- [翻转对](https://leetcode-cn.com/problems/reverse-pairs/)（字节跳动在半年内面试中考过）





# 本周作业

简单

- [位 1 的个数](https://leetcode-cn.com/problems/number-of-1-bits/)
（Facebook、苹果在半年内面试中考过）&radic;  
- [2 的幂](https://leetcode-cn.com/problems/power-of-two/)
（谷歌、亚马逊、苹果在半年内面试中考过）&radic;  
- [颠倒二进制位](https://leetcode-cn.com/problems/reverse-bits/)（苹果在半年内面试中考过）
- 用自己熟悉的编程语言，手写各种初级排序代码，提交到学习总结中。&radic;
- [数组的相对排序](https://leetcode-cn.com/problems/relative-sort-array/)（谷歌在半年内面试中考过）
- [有效的字母异位词](https://leetcode-cn.com/problems/valid-anagram/)
（Facebook、亚马逊、谷歌在半年内面试中考过）&radic;

中等

- [LRU 缓存机制](https://leetcode-cn.com/problems/lru-cache/#/)
（亚马逊、字节跳动、Facebook、微软在半年内面试中常考）&radic;  
- [力扣排行榜](https://leetcode-cn.com/problems/design-a-leaderboard/)（Bloomberg 在半年内面试中考过）
- [合并区间](https://leetcode-cn.com/problems/merge-intervals/) 
（Facebook、字节跳动、亚马逊在半年内面试中常考）&radic;  

困难

- [N 皇后](https://leetcode-cn.com/problems/n-queens/description/)
（字节跳动、亚马逊、百度在半年内面试中考过）&radic;  
- [N 皇后 II ](https://leetcode-cn.com/problems/n-queens-ii/description/)
（亚马逊在半年内面试中考过）&radic;  
- [翻转对](https://leetcode-cn.com/problems/reverse-pairs/)
（字节跳动在半年内面试中考过）&radic;

## 下周预习题目：

- [不同路径](http://leetcode-cn.com/problems/unique-paths/)
- [最小路径和](http://leetcode-cn.com/problems/minimum-path-sum/)



