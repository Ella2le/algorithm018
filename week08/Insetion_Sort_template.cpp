//
// Created by lewang on 12/13/20.
//

#include <iostream>
#include <vector>
#include <random>

using namespace std;

void insertionSort(vector<int> &arr){
    int len = (int)arr.size();

    int preIndex, curr;

    for(int i = 1; i < len; i++) {
        preIndex = i - 1;
        curr = arr[i];
        while(preIndex >= 0 && arr[preIndex] > curr) {
            arr[preIndex + 1] = arr[preIndex];
            preIndex--;
        }
        arr[preIndex + 1] = curr;

    }

}

int main(){
    random_device a;
    uniform_int_distribution<unsigned> u(1,100);
    vector<int> arr;
    for(int i = 0; i < 10; i++) {
        int x = u(a);
        cout<<x<<" ";
        arr.push_back(x);
    }
    cout<<endl;
    insertionSort(arr);
    for(auto a: arr){
        cout << a << " ";
    }

    return 0;
}