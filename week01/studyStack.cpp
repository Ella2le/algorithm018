//
// Created by lewang on 10/23/20.
//

#include <iostream>
#include <string>

//define a stack
std::stack<std::string> words;

//stack容器适配器
//第一个参数是储存对象的类型,第二个参数是底层容器的类型.
//Stack<T>的底层容器默认是deque<T> 容器, 因此模板类型其实是,stack<typename T, typename Container=deque<T>
//通过制定第二个模板类型参数可以使用任意类型的底层容易,只要它们支持back(), push_back(), pop_back(),empty(),size()等操作
std::stack<std::string,std::list<std::string>> strContainer;


//创建堆栈时不能在初始化列表中用对象来初始化,但是可以用另一个容器来初始化,只要堆栈的底层容器是相同的
std::list<double> value {1.2,75,3,5};
std::stack<double,stack::list<double >> myStack(value);
//第二条语句生成了一个包含value的元素副本,myStack. 这里不能在stack够着函数中使用初始化列表,必须使用圆括号,
// 如果没有第二个stack模板类型参数将底层容指定为list,那么会使用默认的底层容器deque,这样就不能用list的内容来初始化stack.

//stack<T>定义了拷贝构造函数,因此可以直接复制现有的stack容器
std::stack<double,std::list<double>>copy_stack {myStack};
//这里可以使用初始化列表{},也可以使用()进行复制

//堆栈相关操作
myStack.top();
myStack.push(23.33);
myStack.pop();
myStack.size();
myStack.empty();
myStack.emplace(9);//用传入的参数调用构造函数,在栈顶生成对象,此时myStack变成 {1.2,75,3,5,9}
std::list<double> value2 {1,70000,300,400};
std::stack<double,std::list<double>> myStack2(value2);
myStack.swap(myStack2);
