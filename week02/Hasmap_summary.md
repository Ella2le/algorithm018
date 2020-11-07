# HashMap Summary

## map vs unordered_map vs set
头文件
```c++
#include <unordered_map>
#include <set>
#include <map>
```

template
```c++
//std::set
template<   class T,
            class Compare = less<T>,
            class Alloc = allocator<T>,
            >class set;


//std::unordered_map
template<   class Key,
            class T,
            class Hash = hash<Key>,
            class Pred = equal_to<Key>,
            class Alloc = allocator< pair<const Key, T> >
            >class unordered_map
            
//std::map
template<   class Key,
            class T,
            class Compare = less<key>,
            class Alloc = allocator<pair<const Key,T>>
            > class map;

```


map和unordered_map都是键值对,而set只有值没有键

map有一个compare的参数,来确保map中没有重复的键.
No two elements in *map* container can have equivalent keys.

unordered_map中有一个pred的参数,来确保没有重复的键,
No two elements in an *unordered_map* can have keys that yield *true* using the predicate.

但是这里map用的是*less<Key>* 而 unordered_map 使用的是*equal_to*,所以,map中的key是有序的
而unordered_map是无序的(在其名字中就也可以看出来了)

成员函数  
- Capacity  一样
- Iterator  因为unordered_map是无序的,所以所有的reverse iterator 他都没有
- Modifiers 一样
- operation find count equal_range一样, 
但是同样是unordered的没有lower_bound,up_bound

unordered_map还有一些独特的性质

Buckets(桶)这个还没有用到但是好像很重要的样子  
- bucket_count
- max_bucket_count
- bucket_size
- bucket



