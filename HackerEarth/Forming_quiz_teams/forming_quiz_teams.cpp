#include <bits/stdc++.h>
using namespace std;
#define INF 1000000

void solve(int n, int tc) {
    int count = 2*n;
    vector<pair<int,int>> students(count);
    string name;
    int xcord, ycord;
    for (int i = 0; i < count; i++) {
        cin >> name;
        cin >> xcord;
        cin >> ycord;
        students[i].first = xcord;
        students[i].second = ycord;
    }
    vector<vector<double>> dist(count, vector<double>(count));
    for (int i = 0; i < count; i++) {
        dist[i][i] = INF;
        for (int j = i+1; j < count; j++) {
            int dx = students[i].first - students[j].first;
            int dy = students[i].second - students[j].second;
            dist[i][j] = sqrt(dx*dx + dy*dy);
            dist[j][i] = dist[i][j];
        }
    }
    // uncomment if you want to see the distance matrix
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            if (dist[i][j] != INF) {
                cout << setw(7) << fixed << setprecision(2) << dist[i][j] << " ";
            }
            else {
                cout << setw(7) << "--" << " ";
            }
        }
        cout << "\n";
    }

    vector<pair<double, pair<int,int>>> edges;
    for (int i = 0; i < count; i++) {
        for (int j = i+1; j < count; j++) {
            edges.push_back({dist[i][j], {i, j}});
        }
    }
    sort(edges.begin(), edges.end());

    // cout << "\nSorted pairs (i, j) with distance:\n";
    // for (auto &e : edges) {
    //     cout << "(" 
    //         << e.second.first << ", " 
    //         << e.second.second << ") -> "
    //         << fixed << setprecision(2) 
    //         << e.first << "\n";
    // }

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

    cout << "\nFormed Teams (index pairs):\n";
    double total_distance = 0.0;
    for (auto &t : teams) {
        cout << "(" << t.first << ", " << t.second << "  " << setprecision(2) << dist[t.first][t.second] << ")\n";
        total_distance += dist[t.first][t.second];
    }
    cout << "Case " << tc << ": " << fixed << setprecision(2) << total_distance << "\n";
}

int main() {
	int n;
    int test_case = 1;
    while (cin >> n && n > 0) {
        if (n == 0) break;
        solve(n, test_case);
        test_case++;
    }
    return 0;
}
