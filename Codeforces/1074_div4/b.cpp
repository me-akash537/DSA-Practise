#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int max = 0;
        int x;
        for (int i = 0; i < n; i++) {
            cin >> x;
            max = (max < x) ? x : max;
        }
        cout << max*n << endl;
    }
    return 0;
}