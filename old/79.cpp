/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */
#include "0.cpp"
// @lc code=start
class Solution {
    int m,n;
    int dir[4][2]={0,1,1,0,-1,0,0,-1};
    vector<vector<bool>> visited;
    bool dfs(int rowIndex,int colIndex,string& word,int wordIndex,vector<vector<char>>& board,vector<vector<bool>> &visited){
        bool result=false;
        
        if(board[rowIndex][colIndex]!=word[wordIndex])
            return false;
        if(wordIndex==word.size()-1) return true;
        for(int i=0;i<4;i++){
            int newRow=rowIndex+dir[i][0];
            int newCol=colIndex+dir[i][1];
            if(newRow<0||newRow>=m||newCol<0||newCol>=n||visited[newRow][newCol]==true)
                continue;
            visited[newRow][newCol]=true;
            result=result||dfs(newRow,newCol,word,wordIndex+1,board,visited);
            visited[newRow][newCol]=false;
        }
        return result;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        n=board[0].size();
        visited=vector<vector<bool>>(m,vector<bool>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                visited[i][j]=true;
                if(dfs(i,j,word,0,board,visited)==true) return true;
                visited[i][j]=false;
            }
        }
        return false;
    }
};
// @lc code=end

int main() {
    // 输入数据
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word = "ABCCED";
    Solution solution;
    bool result = solution.exist(board, word);
    return 0;
}