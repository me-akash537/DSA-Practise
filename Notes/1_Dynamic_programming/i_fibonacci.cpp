#include <bits/stdc++.h>
using namespace std;

int fibo_recursive(int n) {
    if (n < 0) return -1;
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibo_recursive(n - 1) + fibo_recursive(n - 2);
}
// Time complexity - O(2^n)
// Space Complexity - O(n)

int fibo_memo(int n, vector<int>& memo) {
    if (n < 0) return -1;
    if (memo[n] != -1) return memo[n];

    memo[n] = fibo_memo(n - 1, memo) + fibo_memo(n - 2, memo);
    return memo[n];
}
// Time complexity - O(n)
// Space Complexity - O(n)

int fibo_dp(int n) {
    if (n < 0) return -1;
    if (n == 0) return 0;

    vector<int> fibo_numbers(n + 1);
    fibo_numbers[0] = 0;
    fibo_numbers[1] = 1;
    for (int i = 2; i <= n; i++){
        fibo_numbers[i] = fibo_numbers[i - 1] + fibo_numbers[i - 2];
    }
    return fibo_numbers[n];
}
// Time complexity - O(n)
// Space Complexity - O(n)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        if (n < 0) {
            cout << "-1\t-1\t-1\n";
            continue;
        }

        vector<int> memo(n + 1, -1);

        memo[0] = 0;
        if (n >= 1)
            memo[1] = 1;

        cout << fibo_recursive(n) << '\t'
             << fibo_memo(n, memo) << '\t'
             << fibo_dp(n) << '\n';
    }
    return 0;
}
