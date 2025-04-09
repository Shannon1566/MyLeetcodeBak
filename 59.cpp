/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */
#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n));
        int direction=0;
        int i=0,j=0;
        int ilow=-1,ihigh=n,jlow=-1,jhigh=n;
        for(int num=1;num<=n*n;num++){
            matrix[j][i]=num;
            if (direction==0){
                i++;
                if(i>=ihigh){
                    i--;
                    j++;
                    direction=1;
                    jlow++;
                    continue;
                }
            }
            if (direction==1){
                j++;
                if(j>=jhigh){
                    j--;
                    i--;
                    direction=2;
                    ihigh--;
                    continue;
                }
            }
            if (direction==2){
                i--;
                if(i<=ilow){
                    i++;
                    j--;
                    direction=3;
                    jhigh--;
                    continue;
                }
            }
            if (direction==3){
                j--;
                if(j<=jlow){
                    j++;
                    i++;
                    direction=0;
                    ilow++;
                    continue;
                }
            }
            
        }
        return matrix;
    }
};
// @lc code=end
int main() {
    // 测试代码

    Solution solution;


    // 调用解题函数并输出结果
    solution.generateMatrix(3);
    // cout << "Result: " << result << endl;

    return 0;
}
