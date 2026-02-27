One obvious thing to do here is to calculate distance between all the (i,j) pairs of students possible.

## Appraoch 1

Use brute force, check all possible combinations and see if any works. Not sure if this would fit the time limit, as N <= 8, so may work.

## Apprach 2 - but it doesn't work

Sort all the pairs and start taking from the top. Every time, take only such paiers that haven't been chosen earlie. See this snippet:

```cpp
sort(edges.begin(), edges.end());
vector<bool> picked_vec(count, false);
vector<pair<int,int>> teams;
for (auto &e : edges) {
    int i = e.second.first;
    int j = e.second.second;
    if (!picked_vec[i] && !picked_vec[j]) {
        teams.push_back({i, j});
        picked_vec[i] = true;
        picked_vec[j] = true;
    }
}

## Example Where Greedy Fails

The greedy approach does not always produce the optimal solution. For example, consider these points: { (-5,1), (-5,-1), (5,1), (5,-1), (-1,0), (1,0), (-25,0), (25,0) }

Expected output:
Greedy ouptut: 56