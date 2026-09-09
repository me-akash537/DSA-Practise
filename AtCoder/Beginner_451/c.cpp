#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;

    vector<int> trees = {};

    while(q--) {
        int t, h;
        cin >> t >> h;

        if (t == 1) {
            trees.push_back(h);
        } 
        else {
            sort(trees.begin(), trees.end());
            auto it = upper_bound(trees.begin(), trees.end(), h);
            trees.erase(trees.begin(), it);
        }
        cout << trees.size() << endl;
    }
    
    return 0;
}