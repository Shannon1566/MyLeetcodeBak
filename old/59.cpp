/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */
#include "0.h"
// @lc code=start
class Solution {
    int dir[4][2]={0,1,1,0,0,-1,-1,0};
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n));
        int row=0,col=0;
        int curDir=0;
        int up=-1,down=n,left=-1,right=n;
        for(int i=1;i<=n*n;i++){
            ans[row][col]=i;
            row+=dir[curDir][0];
            col+=dir[curDir][1];
            if(col>=right){
                up++;
                row-=dir[curDir][0];
                col-=dir[curDir][1];
                curDir=(curDir+1)%4;
                row+=dir[curDir][0];
                col+=dir[curDir][1];
            }
            if(row>=down){
                right--;
                row-=dir[curDir][0];
                col-=dir[curDir][1];
                curDir=(curDir+1)%4;
                row+=dir[curDir][0];
                col+=dir[curDir][1];
            }
            if(col<=left){
                down--;
                row-=dir[curDir][0];
                col-=dir[curDir][1];
                curDir=(curDir+1)%4;
                row+=dir[curDir][0];
                col+=dir[curDir][1];
            }
            if(row<=up){
                left++;
                row-=dir[curDir][0];
                col-=dir[curDir][1];
                curDir=(curDir+1)%4;
                row+=dir[curDir][0];
                col+=dir[curDir][1];
            }
        }
        return ans;
    }
};
// @lc code=end
int main(){
    Solution sol;
    sol.generateMatrix(3);
    return 0;
}
