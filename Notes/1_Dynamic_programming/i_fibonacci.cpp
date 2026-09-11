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

int fibo_memo(int n, vector<int>* memo = nullptr) {
    if (n < 0) return -1;
    if (n == 0) return 0;
    if (n == 1) return 1;

    vector<int> internal_memo;
    if (memo == nullptr) {
        internal_memo.assign(n + 1, -1);
        memo = &internal_memo;
    }

    if ((*memo)[n] != -1) return (*memo)[n];

    (*memo)[n] = fibo_memo(n - 1, memo) + fibo_memo(n - 2, memo);
    return (*memo)[n];
}
// Time complexity - O(n)
// Space Complexity - O(n)

int fibo_save_in_array(int n) {
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
        cout << fibo_recursive(n) << '\t'
             << fibo_memo(n) << '\t'
             << fibo_save_in_array(n) << '\n';
    }
    return 0;
}
