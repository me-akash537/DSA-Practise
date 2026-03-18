#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m, h;
        cin >> n >> m >> h;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        // copy a to b
        vector<int> copy = a;

        for (int i = 0; i < m; i++) {
            int b, c;
            cin >> b >> c;
            b--;
            if (copy[b] + c <= h) {
                copy[b] += c;
            }
            else {
                copy = a;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << copy[i] << " ";
        }
        cout << endl;

    }
    return 0;
}