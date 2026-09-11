/*

Grid Traveller Problem, Leetcode Problem 62 (medium)

Problem statement: There is a robot on an m x n grid. The robot is initially located at the top-left corner. The robot tries to move to the bottom-right corner. The robot can only move either down or right at any point in time. Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

Solution 1: Arrange 'D' and 'R' in a sequence of length m+n-2, n(D) = m-1, n(R) = n-1. Answer would be (m+n-2)! / ((m-1)! * (n-1)!) = (m+n-2)C(m-1) = (m+n-2)C(n-1). 
The for loop computes (m+n-2) (m+n-3) ... (m) / (1 * 2 * ... * (n-1)).

Solution 2: dp[i][j] = dp[i-1][j] + dp[i][j-1]. Base case will be when i = 0 or j = 0, dp[i][j] = 1. We can optimize the space complexity to O(n) by using a single array of size n, since the matrix is kinda symmetric.

*/


#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n) {
    vector<int> dp(n, 1);
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[j] = dp[j] + dp[j - 1];
            // here dp[j] initially stores the value from previous row, and dp[j-1] stores the value from current row, that gives us the new cell value for dp[i][j].
        }
    }
    return dp[n - 1];
}

int uniquePaths_bionomial(int m, int n) {
    long long ans = 1;
    m--; n--;
    if (n > m) swap(m, n);
    for (int i = 1; i <= n; i++)
        ans = ans * (m + i) / i;
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        cout << uniquePaths(m, n) << '\t' << uniquePaths_bionomial(m, n) << '\n';
    }

    return 0;
}