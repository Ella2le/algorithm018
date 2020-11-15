//
// Created by lewang on 11/14/20.
//

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(!grid.size()) return 0;
        int nr = grid.size();
        int nc = grid[0].size();

        int IslandNum = 0;
        for(int r = 0; r < nr; r++) {
            for( int c = 0; c < nc; c++) {
                if(grid[r][c] == '1') {
                    ++IslandNum;
                    dfs(grid,r,c);
                }
            };
        }
        return IslandNum;
    }

private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int nr = grid.size();
        int nc = grid[0].size();
        //注意遍历过的点要设成'0' 防止重复遍历,死循环
        grid[r][c] = '0';

        if( r - 1 >= 0 && grid[r-1][c] == '1') dfs(grid,r-1,c);
        if( r + 1 < nr  && grid[r+1][c] == '1') dfs(grid,r+1,c);
        if( c - 1 >= 0 && grid[r][c-1] == '1') dfs(grid,r,c-1);
        if( c + 1 <nc  && grid[r][c+1] == '1') dfs(grid,r,c+1);
    }
//Success:
//Runtime:32 ms, faster than 75.89% of C++ online submissions.
//Memory Usage:9.7 MB, less than 44.75% of C++ online submissions.
//-----------------参考国际网的 BFS---------------------------
public:
    int numIslands2(vector<vector<char>>& grid) {
        int m = grid.size(), n=m ? grid[0].size :0, island = 0; offsets[] = {0,1,0,-1,0};
        //c++ 的条件运算符,Exp1?Exp2:Exp3, 如果Exp1是真,计算Exp2,否则计算Exp3
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1'){
                    island++;
                    //遍历过的设为0
                    grid[i][j] = '0';
                    queue<pair<int,int>> todo;
                    todo.push({i,j});
                    while(!todo.empty()) {
                        pair<int,int> p = todo.front();
                        todo.pop();
                        for(int k = 0; k < 4; k++){
                            //p.first 是 i,行序号,p.second 是j, 列序号
                            //k=0,r=r+0,c=c+1 -> 右
                            //k=1,r=r+1,c=c+0 -> 下
                            //k=2,r=r+0,c=c-1 -> 左
                            //k=3,r=r-1,c=c+0 -> 上
                            int r = p.first + offsets[k], c = p.second + offset[k+1];
                            if(r>=0 && r<m && c >= 0 && c < m && grid[r][c] == '1') {
                                grid[r][c] = '0';
                                todo.push({r,c});
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
//info
//Success:
//Runtime:28 ms, faster than 95.08% of C++ online submissions.
//Memory Usage:10.2 MB, less than 15.89% of C++ online submissions.
    //-------------同上作者的 DFS ------------------
public:
    int numIslands3(vector<vector<char>>& grid) {
        int m = grid.size(), n = m?grid[0].size() :0, island = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1'){
                    island ++;
                    eraseIslands(grid,i,j);
                }
            }
        }

        return island;
    }
private:
    void eraseIslands(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if(i < 0 || i == m || j < 0|| j ==n || grid[i][j] == '0') {
            return ;
        }
        grid[i][j] = '0';
        eraseIslands(grid,i-1,j);
        eraseIslands(grid,i,j-1);
        eraseIslands(grid,i+1,j);
        eraseIslands(grid,i,j+1);

    }


};
