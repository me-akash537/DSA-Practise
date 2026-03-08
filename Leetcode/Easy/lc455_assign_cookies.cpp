/*
    LC455: Assign Cookies
    Dificuluty: Easy

    Tags: Greedy
    Tags: Sorting

    Takeaways: quite a basic problem, just sort the arrays and then use two pointers to find the optimal solution.

    One thing to note is that, you shoul always give a child the smallest cookie that can satisfy him, because if you give him a bigger cookie, then you might not have a smaller cookie to satisfy another child, which might lead to a suboptimal solution. 

*/

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