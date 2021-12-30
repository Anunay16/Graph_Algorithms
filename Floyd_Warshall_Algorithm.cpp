// link to the problem: https://www.hackerrank.com/challenges/floyd-city-of-blinding-lights/problem

// Floyd-Warshall Algorithm
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e5+7;

bool isPossible(vector<vector<int>>& dist, int i, int j, int k) {
    return dist[i][k] != INF and dist[k][j] != INF and (dist[i][k] + dist[k][j] < dist[i][j]);
}

vector<vector<int>> floyd(vector<vector<int>>& graph, int V, int E) {
    vector<vector<int>> dist = graph;
    for (int k = 1; k <= V; k++) {
        for (int i = 1; i < (int)graph.size(); i++) {
            for (int j = 1; j < (int)graph[0].size(); j++) {
                //compare dis(i,j) with dis(i, k) + dis(k, j)
                if (isPossible(dist, i, j, k)) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                } 
            }
        }
    }
    return dist;
}

void solve() {
    int V, E;
    cin >> V >> E;
    //create the graph
    vector<vector<int>> graph(V + 1, vector<int> (V + 1, INF));
    for (int i = 0; i < E; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        graph[u][u] = 0;
        graph[v][v] = 0;
        graph[u][v] = wt;
    }
    //graph is ready
    vector<vector<int>> dist = floyd(graph, V, E);
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        int ans = (dist[u][v] == INF) ? -1 : dist[u][v];
        cout << ans << "\n";
    }
}

void FIO()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

int main()
{
    FIO();
    solve();
    return 0;
}
// Time Complexity: O(V^3)
