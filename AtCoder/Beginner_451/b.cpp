#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
   
    vector<int> pres(m, 0);
    vector<int> next(m, 0);
    int n_copy = n;

    int a, b;
    while (n_copy--) {
        cin >> a >> b;
        pres[a - 1]++;
        next[b - 1]++;
    }

    for (int i = 0; i < m; i++) {
        cout << next[i] - pres[i] << endl;
    }

    return 0;
}