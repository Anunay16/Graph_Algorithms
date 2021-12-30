/* 
    link to the problem: https://cses.fi/problemset/task/1676/
    
    PROBLEM:
    There are n cities and initially no roads between them. However, every day a new road will be constructed, and there will be a total of m roads.
    A component is a group of cities where there is a route between any two cities using the roads. After each day, your task is to find the number
    of components and the size of the largest component.
    
    APPROACH:
    use Kruskal's Algorithm with Disjoint Set Union(DSU).
*/

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

int merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (sz[a] < sz[b]) {
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
    }
    return sz[a];
}

void solve() {
    parent.resize(1e6); sz.resize(1e6);
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        make(i);
    }
    int largest = 1;
    int cc = n;
    while(m--) {
        cin >> u >> v;
        if (find(u) != find(v)) {
            largest = max(largest, merge(u, v));
            cc--;
        }
        cout << cc << " " << largest << "\n";
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
