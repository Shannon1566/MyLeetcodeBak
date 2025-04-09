#include <iostream>
#include <vector>
using namespace std;
int main() {
    int m, n;
    cin >> m >> n;
    vector<int> weight(m);
    vector<int> value(m);
    for (int i = 0; i < m; i++) {
        cin >> weight[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> value[i];
    }

    vector<int> dp(n + 1, 0);
    for (int i = 0; i <= n; i++) {
        if (weight[0] > i) continue;
        dp[i] = value[0];
    }
    for (int i = 1; i < m; i++) {              // items
        for (int j = n; j >= weight[i]; j--) { // bag
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << dp[n];
    return 0;
}