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
using namespace std;

clas Solution {
private:
    unordered_map<string,int> dict;
    vector<string> idWord;
    vector<vector<int>> edges;
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> wordList){
        int id = 0;
        //把wordList中的单词放到哈希表dict中,方便搜索单词
        for(const string& word :wordList) {
            if(!dict.count(word)) {
                dict[word] = id++;
                idWord.push_back(word);
            }
        }
        //如果表中没有endword直接返回空列表
        if(dict.count(endWord)) {
            return {};
        }
        //如果dict中有beginword,把beginword放到idword中
        
        if(!dict.count(beginWord)){
            dict[beginWord] = id++;
            idWord.push_back(beginWord);
        }

        edges.resize(idWord.size());
        for(int i = 0; i < idword.size(); i++) {
            for(int j = i + 1; j < idWord.size(); j++) {
                if( transformCheck(idWord[i],idWord[j])) {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }

        const int dest = wordID[enWord];
        vector<vector<string>> res;
        queue<vector<int>> q;
        vector<int> cost(id,INT_MAX);
        q.push(vector<int> {wordID[beginWord]});
        cost[wordID[beginWord]] = 0;

        while(!q.empty()) {
            vector<int> now = q.front();
            q.pop();
            int last = now.back();
            if(last == dest) {
                vector<string> tmp;
                for(int index : now) {
                    tmp.push_back(idWord[index]);
                }
                res.push_back(tmp);
            }else {
                for (int i = 0; i < edges[last].size(); i++) {
                    int to = edges[last][i];
                    if(cost[last] + 1 <= cost[to]) {
                        cost[to] = cost[last] + 1;
                        vector<int> tmp(now);
                        tmp.push_back(to);
                        q.push(tmp);
                    }
                }
            }
        }
        return res;
    }
};