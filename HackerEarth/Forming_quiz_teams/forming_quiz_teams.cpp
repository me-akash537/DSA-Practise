#include <bits/stdc++.h>
using namespace std;
#define INF 1000000

void solve_by_greedy(int count,
                       vector<pair<double, pair<int, int>>> &edges,
                       vector<vector<double>> &dist,
                       int tc) {

    vector<bool> picked_vec(count, false);
    vector<pair<int, int>> teams;

    for (auto &e : edges) {
        int i = e.second.first;
        int j = e.second.second;
        if (!picked_vec[i] && !picked_vec[j]) {
            teams.push_back({i, j});
            picked_vec[i] = true;
            picked_vec[j] = true;
        }
    }
    
    double total_distance = 0.0;
    for (auto &t : teams) {
        total_distance += dist[t.first][t.second];
        // cout << "(" << t.first << ", " << t.second << "  "  << setprecision(2) << dist[t.first][t.second] << ")\n";
    }

    cout << "Case " << tc << ": "
         << fixed << setprecision(2)
         << total_distance << "\n";
}

void read_students(int count, vector<pair<int, int>> &students) {
    string name;
    int xcord, ycord;

    for (int i = 0; i < count; i++) {
        cin >> name;
        cin >> xcord;
        cin >> ycord;
        students[i].first = xcord;
        students[i].second = ycord;
    }
}

void compute_distances(int count,
                       vector<pair<int, int>> &students,
                       vector<vector<double>> &dist) {

    for (int i = 0; i < count; i++) {
        dist[i][i] = INF;
        for (int j = i + 1; j < count; j++) {
            int dx = students[i].first - students[j].first;
            int dy = students[i].second - students[j].second;
            dist[i][j] = sqrt(dx * dx + dy * dy);
            dist[j][i] = dist[i][j];
        }
    }
    // print_dist_matrix(count, dist);
}

void print_dist_matrix(int count, vector<vector<double>> &dist) {
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            if (dist[i][j] != INF) {
                cout << setw(7)
                     << fixed << setprecision(2)
                     << dist[i][j] << " ";
            } else {
                cout << setw(7) << "--" << " ";
            }
        }
        cout << "\n";
    }
}

void obtain_sorted_pairs(int count,
                         vector<pair<double, pair<int, int>>> &edges,
                         vector<vector<double>> &dist) {

    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            edges.push_back({dist[i][j], {i, j}});
        }
    }

    sort(edges.begin(), edges.end());
    // print_edge_pairs(edges);
}

void print_edge_pairs(vector<pair<double, pair<int, int>>> &edges) {
    cout << "\nSorted pairs (i, j) with distance:\n";
    for (auto &e : edges) {
        cout << "("
             << e.second.first << ", "
             << e.second.second << ") -> "
             << fixed << setprecision(2)
             << e.first << "\n";
    }
}

int main() {
    int n;
    int test_case = 1;

    while (cin >> n && n > 0) {
        int count = 2 * n;

        // students stores as (x, y) pairs
        // dist is the distance matrix
        // edges stores all (distance, (i, j)) pairs 

        vector<pair<int, int>> students(count);
        vector<vector<double>> dist(count, vector<double>(count));
        vector<pair<double, pair<int, int>>> edges;

        read_students(count, students);
        compute_distances(count, students, dist);
        obtain_sorted_pairs(count, edges, dist);

        solve_by_greedy(count, edges, dist, test_case);

        test_case++;
    }

    return 0;
}