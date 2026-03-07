/*
    Problem: 860. Lemonade Change
    Difficulty: Easy

    Tags: Greedy
    Takeaways: nothing much really, quite a basic problem.
    
    yeah, note that while updating, you should prefer 10 over 5, because 10 can only be used for 20, while 5 can be used for both 10 and 20, so you should save the 5s as much as possible.

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count[2] = {0};
        int no_of_customers = bills.size();
        for (int i = 0; i< no_of_customers; i++) {
            if (bills[i] == 5) {
                count[0]++;
            }
            else if (bills[i] == 10) {
                count[0]--;
                count[1]++;
            }
            else if (bills[i] == 20) {
                if (count[1] > 0) {
                    count[1]--;
                    count[0]--;
                }
                else {
                    count[0] -= 3;
                }
            }
            if (count[0] < 0 || count[1] < 0) {
                return false;
            }
        }
        return true;
    }  
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    /*
        Input: bills = [5,5,5,10,20]
        Output: true
    */

    Solution sol;
    vector<int> bills = {5, 5, 5, 10, 20};
    cout << sol.lemonadeChange(bills) << endl;


    return 0;
}