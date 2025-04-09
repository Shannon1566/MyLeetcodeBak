/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */
#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=0,column=0;
        int direction=0;
        int m=matrix.size(),n=matrix[0].size();
        int columnHigh=n,rowHigh=m,columnLow=-1,rowLow=-1;
        vector<int> result(m*n);
        for (int i=0;i<m*n;i++){
            result[i]=matrix[row][column];
            if(direction==0){
                column++;
                if(column==columnHigh){
                    column--;
                    row++;
                    direction=1;
                    rowLow++;
                    continue;
                }
            }
            if(direction==1){
                row++;
                if(row==rowHigh){
                    row--;
                    column--;
                    direction=2;
                    columnHigh--;
                    continue;
                }
            }
            if(direction==2){
                column--;
                if(column==columnLow){
                    column++;
                    row--;
                    direction=3;
                    rowHigh--;
                    continue;
                }
            }
            if(direction==3){
                row--;
                if(row==rowLow){
                    row++;
                    column++;
                    direction=0;
                    columnLow++;
                    continue;
                }
            }
        }
        return result;
    }
};
// @lc code=end

int main() {
    // 测试代码

    Solution solution;
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // 调用解题函数并输出结果
    solution.spiralOrder(matrix);
    // cout << "Result: " << result << endl;

    return 0;
}