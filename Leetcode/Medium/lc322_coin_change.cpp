#include <bits/stdc++.h>
using namespace std;

/*
    Tags: Greedy
    Tags: Dynamic Programming
    Tags: Graph
    Tags: Breadh First Search
    Tags: Dijkstra's Algorithm

    Difficulty: Medium
    
    The notes for this problem is present in page number 7.
    The take is that you can see this problem as a graph problem where each node is an amount and the edges are the coins. So, we can use a Dijsktra's algorithm to find the shortest path from the source node (0) to the destination node (amount). 
*/

#define max_amount 10001
#define max_coins 12
#define INF 100000
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int arr_nodes[max_amount];
        fill(arr_nodes, arr_nodes + max_amount, INF);
        int count_coins = coins.size();
        sort(coins.begin(), coins.end());

        int curr_coin = 0;
        int next_hop = 0;
        arr_nodes[0] = 0;
        for (int i = 0; i <= amount; i++) {
            if (arr_nodes[i] == INF) {
                // cout << "i = " << i << ", arr_nodes[i]: " << arr_nodes[i] << "\n";
                continue;
            }
            for (int j = 0; j < count_coins; j++) {
                curr_coin = coins[j];
                // cout << "i = " << i << ", curr_coin: " << curr_coin << "\n";
                if (curr_coin <= amount) {
                    next_hop = i + curr_coin;
                    if (next_hop <= amount) {
                        if (arr_nodes[next_hop] > arr_nodes[i] + 1) {
                            arr_nodes[next_hop] = arr_nodes[i] + 1;
                            // cout << "next_hop: " << next_hop << ", arr_nodes[next_hop]: " << arr_nodes[next_hop] << "\n";
                        }
                    }
                }
            }
            // print_arrnodes(amount, arr_nodes);
        }
        int result = arr_nodes[amount] == INF ? -1 : arr_nodes[amount];
        return result;
    }
    void print_arrnodes(int amount, int arr_nodes[10001]) {
        for (int i = 0; i <= amount; i++) {
            arr_nodes[i] == INF ? cout << "--  " : cout << arr_nodes[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    /*
        Input: coins = [1,2,5], amount = 11
        Output: 3
    */

    vector<int> coins = {1, 2, 5};
    int amount = 11;
    Solution sol;
    cout << sol.coinChange(coins, amount) << "\n";


    return 0;
}