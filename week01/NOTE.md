学习笔记
#2020.10.19
##数组  
    时间复杂度  
        prepend O(1)  
        append O(1)  
        lookup O(1)  
        insert O(n)  
        delete O(n)  
##链表（单向链表，双向链表，环链表）  
    时间复杂度  
        prepend O(1)  
        append O(1)  
        lookup O(n)  
        insert O(1)  
        delete O(1)  

##跳表   
**只能用于元素有序的情况**  
对标平衡树和二分查找  
时间复杂度 O(logn)   (specific h=log2(n)-1)  
维护成本高,每一次增删都需要更新链表  
空间复杂度O(n)  
升维思想+空间换时间  
##工程中的应用（拓展）
LRU Cache  
Linked list  
**HashMap+双向链表**  
https://www.jianshu.com/p/b1ab4a170c3c
https://leetcode cn.com/problems/lru cache

Redis
Skip List
https://redisbook.readthedocs.io/en/latest/internal
datastruct/skiplist.html
https://www.zhihu.com/question/20202931

面试时不太会考，以看资料理解为主  
比如  
1）LRU cache 用的啥，巴拉巴拉  
2）Redis 用的是啥

**-------------------------------------------**
#实战练习
**五毒神掌**  

##Array
1.move zeros  
要检查输入
执行代码的时候尝试输入一下特殊的数字  

#一些疑问
1. 循环中使用++i和i++有没有区别
关于i++和++i是先返回再计算还是先计算再返回部分已经理解;
++i可以作为左值也可以理解;
就是好奇，**++i*** 和 **i++**在  
for ( int i, i < n, i++)  
for ( int i, i < n, ++i)  
有没有区别?  

2.  