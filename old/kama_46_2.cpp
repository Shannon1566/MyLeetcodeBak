#include <iostream>
#include <vector>
using namespace std;
int main() {
    int m, n;
    cin >> m >> n;
    vector<int> weight(m, 0);
    vector<int> value(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> weight[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> value[i];
    }

    vector<int> dp(n + 1, 0);

    for (int i = weight[0]; i <= n; i++) {
        dp[i] = value[0];
    }

    for (int i = 1; i < m; i++) {
        for (int j = n; j >= weight[i]; j--) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    cout << dp[n] << endl;

    // for (int j = 0; j <= n; j++)
    //     cout << dp[j] << ' ';
    // cout << endl;
    return 0;
}