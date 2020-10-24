//
// Created by lewang on 10/23/20.
//
//定义
std::deque<int> dq;
std::deque<int> dp(8);//创建一个有8个元素的int型的双端队列,默认初始化value都为0
std::deque<int> dp(8,50);//创建一个有8个元素的int型双端队列,初始化value为50
std::deque<int> dp(dp1.begin(), dp1.end())//通过迭代器创建队列
std::deque<int> dp(dp1)//通过拷贝构造创建

//增加元素的操作
dp.push_back(1);
dp.push_front(2);
dp.emplace(dp.begin(),8);//在队列的指定位置插入位置
dp.emplace_back(9);
dp.emplace_front();




for (int i=1; i<6, i++){
    dp.push_back(i);//1,2,3,4,5
}

std::deque<int>::iterator it = dp.begin();
++it;
dp.insert(it,10)//在队列某一元素前插入一个元素
//在位置1 前插入一个10,   dp 变成1,10,2,3,4,5

dp.insert(it,2,20)//
//在位置1前插入2个20, dp 变成1,20,20,10,2,3,4,5

it=dp.begin()+2;
std::vector<int> myvector (2,30);
mydeque.insert (it, myvector.begin(),myvector.end());
//在位置2前插入两个30, dp 变成1, 20, 30,30, 20,10,2,3,4,5

