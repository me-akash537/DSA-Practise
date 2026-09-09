#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();

    if (n % 5 == 0) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }

    return 0;   
}