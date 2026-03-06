#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gsize = g.size();
        int ssize = s.size();

        int i = 0, j = 0, count = 0;
        while (i < gsize && j < ssize) {
            if (g[i] <= s[j]) {
                count++;
                i++;
                j++;
            }
            else {
                j++;
            }
        }
        return count;
    }
};

int main () {
    Solution sol;
    vector<int> g = {1, 2};
    vector<int> s = {1, 2, 3};
    cout << sol.findContentChildren(g, s) << endl;
    return 0;
}