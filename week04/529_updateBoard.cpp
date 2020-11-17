//
// Created by lewang on 11/14/20.
//
#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;

//-----------dfs 自己写的------------------有问题!!

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int nr = board.size();
        int nc = board[0].size();
        cout<<board.size()<<endl;
        cout<<board[0].size()<<endl;
        // vector<vector<char>> newBoard (board);
        vector<vector<int>> numM(nr,vector<int>(nc));
        cout<<numM.size()<<endl;
        cout<<numM[0].size()<<endl;
        cout<<click.size()<<endl;
        int r = click[0];
        int c = click[1];
        cout<<r<<","<<c<<endl;
        if ( r > nr || c > nc || r < 0|| c < 0) return board;
        if(board[r][c] == 'M') {
            board[r][c] ='X';
            return board;
        }
        dfs(board,r,c);

        //想用数字8~0,的二位一个矩阵标记8连通中有有几个地雷,
        //但是实际操作过程中有点问题等待解决
        for(int  i = 0; i < nr; i++) {
            for(int  j = 0; j < nc; j++) {
                if(board[i][j] == 'M') {
                    if(r+1 <nr) {
                        numM[r+1][c] ++;
                        if(c+1 < nc){
                            cout<<"test"<<endl;
                            numM[r+1][c+1] +=1;
                        }
                        if(c-1>=0){
                            numM[r+1][c-1] +=1;
                        }
                    }
                    if(r - 1 >= 0) {
                        numM[r+1][c] +=1;
                        if(c+1 < nc){
                            numM[r+1][c+1] +=1;
                        }
                        if(c-1>=0){
                            numM[r+1][c-1] +=1;
                        }
                    }
                    if(c-1 >= 0) numM[r][c]+=1;
                    if(c+1<nc) numM[r][c+1]+=1;

                }
            }
        }

        for(int  i = 0; i < nr; i++) {
            for(int j = 0; j < nc; j++) {
                if(numM[i][j] != 0) {
                    cout<<numM[i][j]<<",";
                    board[i][j] = (char)numM[i][j];
                }

            }
        }

        return board;
    }

private:
    void dfs(vector<vector<char>>& board, int r,int c) {
        int nr = board.size();
        int nc = board[0].size();
        //用来记录其8连通中有几个地雷
        int numMine = 0;


        //遍历过得要标记
        if(board[r][c] == 'E') {
            board[r][c] = 'B';
        }
        if(board[r][c] == 'M'){
//           // board[r][c] = 'X';
//           if(r+1 <nr) {
//               numM[r+1][c] ++;
//               if(c+1 < nc){
//                   cout<<"test"<<endl;
//                   numM[r+1][c+1] +=1;
//               }
//               if(c-1>=0){
//                   numM[r+1][c-1] +=1;
//               }
//           }
//           if(r - 1 >= 0) {
//               numM[r+1][c] +=1;
//               if(c+1 < nc){
//                   numM[r+1][c+1] +=1;
//               }
//               if(c-1>=0){
//                   numM[r+1][c-1] +=1;
//               }
//           }
//           if(c-1 >= 0) numM[r][c]+=1;
//           if(c+1<nc) numM[r][c+1]+=1;
            return;
        }

        if(r + 1 < nr && board[r + 1][c] == 'E') {
            dfs(board,r+1,c); //下
            if(c + 1 < nc && board[r+1][c+1] == 'E'){
                dfs(board,r+1,c+1);//右下
            }
            if(c - 1 >= 0 && board[r+1][c-1] == 'E'){
                dfs(board,r+1,c-1);//左下
            }
        }
        if(r - 1 >= 0 && board[r - 1][c] == 'E') {
            dfs(board,r-1,c); //上
            if(c - 1 >= 0 && board[r-1][c-1] == 'E'){
                dfs(board,r-1,c-1);//左上
            }
            if(c + 1 < nc && board[r-1][c+1] == 'E'){
                dfs(board,r-1,c+1);//左下
            }
        }

        if(c - 1 >= 0 && board[r][c-1] == 'E') dfs(board,r,c-1);//左
        if(c + 1 < nc && board[r][c+1] == 'E') dfs(board,r,c+1);//右

    }
//-----------参考中文官方的dfs+模拟-------------------------------

public:
    int dir_x[8] = {0, 1, 0, -1, 1, 1,-1, -1};//行变换
    int dir_y[8] = {1, 0, -1, 0, 1, -1, 1, -1};//列变换

