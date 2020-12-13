//
// Created by lewang on 12/13/20.
//

#include <iostream>
#include <vector>
#include <random> //可以产生更好的随机数


#define random(x) rand()%(x) //产生的是伪随机数
using namespace std;
//随机数产生范围
//[a,b) (rand()%(b-a)) + a
//[a,b] (rand()%(b-a+1)) + a
//(a,b] (rand()%(b-a)) + a + 1

void BubbleSort(vector<int> &arr) {
    int len =  (int)arr.size();

    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len -1- i; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    //return arr;
}

int main(){
    srand((unsigned)time(0)); //产生随机种子,让rand每次生成的数不一样. ( 把0 换成null也可以)
    vector<int> array;
    default_random_engine e;
    uniform_int_distribution<unsigned> u(0,100);
    for(int i = 0; i < 10 ; i++) {
        cout<<e() <<"|";
        cout<<u(e)<<" ";
    }
    cout<<endl;
    for (int i = 0; i < 10; i++){
        int x = random(100);
        array.push_back(x);
    }

    BubbleSort(array);
    for(auto a:array){
        cout<<a<<" ";
    }

    return 0;
}
