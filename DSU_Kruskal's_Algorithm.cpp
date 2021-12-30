// link to the problem: https://www.hackerrank.com/challenges/kruskalmstrsub/problem

// Kruskal's Algorithm to find minimum spanning tree
#include <bits/stdc++.h>
using namespace std;

vector<int> parent, sz;
void make(int i) {
    parent[i] = i;
    sz[i] = 1;
}

int find(int i) {
    if (i == parent[i]) {
        return i;
    }
    return parent[i] = find(parent[i]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (sz[a] < sz[b]) {
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
    }
}

void solve() {
    parent.resize(1e6); sz.resize(1e6);
    //first take no of vertices and edges as input
    int V, E;
    cin >> V >> E;
    //make the DSU first
    for (int i = 0; i < V; i++) {
        make(i);
    }
    //now store all the edges.
    //we have to sort them in increasing order of weight.
    //so take weight first
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < E; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({wt, {u, v}});
    }
    sort(edges.begin(), edges.end());

    //now iterate over every edge and check whether can we put it.
    int total_cost = 0;
    for (auto &edge: edges) {
        int u = edge.second.first;
        int v = edge.second.second;
        int wt = edge.first;
        //if a and b doesnot belong to same parent, then we can merge them
        //otherwise they will form a cycle which is not a tree
        if (find(u) == find(v)) continue;
        //here, both nodes belong to different parents, so we merge them
        merge(u, v);
        // cout << u << " " << v << " " << wt << "\n";
        total_cost += wt;
    }
    cout << total_cost << "\n";
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
