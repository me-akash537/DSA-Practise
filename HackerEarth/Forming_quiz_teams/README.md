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

This Greedy approach does not give optimal solutoins. Example Test case:

4
sohel -5 1
mahmud -5 -1
sanny 5 1
prince 5 -1
per -1 0
mf 1 0
kugel -25 0
joey 25 0