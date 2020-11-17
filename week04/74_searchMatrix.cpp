#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r_left, r_right, c_left,c_right;
        int nr = (int)matrix.size();
        int nc = (int)matrix[0].size();
        if(nr == 0 || nc == 0) return false;

        int row = 0 ,col = 0;
        r_left = 0,r_right = nr;
        //搜索所在行
        while (r_left < r_right) {
            int mid = (r_left + r_right)/2;
            if(matrix[mid][0] > target) {
                r_right = mid - 1;
            }
            if(matrix[mid][0] < target){
                if(matrix[mid][nc-1] > target) {
                    row = mid;
                    break;
                }else if(matrix[mid][nc-1] < target){
                    r_left = mid +1;
                }
            }
            if(matrix[mid][0] == target || matrix[mid][nc-1] == target) return true;

        }
        //搜索所在列
        cout<<row<<endl;
        //if(row > nr) return false;

        c_left = 0, c_right = nc;
        while (c_left < c_right) {
            int mid = c_left + (c_right-c_left)/2;//(c_left + c_right)/2;
            if(matrix[row][mid] == target) return true;
            if(matrix[row][mid] > target) {
                c_right = mid - 1;
                if(matrix[row][c_right] == target) return true;
            }
            if(matrix[row][mid] < target){
                c_left = mid+1;
                if(matrix[row][c_left] == target) return true;
            }

        }


        return false;
    //超时
    }

//二维变一维+二分
    bool searchMatrix2(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0) return false;
        int n = matrix[0].size();

        int left = 0, right = m*n -1;
        int id, p;
        while(left < right){
            id = (left + right)/2;
            p = matrix[id/n][id%n];
            if(target == p) return true;
            else {
                if(target < p) right = id -1;
                else left = p +1;
            }
        }
        return false;
    }
};


int main(){
    Solution test;
    vector<vector<int>> nums ={{1,3,5,7},{10,11,16,20},{23,30,34,50}};//{{1,3,5,7},{10,11,16,20},{23,30,34,50}};
    int target = 3;

    int res = test.searchMatrix(nums,target);
    cout << res;
    return 0;
}