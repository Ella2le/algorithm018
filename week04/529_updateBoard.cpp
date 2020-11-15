//
// Created by lewang on 11/14/20.
//
#include <iostream>
#include <vector>
#include <string>

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
    void searchM(vector<vector<char>>& board, int x, int y) {
        int cnt = 0; //用来标记该位置8连接上有几个地雷
        int nr = (int)board.size();
        int nc = (int)board[0].size();
        for(int i = 0; i< 8; ++i) {
            //遍历(x,y)的8连通位置
            int tx = x+dir_x[i];
            int ty = y + dir_y[i];
            if(tx < 0 || tx >= nr || ty < 0 || ty >= nc) {
                continue;
            }
            //不用判断M, 因为如果有M的话游戏已经结束了??
            //如果周边有地雷其加一
            cnt += board[tx][ty] == 'M';
        }
        if(cnt > 0) {
            //如果(x,y)周边有地雷,则棋盘上对应位置显示其附近的地雷数量
            board[x][y] = (char)cnt + '0';
        }else {
            //否则就显示'B',来表示这个格子周围没有地雷
            board[x][y] = 'B';
            //如果这个 格子是"B"要继续遍历其周围
            for (int i = 0; i < 8; ++i) {
                int tx = x +dir_x[i];
                int ty = y + dir_y[i];
                if(tx < 0 ||tx >= nr || ty < 0 || ty >= nc){
                    continue;
                }
                searchM(board,tx,ty);

            }
        }
    }

    vector<vector<char>> updateBoard2(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0], y =click[1];
        if(board[x][y] == 'M'){
            board[x][y] = 'X';
        }else {
            searchM(board,x,y);
        }
        return board;
    }

    //时间复杂度O(nm), 其中n,m分别是board的行数和列数,最坏情况下遍历整个面板
    //空间复杂度O(nm), 空间复杂度取决于递归的栈深度,而递归栈深度在最坏情况下有可能遍历整个面板n*m



};


int main() {
    Solution test;
    vector<vector<<
    return 0;
}