//             右, 下, 左,上,右下,左下,右上,左下
//这种offset的写法在岛屿计数中也是用过了,记住在矩阵操作中可以简化代码!
private:
    void searchM(vector<vector<char>>& board, int x, int y,vector<vector<bool>> visited) {
        int cnt = 0; //用来标记该位置8连接上有几个地雷
        const int nr = (int)board.size();
        const int nc = (int)board[0].size();
        //unordered_map<pair<int,int>,bool> visited(pair<nr,nc>,false);



        if(visited[x][y] == true) return;

        for(int i = 0; i< 8; ++i) {
            //遍历(x,y)的8连通位置
            int tx = x + dir_x[i];
            int ty = y + dir_y[i];
            if(tx < 0 || tx >= nr || ty < 0 || ty >= nc) {
                continue;
            }
            //不用判断M, 因为如果有M的话游戏已经结束了??
            //如果周边有地雷其加一
            cnt += board[tx][ty] == 'M';

        }//

        if(cnt > 0) {

            //如果(x,y)周边有地雷,则棋盘上对应位置显示其附近的地雷数量3
            board[x][y] =(char)(cnt + '0');
            visited[x][y] = true;
        }else {
            //否则就显示'B',来表示这个格子周围没有地雷
            board[x][y] = 'B';
            visited[x][y] = true;
            //如果这个 格子是"B"要继续遍历其周围
            for (int i = 0; i < 8; ++i) {
                int tx = x +dir_x[i];
                int ty = y + dir_y[i];

                if(tx < 0 ||tx >= nr || ty < 0 || ty >= nc){
                    continue;
                }
                searchM(board,tx,ty,visited);
            }
        }
    }
public:
    vector<vector<char>> updateBoard2(vector<vector<char>>& board, vector<int>& click) {
        const int nr = (int)board.size();
        const int nc = (int)board[0].size();
        vector<vector<bool>> visited(nr,vector<bool>(nc,false));
        int x = click[0], y =click[1];
        if(x<0 || y<0 || x >= board.size() || y >= board[0].size() ) {
            cerr << "Click Error!!!"<<endl;
            return board;
        }
        if(board[x][y] == 'M'){
            board[x][y] = 'X';
        }else {
            cout<<"here1"<<endl;
            searchM(board,x,y,visited);
        }

        return board;
    }
//Compile Error:
//Time Limit Exceeded
//时间复杂度O(mn),m,n分别是面板的行列数
//空间复杂度,O(mn).空间复杂度取决于递归的栈深度,而递归栈深度在最坏的情况下有可能遍历整个面板

//-----------------参考国际栈的DFS-----------------------

public:
    vector<vector<char>> updateBoard22(vector<vector<char>> &board, vector<int> &click) {
        int x = click[0];
        int y = click[1];
        if(board[x][y] == 'M') {
            board[x][y] = 'X';
            return board;
        }
        dfs(board,x,y);
        return board;
    }
    void dfs2(vector<vector<char>> &board, int x, int y) {
        if(!judge(board,x,y)) return;
        vector<vector<int>> v= {{1,-1},{1,0},{1,1},{-1,-1},{-1,0},{-1,1},{0,-1},{0,1}};
        int count = 0;
        if(board[x][y] == 'E') {
            for(int i = 0; i < 8; i++) {
                if(judge(board,x+v[i][0],y+v[i][1]) && board[x+v[i][0]][y+v[i][1]] == 'M'){
                    count++;
                }
            }
            if(count>0) {
                board[x][y] = '0' + count;
            }else{
                board[x][y] = 'B';
                for(int i = 0; i < 8; i++) {
                    dfs(board, x+v[i][0],y+v[i][1]);
                }
            }
        }

    }
    //用来判断数组是否越界
    bool judge( vector<vector<char>> &board, int x, int y) {
        return x>=0 && x < board.size() && y >= 0 && y < board[0].size();
    }
//运行结果
//
//Success:
//Runtime:224 ms, faster than 5.07% of C++ online submissions.
//Memory Usage:37.5 MB, less than 5.00% of C++ online submissions.
//-----------------参考国际栈的BFS-----------------------
    vector<vector<char>> updateBoard3(vector<vector<char>>& board, vector<int>& click) {
        deque<pair<int,int>> q({{click[0], click[1]}});
        while(!q.empty()){
            auto c = q.front().first, r = q.front().second, mines = 0;
            vector<pair<int,int>> neighbours;
            if(board[c][r] == 'M') board[c][r] = 'X';
            else for (auto i = -1; i <= 1; ++i){
                for (auto j = -1; j <= 1; ++j) {
                    if(c+i >= 0 && r+j >= 0 && c + i < board.size() && r+j < board[0].size()) {
                        if(board[c+i][r+j] == 'M') ++mines;
                        else if(mines == 0 && board[c +i][r+j] == 'E') neighbours.push_back({c+i, r+j});
                    }
                }
            }
            if(mines > 0) board[c][r] = '0' + mines;
            else for (auto n:neighbours) {
                board[n.first][n.second] = 'B';
                q.push_back(n);
            }
            q.pop_front();
        }
        return board;
    }
//Success:
//Runtime:48 ms, faster than 99.46% of C++ online submissions.
//Memory Usage:13.9 MB, less than 31.66% of C++ online submissions.

};


int main() {
    Solution test;
    vector<vector<char>> board{{'E','E','E','E'},{'E','E','E','E'},{'E','E','E','E'},{'E','E','M','E'}};
    vector<int> click {2,0};
    vector<vector<char>> res;
    res = test.updateBoard2(board,click);


    for(auto a : board) {
        for(auto b : a){
            cout<<b<<",";
        }

    }
    cout<<endl;
    return 0;
}