#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;
void dfs(vector<list<int>> &graph, vector<bool> &visited, int cur) {
    list<int> keys = graph[cur];
    for (auto key : keys) {
        if (visited[key]==false) {
            visited[key] = true;
            dfs(graph, visited, key);
        }
    }
    return;
}  

int main() {
    int n, k;
    cin >> n >> k;
    vector<bool> visited(n, false);
    vector<list<int>> graph(n + 1);
    for (int i = 0; i < k; i++) {
        int s, t;
        cin >> s >> t;
        graph[s].emplace_back(t);
    }
    visited[1]=true;
    dfs(graph, visited, 1);

    for (int i = 1; i < n; i++) {
        if (!visited[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << 1;
    return 0;
}