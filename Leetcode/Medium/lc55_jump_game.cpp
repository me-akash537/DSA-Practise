/*
    LC55 Jump Game
    Difficulty: Medium, but I think it's more of an Easy problem
    
    Tags: Greedy
    Takeaways: The greedy approach is to keep track of the farthest reachable index at each step, and if we ever encounter an index that is greater than the farthest reachable index, we can conclude that we cannot reach the end of the array.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i > farthest) return false;
            farthest = max(farthest, i + nums[i]);
        }

        return true;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    /*
        input = [3,2,1,0,4]
    */
    vector<int> nums = {3, 2, 1, 0, 4};
    cout << sol.canJump(nums) << endl;


    return 0;
}