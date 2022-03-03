// link to the problem: https://atcoder.jp/contests/dp/tasks/dp_g
// topic: DP on Graphs. We can also do it with Topological sorting but DP approach is more intuitive

#include <bits/stdc++.h>
using namespace std;

const int nax = 1e5 + 5;
vector<int> adj[nax];
vector<int> dp, vis;

void visit(int v) {
    // we have two options from every vertex
    // 1. End the path right here.
    // 2. Go along the out edges and find the longest path from this vtx
    vis[v] = 1;
    dp[v] = 0;
    for (int child : adj[v]) {
        if (!vis[child]) {
            visit(child);
        }
        dp[v] = max(dp[v], 1 + dp[child]);
    }
}

void solve() {
    vis.resize(nax);
    dp.resize(nax);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }

    // try to find the longest path from every node
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i])
            visit(i);
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
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

// Time Complexity: O(V + E)
