//
// Created by lewang on 10/23/20.
//

//quene
//定义
std::quene<std::string> words;
//使用拷贝构造函数
std::quene<std::string> copyWords {words};
//quenek<T>的底层容器默认是deque<T> 容器, 因此模板类型其实是,stack<typename T, typename Container=deque<T>
//通过制定第二个模板类型参数可以使用任意类型的底层容易,只要它们支持back(), push_back(), pop_back(),empty(),size()等操作
std::quene<std::string, std::list<std::string>> newWords;
//
//front()：返回 queue 中第一个元素的引用。如果 queue 是常量，就返回一个常引用；如果 queue 为空，返回值是未定义的。
//back()：返回 queue 中最后一个元素的引用。如果 queue 是常量，就返回一个常引用；如果 queue 为空，返回值是未定义的。
//push(const T& obj)：在 queue 的尾部添加一个元素的副本。这是通过调用底层容器的成员函数 push_back() 来完成的。
//push(T&& obj)：以移动的方式在 queue 的尾部添加元素。这是通过调用底层容器的具有右值引用参数的成员函数 push_back() 来完成的。
//pop()：删除 queue 中的第一个元素。
//size()：返回 queue 中元素的个数。
//empty()：如果 queue 中没有元素的话，返回 true。
//emplace()：用传给 emplace() 的参数调用 T 的构造函数，在 queue 的尾部生成对象。
//swap(queue<T> &other_q)：将当前 queue 中的元素和参数 queue 中的元素交换。它们需要包含相同类型的元素。也可以调用全局函数模板 swap() 来完成同样的操作。


//priority_quene
//和队列基本一样的操作 top(),empty(), size(), push(), emplace(), pop(), swap
//升序队列
std::priority_queue <int, std::vector<int>, std::greater<int>> upq;
//降序队列
std::priority_queue <int, std::vector<int>, std::less<int>> downq;


