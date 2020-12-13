
//
// Created by lewang on 12/12/20.
//
//为什么要用双向链表,单向不行么???

struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    //构造函数
    DLinkedNode(): key(0), value(0), prev(nullptr),next(nullptr) {}
    //
    DLinkedNode(int _key, int _value): key(_key),value(_value),prev(nullptr),next(nullptr) {}
};
class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;
public:
    //初始化
    LRUCache(int _capacity): capacity(_capacity),size(0) {
        //使用伪头部和伪部结点
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        //现在hashmap中查找是否有这个目标,
        if(!cache.count(key)){
            //如果没有直接返回
            return -1;
        }
        //如果有,将这个目标移到双端链表的头部
        DLinkedNode* node = cache[key];
        moveToHead(node);
        //返回查询的目标的值
        return node->value;
    }


    void put(int key, int value) {
        //如果cache中没有目标,进行插入
        if(!cache.count(key)) {
            DLinkedNode* node = new DLinkedNode(key, value);

            cache[key] = node;
            addToHead(node);
            ++size;
            //判断是否超过缓存的size
            if(size > capacity) {
                DLinkedNode* removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                --size;
            }
        }
        //如果cache中有目标,将其移到最前面
        else {
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(DLinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(DLinkedNode* node) {
        node->prev->next= node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail() {
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }

};