//
// Created by lewang on 12/13/20.
//
#include <iostream>
#include <vector>
#include <random>

using namespace std;

void SelectionSort(vector<int>& arr) {
    int len = arr.size();
    int minIndex, temp;
    for(int i = 0; i < len - 1; i++) {
        minIndex = i;
        int j=0;
        for(j = i +1; j < len; j++){
            if(arr[j]<arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] =temp;

    }
}

int main() {
    default_random_engine e;
    uniform_int_distribution<int> u(1,100);
    random_device a;
    vector<int> arr;
    for(int i = 0; i < 10; i++) {
        int x = u(a);
        cout<<x<<" ";
        arr.push_back(x);
    }
    cout<<endl;


    SelectionSort(arr);
    for(auto a: arr){
        cout<<a<<" ";
    }

    return 0;
}