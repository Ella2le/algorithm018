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
https://redisbook.readthedocs.io/en/latest/internaldatastruct/skiplist.html  
https://www.zhihu.com/question/20202931  

面试时不太会考，以看资料理解为主  
比如  
1）LRU cache 用的啥，巴拉巴拉  
2）Redis 用的是啥   

**-------------------------------------------**  
#实战练习  
**五毒神掌**  

##Array    

1. 3sum  
排序+双指针   
时间复杂度 O(n<sup>2</sup>)  
空间复杂度  

时间复杂度：O(n<sup>2</sup>)，
数组排序 O(nlog<sup>n</sup>)，
遍历数组 O(n)，
双指针遍历 O(n)，
总体 
空间复杂度：O(1)

暴力解法　　
哈希表＋嵌套循环　　
面试的时候简述上面的两种方法，说清楚时间复杂度．载给出最优解


2. plusone
**要考虑清楚问题,弄懂数据的各个不同小问题**  
如果+1<10 不用进位  
如果是9,则会=10,需要进位  
如果都是9则还需要在首位多一位1,ex: 999+1=1000  

3. watercontainer  
双指针夹逼  
时间复杂度 O(n<sup>2</sup>)  
空间复杂度  
**Note** vector<T>::size() 的返回值是siz_t,是無符號的整形.如果題目是一個空的vector,那麼vector的长度是0,
此时nums.size() -1 就会导致整型下溢,此时在for循环中  
for(int i = 0; i < nums.size()-1; i++)  
就是i在和一个非常大的数对比,导致越界.  
正确的做法是  
for(int i=0; i < int(nums.size() -1 ); i++)  

4. climbstair
斐波那契数列  
时间复杂度 O(n<sup>2</sup>)  
空间复杂度  
f(n) = f(n-1) + f(n-2)
变型问题:不能连续两次走2不
f(n) = f(n-1) + f(n-3)

5.  move zeros  
index + for loop  
时间复杂度 O(n<sup>2</sup>)  
空间复杂度  
要检查输入
执行代码的时候尝试输入一下特殊的数字  

6. 2sum   
hash表　iterator的使用  
it-> second 
　　

##Linked List  
思路比较固定,需要多多联系,熟能生巧,面试前再着重过一遍  
1. reverse linked lists  
**a.迭代**  
时间复杂度O(n)  
空间复杂度O(1)  
**b.递归**  
时间复杂度O(n)  
空间复杂度O(1)  

2. swap-nodes-in-pairs  
**a.迭代**  
时间复杂度O(n)  
空间复杂度O(1)  
**b.递归**  
时间复杂度O(n)  
空间复杂度O(1) 

3. linked-list-cycle

4. linked-list-cycle-ii

5. reverse-nodes-in-k-group

##Stack 栈  

##Quene 队列 && Deque 双端队列
类似于滑动窗口的题目通常都是用Deque






  
#Homework  

##第三课
1. remove-duplicates-from-sorted-array  &radic;
2. rotate-array  &radic;
3. merge-two-sorted-lists  &radic;    
4. merge-sorted-array  
5. two-sum  &radic;  
6. move-zeros &radic;    
7. plus-one &radic;  
 
##第四课
1. design-circular-deque &radic;
2. trapping-rain-water &radic;



  
#一些疑问  
1. 循环中使用++i和i++有没有区别  
关于i++和++i是先返回再计算还是先计算再返回部分已经理解;  
++i可以作为左值也可以理解;  
就是好奇，**++i** 和 **i++** 在  
for ( int i, i < n, i++)  
for ( int i, i < n, ++i)  
有没有区别?  
在leetcode上测试过了,for loop中都可以  

  
