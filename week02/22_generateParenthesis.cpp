//
// Created by lewang on 11/1/20.
//

#include <iostream>
#include <string>
#include <vector>
#include <stacak>
//回溯?
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        int lc = 0,rc = 0;
        dfs(res,"",n,lc,rc);
        return res;
    }
private:
    void dfs(vector<string>& res, string path, int n, int lc, int rc){
        if(rc>lc || lc > n || rc > n) return;
        if(lc == rc && lc == n){
            res.push_back(path);
            return;
        }
        dfs(res,path+'(',n,lc+1,rc);
        dfs(res,path+')',n,lc,rc+1);
    }
};

int main(){

}