// This code doesn't work well yet. I started to implement, but don't have the DFS basics. I am just pushing this off for now.
// Btw, the problem link is here:
// https://cses.fi/problemset/task/1694/


// For the CSES submit, you need to reduce the indices u,v by 1 when you are taking input.
// this is because, they didn't use 0 based indexing 

#include <bits/stdc++.h>
using namespace std;

void print_graph(int v, vector<vector<int>> graph);
int compute_maxflow(int n, vector<vector<int>> graph, int source, int sink);
bool dfs(int u, int sink, vector<vector<int>> &residual, vector<bool> &visited, vector<int> &parent, int n);

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> graph(n, vector<int> (n));

    // now let's take the input of edges
    int u, v, c;
    for (int i =0; i < e; i++) {
        cin >> u >> v >> c;
        // this stupid website is 1 indexed and i am 0 indexed so i have to do this
        u--;
        v--;
        graph[u][v] = c;
    }
    // print_graph(n, graph);
    int source = 0, sink = n-1;
    int maxflow = compute_maxflow(n, graph, source, sink);
    cout << maxflow << endl;
    return 0;
}

void print_graph(int n, vector<vector<int>> graph) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setprecision(3) << graph[i][j] << " ";
        }
        cout << endl;
    }
}

bool dfs(int u, int sink, vector<vector<int>> &residual, vector<bool> &visited, vector<int> &parent, int n) {
    visited[u] = true;
    if (u == sink)
        return true;
    for (int v = 0; v < n; v++) {
        if (!visited[v] && residual[u][v] > 0) {
            parent[v] = u;
            if (dfs(v, sink, residual, visited, parent, n))
                return true;
        }
    }
    return false;
}

int compute_maxflow(int n, vector<vector<int>> graph, int source, int sink) {
    vector<vector<int>> residual = graph;
    int maxflow = 0;
    while (true) {
        vector<bool> visited(n, false);
        vector<int> parent(n, -1);
        if (!dfs(source, sink, residual, visited, parent, n))
            break;  // no augmenting path

        int bottleneck = INT_MAX;
        int v = sink;
        while (v != source) {
            int u = parent[v];
            bottleneck = min(bottleneck, residual[u][v]);
            v = u;
        }

        v = sink;
        while (v != source) {
            int u = parent[v];
            residual[u][v] -= bottleneck;
            residual[v][u] += bottleneck;
            v = u;
        }

        maxflow += bottleneck;
    }

    return maxflow;
}