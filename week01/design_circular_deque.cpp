//
// Created by lewang on 10/24/20.
//
#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class MyCircularDeque {
private:
    vector<int> arr;
    int front;
    int rear;
    int capacity;

public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        capacity = k + 1;
        arr.assign(capacity,0);

        front = 0;
        rear = 0;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if( isFull() ) {
            return false;
        }
        front = ( front -1 + capacity) % capacity;
        arr[front] = value;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }
        rear = (rear +1) % capacity;
        arr[rear] = value;
        return true;
    }


    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }
        front = (front + 1) % capacity;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        rear = (rear - 1 + capacity)% capacity;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return arr[front];
    }


    /** Get the last item from the deque. */
    int getRear() {
        if(isEmpty()){
            return -1;
        }
        return arr[(rear -1 + capacity) % capacity];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return front == rear;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return (rear + 1) % capacity == front;
    }
};


int main(){
    MyCircularDeque cdq(10);
    for(int i=0; i<4; i++){
        cdq.insertFront(i);
    }
    for(int j=10;j>8;j--){
        cdq.insertLast(j);
    }
    for(int k=0 ; k<4; k++) {
        cout<<cdq.getFront()<<",";
        cdq.deleteFront();
    }
    cout<<endl;

    cout<<cdq.getRear()<<endl;


    return 0;
}