#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
// code by shalini
int minDistance(string w1, string w2) {
    int l1 = w1.size(), l2 = w2.size();
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
    for (int i = 0; i <= l1; ++i) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= l2; ++j) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= l1; ++i) {
        for (int j = 1; j <= l2; ++j) {
            if (w1[i - 1] == w2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min({
                                   dp[i - 1][j],    // Deletion
                                   dp[i][j - 1],    // Insertion
                                   dp[i - 1][j - 1] // Replacement
                               });
            }
        }
    }
    return dp[l1][l2];
}
main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        cout << minDistance(s1, s2) << endl;
    }
}