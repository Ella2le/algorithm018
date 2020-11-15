//
// Created by lewang on 11/14/20.
//


#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <queue>
#include <bitset>
using namespace std;

//思路
//广度优先搜索
class Solution {
public:
    int ladderLength1(string beginWord, string endWord, vector<string>& wordList) {
        //把wordlist装到map里方便查找有没有需要的单词在
        unordered_set<string> dict(wordList.begin(),wordList.end());
        //如果dict中没有endword不可能变成功,直接返回0
        if(!dict.count(endWord)) return 0;

        //从endword开始往前找到和beginWord相差一个单词就成功了
        int step;



        return step;
    }

//---------------参考官方题解--广度优先搜索+优化建图------------
public:
    unordered_map<string,int> wordID;
    vector<vector<int>> edge;
    int nodeNum = 0;
    //优化建图!!!!!
    void addWord(string& word) {
        if(!wordID.count(word)) {
            //如果wordID中有这个索引 其对应的值就+1
            wordID[word] = nodeNum++;
            edge.emplace_back();//确保edge和wordID一样长??
        }
    }

    void addEdge(string& word) {
        addWord(word);
        int id1 = wordID[word];
        for(char& it : word) {
            char tmp = it;
            it = '*';//构建图索引线,*it,h*t,hi* !!!
            addWord(word);//
            int id2 = wordID[word];
            edge[id1].push_back(id2);
            edge[id2].push_back(id1);
            it = tmp;
        }

    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for (string& word : wordList) {
            addEdge(word);
        }
        addEdge(beginWord);
        if(!wordID.count(endWord)) {
            return 0;
        }

        vector<int> dis(nodeNum, INT_MAX);
        int beginID = wordID[beginWord], endID = wordID[endWord];
        dis[beginID] = 0;

        queue<int> que;//广度优先搜索的套路-->queue
        que.push(beginID);
        while(!que.empty()) {
            int x = que.front();
            que.pop();
            if(x == endID) {
                return dis[endID] /2 + 1;//因为添加了虚拟结点,所以得到的juice为实际最短路劲的长度两倍.所以我们应当返回距离的一半再加一的结果.
            }
            for (int& it : edge[x]) {
                if(dis[it] == INT_MAX) {
                    dis[it] = dis[x] + 1;
                    que.push(it);
                }
            }
        }
        return 0;
    }
/*
 * Success:
 * Runtime:180 ms, faster than 59.54% of C++ online submissions.
 * Memory Usage:31.8 MB, less than 25.47% of C++ online submissions.
 */
//---------------参考国际版的BFS---------------------
//从beginword开始搜索

public:
    int ladderLength2(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end());
        queue<string> todo;
        todo.push(beginWord);
        int ladder = 1;
        while(!todo.empty()) {
            int n = todo.size();
            for(int i = 0; i < n; i++) {
                string word = todo.front();
                todo.pop();
                if(word == endWord) {
                    return ladder;
                }
                dict.erase(word);
                for(int j = 0; j < word.size(); j++) {
                    char c = word[j];
                    for(int k = 0; k < 26; k++) {
                        word[j] = 'a' + k;//没有优化建图,直接搜索替换其中一个为26个小写字母中的一个后的单词在不在字典里
                        if(dict.find(word) != dict.end()) {
                            todo.push(word);
                        }
                    }
                    word[j] = c;
                }
            }
            ladder++;
        }
        return 0;
    }
    //Time Limit Exceeded

//BFS 从endWord开始找
public:
    int ladderLength3(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end()), head, tail,*phead,*ptail;
        if(!dict.count(endWord)) return 0;

        head.insert(beginWord);
        tail.insert(endWord);
        int ladder = 2;//???因为题目有说明endword和beginword不一样,那最少也需要两步
        while(!head.empty() && !tail.empty()) {
            //用上phead和ptail是为了确保搜索的是较短的set,以实现节省时间,和那个最小基因变化的题一样的
            if(head.size() < tail.size()) {
                phead = &head;
                ptail = &tail;
            }else {
                phead = &tail;
                ptail = &head;
            }
            unordered_set<string> temp;

            for(auto it = phead -> begin(); it != phead -> end(); it++) {
                string word = *it;
                for(int i= 0; i< word.size(); i++) {
                    char t = word[i];
                    for(int j = 0; j < 26; j++) {
                        word[i] = 'a' + j;
                        if(ptail->count(word)) {
                            //变换后等于endword直接返回ladder
                            return ladder;
                        }
                        //不等于endWord但是在wordList里面有
                        if(dict.count(word)){
                            //把这个中间词放佛啊temp中
                            temp.insert(word);
                            //从字典中抹去这个词
                            dict.erase(word);
                        }
                    }
                    //将当前的word对应的字符变回原来的word;
                    word[i] = t;
                }
            }
            ladder++;
            //把下一个要搜索的词和当前的phead中的词交换
            phead -> swap(temp);
        }
        return 0;
    }
//时间复杂度O(nx26)??
//空间复杂度4个set最长为wordlist的size

//{"cog"} -> {"dog","log"} -> {"dot", "lot"} -> {"hot"}
/*
 * Runtime:40 ms, faster than 98.05% of C++ online submissions.
 * Memory Usage:10.9 MB, less than 80.63% of C++ online submissions.
 */
};



int main() {
    string a = "dog", b = "aog";
    cout<< a.compare(b)<<endl;

    cout << memcmp(a.data(),b.data(),a.size());
    cout<<endl;
    int i = 1<<20;
    bitset<32> bi(i);
    cout<<bi<<endl;
    cout<<i;
    int n =6, m =7,x=9,y=10;
    cout<<endl;
    int t  = n==m ? x+9 :y+9;

    cout<<t<<endl;
    vector<vector<int>> numM(2,vector<int>(3));
    for (auto a : numM[0]) cout<<a<<",";
    return 0;
}
