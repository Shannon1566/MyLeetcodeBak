#include <iostream>
#include <vector>
using namespace std;
const int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
int main() {
    int area = 0;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    vector<vector<bool>> visited(n, vector<bool>(m, false));
 
    return 0;
}