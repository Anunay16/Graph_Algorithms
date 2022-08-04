// link to the problem: https://www.hackerrank.com/challenges/dijkstrashortreach/problem

//Dijkstra's Algorithm
#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>

struct Edge {
    int u, v, wt;
    Edge(int _u, int _v, int _wt) {
        u = _u;
        v = _v;
        wt = _wt;
    }
};

const int INF = 1e9;

void dijkstras(vector<vector<Edge>>& adj, vector<bool>& visited, vector<int>& shortestPaths, int src) {
    //make a priority queue: min heap
    priority_queue<pi, vector<pi>, greater<pi>> pq; // <wt, vertex>
    pq.push({0, src});
    while (!pq.empty()) {
        //remove
        pi rem = pq.top();
        pq.pop();
        int wt = rem.first;
        int vtx = rem.second;
        //mark*
        if (visited[vtx]) continue; // cycle detected
        visited[vtx] = true;
        //work
        // shortestPaths[vtx] = wt;
        //add*
        for (auto &edge: adj[vtx]) {
            if (wt + edge.wt < shortestPaths[edge.v]) {
                shortestPaths[edge.v] = wt + edge.wt;
                pq.push({shortestPaths[edge.v], edge.v});
            }
        }
    }
}

void solve() {
    int V, E;
    cin >> V >> E;
    // make the adjacency list
    vector<vector<Edge>> adj(V + 1);
    for (int i = 0; i < E; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back(Edge(u, v, wt));
        adj[v].push_back(Edge(v, u, wt));
    }
    int src;
    cin >> src;
    vector<bool> visited(V + 1, false);
    vector<int> shortestPaths(V + 1, INF);
    dijkstras(adj, visited, shortestPaths, src);
    for (int i = 1; i < V + 1; i++) {
        if (i != src) {
            cout << (shortestPaths[i] == INF ? -1 : shortestPaths[i]) << " ";
        }
    }
    cout << "\n";
}

// void FIO()
// {
//     #ifndef ONLINE_JUDGE
//         freopen("input.txt", "r", stdin);
//         freopen("output.txt", "w", stdout);
//     #endif
// }

int main()
{
    //FIO();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
