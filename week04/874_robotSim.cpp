//
// Created by lewang on 11/15/20.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles){
        unordered_set<pair<int,int>> obDict;//(obstacles.begin(),obstacles.end());
        for(vector<int> &obstacle : obstacles){
            obDict.insert(make_pair(obstacle[0],obstacle[1]))
        }
        int y = 0, x = 0, di = 0;
        int dx[4] = {0 ,1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        int ans = 0;
        for(int cmd:commands) {
            if(cmd == -2) {
                di =(di +3)%4;
            }else if(cmd == -1){
                di = (di + 1)%4;
            }else{
                for (int k = 0; k < cmd; ++k) {
                    int nx = x + dx[di];
                    int ny = y + dy[di];
                    if(obDict.find(make_pair(nx,ny)) == obDict.end()) {
                        x = nx;
                        y = ny;
                        ans = max(ans, x*x + y*y);
                    }
                }
            }
        }
        return ans;
    }

    //-------------参考国家版------------------
    int robotSim2(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> obs;
        for(int i = 0; i < obstacles.size(); i++) {
            obs.insert(to_string(obstacles[i][0]) + "#" +to_string(obstacles[i][1]));
        }
        int res = 0,dir =0, x =0, y= 0;
        vector<vector<int>> ds={{0,1},{1,0},{0,-1},{-1,0}};
        for(int i = 0; i < commands.size(); i++) {
            if(commands[i] == -2) {
                dir --;
                if(dir == -1){
                    dir =3;
                }
            }
            else if(commands[i] == -1) {
                dir++;
                if(dir == 4) dir = 0;
            }
            else{
                for(int j = 0; j < commands[i]; j++) {
                    string pos = to_string(x + ds[dir][0]) + "#" + to_string(y + ds[dir][1]);
                    if(obs.find(pos)!=obs.end()) break;
                    x+=ds[dir][0], y+=ds[dir][1];
                }
                res = max(res,x*x + y*y);
            }
            if(dir == -1) dir =3;//这种情况在往回走了,不用计算
            if(dir == 4) dir = 0;
        }
        return res;
    }

};

int main() {
    Solution test;
    vector<int> commands {4,-1,4};
    vector<vector<int>> obstacles {{2,4},{3,4}};
    test.robotSim(commands,obstacles);

    return 0;
}