//
// Created by lewang on 12/6/20.
//

//bfs

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0, offsets[] = {0, 1, 0, -1, 0};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    grid[i][j] = '0';
                    queue<pair<int, int>> todo;
                    todo.push({i, j});
                    while (!todo.empty()) {
                        pair<int, int> p = todo.front();
                        todo.pop();
                        for (int k = 0; k < 4; k++) {
                            int r = p.first + offsets[k], c = p.second + offsets[k + 1];
                            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
                                grid[r][c] = '0';
                                todo.push({r, c});
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};

//dfs

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    eraseIslands(grid, i, j);
                }
            }
        }
        return islands;
    }
private:
    void eraseIslands(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        eraseIslands(grid, i - 1, j);
        eraseIslands(grid, i + 1, j);
        eraseIslands(grid, i, j - 1);
        eraseIslands(grid, i, j + 1);
    }
};

//union find

public class Solution {
public int numIslands(char[][] g) {
        if (g.length < 1 || g[0].length < 1) return 0;
        int n = g.length, m = g[0].length, island = 0;
        UnionFindSet uf = new UnionFindSet(n, m);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (g[i][j] == '1') {
                    uf.find(i, j);
                    if (i > 0 && g[i - 1][j] == '1') uf.merge(i - 1, j, i, j);
                    if (j > 0 && g[i][j - 1] == '1') uf.merge(i, j - 1, i, j);
                }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (g[i][j] == '1' && uf.isSetHead(i, j)) island++;

        return island;
    }

private class UnionFindSet { // 2d
        int n, m;
        int[] size, p;

    public UnionFindSet(int nn, int mm) {
            n = nn; m = mm;
            size = new int[n * m]; p = new int[n * m];
            Arrays.fill(p, -1);
        }

    private int id(int i, int j) {
            return i * m + j;
        }

    private int find(int i, int j) {
            return find(id(i, j));
        }

    private int find(int x) {
            if (p[x] == -1) {
                size[x] = 1;
                p[x] = x;
                return x;
            }
            p[x]  = (p[x] == x) ? x : find(p[x]);
            return p[x];
        }

    private void merge(int i1, int j1, int i2, int j2) {
            int s1 = find(i1, j1), s2 = find(i2, j2);
            if (s1 == s2) return;
            if (size[s1] > size[s2]) {
                p[s2] = s1; size[s1] += size[s2];
            } else {
                p[s1] = s2; size[s2] += size[s1];
            }
        }

    private boolean isSetHead(int i, int j) {
            return id(i, j) == find(i, j);
        }
    }
