#include <bits/stdc++.h>
using namespace std;
#define INF 1000000

double dolve_by_greedy(int tc, int count, vector<vector<double>> &dist_matrix, vector<vector<bool>> &binary_matrix);
double solve_by_bitmask(int tc, int count, vector<vector<double>> &dist_matrix, vector<vector<bool>> &binary_matrix);
void compute_distances(int count, vector<pair<int, int>> &students, vector<vector<double>> &dist_matrix);

void print_binary_matrix(int count, vector<vector<bool>> &binary_matrix); 
void print_dist_matrix(int count, vector<vector<double>> &dist_matrix);
void print_edge_pairs(vector<pair<double, pair<int, int>>> &edges);

int main() {
    int test_case = 1;
    int n;
    while (cin >> n && n > 0) {
        int count = 2 * n;
        vector<pair<int, int>> students(count);
        for (int i = 0; i < count; i++) {
            string name;
            int xcord, ycord;
            cin >> name >> xcord >> ycord;
            students[i] = {xcord, ycord};
        }
        vector<vector<double>> dist_matrix(count, vector<double>(count));
        vector<vector<bool>> binary_matrix(count, vector<bool>(count, false));
        compute_distances(count, students, dist_matrix);
        // print_dist_matrix(count, dist_matrix); 

        double greedy_output = dolve_by_greedy(test_case, count, dist_matrix, binary_matrix);
        double bitmask_output = solve_by_bitmask(test_case, count, dist_matrix, binary_matrix);
        
        cout << "Case " << test_case << ": " << fixed << setprecision(2) << greedy_output << "  " << fixed << setprecision(2) << bitmask_output << " " << greedy_output - bitmask_output << "\n";
        test_case++;
        print_binary_matrix(count, binary_matrix);
    }

    return 0;
}

double solve_by_bitmask(int tc, int count, vector<vector<double>> &dist_matrix, vector<vector<bool>> &binary_matrix) {
    // i don't the optimal way to solve this question, so i am just trying things that may work
    // my first appraoch is to iterate over the binary matrix i have obtained, only the upper half, obviously
    // each 1, will get me a team. so when i have two teams, i will try to swap them, and see if that makes any difference, if that gives me something better, great.
    return 0.0;
}

double dolve_by_greedy(int tc, int count, vector<vector<double>> &dist_matrix, vector<vector<bool>> &binary_matrix){
    vector<pair<double, pair<int, int>>> edges;
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            edges.push_back({dist_matrix[i][j], {i, j}});
        }
    }
    sort(edges.begin(), edges.end());
    // print_edge_pairs(edges);

    vector<bool> visited(count, false);
    vector<pair<int, int>> teams;
    double total_distance = 0.0;
    for (auto &edge : edges) {
        int u = edge.second.first;
        int v = edge.second.second;
        if (!visited[u] && !visited[v]) {
            visited[u] = true;
            visited[v] = true;
            teams.push_back({u, v});
            total_distance += dist_matrix[u][v];
            cout << "(" << u << ", " << v << ") ->  "  << setprecision(2) << dist_matrix[u][v] << endl;
            binary_matrix[u][v] = true;
            binary_matrix[v][u] = true;
        }
    }
    return total_distance;
}



void print_binary_matrix(int count, vector<vector<bool>> &binary_matrix) {
    cout << "\nBinary Matrix:\n";
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            cout << binary_matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

void compute_distances(int count, vector<pair<int, int>> &students, vector<vector<double>> &dist_matrix) {
    for (int i = 0; i < count; i++) {
        dist_matrix[i][i] = INF;
        for (int j = i + 1; j < count; j++) {
            int dx = students[i].first - students[j].first;
            int dy = students[i].second - students[j].second;
            dist_matrix[i][j] = sqrt(dx * dx + dy * dy);
            dist_matrix[j][i] = dist_matrix[i][j];
        }
    }
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

void print_dist_matrix(int count, vector<vector<double>> &dist_matrix) {
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            if (dist_matrix[i][j] != INF) {
                cout << setw(7)
                     << fixed << setprecision(2)
                     << dist_matrix[i][j] << " ";
            } else {
                cout << setw(7) << "--" << " ";
            }
        }
        cout << "\n";
    }
}
